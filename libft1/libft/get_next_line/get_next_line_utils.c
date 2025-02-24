/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayki <tayki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:19:44 by tayki             #+#    #+#             */
/*   Updated: 2025/02/24 14:34:10 by tayki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	append(t_gnl_list **list, t_gnl_list *new_node)
{
	t_gnl_list	*temp;

	if (!list || !new_node)
		return ;
	if (*list == NULL)
		*list = new_node;
	else
	{
		temp = *list;
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
	}
}

void	clean_line(t_gnl_list **head)
{
	t_gnl_list	*temp;
	char		*str;

	while ((*head))
	{
		str = (*head)->str;
		while (*str && *str != '\n')
			str++;
		if (*str == '\n' && *(str + 1) != '\0')
		{
			temp = create_node(++str);
			if (!temp || !(temp->str))
				return ;
			temp->next = (*head)->next;
			free((*head)->str);
			free(*head);
			*head = temp;
			break ;
		}
		temp = *head;
		*head = (*head)->next;
		free(temp->str);
		free(temp);
	}
}

t_gnl_list	*create_node(char *content)
{
	t_gnl_list	*node;

	node = (t_gnl_list *)malloc(sizeof(t_gnl_list));
	if (!node)
		return (NULL);
	node->str = ft_strdup(content);
	if (!(node->str))
	{
		free(node);
		return (NULL);
	}
	node->next = NULL;
	return (node);
}

void	clean_list(t_gnl_list **list)
{
	t_gnl_list	*temp;
	t_gnl_list	*next;

	if (!list || !*list)
		return ;
	temp = *list;
	while (temp)
	{
		next = temp->next;
		free(temp->str);
		free(temp);
		temp = next;
	}
	*list = NULL;
}

char	*ft_strdup(const char *s)
{
	size_t	len_s;
	char	*arr;
	char	*ptr;
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	len_s = i;
	arr = malloc((len_s + 1) * sizeof(char));
	if (!arr)
		return (NULL);
	ptr = arr;
	while (*s)
	{
		*arr++ = *s++;
	}
	*arr = '\0';
	return (ptr);
}
