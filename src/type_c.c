/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 14:11:57 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/04/26 14:11:58 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	type_c(void *p, t_spec *sp)
{
	int		c;
	t_num	num;

	c = (char)p;
	make_tnum(&num);
	if (!p || c == 0)
		put_chzero(sp, &num);
	else if (sp->type == 'c' && !sp->l)
		put_char_simp(sp, &num, c);
	else if ((sp->type == 'C' || (sp->type == 'c' && sp->l)) && MB_CUR_MAX > 1)
		sp->res += put_wchar((wchar_t)p);
	else
		put_char_simp(sp, &num, c);
}

void	put_char_simp(t_spec *sp, t_num *num, char c)
{
	num->s = 1;
	num->n = ft_chardup(c);
	put_together(sp, num);
	write(1, num->n, ft_strlen(num->n));
	// ft_putstr(num->n);
	sp->res += ft_strlen(num->n);
	free(num->n);
}

char	*ft_chardup(char c)
{
	char	*ch;

	ch = (char *)ft_memalloc(sizeof(char) * 2);
	ch[0] = c;
	ch[1] = '\0';
	return (ch); 
}

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

void	put_chzero(t_spec *sp, t_num *num)
{
	num->s = 1;

	num->n = ft_strdup("");
	put_together(sp, num);
	if (sp->minus)
	{
		ft_putchar(0);
		write(1, num->n, ft_strlen(num->n));
		// ft_putstr(num->n);
		sp->res += ft_strlen(num->n) + 1;
	}
	else
	{
		write(1, num->n, ft_strlen(num->n));
		// ft_putstr(num->n);
		ft_putchar(0);
		sp->res += ft_strlen(num->n) + 1;
	}
	free(num->n);
}


