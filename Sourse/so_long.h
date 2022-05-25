/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhakypo <szhakypo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:15:23 by szhakypo          #+#    #+#             */
/*   Updated: 2022/05/25 23:26:15 by szhakypo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include "libft/libft.h"
# include "get_next_line.h"

typedef struct s_vars{
	void	*mlx;
	void	*win;
	int		maph;
	int		mapw;
}				t_vars;

typedef struct t_list
{
	t_vars	vars;
	int		dlinna;
	int		visota;
	int		positoin;
	int		score;
	int		currentscore;
	char	map;
	char	*mapdata;
	char	*mapcontent;
	void	*wall;
	void	*exit;
	void	*item;
	void	*player;
}	t_game;

int		bercheck(t_game *game);
int		fl_dlinna(char *c);
int		ft_zagruzka(t_game *game);
char	*get_player(char *s, char c);
int		read_map(t_game *game);

#endif
