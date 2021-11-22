/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:01:48 by junseole          #+#    #+#             */
/*   Updated: 2021/11/22 18:23:06 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	parse_resolution(t_config *config, char *line)
{
	int		i;
	int		width;
	int		height;

	i = 0;
	width = 0;
	height = 0;
	while (is_upper(line[i]))
		i++;
	while (is_space(line[i]))
		i++;
	while (ft_isdigit(line[i]))
		width = width * 10 + line[i++] - 48;
	while (is_space(line[i]))
		i++;
	while (ft_isdigit(line[i]))
		height = height * 10 + line[i++] - 48;
	config->width = width;
	config->height = height;
	return (1);
}

char	*parse_path(char *line)
{
	int		i;
	char	*buff;

	i = 0;
	while (is_upper(line[i]))
		i++;
	while (is_space(line[i]))
		i++;
	buff = ft_strdup(line + i);
	return (buff);
}

int	parse_color(char *line)
{
	int	i;
	int	j;
	int	color;
	int	colors[3];

	i = 0;
	j = 0;
	while (j < 3)
		colors[j++] = 0;
	while (is_upper(line[i]))
		i++;
	if (is_space(line[i]))
		i++;
	j = -1;
	while (line[i] && ++j < 3)
	{
		while (line[i] && ft_isdigit(line[i]))
			colors[j] = colors[j] * 10 + line[i++] - 48;
		if ((!ft_strchr(",", line[i]) && line[i] != '\0') || colors[j] > 255)
			return (-1);
		if (ft_strchr(",", line[i]))
			i++;
	}
	color = colors[0] * 256 * 256 + colors[1] * 256 + colors[2];
	return (color);
}

static int	parse_map(t_config *config, char *temp)
{
	int		i;
	int		j;

	config->map = ft_split(temp, '\n');
	if (!config->map)
		return (0);
	free(temp);
	i = -1;
	j = 0;
	while (config->map[++i])
		if (j < (int)ft_strlen(config->map[i]))
			j = (int)ft_strlen(config->map[i]);
	config->rows = i;
	config->colums = j;
	config->tile = config->width / config->colums;
	return (1);
}

int	parse_by_type(int ret, t_config *c, int tp, char *line)
{
	static char	*temp = "";

	if (tp == C_R)
	{
		if (!parse_resolution(c, line))
			return (free_line(line, 0));
	}
	else if (tp >= C_NO && tp <= C_S)
	{
		if (!parse_by_type2(c, tp, line, 1))
			return (free_line(line, 0));
	}
	else if (tp == C_F || tp == C_C)
	{
		if ((tp == C_F && !parse_by_type2(c, tp, line, 2))
			|| (tp == C_C && !parse_by_type2(c, tp, line, 3)))
			return (free_line(line, 0));
	}
	else
	{
		temp = update_temp(temp, line);
		if (ret == 0 && !parse_map(c, temp))
			return (free_line(line, 0));
	}
	return (free_line(line, 1));
}
