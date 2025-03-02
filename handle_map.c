/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarakay <tkarakay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 15:16:19 by tkarakay          #+#    #+#             */
/*   Updated: 2025/03/02 20:53:32 by tkarakay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <limits.h>

long	process_string(char *str)
{
	char	*comma;
	long	val;

	comma = str;
	while (*comma && *comma != ',')
		comma++;
	if (*comma == ',')
	{
		*comma = '\0';
		val = ft_strtol(str);
		*comma = ',';
	}
	else
	{
		val = ft_strtol(str);
	}
	return (val);
}

int	is_integer(char *str)
{
	long	val;

	val = process_string(str);
	if (val < INT_MIN || val > INT_MAX)
		return (0);
	return (1);
}

int	validate_line(char *line, int width)
{
	char	**nums;
	int		i;
	int		count;

	nums = ft_split(line, ' ');
	if (!nums)
		return (0);
	i = 0;
	count = 0;
	while (nums[i])
	{
		if (!is_integer(nums[i]))
		{
			while (nums[i])
				free(nums[i++]);
			free(nums);
			return (0);
		}
		if (nums[i][0] != '\0')
			count++;
		free(nums[i]);
		i++;
	}
	free(nums);
	return (count == width);
}

int	process_line(int fd, char *line, int width)
{
	if (!validate_line(line, width))
	{
		free(line);
		close(fd);
		return (0);
	}
	free(line);
	return (1);
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
	if (!process_line(fd, line, width))
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		if (!process_line(fd, line, width))
			return (0);
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}
