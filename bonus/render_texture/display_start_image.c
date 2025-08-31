/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_start_image.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 10:56:43 by ybounite          #+#    #+#             */
/*   Updated: 2025/08/31 11:15:27 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D_bonus.h"

t_imag	init_start_imag(t_data_game *_game)
{
	t_imag	start_img;

	start_img.img = mlx_xpm_file_to_image(_game->_mlx,
			"./textures/start.xpm",
			&start_img.width,
			&start_img.height);
	if (!start_img.img)
		(syntax_error(7), close_window(_game));
	start_img.addr = mlx_get_data_addr(start_img.img,
			&start_img.bit_per_pixel,
			&start_img.line_len,
			&start_img.endian);
	return (start_img);
}

bool	display_start_image(t_data_game *_g)
{
	t_imag	start_img;
	int		x;
	int		y;
	int		color;

	start_img = init_start_imag(_g);
	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			color = get_pixel(&start_img, x * start_img.width / WINDOW_WIDTH,
					y * start_img.height / WINDOW_HEIGHT);
			my_mlx_pixel_put(_g->_img, x++, y, color);
		}
		y++;
	}
	mlx_put_image_to_window(_g->_mlx, _g->_win_mlx, _g->_img->img, 0, 0);
	sleep(3);
	mlx_destroy_image(_g->_mlx, start_img.img);
	return (true);
}
