/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 16:57:49 by ybounite          #+#    #+#             */
/*   Updated: 2025/09/01 08:34:42 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Cub3D.h"

struct s_game	*data_struc(void)
{
	static struct s_game	data_struc = {0};

	return (&data_struc);
}

int	main(int ac, char **av)
{
	t_data_game	*_game;

	if (ac != 2)
		return (syntax_error(true), EXIT_FAILURE);
	_game = initialize_game();
	_game->_mlx = mlx_init();
	if (!_game->_mlx)
		return (syntax_error(6), ft_malloc(CLEAR, CLEAR), false);
	data_struc()->_mlx = _game->_mlx;
	if (!parsing(av[1], _game))
		return (_exit_with_error(), EXIT_FAILURE);
	start_simulation(_game);
	ft_malloc(CLEAR, CLEAR);
	return (EXIT_SUCCESS);
}
