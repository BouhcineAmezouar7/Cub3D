/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:22:09 by ybounite          #+#    #+#             */
/*   Updated: 2025/08/27 13:13:04 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3D.h"

bool	_mlx_init_data(t_data_game *_g)
{
	_g->_win_mlx = mlx_new_window(_g->_mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3D");
	if (!_g->_win_mlx)
		return (ft_putendl_fd("Error:\nmlx_new_window failed.", STDERR), false);
	_g->_img->img = mlx_new_image(_g->_mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!_g->_img->img)
		return (ft_putendl_fd("Error:\nmlx_new_image failed.", STDERR), false);
	_g->_img->addr = mlx_get_data_addr(_g->_img->img, &_g->_img->bit_per_pixel,
			&_g->_img->line_len, &_g->_img->endian);
	_g->_img->width = WINDOW_WIDTH;
	_g->_img->height = WINDOW_HEIGHT;
	return (true);
}
