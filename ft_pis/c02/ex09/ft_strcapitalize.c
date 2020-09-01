/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 17:02:51 by ykori             #+#    #+#             */
/*   Updated: 2020/02/11 17:31:02 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_alpha(char *str)
{
	if ('A' <= *str && *str <= 'Z')
		return (1);
	if ('a' <= *str && *str <= 'z')
		return (1);
	return (0);
}

int		is_numeric(char *str)
{
	if ('0' <= *str && *str <= '9')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	char	*p;
	int		flag;

	flag = 1;
	p = str;
	while (*str != '\0')
	{
		if (flag == 0 && 'A' <= *str && *str <= 'Z')
			*str += 32;
		if (flag == 1 && 'a' <= *str && *str <= 'z')
		{
			*str -= 32;
			flag = 0;
		}
		if (is_alpha(str) == 0 && is_numeric(str) == 0)
			flag = 1;
		if (is_numeric(str) == 1 || ('A' <= *str && *str <= 'Z'))
			flag = 0;
		str++;
	}
	return (p);
}
