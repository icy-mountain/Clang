/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 16:03:00 by ykori             #+#    #+#             */
/*   Updated: 2020/02/19 17:08:25 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *c)
{
	int		ans;

	ans = 0;
	while (*c != '\0')
	{
		c++;
		ans++;
	}
	return (ans);
}

int		find_max(char **str, int size)
{
	int		max;

	max = 0;
	while (size > 0)
	{
		if (ft_strlen(str[size - 1]) > max)
			max = ft_strlen(str[size - 1]);
		size--;
	}
	return (max);
}

void	set_word(char *str, char *sep, char *ans, int flag)
{
	while (*str != '\0')
	{
		*ans = *str;
		ans++;
		str++;
	}
	if (flag == 1)
	{
		while (*sep != '\0')
		{
			*ans = *sep;
			ans++;
			sep++;
		}
	}
}

char	*init(char *str, int size)
{
	char	*p;

	p = str;
	while (size > 0)
	{
		*str = '\0';
		size--;
		str++;
	}
	return (p);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		idx;
	char	*ans;
	int		max;
	char	*p;
	int		flag;

	max = find_max(strs, size);
	idx = (max + ft_strlen(sep)) * size;
	ans = init((char *)malloc(sizeof(char) * idx), idx);
	p = ans;
	idx = 0;
	flag = 1;
	while (idx < size)
	{
		flag = idx == size - 1 ? 0 : 1;
		set_word(strs[idx], sep, ans, flag);
		ans += ft_strlen(strs[idx]);
		ans += ft_strlen(sep);
		idx++;
	}
	return (p);
}
