/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:58:19 by junseole          #+#    #+#             */
/*   Updated: 2021/11/22 19:37:39 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	getC_V0(int choice, int value)
{
	if (choice)
	{
		return (value);
	}
	return (0);
}

int	getC__11(int value)
{
	if (value)
		return (-1);
	return (1);
}

double	getCV__V0(int value1, int value2, double stepx)
{
	if ((value1 && stepx > 0) || (value2 && stepx < 0))
		return (stepx * -1);
	return (stepx);
}

int	getC__10(int value)
{
	if (value)
		return (-1);
	return (0);
}

int	getCV_V0(int choice, int value)
{
	if (choice)
		return (value);
	return (0);
}
