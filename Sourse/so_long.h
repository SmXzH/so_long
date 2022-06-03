/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhakypo <szhakypo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:15:23 by szhakypo          #+#    #+#             */
/*   Updated: 2022/06/03 21:09:52 by szhakypo         ###   ########.fr       */
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

# define W		13
# define S		1
# define A		0
# define D      2

# define ESC	53

# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

# define STALKER	"./textures/stalker.xpm"
# define GROUND 	"./textures/ground.xpm"
# define TREE		"./textures/tree.xpm"
# define BUNKER		"./textures/bunker.xpm"
# define ITEM		"./textures/medusa.xpm"

typedef struct s_vars
{
	void	*mlx;
	void	*window;
	int		size_x;
	int		size_y;
}				t_vars;
typedef struct s_mapsize
{
	int		wght;
	int		hght;
}	t_msize;

typedef struct s_hero
{
	int		hero;
	int		widht;
	int		height;
	char	*path;
	void	*img;
}	t_hero;

typedef struct s_sprite
{
	char	*path;
	int		widht;
	int		height;
	void	*img;
}	t_sprite;

typedef struct s_collect
{
	char	*path;
	int		wight;
	int		height;
	void	*img;
	int		item;
}	t_collect;

typedef struct t_list
{
	t_vars		vars;
	t_hero		hero;
	t_collect	item;
	t_sprite	wall;
	t_sprite	bunker;
	t_sprite	ground;
	t_msize		size;
	int			exit;
	int			position_x;
	int			position_y;
	int			score;
	int			currentscore;
	char		**map;
	char		*mapdata;
	char		*mapcontent;
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
void	not_folder(void);
int		load_files(t_game *game);
int		load_oblects(t_game *game);
int		drow_map(t_game *map);
void	drow_map2(t_game *game, int i, int j);
int		position_player(t_game *game);
int		move_up(t_game *game);
int		move_down(t_game *game);
int		move_left(t_game *game);
int		move_right(t_game *game);
int		endgame(t_game *game);
int		unload_objects(t_game *game);

#endif