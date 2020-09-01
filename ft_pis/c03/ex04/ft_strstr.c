/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:30:49 by ykori             #+#    #+#             */
/*   Updated: 2020/02/14 09:04:09 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strstr(char *str, char *to_find)
{
	char	*ans;
	char	*save;

	save = to_find;
	if (*to_find == '\0')
		return (str);
	while (*str != '\0')
	{
		if (*str == *to_find)
		{
			ans = str;
			while (*str == *to_find)
			{
				if (*(to_find + 1) == '\0')
					return (ans);
				str++;
				to_find++;
			}
			to_find = save;
			str--;
		}
		str++;
	}
	return (NULL);
}
