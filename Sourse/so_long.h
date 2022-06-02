/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:15:23 by szhakypo          #+#    #+#             */
/*   Updated: 2022/06/02 16:13:12 by sam              ###   ########.fr       */
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
	int			positoin;
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

#endif