/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:28:57 by ykori             #+#    #+#             */
/*   Updated: 2020/02/25 08:53:50 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** flag to prime number
*/

int		fl2pn(char flag)
{
	if (flag == '-')
		return (2);
	if (flag == '.')
		return (3);
	if (flag == '0')
		return (5);
	if (flag == '*')
		return (7);
	if (flag == '#')
		return (11);
	if (flag == ' ')
		return (13);
	if (flag == '+')
		return (17);
	return (-1);
}
