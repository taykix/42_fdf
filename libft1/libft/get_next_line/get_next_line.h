/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayki <tayki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:46:44 by tayki             #+#    #+#             */
/*   Updated: 2025/02/24 14:34:03 by tayki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct list
{
	char		*str;
	struct list	*next;
}				t_gnl_list;

char			*get_next_line(int fd);
int				write_to_buffer(t_gnl_list **list, int fd);
void			append(t_gnl_list **list, t_gnl_list *new_node);
int				has_endline(t_gnl_list **list);
char			*get_the_line(t_gnl_list *list);
int				count_line(t_gnl_list *list);
void			clean_line(t_gnl_list **head);
t_gnl_list		*create_node(char *content);
void			clean_list(t_gnl_list **list);
char			*ft_strdup(const char *s);

#endif
