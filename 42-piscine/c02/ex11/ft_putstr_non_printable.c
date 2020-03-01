/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdtr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 17:43:05 by ykori             #+#    #+#             */
/*   Updated: 2020/02/12 17:16:35 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_printable(char *str)
{
	if (*str < ' ' || '~' < *str)
		return (0);
	return (1);
}

void	ft_putstr_non_printable(char *str)
{
	char	hex0;
	char	hex1;

	while (*str != '\0')
	{
		if (!is_printable(str))
		{
			write(1, "\\", 1);
			hex0 = (*str < 0 ? *str + 256 : *str) / 16 + '0';
			hex1 = (*str < 0 ? *str + 256 : *str) % 16 + '0';
			if (hex0 > '9')
				hex0 += 39;
			if (hex1 > '9')
				hex1 += 39;
			write(1, &hex0, 1);
			write(1, &hex1, 1);
			str++;
		}
		write(1, str, 1);
		str++;
	}
}

int		main(void)
{
	char arr[16] = "HELLO\n!";
	arr[2] = -72;
	ft_putstr_non_printable(arr);
}	
