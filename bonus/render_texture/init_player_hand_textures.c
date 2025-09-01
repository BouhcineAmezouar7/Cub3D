/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_hand_textures.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamezoua <bamezoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:00:17 by ybounite          #+#    #+#             */
/*   Updated: 2025/09/01 09:49:22 by bamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D_bonus.h"

static void	build_filename(char *filename, char *base, int frame_num, char *ext)
{
	int	n;
	int	m;

	n = 0;
	while (base[n] != '\0')
	{
		filename[n] = base[n];
		n++;
	}
	filename[n++] = '0' + (frame_num + 1);
	m = 0;
	while (ext[m] != '\0')
	{
		filename[n++] = ext[m];
		m++;
	}
	filename[n] = '\0';
}

static void	load_frame_texture(t_data_game *_game, int i, char *filename)
{
	int	width;
	int	height;

	_game->player_hand->img[i]->img = mlx_xpm_file_to_image(_game->_mlx,
			filename, &width, &height);
	if (!_game->player_hand->img[i]->img)
	{
		ft_putendl_fd("Error:\nEven fallback texture failed to load", STDERR);
		close_window(_game);
	}
	_game->player_hand->img[i]->width = width;
	_game->player_hand->img[i]->height = height;
}

static void	init_player_hand_memory(t_data_game *_game)
{
	_game->player_hand->num_frames = 4;
	_game->player_hand->current_frame = 0;
	_game->player_hand->is_shooting = false;
	_game->player_hand->img = ft_malloc(sizeof(t_imag *)
			* _game->player_hand->num_frames, ALLOC);
}

void	init_player_hand_textures(t_data_game *_game)
{
	int		i;
	char	filename[256];

	init_player_hand_memory(_game);
	i = 0;
	while (i < _game->player_hand->num_frames)
	{
		_game->player_hand->img[i] = ft_malloc(sizeof(t_imag), ALLOC);
		build_filename(filename, "./textures/shotgun/anim_", i, ".xpm");
		load_frame_texture(_game, i, filename);
		i++;
	}
}
