/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:24:01 by junseole          #+#    #+#             */
/*   Updated: 2021/11/22 18:24:05 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_by_type2(t_config *c, int tp, char *line, int flag)
{
	if (flag == 1)
	{
		if (c->tex[tp].tex_path)
			return (free_line(line, 0));
		c->tex[tp].tex_path = parse_path(line);
		if (!c->tex[tp].tex_path)
			return (free_line(line, 0));
	}
	if (flag == 2)
	{
		c->floor_color = parse_color(line);
		if (c->floor_color == -1)
			return (0);
	}
	if (flag == 3)
	{
		c->ceiling_color = parse_color(line);
		if (c->ceiling_color == -1)
			return (0);
	}
	return (1);
}
