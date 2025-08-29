/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_background.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamezoua <bamezoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:20:57 by ybounite          #+#    #+#             */
/*   Updated: 2025/08/28 19:53:14 by bamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D_bonus.h"

void	draw_sky_and_floor(t_data_game *_game)
{
	t_imag	*sky_img;
	int		y;
	int		x;
	int		color;

	(1) && (y = 0), (sky_img = _game->texture->sk_img);
	while (y < WINDOW_HEIGHT / 2)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			color = get_pixel(sky_img,
					x * sky_img->width / WINDOW_WIDTH,
					y * sky_img->height / (WINDOW_HEIGHT / 2));
			my_mlx_pixel_put(_game->_img, x++, y, color);
		}
		y++;
	}
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
			my_mlx_pixel_put(_game->_img, x++, y, _game->config->floor_color);
		y++;
	}
}
/*
void draw_sky_and_floor(t_data_game *_game)
{
	short (y), (x);

	y = 0;
	while (y < WINDOW_HEIGHT / 2)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			my_mlx_pixel_put(_game->_img, x, y, _game->config->ceiling_color);
			x++;
		}
		y++;
	}
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			my_mlx_pixel_put(_game->_img, x, y, _game->config->floor_color);
			x++;
		}
		y++;
	}
}
*/
