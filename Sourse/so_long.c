/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhakypo <szhakypo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:14:55 by szhakypo          #+#    #+#             */
/*   Updated: 2022/06/06 17:26:54 by szhakypo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hooks(int keycode, t_game *game)
{
	if (keycode == ESC)
		endgame(game);
	if (keycode == W || keycode == UP)
		move_up(game);
	if (keycode == S || keycode == DOWN)
		move_down(game);
	if (keycode == A || keycode == LEFT)
		move_left(game);
	if (keycode == D || keycode == RIGHT)
		move_right(game);
	if (keycode == D || keycode == A || keycode == W || keycode == S || \
	keycode == UP || keycode == DOWN || keycode == LEFT || keycode == RIGHT)
	{
		drow_map(game);
		game->steps++;
		printf("STEPS =  '%d'\n", game->steps);
	}
	return (0);
}

int	init_game(t_game *game)
{
	game->hero.hero = 0;
	game->item.item = 0;
	game->exit = 0;
	game->score = 0;
	game->steps = 0;
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
	drow_map(&game);
	mlx_key_hook(game.vars.window, key_hooks, &game);
	mlx_hook(game.vars.window, 17, 0, endgame, &game);
	mlx_loop(game.vars.mlx);
}
