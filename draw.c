/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayki <tayki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 13:59:23 by tayki             #+#    #+#             */
/*   Updated: 2025/02/24 15:11:47 by tayki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>


#define ISO_ANGLE 0.7

void	isometric(float *x, float *y, int z)
{
	float	previous_x;

	previous_x = *x;
	*x = (previous_x - *y) * cos(ISO_ANGLE);
	*y = (previous_x + *y) * sin(ISO_ANGLE) - z;
}

void	bresenham(float x, float y, float x1, float y1, fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;
	int		z;
	int		z1;

	z = data->z_matrix[(int)y][(int)x];
	z1 = data->z_matrix[(int)y1][(int)x1];
	x *= data->zoom;
	x1 *= data->zoom;
	y *= data->zoom;
	y1 *= data->zoom;
	data->color = (z || z1) ? 0xe80c0c : 0xffffff;
	isometric(&x, &y, z);
	isometric(&x1, &y1, z1);
	x += data->x_shift;
	y += data->y_shift;
	x1 += data->x_shift;
	y1 += data->y_shift;
	x_step = x1 - x;
	y_step = y1 - y;
	max = fmax(fabs(x_step), fabs(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
		x += x_step;
		y += y_step;
	}
}

void	draw(fdf *data)
{
	int x;
	int y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				bresenham(x, y, x + 1, y, data);
			if (y < data->height - 1)
				bresenham(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
}