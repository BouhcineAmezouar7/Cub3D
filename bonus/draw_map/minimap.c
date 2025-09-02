/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamezoua <bamezoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 12:00:00 by bamezoua          #+#    #+#             */
/*   Updated: 2025/09/02 11:54:29 by bamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D_bonus.h"

void	draw_minimap_walls(t_data_game *_game)
{
	int		screen_x;
	int		screen_y;
	t_point	world;

	screen_y = MINIMAP_CENTER_Y - MINIMAP_RADIUS;
	while (screen_y <= MINIMAP_CENTER_Y + MINIMAP_RADIUS)
	{
		screen_x = MINIMAP_CENTER_X - MINIMAP_RADIUS;
		while (screen_x <= MINIMAP_CENTER_X + MINIMAP_RADIUS)
		{
			if (screen_x >= 0 && screen_y >= 0 && screen_x < WINDOW_WIDTH
				&& screen_y < WINDOW_HEIGHT)
			{
				if (is_inside_circle((t_vars){screen_x, screen_y,
						MINIMAP_CENTER_X, MINIMAP_CENTER_Y, MINIMAP_RADIUS}))
				{
					convert_screen_to_world(_game, screen_x, screen_y, &world);
					draw_minimap_pixel(_game, screen_x, screen_y, world);
				}
			}
			screen_x++;
		}
		screen_y++;
	}
}

static void	draw_player_circle(t_data_game *_game)
{
	int (dx), (dy), (px), (py);
	dy = -3;
	while (dy <= 3)
	{
		dx = -3;
		while (dx <= 3)
		{
			if (dx * dx + dy * dy <= 9)
			{
				px = MINIMAP_CENTER_X + dx;
				py = MINIMAP_CENTER_Y + dy;
				if (px >= 0 && py >= 0 && px < WINDOW_WIDTH
					&& py < WINDOW_HEIGHT)
				{
					if (is_inside_circle((t_vars){px, py, MINIMAP_CENTER_X,
							MINIMAP_CENTER_Y, MINIMAP_RADIUS}))
						my_mlx_pixel_put(_game->_img, px, py, RED);
				}
			}
			dx++;
		}
		dy++;
	}
}

void	draw_minimap(t_data_game *_game)
{
	draw_minimap_background(_game);
	draw_minimap_walls(_game);
	draw_player_circle(_game);
	draw_minimap_border(_game);
}
