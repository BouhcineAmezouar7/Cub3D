/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamezoua <bamezoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:28:22 by bamezoua          #+#    #+#             */
/*   Updated: 2025/08/28 19:53:14 by bamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D_bonus.h"

int	is_inside_circle(t_vars vars)
{
	int	dx;
	int	dy;

	dx = vars.x - vars.center_x;
	dy = vars.y - vars.center_y;
	return (dx * dx + dy * dy <= vars.radius * vars.radius);
}

void	draw_minimap_border(t_data_game *_game)
{
	int	border_radius;
	int	x;
	int	y;

	border_radius = MINIMAP_RADIUS + 3;
	y = MINIMAP_CENTER_Y - border_radius;
	while (y <= MINIMAP_CENTER_Y + border_radius)
	{
		x = MINIMAP_CENTER_X - border_radius;
		while (x <= MINIMAP_CENTER_X + border_radius)
		{
			if (x >= 0 && y >= 0 && x < WINDOW_WIDTH && y < WINDOW_HEIGHT)
			{
				if (is_inside_circle((t_vars){x, y, MINIMAP_CENTER_X,
						MINIMAP_CENTER_Y, border_radius})
					&& !is_inside_circle((t_vars){x, y, MINIMAP_CENTER_X,
						MINIMAP_CENTER_Y, MINIMAP_RADIUS}))
					my_mlx_pixel_put(_game->_img, x, y, WHITE);
			}
			x++;
		}
		y++;
	}
}

void	draw_minimap_background(t_data_game *_game)
{
	int	x;
	int	y;

	y = MINIMAP_CENTER_Y - MINIMAP_RADIUS;
	while (y <= MINIMAP_CENTER_Y + MINIMAP_RADIUS)
	{
		x = MINIMAP_CENTER_X - MINIMAP_RADIUS;
		while (x <= MINIMAP_CENTER_X + MINIMAP_RADIUS)
		{
			if (x >= 0 && y >= 0 && x < WINDOW_WIDTH && y < WINDOW_HEIGHT)
			{
				if (is_inside_circle((t_vars){x, y, MINIMAP_CENTER_X,
						MINIMAP_CENTER_Y, MINIMAP_RADIUS}))
					my_mlx_pixel_put(_game->_img, x, y, BLACK);
			}
			x++;
		}
		y++;
	}
}

void	convert_screen_to_world(t_data_game *_game, int screen_x, int screen_y,
		t_point *world)
{
	double	offset_x;
	double	offset_y;

	offset_x = (screen_x - MINIMAP_CENTER_X) * MINIMAP_ZOOM;
	offset_y = (screen_y - MINIMAP_CENTER_Y) * MINIMAP_ZOOM;
	world->x = _game->player->_x + offset_x;
	world->y = _game->player->_y + offset_y;
}

void	draw_minimap_pixel(t_data_game *_game, int screen_x, int screen_y,
		t_point world)
{
	int	map_x;
	int	map_y;

	map_x = (int)(world.x / TILE_SIZE);
	map_y = (int)(world.y / TILE_SIZE);
	if (map_x >= 0 && map_y >= 0 && map_y < _game->map_height
		&& map_x < (int)ft_strlen(_game->map[map_y]))
	{
		if (_game->map[map_y][map_x] == '1')
			my_mlx_pixel_put(_game->_img, screen_x, screen_y, GRAY);
		else if (_game->map[map_y][map_x] == 'D')
			my_mlx_pixel_put(_game->_img, screen_x, screen_y, GREEN);
		else if (_game->map[map_y][map_x] == '0'
			|| _game->map[map_y][map_x] == 'N'
			|| _game->map[map_y][map_x] == 'S'
			|| _game->map[map_y][map_x] == 'E'
			|| _game->map[map_y][map_x] == 'W')
			my_mlx_pixel_put(_game->_img, screen_x, screen_y, DARK_GRAY);
	}
}
