/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayki <tayki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 09:42:49 by tayki             #+#    #+#             */
/*   Updated: 2025/02/24 14:33:15 by tayki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_height(char *file_name)
{
	char	*line;
	int		fd;
	int		height;

	fd = open(file_name, O_RDONLY);
	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

int	get_width(char *file_name)
{
	int		width;
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	width = (int)ft_countword(line, ' ');
	free(line);
	close(fd);
	return (width);
}

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
	// Free remaining strings if any
	while (nums[i])
	{
		free(nums[i]);
		i++;
	}
	free(nums);
}

void	read_file(char *file_name, fdf *data)
{
	int fd;
	char *line;
	int i;

	data->height = get_height(file_name);
	data->width = get_width(file_name);

	data->z_matrix = (int **)malloc(sizeof(int *) * data->height);
	if (!data->z_matrix)
		return ;
	i = 0;
	while (i < data->height)
	{
		data->z_matrix[i] = (int *)malloc(sizeof(int) * data->width);
		if (!data->z_matrix[i])
		{
			while (--i >= 0)
				free(data->z_matrix[i]);
			free(data->z_matrix);
			data->z_matrix = NULL;
			return ;
		}
		i++;
	}
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return ;

	i = 0;
	while ((line = get_next_line(fd)) && i < data->height)
	{
		fill_matrix(data->z_matrix[i], line, data);
		free(line);
		i++;
	}
	close(fd);
}