/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamezoua <bamezoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 10:53:53 by bamezoua          #+#    #+#             */
/*   Updated: 2025/08/28 11:15:54 by bamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3D.h"

char	*remove_space(char *str)
{
	int		i;
	bool	isother_word;

	i = 0;
	isother_word = false;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\n' && isother_word)
			return (syntax_error(3), exit(EXIT_FAILURE), NULL);
		if (str[i] == ' ' || str[i] == '\n')
		{
			str[i] = '\0';
			isother_word = true;
		}
		i++;
	}
	return (str);
}

static bool	validate_door_placement(t_data_game *_game, int i, int j, int width)
{
	if (j > 0 && j < width - 1 && i > 0 && i < _game->map_height - 1)
	{
		if (!(_game->map[i][j - 1] == '1' && _game->map[i][j + 1] == '1')
			&& !(_game->map[i - 1][j] == '1' && _game->map[i + 1][j] == '1'))
		{
			printf("Error\nDoor must be enclosed by walls on opposite sides\n");
			return (false);
		}
	}
	else
	{
		printf("Error\nDoor cannot be at map boundary\n");
		return (false);
	}
	return (true);
}

static bool	check_adjacent_cells(t_data_game *_game, int i, int j, int width)
{
	bool	invalid;

	invalid = false;
	if (i > 0 && (j >= ft_count(_game->map[i - 1]) || _game->map[i
				- 1][j] == ' '))
		invalid = true;
	if (i < _game->map_height - 1 && (j >= ft_count(_game->map[i + 1])
			|| _game->map[i + 1][j] == ' '))
		invalid = true;
	if (j > 0 && _game->map[i][j - 1] == ' ')
		invalid = true;
	if (j < width - 1 && _game->map[i][j + 1] == ' ')
		invalid = true;
	if (invalid)
	{
		printf("Error\nMap is not closed around position (%d, %d)\n", i, j);
		return (false);
	}
	return (true);
}

static bool	validate_cell(t_data_game *_game, int i, int j, int width)
{
	if (_game->map[i][j] == 'D')
	{
		if (!validate_door_placement(_game, i, j, width))
			return (false);
	}
	if (is_valid_cell(_game->map[i][j]))
	{
		if (i == 0 || i == _game->map_height - 1 || j == 0 || j == width - 1)
		{
			printf("Error\nValid cells cannot be at map boundary\n");
			return (false);
		}
		if (!check_adjacent_cells(_game, i, j, width))
			return (false);
	}
	return (true);
}

bool	is_valid_map(t_data_game *_game)
{
	int	i;
	int	j;
	int	width;

	if (check_map_if_closed(_game) == false)
		return (false);
	i = 0;
	while (i < _game->map_height)
	{
		j = 0;
		width = ft_count(_game->map[i]);
		while (j < width)
		{
			if (!validate_cell(_game, i, j, width))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
