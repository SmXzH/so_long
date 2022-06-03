/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhakypo <szhakypo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:41:40 by szhakypo          #+#    #+#             */
/*   Updated: 2022/06/03 21:21:59 by szhakypo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	position_player(t_game *game)
{
	game->position_y = 0;
	game->position_x = 0;
	while (game->map[game->position_y][game->position_x] != 'P' ||
		game->map[game->position_y][game->position_x])
	{
		while (game->map[game->position_y][game->position_x] != 'P' ||
			game->map[game->position_y][game->position_x] != '\n')
		{
			game->position_x++;
		}
		game->position_x = 0;
		game->position_y++;
	}
	return (0);
}

int	move_up(t_game *game)
{
	if (game->map[game->position_y - 1][game->position_x] == '0')
	{
		game->map[game->position_y - 1][game->position_x] = 'P';
		mlx_put_image_to_window(game->vars.mlx, game->vars.window,
			game->hero.img, ((game->position_y - 1) * 50), (game->position_x * 50));
		mlx_put_image_to_window(game->vars.mlx, game->vars.window,
			game->ground.img, (game->position_y * 50), (game->position_x * 50));
		game->map[game->position_y][game->position_x] = '0';
		game->position_y -= 1;
	}
	return (0);
}

int	move_down(t_game *game)
{
	if (game->map[game->position_y + 1][game->position_x] == '0')
	{
		game->map[game->position_y + 1][game->position_x] = 'P';
		mlx_put_image_to_window(game->vars.mlx, game->vars.window,
			game->hero.img, ((game->position_y + 1) * 50), (game->position_x * 50));
		mlx_put_image_to_window(game->vars.mlx, game->vars.window,
			game->ground.img, (game->position_y * 50), (game->position_x * 50));
		game->map[game->position_y][game->position_x] = '0';
		game->position_y += 1;
	}
	return (0);
}

int	move_left(t_game *game)
{
	if (game->map[game->position_y][game->position_x - 1] == '0')
	{
		game->map[game->position_y][game->position_x - 1] = 'P';
		mlx_put_image_to_window(game->vars.mlx, game->vars.window,
			game->hero.img, (game->position_y * 50), ((game->position_x - 1) * 50));
		mlx_put_image_to_window(game->vars.mlx, game->vars.window,
			game->ground.img, (game->position_y * 50), (game->position_x * 50));
		game->map[game->position_y][game->position_x] = '0';
		game->position_x -= 1;
	}
	return (0);
}

int	move_right(t_game *game)
{
	if (game->map[game->position_y][game->position_x + 1] == '0')
	{
		game->map[game->position_y][game->position_x + 1] = 'P';
		mlx_put_image_to_window(game->vars.mlx, game->vars.window,
			game->hero.img, (game->position_y * 50), ((game->position_x + 1) * 50));
		mlx_put_image_to_window(game->vars.mlx, game->vars.window,
			game->ground.img, (game->position_y * 50), (game->position_x * 50));
		game->map[game->position_y][game->position_x] = '0';
		game->position_x += 1;
	}
	return (0);
}
