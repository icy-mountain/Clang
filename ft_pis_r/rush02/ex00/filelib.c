/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filelib.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 09:07:09 by ykori             #+#    #+#             */
/*   Updated: 2020/02/23 21:34:35 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int		set_dict(char *dict, char *filename, int size)
{
	int		fd;
	int		rsize;

	fd = open(filename, O_RDWR);
	if (fd < 0)
	{
		write(1, "open Error\n", 11);
		return (1);
	}
	while (1)
	{
		rsize = read(fd, dict, size);
		if (rsize < 0)
		{
			write(2, "read Error\n", 11);
			close(fd);
			return (1);
		}
		if (rsize == 0)
			break ;
	}
	close(fd);
	return (0);
}
