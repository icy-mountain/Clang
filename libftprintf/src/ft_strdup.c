/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <ykori@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 22:06:08 by ykori             #+#    #+#             */
/*   Updated: 2020/06/22 22:13:01 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*ft_strdup(const char *s1)
{
	char	*p;
	char	*save;
	int		size;

	size = ft_strlen((char *)s1);
	p = (char *)malloc(sizeof(char) * (size + 1));
	if (p == NULL)
		return (NULL);
	save = p;
	while (*s1 != '\0')
		*(p++) = *(s1++);
	*p = '\0';
	return (save);
}
