/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 13:55:15 by ykori             #+#    #+#             */
/*   Updated: 2020/02/14 13:59:53 by ykori            ###   ########.fr       */
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
	int		idx;

	idx = 1;
	while (idx < argc)
	{
		size = ft_strlen(argv[idx]);
		write(1, argv[idx], size);
		write(1, "\n", 1);
		idx++;
	}
	return (0);
}
