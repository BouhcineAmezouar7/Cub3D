/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamezoua <bamezoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:41:31 by ybounite          #+#    #+#             */
/*   Updated: 2025/08/28 19:53:14 by bamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D_bonus.h"

bool	is_spawm_direction(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

void	player_position(t_data_game *_game)
{
	short (x), (y);
	y = 0;
	while (_game->map[y])
	{
		x = 0;
		while (_game->map[y][x])
		{
			if (is_spawm_direction(_game->map[y][x]))
			{
				_game->spawm_dir = _game->map[y][x];
				_game->player->_x = x;
				_game->player->_y = y;
				break ;
			}
			x++;
		}
		y++;
	}
}

void	init_player_direction(t_data_game *_game, char spawn_dir)
{
	if (spawn_dir == 'N')
		_game->player->angle = (PI * 1.5);
	else if (spawn_dir == 'S')
		_game->player->angle = PI / 2;
	else if (spawn_dir == 'E')
		_game->player->angle = 0;
	else if (spawn_dir == 'W')
		_game->player->angle = PI;
}

void	player_init(t_data_game *_game)
{
	player_position(_game);
	init_player_direction(_game, _game->spawm_dir);
	_game->player->_x = (_game->player->_x * TILE_SIZE) + TILE_SIZE / 2.0;
	_game->player->_y = (_game->player->_y * TILE_SIZE) + TILE_SIZE / 2.0;
}
