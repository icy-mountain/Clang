/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 09:34:38 by ykori             #+#    #+#             */
/*   Updated: 2020/02/11 12:14:12 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	init(char *arr)
{
	int idx;

	idx = -1;
	while (++idx < 5)
	{
		arr[idx] = '0';
	}
	arr[1] = '/';
	arr[2] = ' ';
}

void	print(char *arr)
{
	write(1, arr, 5);
	if (arr[0] == '9' && arr[1] == '8')
		return ;
	write(1, ", ", 2);
	if (arr[4] == '9')
	{
		arr[3]++;
		arr[4] = '0' - 1;
	}
}

void	ft_print_comb2(void)
{
	char arr[5];

	init(arr);
	while (1 && ++arr[1] != 'X')
	{
		arr[3] = arr[1] == '9' ?  arr[0] + 1 : arr[0];
		arr[4] = arr[1] == '9' ? '0' - 1 : arr[1];
		while (arr[3] <= '9' && ++arr[4] != 'X')
		{
			print(arr);
			if (arr[0] == '9' && arr[1] == '8')
				return ;
		}
		if (arr[1] == '9')
		{
			arr[0]++;
			arr[1] = '0' - 1;
		}
	}
}

int		main(void)
{
	ft_print_comb2();
	return (0);
}
