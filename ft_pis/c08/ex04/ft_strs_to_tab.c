/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 19:59:29 by ykori             #+#    #+#             */
/*   Updated: 2020/02/24 17:52:32 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int					ft_strlen(char *str)
{
	int		count;

	count = 0;
	while (*str != '\0')
	{
		str++;
		count++;
	}
	return (count);
}

void				ft_strcpy(char *dest, char *src)
{
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str		*my_arr;
	int				idx;
	int				size;
	t_stock_str		*save;

	idx = 0;
	my_arr = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (my_arr == NULL)
		return (NULL);
	save = my_arr;
	while (idx < ac)
	{
		size = ft_strlen(av[idx]);
		my_arr->size = size;
		my_arr->str = av[idx];
		my_arr->copy = (char *)malloc(sizeof(char) * (size + 1));
		if (my_arr->copy == NULL)
			return (NULL);
		ft_strcpy(my_arr->copy, av[idx]);
		my_arr++;
		idx++;
	}
	my_arr->str = 0;
	return (save);
}
