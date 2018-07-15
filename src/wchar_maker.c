/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar_maker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 18:22:35 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/07/15 18:22:37 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		get_wlen(wchar_t *str)
{
	int i;
	int len;

	len = 0;
	i = -1;
	while (str[++i])
		len = len + count_bytes(str[i]);
	return (len);
}

int		count_bytes(wchar_t c)
{
	if (c <= 127)
		return (1);
	else if (c <= 2047)
		return (2);
	else if (c <= 65535)
		return (3);
	else
		return (4);
}

int		put_wchar(wchar_t c)
{
	int len;

	len = count_bytes(c);
	if (len == 1)
		ft_putchar(c);
	else if (len == 2)
	{
		ft_putchar((c >> 6) | 0xC0);
		ft_putchar((c & 0x3F) | 0x80);
	}
	else if (len == 3)
	{
		ft_putchar((c >> 12) | 0xE0);
		ft_putchar(((c >> 6) & 0x3F) | 0x80);
		ft_putchar((c & 0x3F) | 0x80);
	}
	else if (len == 4)
	{
		ft_putchar((c >> 18) | 0xF0);
		ft_putchar(((c >> 12) & 0x3F) | 0x80);
		ft_putchar(((c >> 6) & 0x3F) | 0x80);
		ft_putchar((c & 0x3F) | 0x80);
	}
	return (len);
}

void	use_width_wstr(t_wstr *w, t_spec *sp)
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

void	precise_wstr(t_wstr *w, t_spec *sp)
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
