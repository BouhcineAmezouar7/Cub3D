/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_hand_animation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamezoua <bamezoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 18:52:19 by ybounite          #+#    #+#             */
/*   Updated: 2025/09/02 12:07:34 by bamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D_bonus.h"

void	update_player_hand_animation(t_data_game *_game)
{
	static int	frame_counter = 0;
	static int	animation_speed = 5;

	frame_counter++;
	if (frame_counter >= animation_speed)
	{
		_game->player_hand->current_frame++;
		if (_game->player_hand->current_frame >= _game->player_hand->num_frames)
			_game->player_hand->current_frame = 0;
		frame_counter = 0;
	}
}

void	trigger_shooting_animation(t_data_game *_game)
{
	_game->player_hand->current_frame = 0;
	_game->player_hand->is_shooting = true;
}

unsigned int	ft_pixel_color(char *src_data, int x, int y,
		t_imag *current_frame)
{
	unsigned int	pixel_color;

	pixel_color = *(unsigned int *)(src_data + (y * current_frame->line_length
				+ x * (current_frame->bpp / 8)));
	return (pixel_color);
}

static void	draw_hand_pixel(t_data_game *_game, int x_pos, int y_pos,
		t_imag *current_frame)
{
	unsigned int	pixel_color;
	char			*src_data;
	int				x;
	int				y;

	src_data = mlx_get_data_addr(current_frame->img, &current_frame->bpp,
			&current_frame->line_length, &current_frame->endian);
	y = 0;
	while (y < current_frame->height)
	{
		x = 0;
		while (x < current_frame->width)
		{
			pixel_color = ft_pixel_color(src_data, x, y, current_frame);
			if (pixel_color != 0x000000 && pixel_color != 0xFF000000)
			{
				if (x_pos + x >= 0 && y_pos + y >= 0 && x_pos
					+ x < _game->_img->width && y_pos + y < _game->_img->height)
					my_mlx_pixel_put(_game->_img, x_pos + x, y_pos + y,
						pixel_color);
			}
			x++;
		}
		y++;
	}
}

void	render_player_hand(t_data_game *_game)
{
	t_imag	*current_frame;
	int		x_pos;
	int		y_pos;

	if (!_game || !_game->player_hand || !_game->player_hand->img)
		return ;
	current_frame = _game->player_hand->img[_game->player_hand->current_frame];
	if (!current_frame || !current_frame->img)
		return ;
	x_pos = _game->_img->width - current_frame->width - 350;
	y_pos = _game->_img->height - current_frame->height;
	draw_hand_pixel(_game, x_pos, y_pos, current_frame);
}
