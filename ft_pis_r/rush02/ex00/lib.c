/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuehara <yuehara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 21:59:28 by yuehara           #+#    #+#             */
/*   Updated: 2020/02/23 21:30:36 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	ft_writeerror(int i)
{
	if (i == 1)
		write(1, "Error\n", 6);
	else if (i == 2)
		write(1, "Dict Error\n", 11);
}

/*
** man ft_writeerror
**
** ft_writeerror(int nbr);
**
** nbr == 1 : "Error"
** nbr == 2 : "Dict Error"
*/

int		pint_check(char *str)
{
	int		zero_flag;

	zero_flag = 0;
	if (*str == '0')
	{
		zero_flag = 1;
		str++;
	}
	while (*str != '\0')
	{
		if (!('0' <= *str && *str <= '9') || zero_flag == 1)
			return (0);
		str++;
	}
	return (1);
}

int		key_check(char *dict, char *key)
{
	char	*str;
	char	*check;
	int		size;
	int		idx;

	size = str_len(key, '\0');
	if (size >= 4)
		size -= 2;
	str = (char *)malloc(sizeof(char) * size + 1);
	ft_init(str, size + 1);
	str[0] = '1';
	idx = 1;
	while (idx < size)
		str[idx++] = '0';
	check = search_val(dict, str);
	if (check == 0)
	{
		free(str);
		free(check);
		return (0);
	}
	free(str);
	free(check);
	return (1);
}

int		ft_checkargv(int elm, char *elmv, char *dict)
{
	if (elm <= 1 || 4 <= elm)
	{
		ft_writeerror(1);
		return (1);
	}
	if (pint_check(elmv) == 0)
	{
		ft_writeerror(1);
		return (0);
	}
	if (key_check(dict, elmv) == 0 || dict_check(dict) == 0)
	{
		ft_writeerror(2);
		return (0);
	}
	return (1);
}
