/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 13:45:40 by ykori             #+#    #+#             */
/*   Updated: 2020/02/17 09:09:34 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *c)
{
	int		ans;

	ans = 0;
	while (*c != '\0')
	{
		ans++;
		c++;
	}
	return (ans);
}

int		main(int argc, char *argv[])
{
	int		size;

	size = argc;
	size = ft_strlen(argv[0]);
	write(1, argv[0], size);
	write(1, "\n", 1);
	return (0);
}
