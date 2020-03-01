/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 12:51:10 by ykori             #+#    #+#             */
/*   Updated: 2020/02/27 13:54:41 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int		*ans;
	int		*save;

	ans = (int *)malloc(sizeof(int) * length);
	if (ans == NULL)
		return (NULL);
	save = ans;
	while (length-- > 0)
	{
		*ans = f(*tab);
		ans++;
		tab++;
	}
	return (save);
}
