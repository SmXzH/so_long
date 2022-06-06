/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhakypo <szhakypo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:41:40 by szhakypo          #+#    #+#             */
/*   Updated: 2022/06/06 18:23:32 by szhakypo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_up(t_game *game)
{
	if (game->map[game->position_y - 1][game->position_x] == '0')
		move_up_utill_0(game);
	else if (game->map[game->position_y - 1][game->position_x] == 'C')
	{
		game->map[game->position_y - 1][game->position_x] = 'P';
		mlx_put_image_to_window(game->vars.mlx, game->vars.window,
			game->hero.img, (game->position_y - 1) * 50, game->position_x * 50);
		mlx_put_image_to_window(game->vars.mlx, game->vars.window,
			game->ground.img, (game->position_y * 50), (game->position_x * 50));
			game->map[game->position_y][game->position_x] = '0';
		game->position_y -= 1;
		game->currentscore++;
		ft_printf("SCORE :  %d\n", game->currentscore);
	}
	else if (game->map[game->position_y - 1][game->position_x] == 'E'
	&& game->currentscore == game->item.item)
	{
		game->map[game->position_y - 1][game->position_x] = 'P';
		mlx_put_image_to_window(game->vars.mlx, game->vars.window,
			game->hero.img, (game->position_y - 1) * 50, game->position_x * 50);
		endgame(game);
	}
	return (0);
}

int	move_down(t_game *game)
{
	if (game->map[game->position_y + 1][game->position_x] == '0')
		move_down_utill_0(game);
	else if (game->map[game->position_y + 1][game->position_x] == 'C')
	{
		game->map[game->position_y + 1][game->position_x] = 'P';
		mlx_put_image_to_window(game->vars.mlx, game->vars.window,
			game->hero.img, (game->position_y + 1) * 50, game->position_x * 50);
		mlx_put_image_to_window(game->vars.mlx, game->vars.window,
			game->ground.img, (game->position_y * 50), (game->position_x * 50));
			game->map[game->position_y][game->position_x] = '0';
		game->position_y += 1;
		game->currentscore++;
		ft_printf("SCORE :  %d\n", game->currentscore);
	}
	else if (game->map[game->position_y + 1][game->position_x] == 'E'
		&& game->currentscore == game->item.item)
	{
		game->map[game->position_y + 1][game->position_x] = 'P';
		mlx_put_image_to_window(game->vars.mlx, game->vars.window,
			game->hero.img, (game->position_y + 1) * 50, game->position_x * 50);
		endgame(game);
	}
	return (0);
}

int	move_left(t_game *game)
{
	if (game->map[game->position_y][game->position_x - 1] == '0')
		move_left_utill_0(game);
	else if (game->map[game->position_y][game->position_x - 1] == 'C')
	{
		game->map[game->position_y][game->position_x - 1] = 'P';
		mlx_put_image_to_window(game->vars.mlx, game->vars.window,
			game->hero.img, game->position_y * 50, (game->position_x - 1) * 50);
		mlx_put_image_to_window(game->vars.mlx, game->vars.window,
			game->ground.img, (game->position_y * 50), (game->position_x * 50));
			game->map[game->position_y][game->position_x] = '0';
		game->position_x -= 1;
		game->currentscore++;
		ft_printf("SCORE :  %d\n", game->currentscore);
	}
	else if (game->map[game->position_y][game->position_x - 1] == 'E'
		&& game->currentscore == game->item.item)
	{
		game->map[game->position_y][game->position_x - 1] = 'P';
		mlx_put_image_to_window(game->vars.mlx, game->vars.window,
			game->hero.img, game->position_y * 50, (game->position_x - 1) * 50);
		endgame(game);
	}
	return (0);
}

int	move_right(t_game *game)
{
	if (game->map[game->position_y][game->position_x + 1] == '0')
		move_right_utill_0(game);
	else if (game->map[game->position_y][game->position_x + 1] == 'C')
	{
		game->map[game->position_y][game->position_x + 1] = 'P';
		mlx_put_image_to_window(game->vars.mlx, game->vars.window,
			game->hero.img, game->position_y * 50, (game->position_x + 1) * 50);
		mlx_put_image_to_window(game->vars.mlx, game->vars.window,
			game->ground.img, (game->position_y * 50), (game->position_x * 50));
			game->map[game->position_y][game->position_x] = '0';
		game->position_x += 1;
		game->currentscore++;
		ft_printf("SCORE :  %d\n", game->currentscore);
	}
	else if (game->map[game->position_y][game->position_x + 1] == 'E'
		&& game->currentscore == game->item.item)
	{
		game->map[game->position_y][game->position_x + 1] = 'P';
		mlx_put_image_to_window(game->vars.mlx, game->vars.window,
			game->hero.img, game->position_y * 50, (game->position_x + 1) * 50);
		endgame(game);
	}
	return (0);
}
