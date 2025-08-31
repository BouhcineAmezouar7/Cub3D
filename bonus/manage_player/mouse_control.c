/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 10:28:19 by ybounite          #+#    #+#             */
/*   Updated: 2025/08/31 10:30:07 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D_bonus.h"

int	mouse_move(int x, int y, t_data_game *_g)
{
	static int	center = WINDOW_WIDTH / 2;

	(void)y;
	if (x < center)
		_g->player->angle -= ROTATION_SPEED;
	else if (x > center)
		_g->player->angle += ROTATION_SPEED;
	normalize_angle(&_g->player->angle);
	return (0);
}
