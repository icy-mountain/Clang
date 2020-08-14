/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <ykori@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 12:39:11 by ykori             #+#    #+#             */
/*   Updated: 2020/06/24 14:46:49 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <stdint.h>
# include <wchar.h>
# define ABS(X) (X) < 0 ? -1 * (X) : (X)

typedef struct		s_format
{
	char			type;
	int				flag;
	int				pad;
	int				pred;
	int				rtn;
	va_list			args;
}					t_format;

void				which_spec(t_format *f);
const char			*exist_parcent(const char *str, t_format *f);
void				for_n(int* p, t_format *f);
void				format_init(t_format *f);
const char			*reach_type(const char *str);
void				find_pred(const char *str, t_format *f);
void				find_padding(const char *str, t_format *f);
void				find_flags(const char *str, t_format *f);
char				which_type(char const *str);
char				which_type2(char const *str);
void				put_p(void *p, t_format *f);
void				putbase_ull(unsigned long long num, t_format *f);
void				putbase_ui(unsigned int num, t_format *f);
int					ft_printf(const char *str, ...);
int					ft_strlen(char *s);
char				*ft_strdup(char const *s);
int					ft_numlen(long long num, int base);
int					ft_numlen_i(int num, int base);
int					ft_numlen_ui(unsigned int num, int base);
int					ft_numlen_lui(long unsigned int num, int base);
int					ft_numlen_ull(unsigned long long num, int base);
void				pf_putnbr_i(int nbr, t_format *f);
void				pf_putnbr_ui(unsigned int nbr, t_format *f);
void				pf_putnbr_ll(long long nbr, t_format *f);
void				pf_putnbr_ull(unsigned long long nbr, t_format *f);
void				pf_putchar(int nb, t_format *t);
void				pf_putstr(char *str, t_format *f);
void				pf_putnbr_base_ui(unsigned int nbr, char *base, t_format *f);
void				pf_putnbr_base_ull(unsigned long long nbr, char *base, t_format *f);
void				pf_put_pointer(long unsigned int nbr, char *base, t_format *f);
void				ft_putnbr_i(int nbr);
void				ft_putnbr_ui(unsigned int nbr);
void				ft_putnbr_ll(long long nbr);
void				ft_putnbr_ull(unsigned long long nbr);
void				ft_putchar(char c);
void				ft_putstr(char *str);
void				ft_putnbr_base_ui(unsigned int nbr, char *base);
void				ft_putnbr_base_ull(unsigned long long nbr, char *base);
void				ft_put_pointer(long unsigned int nbr, char *base);
int					fl2pn(char flag);
#endif
