/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhakypo <szhakypo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:44:33 by szhakypo          #+#    #+#             */
/*   Updated: 2022/05/30 17:07:23 by szhakypo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	bercheck(t_game *game)
{
	int	i;

	i = ft_strlen(game->mapdata) - 4;
	if (i < 0)
		return (write(2, "No name file\n", 17), exit(1), 0);
	if (game->mapdata[i] == '.' && game->mapdata[i + 1] == 'b'
		&& game->mapdata[i + 2] == 'e' && game->mapdata[i + 3] == 'r')
		return (0);
	else
		return (write(2, "File its not ber\n", 17), exit(1), 0);
}

//Check: Its rectangle?

int	rectangle(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		if (game->vars.size_x != (int)(ft_strlen(game->map[i]) - 1))
			break ;
		i++;
	}
	if (++i == game->vars.size_y)
		return (1);
	return (write(2, "Map its not rectangle\n", 22),
		exit(10), free(game->map), 0);
}

static int	wallcheck(int point, t_game *game)
{
	if (point != '1')
	{
		ft_putstr_fd("Map is not correct!\n", 2);
		free(game->map);
		return (1);
	}
	return (0);
}

//Check: Its rectangle of 1

int	jungle(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
		if (wallcheck(game->map[i++][0], game))
			exit(0);
	i = 0;
	while (game->map[i])
		if (wallcheck(game->map[i++][game->vars.size_x - 1], game))
			exit(0);
	i = 0;
	while (game->map[game->vars.size_y - 1][i])
		if (wallcheck(game->map[game->vars.size_y - 1][i++], game))
			exit(0);
	i = 0;
	while (game->map[0][i] != '\n')
		if (wallcheck(game->map[0][i++], game))
			exit(0);
	return (0);
}
