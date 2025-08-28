/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamezoua <bamezoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 12:44:47 by ybounite          #+#    #+#             */
/*   Updated: 2025/08/28 14:40:05 by bamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3D.h"

t_list	*listnew(void *content)
{
	t_list	*new;

	new = ft_malloc(sizeof(t_list), ALLOC);
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

t_list	*file_reading(short fd)
{
	char	*line;
	t_list	*list;

	list = NULL;
	line = get_next_line(fd);
	while (line)
	{
		ft_lstadd_back(&list, listnew(line));
		line = get_next_line(fd);
	}
	close(fd);
	return (list);
}

t_texture_type	get_texturs_type(char *line)
{
	if (!ft_strncmp(line, "NO ", 3))
		return (NO_TEXTURE);
	else if (!ft_strncmp(line, "SO ", 3))
		return (SO_TEXTURE);
	else if (!ft_strncmp(line, "WE ", 3))
		return (WE_TEXTURE);
	else if (!ft_strncmp(line, "EA ", 3))
		return (EA_TEXTURE);
	else if (!ft_strncmp(line, "F ", 2))
		return (F_COLOR);
	else if (!ft_strncmp(line, "C ", 2))
		return (C_COLOR);
	return (IDNTIFIER_TEXTURE);
}
