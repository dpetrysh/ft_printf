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
		num.n = ft_strdup("(null)");
	else
		num.n = ft_strjoin((char *)p, "");
	num.s = ft_strlen(num.n);
	if (!sp->l)
		put_str_simp(sp, &num);
	else
		put_wstr((wchar_t *)p);
}

void	put_str_simp(t_spec *sp, t_num *num)
{
	if (sp->prec != -1)
		precise_string(num, sp);
	if (sp->width > num->s)
	{
		if (sp->minus)
			minus_flag_in(sp, num);
		else
			minus_flag_off(sp, num);
	}
	ft_putstr(num->n);
	sp->res += ft_strlen(num->n);
	free(num->n);
}

void	make_wstr(void *p, t_spec *sp)
{
	w_str	w;

	w.s = get_wlen((wchar_t *)p);
	if (sp->prec != -1)
		precise_wstr(&w, sp);
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

void	precise_wstr(w_str *w, t_spec *sp)
{
	int		i;
	int		s;
	wchar_t	*tmp;

	i = 0;
	s = 0;
	tmp = w->n;
	w->n = (wchar_t *)malloc(sp->prec + 1);
	while ((s = s + count_bytes(tmp[i])) < sp->prec && i < w->s)
	{
		w->n[i] = tmp[i];
		i++;
	}
	w->n[i] = '\0';
	w->s = get_wlen(w->n);
	free(tmp);
}

void	put_wstr(wchar_t *wstr)
{
	int	i;

	i = -1;
	while (wstr[++i])
		put_wchar(wstr[i]);
}
