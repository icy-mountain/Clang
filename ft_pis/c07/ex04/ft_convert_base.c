/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:08:17 by ykori             #+#    #+#             */
/*   Updated: 2020/02/19 11:55:32 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		at(char *base, char c);

int		check_sp_and_np(char *str, char *from);

char	*init(char *c, int size);

int		len(char *base)
{
	int		obase;
	char	*save;

	obase = 0;
	while (*base != '\0')
	{
		if (*base == '-' || *base == '+' || *base == ' ')
			return (0);
		save = base;
		while (*base++ != '\0')
		{
			if (*base == *save)
				return (0);
		}
		base = save;
		obase++;
		base++;
	}
	if (obase <= 1)
		return (0);
	return (obase);
}

long	ten(char *base, int np, int ibase, char *from)
{
	long	ans;
	int		max_pow;
	int		to_int;
	int		len;
	char	*p;

	ans = 0;
	max_pow = 1;
	len = 0;
	p = base;
	while (at(from, *(p++)) != -1)
		len++;
	while (len-- > 1)
		max_pow *= ibase;
	while (*base != '\0')
	{
		to_int = at(from, *base);
		ans += to_int * max_pow;
		max_pow /= ibase;
		base++;
	}
	return (np * ans);
}

void	obase(long ten, int np, char *to, char *ans)
{
	int		idx;
	int		size;
	char	buf;
	int		idxr;

	idx = 0;
	size = 0;
	ten = ten < 0 ? ten * -1 : ten;
	while (ten > 0)
	{
		ans[idx++] = to[ten % len(to)];
		ten /= len(to);
	}
	ans[idx] = np < 0 ? '-' : ans[idx];
	idx = 0;
	while (ans[idx++] != '\0')
		size++;
	idx = 0;
	idxr = size - 1;
	while (idx < size / 2)
	{
		buf = ans[idx];
		ans[idx++] = ans[idxr];
		ans[idxr--] = buf;
	}
}

char	*ft_convert_base(char *nbr, char *from, char *to)
{
	int		np;
	int		diff;
	char	*ans;

	np = 1;
	diff = 0;
	if (len(from) == 0 || len(to) == 0)
		return (NULL);
	ans = init((char *)malloc(sizeof(char) * 34), 34);
	while (*nbr != '\0' && check_sp_and_np(nbr, from))
	{
		if (*nbr == '-')
			np *= -1;
		if (at(from, *nbr) > -1)
		{
			while (at(from, *(nbr++)) > -1)
				diff++;
			obase(ten(nbr - (diff + 1), np, len(from), from), np, to, ans);
			return (ans);
		}
		nbr++;
	}
	return (NULL);
}
