/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamezoua <bamezoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 19:03:20 by ybounite          #+#    #+#             */
/*   Updated: 2025/07/19 10:00:14 by bamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3D.h"

void	syntax_error(short option)
{
	if (option == 1)
		ft_putendl_fd("Error\nInvalid arguments", STDERR);
	else if (option == 2)
		ft_putendl_fd("Error\nDuplicate texture identifier", STDERR);
	else if (option == 3)
		ft_putendl_fd("Error\nInvalid texture identifier", STDERR);
	else if (option == 4)
		ft_putendl_fd("Error\nMemory allocation failed", STDERR);
	else if (option == 5)
		ft_putendl_fd("Erroe\nincorrect texture .xpm", STDERR);
	else if (option == 6)
		ft_putendl_fd("Error:\nmlx_init failed.", STDERR);
	else if (option == 7)
		ft_putendl_fd("Error:\nFailed to load textures.", STDERR);
	else if (option == 8)
		ft_putendl_fd("Error: Address Failed to load textures.", STDERR);
}
