/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 08:27:16 by ybounite          #+#    #+#             */
/*   Updated: 2025/09/01 08:32:45 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

int	render(t_data_game *g)
{
	static short	frame;

	if (frame == 100)
	{
		clear_image(g->_img, BLACK);
		draw_sky_and_floor(g);
		_cast_all_rays(g);
		mlx_put_image_to_window(g->_mlx, g->_win_mlx, g->_img->img, 0, 0);
		frame = 0;
	}
	frame++;
	return (0);
}

bool	start_simulation(t_data_game *_game)
{
	_game->close_win = false;
	if (!_mlx_init_data(_game))
		return (_game->close_win = false, close_window(_game), false);
	init_textures_data(_game);
	player_init(_game);
	mlx_hook(_game->_win_mlx, KeyPress, KeyPressMask, control_key_, _game);
	mlx_loop_hook(_game->_mlx, render, _game);
	mlx_loop(_game->_mlx);
	return (true);
}
