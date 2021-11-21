/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:11:56 by namhkim           #+#    #+#             */
/*   Updated: 2021/11/21 17:31:48 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	g_fd;
int	g_ret;

static int	is_cub_file(char const *conf_path)
{
	int	ret;
	int	len;

	ret = 1;
	len = ft_strlen(conf_path);
	if (len >= 4)
		ret = ft_strncmp(conf_path + len - 4, ".cub", 4);
	if (ret == 0)
		return (1);
	else
		return (0);
}

static int	check_map_component(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_strchr("012NSEW ", line[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_type(char *line)
{
	if (line[0] == 'R' && line[1] == ' ')
		return (C_R);
	else if (line[0] == 'N' && line[1] == 'O')
		return (C_NO);
	else if (line[0] == 'S' && line[1] == 'O')
		return (C_SO);
	else if (line[0] == 'W' && line[1] == 'E')
		return (C_WE);
	else if (line[0] == 'E' && line[1] == 'A')
		return (C_EA);
	else if (line[0] == 'S' && line[1] == ' ')
		return (C_S);
	else if (line[0] == 'F' && line[1] == ' ')
		return (C_F);
	else if (line[0] == 'C' && line[1] == ' ')
		return (C_C);
	else if (check_map_component(line))
		return (C_MAP);
	return (-1);
}

int	is_blank_line(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (!is_space(line[i]))
			return (0);
		i++;
	}
	return (1);
}

int	parse_config(t_game *game, t_config *config, char const *conf_path)
{
	char	*line;

	if (!(is_cub_file(conf_path)))
		return (exit_error(game, EXIT_FAILURE, "ERROR\nNOT .CUB EXTENSION\n"));
	g_fd = open(conf_path, O_RDONLY);
	if (g_fd < 0)
		return (exit_error(game, EXIT_FAILURE, "ERROR\nWRONG FILE PATH\n"));
	g_ret = 1;
	g_ret = get_next_line(g_fd, &line);
	process_except(&g_ret, line, game, config);
	close(g_fd);
	return (1);
}
