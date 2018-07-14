/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 18:56:16 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/03/01 18:56:16 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
#define PRINTF_H


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "../libft/libft.h"

# define ABS(x)	((x) < 0 ? -(x) : (x))

typedef	struct	s_num
{
	int		m;
	int		s;
	char	*n;
}				t_num;

typedef	struct	s_str1
{
	int			s;
	wchar_t		*n;
}				w_str;

typedef	struct	s_str
{
	int		s;
	char	*str;
}				t_str;

typedef struct	s_spec
{
	int			res;
	int			minus;
	int			plus;
	int			space;
	int			hash;
	int			zero;
	int			width;
	int			prec;
	int			l;
	int			ll;
	int			h;
	int			hh;
	int			j;
	int			z;
	int			type;
	int			other;
}				t_spec;



int	ft_printf(const char *format, ...);

//printf.c
int		detect_type(char *str);
int		make_specific(char **str, t_spec *sp);
void	make_struct(t_spec *sp, int start);
int		ft_printf(const char *format, ...);
void	main_job(void *p, t_spec *sp);


int		is_flag(char c);
int		is_length(char c);
int		is_type(char c);
int		is_unsigned_type(char c);
int		is_known(char c);

void	make_flag(char *str, t_spec *sp);
void	make_length(char *str, t_spec *sp);
void	make_width(char *str, t_spec *sp);
void	make_precision(char *str, t_spec *sp);
void	make_type(char *str, t_spec *sp);
//atoi_base.c
void		add_digit(int n, int big, char **src);

char		*ft_itoa_base(long long n, int base, int big);
char		*ft_itoa_base_uns(unsigned long long n, int base, int big);

void		type_d(void *p, t_spec *sp, int big);
void		type_o(void *p, t_spec *sp, int big);
void		type_x(void *p, t_spec *sp, int big);
void		type_u(void *p, t_spec *sp, int big);
void		type_s(void *p, t_spec *sp);
void		type_c(void *p, t_spec *sp);
void		type_p(void *p, t_spec *sp);
void		type_pers(t_spec *sp);


//sign_maker.c
void		make_sign(t_spec *sp, t_num *num);
void		make_minus(t_num *num);
void		make_plus(t_num *num);
void		make_inv_plus(t_num *num);
void		make_more_zero(t_num *num);

char	*str_add(char **s1, char *s2);
int		detect_pers(char *str);
void	bring_text(char *format, t_spec *sp, int *i);

void	add_char(char **s1, char c);

void	make_tnum(t_num *num);
void	nbr_struct(char *str, t_num *num);
void	use_prec(t_spec *sp, t_num *num);

//bracer.c
void	put_together(t_spec *sp, t_num *num);
void	noprec_minus_in(t_spec *sp, t_num *num);
void	noprec_minus_off(t_spec *sp, t_num *num);
void	make_zero(t_spec *sp, t_num *num);
void	minus_flag_in(t_spec *sp, t_num *num);
void	minus_flag_off(t_spec *sp, t_num *num);

void	make_hash_o(t_spec *sp, t_num *num);
void	make_hash_x(void *p, t_spec *sp, t_num *num);
void	precise_string(t_num *num, t_spec *sp);
void	precise_wstr(w_str *w, t_spec *sp);
void	make_wstr(void *p, t_spec *sp);
void	use_width_wstr(w_str *w, t_spec *sp);

int		get_wlen(wchar_t *str);
int		count_bytes(wchar_t c);
int		put_wchar(wchar_t c);
void	put_wstr(t_spec *sp, wchar_t *wstr);

int		get_rank(long long n, int base);
int		get_rank_uns(unsigned long long n, int base);
char	get_chardig(int n, int big);

void	put_char_simp(t_spec *sp, t_num *num, char c);
char	*ft_chardup(char c);
void	put_chzero(t_spec *sp, t_num *num);

void	put_str_simp(t_spec *sp, t_num *num);


#endif