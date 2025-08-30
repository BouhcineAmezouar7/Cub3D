/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 11:30:12 by ybounite          #+#    #+#             */
/*   Updated: 2025/08/29 18:29:03 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

unsigned int	get_pixel(t_imag *tex, int x, int y)
{
	char	*dst;

	if (x < 0 || x >= tex->width || y < 0 || y >= tex->height)
		return (0xFF00FF);
	dst = tex->addr + (y * tex->line_len + x * (tex->bit_per_pixel / 8));
	return (*(unsigned int *)dst);
}

t_imag	*choose_texture(t_data_game *g, t_ray *ray)
{
	if (ray->was_hit_vertical == 1)
	{
		if (is_facing_left(ray->ray_angle))
			return (g->texture->we_img);
		else
			return (g->texture->ea_img);
	}
	else
	{
		if (is_facing_down(ray->ray_angle))
			return (g->texture->no_img);
		else
			return (g->texture->so_img);
	}
}

static void	extract_rgb(unsigned int color, int *r, int *g, int *b)
{
	*r = (color >> 16) & 0xFF;
	*g = (color >> 8) & 0xFF;
	*b = color & 0xFF;
}

static int	blend_channel(int c1, int c2, double alpha)
{
	return ((int)(c1 * alpha + c2 * (1 - alpha)));
}

unsigned int	blend_color(unsigned int src, unsigned int bg, double alpha)
{
	int	src_rgb[3];
	int	bg_rgb[3];
	int	result_rgb[3];

	extract_rgb(src, &src_rgb[0], &src_rgb[1], &src_rgb[2]);
	extract_rgb(bg, &bg_rgb[0], &bg_rgb[1], &bg_rgb[2]);
	result_rgb[0] = blend_channel(src_rgb[0], bg_rgb[0], alpha);
	result_rgb[1] = blend_channel(src_rgb[1], bg_rgb[1], alpha);
	result_rgb[2] = blend_channel(src_rgb[2], bg_rgb[2], alpha);
	return ((result_rgb[0] << 16) | (result_rgb[1] << 8) | result_rgb[2]);
}
