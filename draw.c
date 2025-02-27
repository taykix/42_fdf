/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarakay <tkarakay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 13:59:23 by tayki             #+#    #+#             */
/*   Updated: 2025/02/27 17:29:57 by tkarakay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(t_fdf *data)
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
