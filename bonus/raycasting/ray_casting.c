/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamezoua <bamezoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:53:10 by ybounite          #+#    #+#             */
/*   Updated: 2025/08/28 19:53:14 by bamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D_bonus.h"

void	cast_ray(t_data_game *g, t_ray *ray)
{
	t_point	h_hit;
	t_point	v_hit;
	double	h_dist;
	double	v_dist;

	(1) && (h_dist = 1e30), (v_dist = 1e30);
	(1) && (g->is_door_h = false), (g->is_door_v = false);
	g->h_found = cast_horizontal(g, ray, &h_hit, &h_dist);
	g->v_found = cast_vertical(g, ray, &v_hit, &v_dist);
	if (g->h_found && (!g->v_found || h_dist < v_dist))
	{
		ray->hit = h_hit;
		ray->distance = h_dist;
		ray->was_hit_vertical = 0;
	}
	else if (g->v_found)
	{
		ray->hit = v_hit;
		ray->distance = v_dist;
		ray->was_hit_vertical = 1;
	}
}

void	init_ray(t_ray *ray, t_data_game *_game)
{
	ray->ray_angle = _game->player->angle - (FOV / 2.0);
	ray->step_angle = FOV / WINDOW_WIDTH;
	ray->player.x = _game->player->_x;
	ray->player.y = _game->player->_y;
	ray->dist_proj_plane = (WINDOW_HEIGHT / 2.0) / tan(FOV / 2.0);
}

void	_cast_all_rays(t_data_game *_game)
{
	t_ray	ray;
	short	i;

	init_ray(&ray, _game);
	i = 0;
	while (i < WINDOW_WIDTH)
	{
		normalize_angle(&ray.ray_angle);
		cast_ray(_game, &ray);
		_render_wall_slice(_game, &ray, i);
		ray.ray_angle += ray.step_angle;
		i++;
	}
}
