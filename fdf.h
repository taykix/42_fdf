/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarakay <tkarakay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 09:19:03 by tayki             #+#    #+#             */
/*   Updated: 2025/03/02 19:49:05 by tkarakay         ###   ########.fr       */
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

typedef struct s_fdf
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
}			t_fdf;

void		free_matrix(t_fdf *data);
void		read_file(char *file_name, t_fdf *data);
void		fill_matrix(int *z_line, char *line, t_fdf *data);
int			get_width(char *file_name);
int			get_height(char *file_name);
void		bresenham(t_point start, t_point end, t_fdf *data);
void		draw(t_fdf *data);
int			free_and_close(t_fdf *data);
void		handle_mlx_error(t_fdf *data);
void		handle_error(t_fdf *data);
int			validate_file(char *file_name);

#endif
