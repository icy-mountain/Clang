/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 19:23:06 by ykori             #+#    #+#             */
/*   Updated: 2020/02/13 17:10:32 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		make_base(char *base)
{
	int		obase;
	char	black_l[128];

	obase = 0;
	while (*base != '\0')
	{
		if (black_l[(int)*base] == '!')
			return (0);
		if (*base == '-' || *base == '+' || *base == ' ')
			return (0);
		black_l[(int)*base] = '!';
		obase++;
		base++;
	}
	if (obase <= 1)
		return (0);
	return (obase);
}

int		make_ans(char *base_ans, int np, int ibase)
{
	long	ans;
	int		max_pow;
	int		to_int;
	int		len;
	char	*p;

	ans = 0;
	max_pow = 1;
	len = 0;
	p = base_ans;
	while (*(p++) != '\0')
		len++;
	while (len-- > 1)
		max_pow *= ibase;
	while (*base_ans != '\0')
	{
		to_int = '9' <= *base_ans ? *base_ans - 55 : *base_ans - '0';
		ans += to_int * max_pow;
		max_pow /= ibase;
		base_ans++;
	}
	return (np * ans);
}

void	init(char *str, int size, int *params)
{
	while (size-- > 0)
		str[size] = '\0';
	params[0] = 1;
	params[2] = 0;
}

int		t_f(char *str, int *params)
{
	return (!(':' <= *str && *str <= '@') && '0' <= *str && *str <= params[3]);
}

int		ft_atoi_base(char *str, char *base)
{
	int		params[4];
	char	base_ans[33];

	init(base_ans, 33, params);
	params[1] = make_base(base);
	if (*str == '\0' || params[1] == 0)
		return (0);
	params[3] = params[1] > 10 ? params[1] + 54 : params[1] - 1 + '0';
	while (*str++ != '\0')
	{
		params[0] = *str == '-' ? params[0] * -1 : params[0];
		if (t_f(str, params))
		{
			if (*str == '0')
				return (0);
			while (1)
			{
				if (t_f(str, params))
					base_ans[params[2]++] = *(str++);
				else
					return (make_ans(base_ans, params[0], params[1]));
			}
		}
	}
	return (0);
}
/*
** params[0] indicate variance of  "np" means -1 or 1.
** params[1] indicate variance of  "ibase" means base num. 2 ~ 36
** params[2] indicate variance of  "index" means index of base_ans.
** params[3] indicate variance of  "max" means base max. 2->1,16->F
*/
