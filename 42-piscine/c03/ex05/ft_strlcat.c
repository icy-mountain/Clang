/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 17:17:27 by ykori             #+#    #+#             */
/*   Updated: 2020/02/12 16:20:00 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int					ft_strlen(char *c)
{
	int		ans;

	ans = 0;
	while (*c != '\0')
	{
		ans++;
		c++;
	}
	return (ans);
}

unsigned	int		ft_strlcat(char *dest, char *src, unsigned int size)
{
	char				*destp;
	char				*srcp;
	unsigned	int		n;
	unsigned	int		d_len;

	n = size;
	destp = dest;
	srcp = src;
	while (n-- != 0 && *dest != '\0')
		dest++;
	d_len = dest - destp;
	n = size - d_len;
	if (n-- == 0)
		return (d_len + ft_strlen(src));
	while (*src != '\0')
	{
		if (n != 0)
		{
			*dest++ = *src;
			n--;
		}
		src++;
	}
	*dest = '\0';
	return (d_len + (src - srcp));
}
