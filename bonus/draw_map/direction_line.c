/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamezoua <bamezoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 13:10:22 by bamezoua          #+#    #+#             */
/*   Updated: 2025/08/28 19:52:28 by bamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D_bonus.h"

static void	calculate_direction_line_params(t_data_game *_g)
{
	_g->minimap->line_length = 15;
	_g->minimap->end_x = MINIMAP_CENTER_X + cos(_g->player->angle)
		* _g->minimap->line_length;
	_g->minimap->end_y = MINIMAP_CENTER_Y + sin(_g->player->angle)
		* _g->minimap->line_length;
	_g->minimap->d_dx = _g->minimap->end_x - MINIMAP_CENTER_X;
	_g->minimap->d_dy = _g->minimap->end_y - MINIMAP_CENTER_Y;
	_g->minimap->steps = fmax(fabs(_g->minimap->d_dx), fabs(_g->minimap->d_dy));
	if (_g->minimap->steps > 0)
	{
		_g->minimap->d_dx /= _g->minimap->steps;
		_g->minimap->d_dy /= _g->minimap->steps;
	}
}

static void	draw_line_pixels(t_data_game *_g)
{
	int	i;

	i = 0;
	while (i <= (int)_g->minimap->steps)
	{
		_g->minimap->lx = (int)(MINIMAP_CENTER_X + _g->minimap->d_dx * i);
		_g->minimap->ly = (int)(MINIMAP_CENTER_Y + _g->minimap->d_dy * i);
		if (_g->minimap->lx >= 0 && _g->minimap->ly >= 0
			&& _g->minimap->lx < WINDOW_WIDTH
			&& _g->minimap->ly < WINDOW_HEIGHT)
		{
			if (is_inside_circle((t_vars){_g->minimap->lx, _g->minimap->ly,
					MINIMAP_CENTER_X, MINIMAP_CENTER_Y, MINIMAP_RADIUS}))
				my_mlx_pixel_put(_g->_img, _g->minimap->lx, _g->minimap->ly,
					YELLOW);
		}
		i++;
	}
}

void	draw_direction_line(t_data_game *_g)
{
	calculate_direction_line_params(_g);
	if (_g->minimap->steps > 0)
		draw_line_pixels(_g);
}
