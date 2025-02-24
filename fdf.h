/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayki <tayki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 09:19:03 by tayki             #+#    #+#             */
/*   Updated: 2025/02/24 15:11:20 by tayki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft1/ft_printf/ft_printf.h"
# include "libft1/libft/get_next_line/get_next_line.h"
# include "libft1/libft/libft.h"
# include "mlx.h"

typedef struct s_point
{
	float	x;
	float	y;
}			t_point;

typedef struct
{
	int		width;
	int		height;
	int		**z_matrix;
	int		zoom;
	int		x_shift;
	int		y_shift;
	int		color;
	void	*mlx_ptr;
	void	*win_ptr;
}			fdf;

void		free_matrix(fdf *data);
void		read_file(char *file_name, fdf *data);
void		fill_matrix(int *z_line, char *line, fdf *data);
int			get_width(char *file_name);
int			get_height(char *file_name);
void		bresenham(float x, float y, float x1, float y1, fdf *data);
void		draw(fdf *data);

#endif