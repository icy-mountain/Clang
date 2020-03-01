/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:41:35 by ykori             #+#    #+#             */
/*   Updated: 2020/02/19 13:08:43 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		*ans;
	int		*p;

	if (min >= max)
		return (NULL);
	ans = (int *)malloc(sizeof(int) * (max - min));
	p = ans;
	while (min < max)
	{
		*ans = min;
		min++;
		ans++;
	}
	return (p);
}
