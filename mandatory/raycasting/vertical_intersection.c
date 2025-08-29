/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamezoua <bamezoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 15:21:05 by ybounite          #+#    #+#             */
/*   Updated: 2025/08/28 19:54:39 by bamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

t_point	get_first_vertical_intercept(t_ray *ray)
{
	t_point	intercept;
	double	valuie_tan;

	valuie_tan = tan(ray->ray_angle);
	intercept.x = floor(ray->player.x / TILE_SIZE) * TILE_SIZE;
	if (is_facing_right(ray->ray_angle))
		intercept.x += TILE_SIZE;
	intercept.y = ray->player.y + (intercept.x - ray->player.x) * valuie_tan;
	return (intercept);
}

t_point	get_vertical_ray_step(t_ray *ray)
{
	t_point	step;

	step.x = TILE_SIZE;
	if (is_facing_left(ray->ray_angle))
		step.x *= -1;
	step.y = TILE_SIZE * tan(ray->ray_angle);
	if ((is_facing_up(ray->ray_angle) && step.y > 0)
		|| (is_facing_down(ray->ray_angle) && step.y < 0))
		step.y *= -1;
	return (step);
}

bool	cast_vertical(t_data_game *g, t_ray *ray, t_point *hit, double *dist)
{
	t_point	step;
	t_point	next;
	int		map_x;
	int		map_y;

	step = get_vertical_ray_step(ray);
	next = get_first_vertical_intercept(ray);
	while (is_within_map_bounds(g, next))
	{
		map_x = (int)next.x;
		if (is_facing_left(ray->ray_angle))
			map_x -= 1;
		map_y = (int)next.y;
		if (is_wall(g, map_x, map_y))
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
