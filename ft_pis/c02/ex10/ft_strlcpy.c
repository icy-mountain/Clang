/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 11:40:02 by ykori             #+#    #+#             */
/*   Updated: 2020/02/17 12:01:48 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_strlcpy(char *dest, char *src, int size)
{
	char				*p;
	unsigned int		count;

	count = 0;
	p = src - 1;
	while (*(++p) != '\0')
		count++;
	if (size <= 0)
		return (count);
	while (1)
	{
		if ((int)size <= 1 || *src == '\0')
		{
			*dest = '\0';
			return (count);
		}
		*dest = *src;
		src++;
		dest++;
		size--;
	}
	*dest = '\0';
	return (count);
}
