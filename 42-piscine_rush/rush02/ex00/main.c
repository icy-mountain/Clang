/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuehara <yuehara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 08:49:58 by ykori             #+#    #+#             */
/*   Updated: 2020/02/23 22:02:43 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#define FILE_NAME "numbers.dict"

int		main(int argc, char **argv)
{
	int		size;
	char	dict[8192 * 100];

	size = 8192 * 100;
	ft_init(dict, size);
	if (argc <= 1 || argc >= 4)
		write(1, "Dict Error\n", 11);
	if (argc == 3)
	{
		if (set_dict(dict, argv[1], size) == 1)
			return (1);
		if (ft_checkargv(argc, argv[2], dict) == 0)
			return (0);
		read_argv(argv[2], dict);
	}
	if (argc == 2)
	{
		if (set_dict(dict, FILE_NAME, size) == 1)
			return (1);
		if (ft_checkargv(argc, argv[1], dict) == 0)
			return (0);
		read_argv(argv[1], dict);
	}
	return (0);
}
