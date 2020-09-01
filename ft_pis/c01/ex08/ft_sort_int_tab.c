/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:45:42 by ykori             #+#    #+#             */
/*   Updated: 2020/02/06 19:30:20 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int flag;
	int idx;
	int buf;

	flag = 0;
	while (flag != 1)
	{
		flag = 1;
		idx = 0;
		while (idx < size - 1)
		{
			if (tab[idx] > tab[idx + 1])
			{
				buf = tab[idx];
				tab[idx] = tab[idx + 1];
				tab[idx + 1] = buf;
				flag = 0;
			}
			idx++;
		}
	}
}
