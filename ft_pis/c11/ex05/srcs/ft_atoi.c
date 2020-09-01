/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:58:29 by ykori             #+#    #+#             */
/*   Updated: 2020/02/27 12:23:23 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		check_sp_and_np(char *str)
{
	while (*str != '+' && *str != '-')
	{
		if (*str == ' ' || *str == '\t' || *str == '\n'\
			|| *str == '\v' || *str == '\f' || *str == '\r')
			str++;
		else if ('0' <= *str && *str <= '9')
			return (1);
		else
			return (0);
	}
	while (*str != '\0')
	{
		if (*str == '+' || *str == '-')
			str++;
		else if ('0' <= *str && *str <= '9')
			return (1);
		else
			return (0);
	}
	return (1);
}

int		ft_atoi(char *str)
{
	int		np;
	int		ans;

	np = 1;
	while (*str != '\0' && check_sp_and_np(str))
	{
		if (*str == '-')
			np *= -1;
		if ('0' <= *str && *str <= '9')
		{
			ans = *str - '0';
			while (1)
			{
				str++;
				if ('0' <= *str && *str <= '9')
					ans = ans * 10 + *str - '0';
				else
					return (np * ans);
			}
		}
		str++;
	}
	return (0);
}
