/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamezoua <bamezoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:04:46 by ybounite          #+#    #+#             */
/*   Updated: 2025/08/28 19:54:39 by bamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

bool	parse_texture_line(t_data_game *_game, char *line)
{
	t_texture_type	type;
	char			*path_start;

	type = get_texturs_type(line);
	if (type == IDNTIFIER_TEXTURE)
		return (syntax_error(3), true);
	if (_game->config->textures[type])
		return (syntax_error(2), true);
	path_start = line + 2;
	if (type <= EA_TEXTURE)
		path_start++;
	while (*path_start == ' ')
		path_start++;
	_game->config->textures[type] = ft_strdup(path_start);
	if (!_game->config->textures[type])
		return (syntax_error(4), true);
	return (false);
}

bool	isconfig(char *line)
{
	return (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "SO ", 3)
		|| !ft_strncmp(line, "WE ", 3) || !ft_strncmp(line, "EA ", 3)
		|| !ft_strncmp(line, "C ", 2) || !ft_strncmp(line, "F ", 2));
}

bool	is_emty_line(char *str)
{
	short	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '\n')
		return (true);
	return (false);
}

bool	is_map_line(char *line)
{
	while (*line)
	{
		if (*line == '\n')
		{
			line++;
			continue ;
		}
		if (*line != ' ' && *line != '0' && *line != '1' && *line != 'N'
			&& *line != 'S' && *line != 'E' && *line != 'W')
			return (false);
		line++;
	}
	return (true);
}

bool	parse_config(t_data_game *_game)
{
	t_list	*tmp;
	char	*line;

	tmp = _game->list;
	while (tmp)
	{
		line = (char *)tmp->content;
		while (*line == ' ' || *line == '\t')
			line++;
		if (is_emty_line(line))
		{
			tmp = tmp->next;
			continue ;
		}
		if (is_map_line(line))
			return (_game->map_start = tmp, true);
		if (isconfig(line))
			parse_texture_line(_game, line);
		else
			return (syntax_error(3), _exit_with_error(), false);
		tmp = tmp->next;
	}
	return (false);
}
