/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 12:36:27 by ykori             #+#    #+#             */
/*   Updated: 2020/02/27 12:47:27 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doop.h"

int		str_len(char *str)
{
	int		count;

	count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return (count);
}

int		write_err(char *str)
{
	write(1, str, str_len(str));
	return (0);
}
