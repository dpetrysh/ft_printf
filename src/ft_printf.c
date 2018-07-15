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

#include <limits.h>
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
	sp->other = 0;
}

void	main_job(void *p, t_spec *sp)
{
	if (sp->type == '%')
		type_pers(sp);
	if (sp->type == 's' || sp->type == 'S')
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

int		ft_printf(const char *format, ...)
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
		if (format[i] == '%' && format[i + 1] != '%' &&
			detect_type((char *)format + i))
		{
			if ((s = ft_strsub(format, i, detect_type((char *)format + i) + 1)))
				i += ft_strlen(s) - 1;
			if (make_specific(&s, &sp))
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
	while (str[i] && !is_type(str[i]) && str[i] != '%' && is_known(str[i]))
		i++;
	if (str[i] == '\0')
		return (0);
	return (i);
}
