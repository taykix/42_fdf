/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayki <tayki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 09:42:49 by tayki             #+#    #+#             */
/*   Updated: 2025/02/24 16:43:51 by tayki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_matrix(int *z_line, char *line, fdf *data)
{
	char	**nums;
	int		i;

	nums = ft_split(line, ' ');
	if (!nums)
		return ;
	i = 0;
	while (nums[i] && i < data->width)
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	while (nums[i])
	{
		free(nums[i]);
		i++;
	}
	free(nums);
}

static void	free_matrix_error(fdf *data, int i)
{
	while (--i >= 0)
		free(data->z_matrix[i]);
	free(data->z_matrix);
	data->z_matrix = NULL;
}

static int	allocate_matrix(fdf *data)
{
	int	i;

	data->z_matrix = (int **)malloc(sizeof(int *) * data->height);
	if (!data->z_matrix)
		return (0);
	i = 0;
	while (i < data->height)
	{
		data->z_matrix[i] = (int *)malloc(sizeof(int) * data->width);
		if (!data->z_matrix[i])
		{
			free_matrix_error(data, i);
			return (0);
		}
		i++;
	}
	return (1);
}

static void	fill_from_file(char *file_name, fdf *data)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return ;
	i = 0;
	line = get_next_line(fd);
	while ((line) && i < data->height)
	{
		fill_matrix(data->z_matrix[i], line, data);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
}

void	read_file(char *file_name, fdf *data)
{
	data->height = get_height(file_name);
	data->width = get_width(file_name);
	if (!allocate_matrix(data))
		return ;
	fill_from_file(file_name, data);
}
