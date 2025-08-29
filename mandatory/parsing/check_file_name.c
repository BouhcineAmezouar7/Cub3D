/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamezoua <bamezoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 16:53:03 by ybounite          #+#    #+#             */
/*   Updated: 2025/08/28 19:54:39 by bamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

bool	check_filename(char *file_name, char *str)
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

void	check_file_name(char *file_name)
{
	if (!file_name || !check_filename(file_name, ".cub"))
	{
		ft_putendl_fd("Erroe:\nfile name is incorrect!", STDERR);
		_exit_with_error();
	}
}
