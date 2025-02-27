/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarakay <tkarakay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 09:19:03 by tayki             #+#    #+#             */
/*   Updated: 2025/02/27 17:18:27 by tkarakay         ###   ########.fr       */
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
void		bresenham(t_point start, t_point end, fdf *data);
void		draw(fdf *data);
int			free_and_close(fdf *data);
void		handle_mlx_error(fdf *data);
void		handle_error(fdf *data);

#endif
