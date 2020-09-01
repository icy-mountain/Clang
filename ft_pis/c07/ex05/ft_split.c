/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 11:46:49 by ykori             #+#    #+#             */
/*   Updated: 2020/02/24 13:50:08 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		str_len(char *c)
{
	int		count;

	count = 0;
	while (*c != '\0')
	{
		c++;
		count++;
	}
	return (count);
}

int		lets_split(char *str, char *cset)
{
	int		len;

	len = str_len(cset);
	if (len < 1)
		return (0);
	while (len > 0)
	{
		if (*str != *cset)
			return (0);
		str++;
		cset++;
		len--;
	}
	return (1);
}

void	ncpy(char *dest, char *src, int n)
{
	while (n > 0)
	{
		*dest = *src;
		dest++;
		src++;
		n--;
	}
	*dest = '\0';
}

void	rm_charset(char *str, char *cset)
{
	int		csize;

	while (*str != '\0')
	{
		if (lets_split(str, cset) == 1)
		{
			csize = str_len(cset);
			while (csize-- > 0)
			{
				*str = -1;
				str++;
			}
			str--;
		}
		str++;
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**ans;
	char	*dup;
	int		idx;
	int		diff;

	dup = (char *)malloc(sizeof(char) * str_len(str) + 1);
	ans = (char **)malloc(sizeof(char *) * str_len(str) / 2 + 2);
	ncpy(dup, str, str_len(str));
	rm_charset(dup, charset);
	idx = 0;
	diff = 0;
	while (*dup != '\0')
	{
		while (*dup != -1 && *dup != '\0' && diff++ >= 0)
			dup++;
		if (diff > 0)
		{
			ans[idx] = (char *)malloc(sizeof(char) * diff);
			ncpy(ans[idx++], dup-- - diff, diff);
			diff = 0;
		}
		dup++;
	}
	ans[idx] = NULL;
	return (ans);
}
