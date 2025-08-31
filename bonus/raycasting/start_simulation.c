/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamezoua <bamezoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 11:23:09 by ybounite          #+#    #+#             */
/*   Updated: 2025/08/31 14:48:10 by bamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D_bonus.h"

int	render(t_data_game *g)
{
	static short	frame;

	if (frame == 100)
	{
		clear_image(g->_img, BLACK);
		draw_sky_and_floor(g);
		_cast_all_rays(g);
		draw_minimap(g);
		if (g->player_hand->is_shooting)
		{
			if (g->player_hand->current_frame == g->player_hand->num_frames - 1)
				g->player_hand->is_shooting = false;
			update_player_hand_animation(g);
		}
		mlx_put_image_to_window(g->_mlx, g->_win_mlx, g->_img->img, 0, 0);
		mlx_mouse_move(g->_mlx, g->_win_mlx, WINDOW_WIDTH / 2,
			WINDOW_HEIGHT / 2);
		render_player_hand(g);
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
	init_player_hand_textures(_game);
	player_init(_game);
	display_start_image(_game);
	_game->minimap = ft_malloc(sizeof(t_minimap), ALLOC);
	mlx_hook(_game->_win_mlx, KeyPress, KeyPressMask, control_key_, _game);
	mlx_mouse_hook(_game->_win_mlx, control_gun_key, _game);
	mlx_hook(_game->_win_mlx, 6, 1L << 6, mouse_move, _game);
	mlx_loop_hook(_game->_mlx, render, _game);
	mlx_loop(_game->_mlx);
	return (true);
}
