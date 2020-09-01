/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 14:34:10 by ykori             #+#    #+#             */
/*   Updated: 2020/02/23 21:30:38 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

char	*num_check(char *dict)
{
	int		zero_flag;

	if (!('0' <= *dict && *dict <= '9'))
		return (0);
	zero_flag = 0;
	if (*dict == '0')
	{
		dict++;
		zero_flag = 1;
	}
	while ('0' <= *dict && *dict <= '9' && zero_flag == 0)
		dict++;
	return (dict);
}

char	*char_check(char *dict)
{
	if (*dict == '\n')
		return (0);
	while (' ' <= *dict && *dict != 127)
		dict++;
	return (dict);
}

int		dict_check(char *dict)
{
	while (*dict != '\0')
	{
		dict = num_check(dict);
		if (dict == 0 || (*dict != ' ' && *dict != ':'))
			return (0);
		while (*dict == ' ')
			dict++;
		if (*dict != ':')
			return (0);
		if (*dict == ':')
			dict++;
		while (*dict == ' ')
			dict++;
		dict = char_check(dict);
		if (dict == 0 || *dict != '\n')
			return (0);
		if (*dict == '\n')
			dict++;
	}
	return (1);
}
