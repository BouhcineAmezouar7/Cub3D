/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamezoua <bamezoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:07:00 by bamezoua          #+#    #+#             */
/*   Updated: 2025/08/28 19:53:14 by bamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D_bonus.h"

bool	is_valid_cell(char c)
{
	return (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == 'D');
}

bool	check_top_and_bottum(t_data_game *_game)
{
	int	i;
	int	j;

	i = 0;
	while (i < _game->map_height)
	{
		j = 0;
		if (i == 0 || i == _game->map_height - 1)
		{
			while (_game->map[i][j])
			{
				if (_game->map[i][j] == 'N' || _game->map[i][j] == 'S'
					|| _game->map[i][j] == 'E' || _game->map[i][j] == 'W')
				{
					printf("Invalid map: top or bottom row not walls\n");
					return (false);
				}
				j++;
			}
		}
		i++;
	}
	return (true);
}

bool	check_right_and_left(t_data_game *_game)
{
	int	i;
	int	j;

	i = 0;
	while (i < _game->map_height)
	{
		j = 0;
		if (_game->map[i][j] == 'N' || _game->map[i][j] == 'S'
			|| _game->map[i][j] == 'E' || _game->map[i][j] == 'W'
			|| _game->map[i][ft_strlen(_game->map[i]) - 1] == 'N')
		{
			printf("Invalid map: left or right column must be all walls\n");
			return (false);
		}
		i++;
	}
	return (true);
}

bool	check_map_if_closed(t_data_game *_game)
{
	if (check_top_and_bottum(_game) == false)
		return (false);
	if (check_right_and_left(_game) == false)
		return (false);
	return (true);
}

int	ft_count(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i] != '\0')
		i++;
	return (i);
}
