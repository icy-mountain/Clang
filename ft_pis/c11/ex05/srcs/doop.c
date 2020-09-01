/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 10:26:17 by ykori             #+#    #+#             */
/*   Updated: 2020/02/27 14:26:56 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doop.h"

char	judge_ope(char *str)
{
	if (str[1] != '\0')
		return (0);
	if (str[0] == '+' || str[0] == '-' ||\
			str[0] == '*' || str[0] == '/' || str[0] == '%')
		return (str[0]);
	return (0);
}

int		calc(char op, int left, int right)
{
	int		(*func[5])(int, int);

	func[0] = plus;
	func[1] = minus;
	func[2] = mul;
	func[3] = div;
	func[4] = mod;
	if (op == '+')
		return (func[0](left, right));
	if (op == '-')
		return (func[1](left, right));
	if (op == '*')
		return (func[2](left, right));
	if (op == '/')
		return (func[3](left, right));
	if (op == '%')
		return (func[4](left, right));
	return (0);
}
