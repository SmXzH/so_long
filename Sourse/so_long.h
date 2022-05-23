/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhakypo <szhakypo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:15:23 by szhakypo          #+#    #+#             */
/*   Updated: 2022/05/23 19:58:16 by szhakypo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include "GNL/get_next_line.h"
# include "libft/libft.h"

typedef struct t_list
{
    int     dlinna;
    int     visota;
    int     positoin;
    int     score;
    int     currentscore;
    char    *mapdata;
    void    *wall;
    void    *exit;
    void    *item;
    void    *player;
}               t_game;

int bercheck(t_game *game);
int fl_dlinna(char *c);

# endif
