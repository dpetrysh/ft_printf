/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 12:22:47 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/04/10 12:22:49 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	type_s(void *p, t_spec *sp)
{
	t_num	num;

	make_tnum(&num);
	if (!p)
	{
		num.n = ft_strdup("(null)");
		num.s = ft_strlen(num.n);
		put_str_simp(sp, &num);
	}
	else if (sp->type == 'S' || (sp->type == 's' && sp->l))
	{
		make_wstr((wchar_t *)p, sp);
	}
	else
	{
		num.n = ft_strjoin((char *)p, "");
		num.s = ft_strlen(num.n);
		put_str_simp(sp, &num);
	}
}

void	put_wstr(t_spec *sp, wchar_t *wstr)
{
	int	i;

	i = -1;
	while (wstr[++i])
		put_wchar(wstr[i]);
	sp->res += get_wlen(wstr);
}

void	make_wstr(void *p, t_spec *sp)
{
	int		i;
	wchar_t *wch;
	w_str	w;

	i = -1;
	wch = (wchar_t *)p;
	w.s = get_wlen(wch);
	w.n = (wchar_t *)ft_memalloc(sizeof(wchar_t) * w.s + 1);
	while (wch[++i])
		w.n[i] = wch[i];
	w.n[i] = '\0';
	if (sp->prec != -1)
		precise_wstr(&w, sp);
	if (sp->width > w.s)
		use_width_wstr(&w, sp);
	else
		put_wstr(sp, w.n);
	free(w.n);
}

void	use_width_wstr(w_str *w, t_spec *sp)
{
	int		i;
	char	*ch;

	i = -1;
	ch = (char *)ft_memalloc(sp->width - w->s + 1);
	while (++i < sp->width - w->s)
	{
		if (sp->zero)
			ch[i] = '0';
		else
			ch[i] = ' ';
	}
	ch[i] = '\0';
	if (sp->minus)
	{
		put_wstr(sp, w->n);
		ft_putstr(ch);
	}
	else
	{
		ft_putstr(ch);
		put_wstr(sp, w->n);
	}
	sp->res += ft_strlen(ch);
	free(ch);
}
void	precise_wstr(w_str *w, t_spec *sp)
{
	int		i;
	int		s;
	wchar_t	*tmp;

	i = 0;
	s = 0;
	tmp = w->n;
	w->n = (wchar_t *)ft_memalloc(sizeof(wchar_t) * sp->prec + 1);
	while ((s += count_bytes(tmp[i])) <= sp->prec && i < w->s)
	{
		w->n[i] = tmp[i];
		i++;
	}
	w->n[i] = '\0';
	w->s = get_wlen(w->n);
	free(tmp);
}

void	precise_string(t_num *num, t_spec *sp)
{
	int		i;
	char	*tmp;

	i = -1;
	tmp = num->n;
	num->n = (char *)malloc(sp->prec + 1);
	while (++i < sp->prec && i < num->s)
		num->n[i] = tmp[i];
	num->n[i] = '\0';
	num->s = ft_strlen(num->n);
	free(tmp);
}

void	put_str_simp(t_spec *sp, t_num *num)
{
	if (sp->prec != -1 && sp->type != 'p')
		precise_string(num, sp);
	if (sp->width > num->s)
	{
		if (sp->minus)
			minus_flag_in(sp, num);
		else if (sp->zero)
			make_zero(sp, num);
		else
			minus_flag_off(sp, num);
	}
	ft_putstr(num->n);
	sp->res += ft_strlen(num->n);
	free(num->n);
}
