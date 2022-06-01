/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhakypo <szhakypo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 19:34:36 by szhakypo          #+#    #+#             */
/*   Updated: 2022/06/01 20:34:27 by szhakypo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	put_hero(t_game *game, int pos_x, int pos_y)
{
	mlx_put_image_to_window(game->vars.mlx, game->vars.window,
		game->hero.img, 0, 0);
	return (0);
}

int	put_wall(t_game *game, int pos_x, int pos_y)
{
	mlx_put_image_to_window(game->vars.mlx, game->vars.window,
		game->wall.img, 0, 0);
}

int	put_bunker(t_game *game, int pos_x, int pos_y)
{
	mlx_put_image_to_window(game->vars.mlx, game->vars.window,
		game->bunker.img, 1, 5);
}

int	put_item(t_game *game, int pos_x, int pos_y)
{
	mlx_put_image_to_window(game->vars.mlx, game->vars.window,
		game->item.img, 3, 6);
}

int	put_ground(t_game *game, int pos_x, int pos_y)
{
	mlx_put_image_to_window(game->vars.mlx, game->vars.window,
		game->ground.img, 3, 6);
}
