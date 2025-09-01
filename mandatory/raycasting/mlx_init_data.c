/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:22:09 by ybounite          #+#    #+#             */
/*   Updated: 2025/09/01 08:32:06 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

t_data_game	*initialize_game(void)
{
	t_data_game	*_game;

	_game = ft_malloc(sizeof(t_data_game), ALLOC);
	_game->config = ft_malloc(sizeof(t_config), ALLOC);
	_game->texture = ft_malloc(sizeof(t_texture), ALLOC);
	_game->player = ft_malloc(sizeof(t_player), ALLOC);
	ft_memset(_game->config->textures, 0, sizeof(char *) * TEXTURE_COUNT);
	_game->_img = ft_malloc(sizeof(t_imag), ALLOC);
	ft_memset(_game->texture, 0, sizeof(t_texture));
	return (_game);
}

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
