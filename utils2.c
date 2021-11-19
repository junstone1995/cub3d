/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 14:52:27 by junseole          #+#    #+#             */
/*   Updated: 2021/11/19 15:10:49 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_machine(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->config.rows)
	{
		if (game->config.map[i])
			free(game->config.map[i]);
	}
	free(game->config.map);
	i = -1;
	while (++i < TEXTURES - 3)
	{
		if (game->config.tex[i].texture)
			free(game->config.tex[i].texture);
	}
}

int	free_line(char *line, int ret)
{
	free(line);
	return (ret);
}

char	*update_temp(char *temp, char *line)
{
	char	*temp2;
	char	*temp3;

	temp2 = ft_strjoin(line, "\n");
	temp3 = ft_strjoin(temp, temp2);
	if (*temp && temp)
	{
		free(temp);
		temp = NULL;
	}
	free(temp2);
	return (temp3);
}
