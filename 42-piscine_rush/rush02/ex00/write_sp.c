/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_sp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuehara <yuehara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 13:52:53 by ykori             #+#    #+#             */
/*   Updated: 2020/02/23 22:19:33 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	write_sp2(char *key, char *argv)
{
	int len_argv;
	int len_key;

	len_argv = str_len(argv, '\0');
	len_key = str_len(key, '\0');
	if (len_argv > 3)
		write(1, " ", 1);
	else if (len_argv == 3 && \
			(*(argv + 1) != '0' || *(argv + 2) != '0'))
		write(1, " ", 1);
	else if (len_key == 1 && len_argv > 1)
		write(1, " ", 1);
	else if (len_key == 2 && *argv != '1' &&\
			*(argv + 1) != '0')
		write(1, " ", 1);
	else
		write(1, "\n", 1);
}

void	write_sp(char *key, char *argv)
{
	int sp_flag;
	int len_argv;
	int len_key;

	len_argv = str_len(argv, '\0');
	len_key = str_len(key, '\0');
	if (len_key > 3)
	{
		sp_flag = 0;
		if (len_argv % 3 == 0)
			argv += 3;
		else
			argv += len_argv % 3;
		while (*argv != '\0')
		{
			if (*argv != '0' && sp_flag++ > -1)
				break ;
			argv++;
		}
		if (sp_flag == 1)
			write(1, " ", 1);
	}
	else
		write_sp2(key, argv);
}
