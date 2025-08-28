/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_background.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:20:57 by ybounite          #+#    #+#             */
/*   Updated: 2025/08/27 18:21:26 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3D.h"

int	get_pixel_color(void *img, int x, int y)
{
    char	*addr;
    int	bits_per_pixel;
    int	line_length;
    int	endian;
    int	color;

    addr = mlx_get_data_addr(img, &bits_per_pixel, &line_length, &endian);
    color = *(int *)(addr + (y * line_length + x * (bits_per_pixel / 8)));
    return color;
}

void	draw_sky_and_floor(t_data_game *_game)
{
	int (y), (x), (color);
	y = 0;
	while (y < WINDOW_HEIGHT / 2)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			int sx = x * _game->texture->sk_img->width / WINDOW_WIDTH;
			int sy = y * _game->texture->sk_img->height / (WINDOW_HEIGHT / 2);
			color = get_pixel_color(_game->texture->sk_img->img, sx, sy);
			my_mlx_pixel_put(_game->_img, x, y, color);
			x++;
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
