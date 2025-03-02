/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarakay <tkarakay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:17:59 by tkarakay          #+#    #+#             */
/*   Updated: 2025/03/02 20:52:48 by tkarakay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	handle_error(t_fdf *data)
{
	if (data)
		free(data);
	exit(1);
}

void	handle_mlx_error(t_fdf *data)
{
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	free(data);
	exit(1);
}

int	is_valid_fdf_file(const char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 4 || ft_strncmp(filename + len - 4, ".fdf", 4) != 0)
	{
		ft_printf("Error: File must have .fdf extension\n");
		return (0);
	}
	return (1);
}
