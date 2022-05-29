/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhakypo <szhakypo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:14:55 by szhakypo          #+#    #+#             */
/*   Updated: 2022/05/29 19:33:03 by szhakypo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_game(t_game *game)
{
	game->hero = 0;
	game->item = 0;
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
	rectangle(&game);
	jungle(&game);
	init_game(&game);
	level_validation(&game);
}
