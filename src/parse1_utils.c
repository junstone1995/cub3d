/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:37:51 by namhkim           #+#    #+#             */
/*   Updated: 2021/11/22 16:52:05 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

extern int	g_fd;
extern int	g_ret;

void	parseandclose(int g_ret, t_config *c, int tp, char *line)
{
	parse_by_type(g_ret, c, tp, line);
	close(g_fd);
	return ;
}

int	operate(char const *conf_path)
{
	if (!(is_cub_file(conf_path)))
		return (23);
	g_fd = open(conf_path, O_RDONLY);
	if (g_fd < 0)
		return (24);
	return (0);
}
