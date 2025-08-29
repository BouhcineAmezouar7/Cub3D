/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_intersection.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamezoua <bamezoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 15:19:58 by ybounite          #+#    #+#             */
/*   Updated: 2025/08/28 19:54:39 by bamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

t_point	get_first_horizontal_intercept(t_ray *ray)
{
	t_point	intercept;
	double	value_tan;

	value_tan = tan(ray->ray_angle);
	intercept.y = floor(ray->player.y / TILE_SIZE) * TILE_SIZE;
	if (is_facing_down(ray->ray_angle))
		intercept.y += TILE_SIZE;
	intercept.x = ray->player.x + (intercept.y - ray->player.y) / value_tan;
	return (intercept);
}

t_point	get_horizontal_ray_step(t_ray *ray)
{
	t_point	step;

	step.y = TILE_SIZE;
	if (is_facing_up(ray->ray_angle))
		step.y *= -1;
	step.x = TILE_SIZE / tan(ray->ray_angle);
	if ((is_facing_left(ray->ray_angle) && step.x > 0)
		|| (is_facing_right(ray->ray_angle) && step.x < 0))
		step.x *= -1;
	return (step);
}

bool	is_within_map_bounds(t_data_game *_game, t_point next)
{
	return (next.x >= 0 && next.y >= 0 && next.x < _game->map_width * TILE_SIZE
		&& next.y < _game->map_height * TILE_SIZE);
}

bool	cast_horizontal(t_data_game *g, t_ray *ray, t_point *hit, double *dist)
{
	t_point	step;
	t_point	map_;
	t_point	next;

	next = get_first_horizontal_intercept(ray);
	step = get_horizontal_ray_step(ray);
	while (is_within_map_bounds(g, next))
	{
		map_.x = (int)next.x;
		map_.y = (int)(next.y);
		if (is_facing_up(ray->ray_angle))
			map_.y -= 1;
		if (is_wall(g, map_.x, map_.y))
		{
			*hit = (t_point){next.x, next.y};
			*dist = hypot(next.x - ray->player.x, next.y - ray->player.y);
			return (true);
		}
		next.x += step.x;
		next.y += step.y;
	}
	return (false);
}
