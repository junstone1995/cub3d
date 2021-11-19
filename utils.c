/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:05:01 by junseole          #+#    #+#             */
/*   Updated: 2021/11/19 15:35:05 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	max(double a, double b)
{
	if (a > b)
		return (a);
	return (b);
}

int	is_upper(int x)
{
	if (x >= 65 && x <= 90)
		return (1);
	return (0);
}

int	is_space(int x)
{
	if ((x >= 9 && x <= 13) || x == 32)
		return (1);
	return (0);
}
