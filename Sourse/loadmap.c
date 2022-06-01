/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhakypo <szhakypo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:36:44 by szhakypo          #+#    #+#             */
/*   Updated: 2022/06/01 19:51:23 by szhakypo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//READ MAP

int	ft_loadmap(t_game *game)
{
	int		fd;

	fd = open(game->mapdata, O_RDONLY);
	game->vars.size_y = 0;
	game->mapcontent = get_next_line(fd);
	if (!game->mapcontent)
		not_folder();
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
		game->vars.size_x++;
	}
	game->map[game->vars.size_x] = 0;
	close(fd);
	return (0);
}

// Check its file or folder?

void	not_folder(void)
{
	ft_putstr_fd("Error: Didn't find file\n", 2);
	exit(1);
}
