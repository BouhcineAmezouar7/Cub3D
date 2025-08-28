/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamezoua <bamezoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 12:39:41 by ybounite          #+#    #+#             */
/*   Updated: 2025/08/28 15:03:49 by bamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3D.h"

bool	check_filename_xpm(char *file_name, char *str)
{
	int	i;

	i = 0;
	file_name = file_name + (ft_strlen(file_name) - 4);
	if (ft_strlen(file_name) == 0)
		return (false);
	while (file_name[i])
	{
		if (file_name[i] != str[i])
			return (false);
		i++;
	}
	return (true);
}

void	validate_textures(t_config *_config)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!_config->textures[i]
			|| !check_filename_xpm(remove_space(_config->textures[i]), ".xpm"))
		{
			syntax_error(5);
			ft_malloc(CLEAR, CLEAR);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

int	shift_color(int r, int g, int b)
{
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		printf("Error : Invalid color range [0, 255] in texture\n");
		syntax_error(6);
		ft_malloc(CLEAR, CLEAR);
		exit(1);
	}
	return (r << 16 | g << 8 | b);
}

void	check_spaces(t_config *_config)
{
	int	i;
	int	j;

	i = 4;
	while (_config->textures[i])
	{
		j = 0;
		while (_config->textures[i][j])
		{
			if (_config->textures[i][j] == ' '
				|| _config->textures[i][j] == '\t'
				|| (_config->textures[i][j] == ',' && (_config->textures[i][j
						+ 1] == ',')))
			{
				printf("Error: Invalid character in color texture\n");
				syntax_error(6);
				ft_malloc(CLEAR, CLEAR);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

void	validate_colors(t_config *_config, t_data_game *_game)
{
	int		i;
	char	**split;
	int		rgb[3];

	i = 4;
	while (i < 6)
	{
		check_colors(_config, i);
		split = ft_split(_config->textures[i], ',');
		if (!split | !split[0] || !split[1] || !split[2] || split[3])
		{
			ft_malloc(CLEAR, CLEAR);
			exit(1);
		}
		rgb[0] = ft_atoi(split[0]);
		rgb[1] = ft_atoi(split[1]);
		rgb[2] = ft_atoi(split[2]);
		if (i == 4)
			_config->floor_color = mlx_get_color_value(_game->_mlx,
					shift_color(rgb[0], rgb[1], rgb[2]));
		else if (i == 5)
			_config->ceiling_color = mlx_get_color_value(_game->_mlx,
					shift_color(rgb[0], rgb[1], rgb[2]));
		i++;
	}
}
