/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhakypo <szhakypo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:36:44 by szhakypo          #+#    #+#             */
/*   Updated: 2022/05/25 23:22:30 by szhakypo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_zagruzka(t_game *game)
{
	int		fd;

	game->mapcontent = malloc(sizeof(char *) + 1);
	fd = open(game->mapdata, O_RDONLY);
	while (game->mapcontent)
	{
		free(game->mapcontent);
		game->mapcontent = get_next_line(fd);
	}
	close(fd);
	return (0);
}

int	read_map(t_game *game)
{
	int	fd;

	fd = open(game->mapcontent, O_RDONLY);
	read(fd, game->map, 1000);
	close(fd);
	return (0);
}
