/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_util2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:11:33 by junseole          #+#    #+#             */
/*   Updated: 2021/11/23 22:26:55 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	getccc__11(int value1, int value2, double value3)
{
	if ((value1 && value3 > 0) || (value2 && value3 < 0))
		return (-1);
	return (1);
}
