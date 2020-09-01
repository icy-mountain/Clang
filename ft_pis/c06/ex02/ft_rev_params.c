/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 14:00:08 by ykori             #+#    #+#             */
/*   Updated: 2020/02/14 14:04:24 by ykori            ###   ########.fr       */
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

	while (argc > 1)
	{
		size = ft_strlen(argv[argc - 1]);
		write(1, argv[argc - 1], size);
		write(1, "\n", 1);
		argc--;
	}
	return (0);
}
