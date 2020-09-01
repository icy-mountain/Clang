/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 10:14:57 by ykori             #+#    #+#             */
/*   Updated: 2020/02/27 14:24:46 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doop.h"

int		main(int argc, char *argv[])
{
	int		left;
	int		right;
	int		ans;
	char	op;

	if (argc == 4)
	{
		left = ft_atoi(argv[1]);
		right = ft_atoi(argv[3]);
		op = judge_ope(argv[2]);
		if (op == 0)
			return (write_err("0\n"));
		if (right == 0)
		{
			if (op == '/')
				return (write_err("Stop : division by zero\n"));
			if (op == '%')
				return (write_err("Stop : modulo by zero\n"));
		}
		ans = calc(op, left, right);
		ft_putnbr(ans);
		write(1, "\n", 1);
	}
	return (0);
}
