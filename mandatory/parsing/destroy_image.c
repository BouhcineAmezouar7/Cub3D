/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 16:43:23 by ybounite          #+#    #+#             */
/*   Updated: 2025/08/30 11:50:59 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

void	_exit_with_error(void)
{
	if (data_struc()->_mlx)
	{
		mlx_destroy_display(data_struc()->_mlx);
		free(data_struc()->_mlx);
	}
	ft_malloc(CLEAR, CLEAR);
	exit(EXIT_FAILURE);
}

void	destroys_images(t_data_game *_g)
{
	if (_g->_img && _g->_img->img)
		mlx_destroy_image(_g->_mlx, _g->_img->img);
	if (_g->texture->no_img && _g->texture->no_img->img)
		mlx_destroy_image(_g->_mlx, _g->texture->no_img->img);
	if (_g->texture->so_img && _g->texture->so_img->img)
		mlx_destroy_image(_g->_mlx, _g->texture->so_img->img);
	if (_g->texture->we_img && _g->texture->we_img->img)
		mlx_destroy_image(_g->_mlx, _g->texture->we_img->img);
	if (_g->texture->ea_img && _g->texture->ea_img->img)
		mlx_destroy_image(_g->_mlx, _g->texture->ea_img->img);
}

bool	close_window(t_data_game *game)
{
	destroys_images(game);
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
