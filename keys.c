/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:58:15 by namhkim           #+#    #+#             */
/*   Updated: 2021/11/19 16:58:38 by namhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	key_press_bonus(int key_code, t_game *game)
{
	if (key_code == KEY_UP)
		game->player.eyelevel = 1;
	else if (key_code == KEY_DOWN)
		game->player.eyelevel = -1;
	else if (key_code == KEY_MINUS)
		game->player.walkspeed = get_speed1(game->player.walkspeed);
	else if (key_code == KEY_PLUS)
		game->player.walkspeed = get_speed2(game->player.walkspeed);
	return (0);
}

int	key_press(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
	{
		free_machine(game);
		exit(0);
	}
	else if (key_code == KEY_W)
		game->player.walkdirection = 1;
	else if (key_code == KEY_S)
		game->player.walkdirection = -1;
	else if (key_code == KEY_D)
	{
		game->player.walkdirection_lr = -1;
		game->player.walkdirection = 1;
	}
	else if (key_code == KEY_A)
	{
		game->player.walkdirection_lr = 1;
		game->player.walkdirection = 1;
	}
	else if (key_code == KEY_RIGHT)
		game->player.turndirection = 1;
	else if (key_code == KEY_LEFT)
		game->player.turndirection = -1;
	key_press_bonus(key_code, game);
	return (0);
}

static int	key_release_bonus(int key_code, t_game *game)
{
	if (key_code == KEY_UP)
		game->player.eyelevel = 0;
	else if (key_code == KEY_DOWN)
		game->player.eyelevel = 0;
	else if (key_code == KEY_MINUS)
		game->player.walkspeed -= 0;
	else if (key_code == KEY_PLUS)
		game->player.walkspeed += 0;
	return (0);
}

int	key_release(int key_code, t_game *game)
{
	if (key_code == KEY_W)
		game->player.walkdirection = 0;
	else if (key_code == KEY_S)
		game->player.walkdirection = 0;
	else if (key_code == KEY_D)
	{
		game->player.walkdirection_lr = 0;
		game->player.walkdirection = 0;
	}
	else if (key_code == KEY_A)
	{
		game->player.walkdirection_lr = 0;
		game->player.walkdirection = 0;
	}
	else if (key_code == KEY_RIGHT)
		game->player.turndirection = 0;
	else if (key_code == KEY_LEFT)
		game->player.turndirection = 0;
	key_release_bonus(key_code, game);
	return (0);
}

int	exit_game(void *parameter)
{
	t_game	*game;

	game = (t_game *)parameter;
	free_machine(game);
	exit(0);
	return (0);
}
