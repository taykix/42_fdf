/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayki <tayki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 09:40:39 by tayki             #+#    #+#             */
/*   Updated: 2025/02/24 14:33:08 by tayki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_key(int key, fdf *data)
{
	ft_printf("%d\n", key);
	if (key == 65363)
		data->x_shift += 10;
	if (key == 65361)
		data->x_shift -= 10;
	if (key == 65362)
		data->y_shift -= 10;
	if (key == 65364)
		data->y_shift += 10;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}

int	main(int argc, char **argv)
{
	fdf *data;
	int i;
	int j;
	data = (fdf *)malloc(sizeof(fdf));
	if (!data)
		return (1);

	read_file(argv[1], data);
	if (!data->z_matrix || data->height <= 0 || data->width <= 0)
	{
		free(data);
		return (1);
	}
	data->zoom = 20;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");

	draw(data);

	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);

	i = 0;
	while (i < data->height)
	{
		free(data->z_matrix[i]);
		i++;
	}
	free(data->z_matrix);
	free(data);

	return (0);
}