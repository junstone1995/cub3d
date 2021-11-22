/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:37:51 by namhkim           #+#    #+#             */
/*   Updated: 2021/11/21 17:31:21 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	process_except(int *g_ret, char *line,
	t_game *game, t_config *config)
{
	int	type;

	while (g_ret > 0)
	{
		type = check_type(line);
		if (type == -1)
			return (exit_error(game, EXIT_FAILURE, "ERROR\nwrong type"));
		if (is_blank_line(line) && !(config->map))
		{
			free(line);
			continue ;
		}
		else if (is_blank_line(line) && config->map && g_ret)
			return (exit_error(game, EXIT_FAILURE, "blank line in the map"));
		if (!parse_by_type(*g_ret, config, type, line))
			return (0);
	}
	parse_by_type(*g_ret, config, type, line);
	return (0);
}
