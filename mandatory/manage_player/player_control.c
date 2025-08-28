/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:03:03 by ybounite          #+#    #+#             */
/*   Updated: 2025/08/28 11:11:18 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3D.h"

void	_player_move(int key, t_data_game *_g)
{
	if (key == S_KEY)
	{
		_g->player->_x -= cos(_g->player->angle) * MOVE_SPEED;
		_g->player->_y -= sin(_g->player->angle) * MOVE_SPEED;
	}
	else if (key == W_KEY)
	{
		_g->player->_x += cos(_g->player->angle) * MOVE_SPEED;
		_g->player->_y += sin(_g->player->angle) * MOVE_SPEED;
	}
	else if (key == A_KEY)
	{
		_g->player->_x += cos(_g->player->angle - M_PI_2) * MOVE_SPEED;
		_g->player->_y += sin(_g->player->angle - M_PI_2) * MOVE_SPEED;
	}
	else if (key == D_KEY)
	{
		_g->player->_x += cos(_g->player->angle + M_PI_2) * MOVE_SPEED;
		_g->player->_y += sin(_g->player->angle + M_PI_2) * MOVE_SPEED;
	}
}

bool	wall_collisions(t_data_game *_game, t_point old_player)
{
	if (_hase_wall(_game, _game->player->_x, old_player.y))
		_game->player->_x = old_player.x;
	if (_hase_wall(_game, old_player.x, _game->player->_y))
		_game->player->_y = old_player.y;
	return (true);
}

bool	is_door(t_data_game *_game, double px, double py)
{
	px /= TILE_SIZE;
	py /= TILE_SIZE;
	if (_game->map[(int)py][(int)px] == 'O')
		return (true);
	return (false);
}

void	open_door(t_data_game *_g, t_point check_)
{
	int		door_x;
	int		door_y;
	char	*cell;

	check_.x = check_.x + cos(_g->player->angle) * (TILE_SIZE / 2.0);
	check_.y = check_.y + sin(_g->player->angle) * (TILE_SIZE / 2.0);
	door_x = (int)(check_.x / TILE_SIZE);
	door_y = (int)(check_.y / TILE_SIZE);
	if (door_x < 0 || door_y < 0 || door_x >= _g->map_width
		|| door_y >= _g->map_height)
		return ;
	cell = &_g->map[door_y][door_x];
	if (*cell == 'D')
		*cell = 'O';
	else if (*cell == 'O' && !is_door(_g, _g->player->_x, _g->player->_y))
		*cell = 'D';
}

int	control_key_(int keycode, t_data_game *_g)
{
	t_point	old_player;

	(1) && (old_player.y = _g->player->_y), (old_player.x = _g->player->_x);
	if (keycode == ESCAPE)
		return (close_window(_g),
			exit(EXIT_SUCCESS), true);
	_player_move(keycode, _g);
	wall_collisions(_g, old_player);
	if (keycode == LEFT_ARROW)
	{
		_g->player->angle -= ROTATION_SPEED;
		if (_g->player->angle < 0)
			_g->player->angle += 2 * PI;
	}
	else if (keycode == RIGHT_ARROW)
	{
		_g->player->angle += ROTATION_SPEED;
		if (_g->player->angle >= 2)
			_g->player->angle -= 2 * PI;
	}
	if (keycode == E_KEY)
		open_door(_g, (t_point){_g->player->_x, _g->player->_y});
	return (true);
}

int	control_gun_key(int button, int x, int y, t_data_game *_game)
{
	(void)x;
	(void)y;
	if (button == 1) // Left mouse button
	{
		trigger_shooting_animation(_game);
	}
	return (0);
}
