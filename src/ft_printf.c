/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 12:16:34 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/03/01 12:16:36 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <locale.h>

void	make_struct(t_spec *sp, int start)
{
	if (start)
		sp->res = 0;
	sp->minus = 0;
	sp->plus = 0;
	sp->space = 0;
	sp->hash = 0;
	sp->zero = 0;
	sp->width = 0;
	sp->prec = -1;
	sp->l = 0;
	sp->ll = 0;
	sp->h = 0;
	sp->hh = 0;
	sp->j = 0;
	sp->z = 0;
	sp->type = 0;
}

void	print_spec(t_spec *sp)
{
	printf("minus=%d\n", sp->minus);
	printf("plus=%d\n", sp->plus);
	printf("space=%d\n", sp->space);
	printf("hash=%d\n", sp->hash);
	printf("zero=%d\n", sp->zero);

	printf("width=%d\n", sp->width);
	printf("prec=%d\n", sp->prec);
	printf("l=%d\n", sp->l);
	printf("ll=%d\n", sp->ll);
	printf("h=%d\n", sp->h);
	printf("hh=%d\n", sp->hh);

	printf("j=%d\n", sp->j);
	printf("z=%d\n", sp->z);
	printf("type=%d\n", sp->type);
}

void	main_job(void *p, t_spec *sp)
{
	if (sp->type == '%')
		type_pers(sp);
	if (sp->type == 's')
		type_s(p, sp);
	if (sp->type == 'p')
		type_p(p, sp);
	if (sp->type == 'd' || sp->type == 'D' || sp->type == 'i')
		type_d(p, sp, 0);
	if (sp->type == 'o' || sp->type == 'O')
		type_o(p, sp, 0);
	if (sp->type == 'x')
		type_x(p, sp, 0);
	if (sp->type == 'X')
		type_x(p, sp, 1);
	if (sp->type == 'u' || sp->type == 'U')
		type_u(p, sp, 0);
	if (sp->type == 'c' || sp->type == 'C')
		type_c(p, sp);
	make_struct(sp, 0);
}

int	ft_printf(const char *format, ...)
{
	va_list ap;
	void	*p;
	int		i;
	char	*s;
	t_spec	sp;

	va_start(ap, format);
	i = -1;
	make_struct(&sp, 1);
	while (format[++i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '%')
		{
			if ((s = ft_strsub(format, i, detect_type((char *)format + i) + 1)))
				i += ft_strlen(s) - 1;
			make_specific(&s, &sp);
			p = va_arg(ap, void *);
			main_job(p, &sp);
		}
		else
			bring_text((char *)(format + i), &sp, &i);
	}
	va_end(ap);
	return (sp.res);
}

void	bring_text(char *str, t_spec *sp, int *ind)
{
	int		i;

	i = 0;
	if (str[i] == '%' && str[i + 1] == '%')
	{
		write(1, "%", 1);
		(sp->res)++;
		(*ind)++;
	}
	else if (str[i] && str[i] != '%')
	{
		write(1, &str[i], 1);
		(sp->res)++;
	}
}

int		detect_type(char *str)
{
	int	i;

	i = 1;
	while (str[i] && !is_type(str[i]) && str[i] != '%')
		i++;
	return (i);
}

void	make_specific(char **str, t_spec *sp)
{
	make_flag(*str, sp);
	make_length(*str, sp);
	make_width(*str, sp);
	make_precision(*str, sp);
	make_type(*str, sp);
	free(*str);
	*str = NULL;
}

/*
int		detect_pers(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '%')
		i++;
	return (i);
}
*/


int		main(void)
{
	int i;
	
	printf("%p\n", &i);
	ft_printf("%s", &i);
	// ft_printf("%-5c", 42);
	// ft_printf("%+ d", 42);
	// t_num num;
	// t_spec sp;
	// make_struct(&sp, 0);
	// nbr_struct(atoi_base_i(123, 10, 0), &num);
	// sp.plus = 1;
	// //sp.zero = 1;
	// sp.width = 5;
	// //sp.minus = 1;
	// sp.prec = 3;
	// precise_string(&str, &sp);
	// put_together(&sp, &num);
	// printf("num=%s\n", num.n);
	// printf("num_size=%d\n", num.s);
	// char* l = setlocale(LC_ALL, "");
	// if (l == NULL) 
	// {
	// printf("Locale not set\n");
	// }
	// else
	// {
	// printf("Locale set to %s\n", l);
	// }  // ᤗᤃᤃ
	// printf("%d", printf("%ls", L"ᤗan"));
	// printf("%-14ls\n", L"ᤗanmᤃᤃ");
	// ft_printf("%8ls\n", L"b-b-b");
	// printf("AAA%C\n", L'狼');
	// printf("MB_CUR_MAX=%d\n", MB_CUR_MAX);
	// ft_printf("%7.7s\n", "Hello");
	// printf("%d\n", ft_wstrlen("ᤃ"));
	// printf("%-5.2s\n", "abcd");
	return (0);
}




