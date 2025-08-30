/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 16:57:49 by ybounite          #+#    #+#             */
/*   Updated: 2025/08/30 09:55:32 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Cub3D.h"

struct s_game	*data_struc(void)
{
	static struct s_game	data_struc = {0};

	return (&data_struc);
}

int	render(t_data_game *g)
{
	static short	frame;

	if (frame == 100)
	{
		clear_image(g->_img, BLACK);
		draw_sky_and_floor(g);
		_cast_all_rays(g);
		mlx_put_image_to_window(g->_mlx, g->_win_mlx, g->_img->img, 0, 0);
		frame = 0;
	}
	frame++;
	return (0);
}

t_data_game	*initialize_game(void)
{
	t_data_game	*_game;

	_game = ft_malloc(sizeof(t_data_game), ALLOC);
	_game->config = ft_malloc(sizeof(t_config), ALLOC);
	_game->texture = ft_malloc(sizeof(t_texture), ALLOC);
	_game->player = ft_malloc(sizeof(t_player), ALLOC);
	ft_memset(_game->config->textures, 0, sizeof(char *) * TEXTURE_COUNT);
	_game->_img = ft_malloc(sizeof(t_imag), ALLOC);
	ft_memset(_game->texture, 0, sizeof(t_texture));
	return (_game);
}

bool	start_simulation(t_data_game *_game)
{
	_game->clos_win = false;
	if (!_mlx_init_data(_game))
		return (_game->clos_win = false, close_window(_game), false);
	init_textures_data(_game);
	player_init(_game);
	mlx_hook(_game->_win_mlx, KeyPress, KeyPressMask, control_key_, _game);
	mlx_loop_hook(_game->_mlx, render, _game);
	mlx_loop(_game->_mlx);
	return (true);
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
