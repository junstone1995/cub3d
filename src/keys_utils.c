/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:16:11 by namhkim           #+#    #+#             */
/*   Updated: 2021/11/22 16:42:49 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_speed1(int playerSpeed)
{
	if (playerSpeed > 1)
		return (playerSpeed - 1);
	else
		return (0);
}

int	get_speed2(int playerSpeed)
{
	if (playerSpeed < 10)
		return (playerSpeed + 1);
	else
		return (0);
}
