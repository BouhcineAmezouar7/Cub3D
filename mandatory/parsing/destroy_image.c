/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 16:43:23 by ybounite          #+#    #+#             */
/*   Updated: 2025/08/28 10:42:13 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3D.h"

void	destroy_player_hand(t_data_game *_g)
{
	short	i;

	i = 0;
	while (i < _g->player_hand->num_frames)
	{
		if (_g->player_hand->img[i])
			mlx_destroy_image(_g->_mlx, _g->player_hand->img[i]->img);
		i++;
	}
}

void	destroys_images(t_data_game *_g)
{
	if (_g->_img->img)
		mlx_destroy_image(_g->_mlx, _g->_img->img);
	if (_g->texture->no_img->img)
		mlx_destroy_image(_g->_mlx, _g->texture->no_img->img);
	if (_g->texture->so_img->img)
		mlx_destroy_image(_g->_mlx, _g->texture->so_img->img);
	if (_g->texture->we_img->img)
		mlx_destroy_image(_g->_mlx, _g->texture->we_img->img);
	if (_g->texture->ea_img->img)
		mlx_destroy_image(_g->_mlx, _g->texture->ea_img->img);
	if (_g->texture->sk_img->img)
		mlx_destroy_image(_g->_mlx, _g->texture->sk_img->img);
	if (_g->texture->dr_img->img)
		mlx_destroy_image(_g->_mlx, _g->texture->dr_img->img);
}

bool	close_window(t_data_game *game)
{
	destroys_images(game);
	destroy_player_hand(game);
	if (game->_win_mlx)
	{
		mlx_destroy_window(game->_mlx, game->_win_mlx);
		game->_win_mlx = NULL;
	}
	if (game->_mlx)
	{
		mlx_destroy_display(game->_mlx);
		free(game->_mlx);
		game->_mlx = NULL;
	}
	if (game->clos_win)
		return (ft_malloc(CLEAR, CLEAR), exit(EXIT_SUCCESS), true);
	else
		return (ft_malloc(CLEAR, CLEAR), exit(EXIT_FAILURE), false);
}
