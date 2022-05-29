/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhakypo <szhakypo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 23:11:03 by szhakypo          #+#    #+#             */
/*   Updated: 2022/05/29 20:15:21 by szhakypo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Получение текущей позиции

char	*get_player(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

int	check_invalid_chars(t_game *game, int pos_x, int pos_y)
{
	char	*valid_chars;

	valid_chars = "PEC10\n";
	if (get_player(valid_chars, game->map[pos_y][pos_x]) == NULL)
		return (ft_putstr_fd("Map dosent access\n", 2),
			free(game->map), exit(0), 0);
	else
		return (0);
}

int	check_map_content(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[j])
	{
		i = 0;
		while (game->map[j][i])
		{
			check_invalid_chars(game, i, j);
			if (game->map[j][i] == 'P')
				game->hero++;
			if (game->map[j][i] == 'E')
				game->exit++;
			if (game->map[j][i] == 'C')
				game->item++;
			i++;
		}
		j++;
	}
	return (0);
}

int	level_validation(t_game *game)
{
	check_map_content(game);
	if (game->hero == 0)
		return (ft_putstr_fd("Dint find player", 2),
			free(game->map), exit(0), 0);
	if (game->hero > 1)
		return (ft_putstr_fd("Player more than 1", 2),
			free(game->map), exit(0), 0);
	if (game->item == 0)
		return (ft_putstr_fd("Dint find item(C)", 2),
			free(game->map), exit(0), 0);
	if (game->exit == 0)
		return (ft_putstr_fd("Dint find exit(E)", 2),
			free(game->map), exit(0), 0);
	return (0);
}
