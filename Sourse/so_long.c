/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhakypo <szhakypo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:14:55 by szhakypo          #+#    #+#             */
/*   Updated: 2022/06/01 19:52:04 by szhakypo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_game(t_game *game)
{
	game->hero.hero = 0;
	game->item.item = 0;
	game->exit = 0;
	game->score = 0;
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (write(2, "Wrong number of arguments\n", 26), exit(0), 0);
	game.mapdata = av[1];
	bercheck(&game);
	ft_loadmap(&game);
	game.vars.size_x = ft_strlen(game.map[0]) - 1;
	rectangle(&game);
	jungle(&game);
	init_game(&game);
	level_validation(&game);
	load_files(&game);
	game.vars.mlx = mlx_init();
	load_oblects(&game);
	game.size.hght = game.vars.size_y * game.wall.height;
	game.size.wght = game.vars.size_x * game.wall.widht;
	game.vars.window = mlx_new_window(game.vars.mlx, game.size.wght,
			game.size.hght, "SO_LONG");
	mlx_loop(game.vars.mlx);
}
