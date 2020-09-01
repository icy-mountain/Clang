/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 08:18:32 by ykori             #+#    #+#             */
/*   Updated: 2020/02/17 09:05:01 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *c)
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

int		judge_ascii(char *s1, char *s2)
{
	while (1)
	{
		if (*s1 > *s2)
			return (1);
		if (*s1 < *s2)
			return (0);
		if (*s1 == '\0' && *s2 == '\0')
			return (0);
		s1++;
		s2++;
	}
}

void	sort(char *str[], int len)
{
	int		idx;
	char	*buf;

	idx = 1;
	while (len > 0)
	{
		while (idx < len - 1)
		{
			if (judge_ascii(str[idx], str[idx + 1]))
			{
				buf = str[idx];
				str[idx] = str[idx + 1];
				str[idx + 1] = buf;
			}
			idx++;
		}
		idx = 1;
		len--;
	}
}

int		main(int argc, char *argv[])
{
	int		len;
	int		idx;

	idx = 1;
	if (argc > 1)
	{
		sort(argv, argc);
		while (idx < argc)
		{
			len = ft_strlen(argv[idx]);
			write(1, argv[idx], len);
			write(1, "\n", 1);
			idx++;
		}
	}
	return (0);
}
