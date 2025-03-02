/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarakay <tkarakay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 15:16:19 by tkarakay          #+#    #+#             */
/*   Updated: 2025/03/02 15:21:50 by tkarakay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <limits.h>

int	is_integer(char *str)
{
	long	val;

	val = ft_strtol(str);
	if ( val < INT_MIN && val > INT_MAX)
		return (0);
	return (1);
}

int	validate_line(char *line, int width)
{
	char	**nums;
	int		i;

	nums = ft_split(line, ' ');
	if (!nums)
		return (0);
	i = 0;
	while (nums[i])
	{
		if (!is_integer(nums[i]))
		{
			while (nums[i])
				free(nums[i++]);
			free(nums);
			return (0);
		}
		free(nums[i]);
		i++;
	}
	free(nums);
	return (i == width);
}

int	validate_file(char *file_name)
{
	int		fd;
	char	*line;
	int		width;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		return (0);
	}
	width = ft_countword(line, ' ');
	if (!validate_line(line, width))
	{
		free(line);
		close(fd);
		return (0);
	}
	free(line);
	while ((line = get_next_line(fd)))
	{
		if (!validate_line(line, width))
		{
			free(line);
			close(fd);
			return (0);
		}
		free(line);
	}
	close(fd);
	return (1);
}
