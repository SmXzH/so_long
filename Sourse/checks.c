/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhakypo <szhakypo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:44:33 by szhakypo          #+#    #+#             */
/*   Updated: 2022/05/23 20:03:08 by szhakypo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int bercheck(t_game *game)
{
    int i;

    i = fl_dlinna(game->mapdata) - 4;
    if(game->mapdata[i] == '.' && game->mapdata[i + 1] == 'b'
        && game->mapdata[i + 2] == 'e' && game->mapdata[i + 3] == 'r')
        return (0);
    else
    {
        ft_putstr_fd("FILE ITs NOT BER", 2);
        return (1);
    }
}

int	fl_dlinna(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}