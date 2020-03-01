/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictlib.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 10:16:52 by ykori             #+#    #+#             */
/*   Updated: 2020/02/23 23:11:54 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

char	*judge_key(char *dict, char *key)
{
	char	*val;
	int		idx;

	while (*key != '\0')
	{
		if (*dict != *key)
			return (0);
		dict++;
		key++;
	}
	while (*dict == ' ' || *dict == ':')
		dict++;
	val = (char *)malloc(sizeof(char) * str_len(dict, '\n') + 1);
	idx = str_len(dict, '\n') - 1;
	str_ncpy(val, dict, str_len(dict, '\n'));
	while (val[idx] == ' ')
		idx--;
	val[idx + 1] = '\n';
	return (val);
}

char	*search_val(char *dict, char *key)
{
	while (*dict != '\0')
	{
		if (judge_key(dict, key) == 0)
		{
			while (*dict != '\n')
				dict++;
		}
		else
			return (judge_key(dict, key));
		dict++;
	}
	return (0);
}
