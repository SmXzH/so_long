/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilits.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhakypo <szhakypo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:16:40 by szhakypo          #+#    #+#             */
/*   Updated: 2022/06/03 21:16:56 by szhakypo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Загрузка текстур

int	load_files(t_game *game)
{
	game->hero.path = STALKER;
	game->ground.path = GROUND;
	game->wall.path = TREE;
	game->bunker.path = BUNKER;
	game->item.path = ITEM;
	return (0);
}

int	load_oblects(t_game *game)
{
	game->hero.img = mlx_xpm_file_to_image(game->vars.mlx, game->hero.path,
			&game->hero.widht, &game->hero.height);
	game->wall.img = mlx_xpm_file_to_image(game->vars.mlx, game->wall.path,
			&game->wall.widht, &game->wall.height);
	game->item.img = mlx_xpm_file_to_image(game->vars.mlx, game->item.path,
			&game->item.wight, &game->item.height);
	game->ground.img = mlx_xpm_file_to_image(game->vars.mlx, game->ground.path,
			&game->ground.widht, &game->ground.height);
	game->bunker.img = mlx_xpm_file_to_image(game->vars.mlx, game->bunker.path,
			&game->bunker.widht, &game->bunker.height);
	return (0);
}

int	unload_objects(t_game *game)
{
	mlx_destroy_image(game->vars.mlx, game->hero.img);
	mlx_destroy_image(game->vars.mlx, game->ground.img);
	mlx_destroy_image(game->vars.mlx, game->wall.img);
	mlx_destroy_image(game->vars.mlx, game->item.img);
	mlx_destroy_image(game->vars.mlx, game->bunker.img);
	return (0);
}

int	endgame(t_game *game)
{
	unload_objects(game);
	mlx_destroy_window(game->vars.mlx, game->vars.window);
	free(game->vars.mlx);
	free(game->map);
	exit(0);
	return (0);
}
