/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhakypo <szhakypo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:14:55 by szhakypo          #+#    #+#             */
/*   Updated: 2022/05/23 20:01:49 by szhakypo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
    t_game  game;
    if (ac != 2)
        ft_putstr_fd("Wrong number of argument", 2);
    bercheck(&game);
    game.mapdata = av[1];
    bercheck(&game);
    
}