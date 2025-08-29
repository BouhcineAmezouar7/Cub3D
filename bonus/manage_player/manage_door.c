/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_door.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamezoua <bamezoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:30:45 by ybounite          #+#    #+#             */
/*   Updated: 2025/08/28 19:53:14 by bamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D_bonus.h"

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
