/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhakypo <szhakypo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:36:44 by szhakypo          #+#    #+#             */
/*   Updated: 2022/05/26 20:23:53 by szhakypo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_loadmap(t_game *game)
{
	int		fd;

	fd = open(game->mapdata, O_RDONLY);
	game->vars.size_y = 0;
	game->mapcontent = get_next_line(fd);
	while (game->mapcontent)
	{
		free(game->mapcontent);
		game->mapcontent = get_next_line(fd);
		game->vars.size_y++;
	}
	close(fd);
	game->map = malloc(sizeof(char *) * (game->vars.size_y + 1));
	fd = open(game->mapdata, O_RDONLY);
	game->vars.size_x = 0;
	while (game->vars.size_x < game->vars.size_y)
	{
		game->map[game->vars.size_x] = get_next_line(fd);
		printf("%s", game->map[game->vars.size_x]);
		game->vars.size_x++;
	}
	game->map[game->vars.size_y] = 0;
	close(fd);
	game->vars.size_x = ft_strlen(game->map[0]);
	return (0);
}

void	read_map(t_game *game)
{
	printf("\t%d - its y    %d - ints size_x\n", game->vars.size_y, game->vars.size_x);
}
