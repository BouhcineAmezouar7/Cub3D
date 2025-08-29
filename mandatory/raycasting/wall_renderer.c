/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_renderer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamezoua <bamezoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 12:52:22 by ybounite          #+#    #+#             */
/*   Updated: 2025/08/28 19:54:39 by bamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

int	get_tex_x(t_ray *ray, t_imag *textuer)
{
	int	tex_x;

	if (ray->was_hit_vertical)
		tex_x = (int)fmod(ray->hit.y, TILE_SIZE);
	else
		tex_x = (int)fmod(ray->hit.x, TILE_SIZE);
	return (tex_x * textuer->width / TILE_SIZE);
}

void	draw_wall_strip(t_data_game *_g, t_ray *ray, t_imag *tex,
	t_data_slice sd)
{
	int				y;
	int				d;
	unsigned int	color;
	unsigned int	final_color;

	y = sd.wall_top;
	while (y < sd.wall_bottome)
	{
		d = (y + (sd.wall_height / 2.0)) - WINDOW_HEIGHT / 2.0;
		d *= tex->height;
		sd.tex_y = d / sd.wall_height;
		sd.alpha = 1.0 - (ray->distance / 800);
		color = get_pixel(tex, sd.tex_x, sd.tex_y);
		if (sd.alpha < 0)
			sd.alpha = 0;
		if (sd.alpha > 1)
			sd.alpha = 1;
		final_color = blend_color(color, BLACK, sd.alpha);
		my_mlx_pixel_put(_g->_img, sd.i, y++, final_color);
	}
}

void	_render_wall_slice(t_data_game *g, t_ray *ray, int i)
{
	t_data_slice	slic;
	t_imag			*tex;

	slic.perp_dist = ray->distance * cos(ray->ray_angle - g->player->angle);
	slic.wall_height = (TILE_SIZE / slic.perp_dist) * ray->dist_proj_plane;
	slic.wall_top = (WINDOW_HEIGHT / 2.0) - slic.wall_height / 2.0;
	slic.wall_bottome = (WINDOW_HEIGHT / 2.0) + slic.wall_height / 2.0;
	if (slic.wall_top < 0)
		slic.wall_top = 0;
	if (slic.wall_bottome > WINDOW_HEIGHT)
		slic.wall_bottome = WINDOW_HEIGHT;
	tex = choose_texture(g, ray);
	slic.tex_x = get_tex_x(ray, tex);
	slic.i = i;
	draw_wall_strip(g, ray, tex, slic);
}
