/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhakypo <szhakypo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:14:55 by szhakypo          #+#    #+#             */
/*   Updated: 2022/05/25 23:02:07 by szhakypo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	int	initgame(t_game game)
{
	game->score = 0;
	game->currentscore = 0;
	game->exit = 0;
	game->hero = 0;
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		ft_putstr_fd("Wrong number of argument", 2);
	game.mapdata = av[1];
	bercheck(&game);
	ft_zagruzka(&game);
	initgame(&game);
}
