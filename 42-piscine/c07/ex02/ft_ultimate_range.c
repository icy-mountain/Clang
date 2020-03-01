/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:14:52 by ykori             #+#    #+#             */
/*   Updated: 2020/02/19 16:41:11 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int		i;
	int		size;

	if (min >= max)
	{
		range = NULL;
		return (0);
	}
	size = max - min;
	*range = (int *)malloc(sizeof(int) * size);
	i = 0;
	while (min < max)
	{
		if (*range == NULL)
			return (-1);
		*(*range + i) = min;
		i++;
		min++;
	}
	return (size);
}
