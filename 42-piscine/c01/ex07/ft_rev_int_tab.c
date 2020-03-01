/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:17:59 by ykori             #+#    #+#             */
/*   Updated: 2020/02/06 18:39:42 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int idx_l;
	int idx_r;
	int buf;

	idx_l = 0;
	idx_r = size - 1;
	while (idx_l < size / 2)
	{
		buf = tab[idx_l];
		tab[idx_l] = tab[idx_r];
		tab[idx_r] = buf;
		idx_l++;
		idx_r--;
	}
}
