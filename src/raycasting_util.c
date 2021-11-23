/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:58:19 by junseole          #+#    #+#             */
/*   Updated: 2021/11/23 22:26:54 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	getc_v0(int choice, int value)
{
	if (choice)
	{
		return (value);
	}
	return (0);
}

int	getc__11(int value)
{
	if (value)
		return (-1);
	return (1);
}

double	getcv__v0(int value1, int value2, double stepx)
{
	if ((value1 && stepx > 0) || (value2 && stepx < 0))
		return (stepx * -1);
	return (stepx);
}

int	getc__10(int value)
{
	if (value)
		return (-1);
	return (0);
}

int	getcv_v0(int choice, int value)
{
	if (choice)
		return (value);
	return (0);
}
