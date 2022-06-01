/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilits.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhakypo <szhakypo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:16:40 by szhakypo          #+#    #+#             */
/*   Updated: 2022/06/01 18:51:49 by szhakypo         ###   ########.fr       */
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
