/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhakypo <szhakypo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:36:44 by szhakypo          #+#    #+#             */
/*   Updated: 2022/06/03 17:11:14 by szhakypo         ###   ########.fr       */
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

void	drow_map2(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->vars.mlx, game->vars.window, \
		game->wall.img, (j * 50), (i * 50));
	else if (game->map[i][j] == '0')
		mlx_put_image_to_window(game->vars.mlx, game->vars.window, \
		game->ground.img, (j * 50), (i * 50));
	else if (game->map[i][j] == 'P')
		mlx_put_image_to_window(game->vars.mlx, game->vars.window, \
		game->hero.img, (j * 50), (i * 50));
	else if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->vars.mlx, game->vars.window, \
		game->bunker.img, (j * 50), (i * 50));
	else if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->vars.mlx, game->vars.window, \
		game->item.img, (j * 50), (i * 50));
}

int	drow_map(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
			drow_map2(game, i, j);
	}
	return (0);
}
