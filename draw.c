/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayki <tayki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 13:59:23 by tayki             #+#    #+#             */
/*   Updated: 2025/02/24 16:14:31 by tayki            ###   ########.fr       */
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

static void	init_points(t_point *start, t_point *end, fdf *data, int *z)
{
	z[0] = data->z_matrix[(int)start->y][(int)start->x];
	z[1] = data->z_matrix[(int)end->y][(int)end->x];
	start->x *= data->zoom;
	start->y *= data->zoom;
	end->x *= data->zoom;
	end->y *= data->zoom;
	if (z[0])
		data->color = 0xFF0000;
	else if (z[1])
		data->color = 0xFF8080;
	else
		data->color = 0xFFFFFF;
}

static void	apply_transforms(t_point *start, t_point *end, fdf *data, int *z)
{
	isometric(&start->x, &start->y, z[0]);
	isometric(&end->x, &end->y, z[1]);
	start->x += data->x_shift;
	start->y += data->y_shift;
	end->x += data->x_shift;
	end->y += data->y_shift;
}

static void	calculate_steps(t_point start, t_point end, float *steps)
{
	float	max;

	steps[0] = end.x - start.x;
	steps[1] = end.y - start.y;
	max = fmax(fabs(steps[0]), fabs(steps[1]));
	steps[0] /= max;
	steps[1] /= max;
}

void	bresenham(t_point start, t_point end, fdf *data)
{
	float	steps[2];
	int		z[2];
	t_point	current;

	init_points(&start, &end, data, z);
	apply_transforms(&start, &end, data, z);
	calculate_steps(start, end, steps);
	current = start;
	while ((int)(current.x - end.x) || (int)(current.y - end.y))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, current.x, current.y,
			data->color);
		current.x += steps[0];
		current.y += steps[1];
	}
}

void	draw(fdf *data)
{
	t_point	current;
	t_point	next;

	current.y = 0;
	while (current.y < data->height)
	{
		current.x = 0;
		while (current.x < data->width)
		{
			if (current.x < data->width - 1)
			{
				next.x = current.x + 1;
				next.y = current.y;
				bresenham(current, next, data);
			}
			if (current.y < data->height - 1)
			{
				next.x = current.x;
				next.y = current.y + 1;
				bresenham(current, next, data);
			}
			current.x++;
		}
		current.y++;
	}
}
