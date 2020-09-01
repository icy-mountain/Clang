/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:29:11 by ykori             #+#    #+#             */
/*   Updated: 2020/02/19 17:32:01 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int		c;

	c = 0;
	while (*str != '\0')
	{
		c++;
		str++;
	}
	return (c);
}

char	*init(char *str, int size)
{
	char	*p;

	p = str;
	while (size > 0)
	{
		*str = '\0';
		str++;
		size--;
	}
	return (p);
}

char	*ft_strdup(char *src)
{
	char	*ans;
	char	*p;
	int		m_size;

	m_size = ft_strlen(src) + 1;
	ans = init((char *)malloc(sizeof(char) * m_size), m_size);
	p = ans;
	if (ans == NULL)
		return (NULL);
	while (*src != '\0')
	{
		*ans = *src;
		ans++;
		src++;
	}
	*ans = '\0';
	return (p);
}
