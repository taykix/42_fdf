/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarakay <tkarakay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:24:08 by tayki             #+#    #+#             */
/*   Updated: 2025/03/02 20:44:47 by tkarakay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_power(int base, int exp)
{
	long	result;

	result = 1;
	while (exp > 0)
	{
		result *= base;
		exp--;
	}
	return (result);
}

long int	ft_strtol(char *line)
{
	long int	rslt;
	int			sign;
	int			i;

	rslt = 0;
	sign = 1;
	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (line[i] == '+')
		i++;
	while (line[i] >= '0' && line[i] <= '9')
	{
		rslt = rslt * 10 + (line[i] - '0');
		i++;
	}
	return (sign * rslt);
}
