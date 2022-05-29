/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhakypo <szhakypo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:15:23 by szhakypo          #+#    #+#             */
/*   Updated: 2022/05/29 19:49:54 by szhakypo         ###   ########.fr       */
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
	void	*window;
	int		size_x;
	int		size_y;
}				t_vars;

typedef struct t_list
{
	t_vars	vars;
	int		positoin;
	int		score;
	int		currentscore;
	int		hero;
	char	**map;
	char	*mapdata;
	char	*mapcontent;
	void	*wall;
	void	*exit;
	void	*item;
}	t_game;

int		bercheck(t_game *game);
int		ft_loadmap(t_game *game);
char	*get_player(char *s, char c);
int		rectangle(t_game *game);
int		jungle(t_game *game);
int		level_validation(t_game *game);
int		init_game(t_game *game);
int		check_map_content(t_game *game);
int		check_invalid_chars(t_game *game, int pos_x, int pos_y);

#endif
