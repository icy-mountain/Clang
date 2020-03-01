/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 09:03:53 by ykori             #+#    #+#             */
/*   Updated: 2020/02/23 22:05:33 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	ft_init(char *str, int size)
{
	while (size > 0)
	{
		*str = '\0';
		size--;
		str++;
	}
}

int		str_len(char *str, char end)
{
	int		c;

	c = 0;
	while (*str != end)
	{
		c++;
		str++;
	}
	return (c);
}

void	str_ncpy(char *dest, char *src, int size)
{
	while (size > 0)
	{
		*dest = *src;
		dest++;
		src++;
		size--;
	}
	*dest = '\0';
}
