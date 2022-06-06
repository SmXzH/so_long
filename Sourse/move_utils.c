/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhakypo <szhakypo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:11:18 by szhakypo          #+#    #+#             */
/*   Updated: 2022/06/06 18:20:21 by szhakypo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up_utill_0(t_game *game)
{
	game->map[game->position_y - 1][game->position_x] = 'P';
	mlx_put_image_to_window(game->vars.mlx, game->vars.window,
		game->hero.img, (game->position_y - 1) * 50, game->position_x * 50);
	mlx_put_image_to_window(game->vars.mlx, game->vars.window,
		game->ground.img, (game->position_y * 50), (game->position_x * 50));
	game->map[game->position_y][game->position_x] = '0';
	game->position_y -= 1;
}

void	move_down_utill_0(t_game *game)
{
		game->map[game->position_y + 1][game->position_x] = 'P';
	mlx_put_image_to_window(game->vars.mlx, game->vars.window,
		game->hero.img, (game->position_y + 1) * 50, game->position_x * 50);
	mlx_put_image_to_window(game->vars.mlx, game->vars.window,
		game->ground.img, (game->position_y * 50), (game->position_x * 50));
	game->map[game->position_y][game->position_x] = '0';
	game->position_y += 1;
}

void	move_left_utill_0(t_game *game)
{
	game->map[game->position_y][game->position_x - 1] = 'P';
	mlx_put_image_to_window(game->vars.mlx, game->vars.window,
		game->hero.img, game->position_y * 50, (game->position_x - 1) * 50);
	mlx_put_image_to_window(game->vars.mlx, game->vars.window,
		game->ground.img, (game->position_y * 50), (game->position_x * 50));
	game->map[game->position_y][game->position_x] = '0';
	game->position_x -= 1;
}

void	move_right_utill_0(t_game *game)
{
	game->map[game->position_y][game->position_x + 1] = 'P';
	mlx_put_image_to_window(game->vars.mlx, game->vars.window,
		game->hero.img, game->position_y * 50, (game->position_x + 1) * 50);
	mlx_put_image_to_window(game->vars.mlx, game->vars.window,
		game->ground.img, (game->position_y * 50), (game->position_x * 50));
	game->map[game->position_y][game->position_x] = '0';
	game->position_x += 1;
}
