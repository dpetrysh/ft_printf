/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 19:26:48 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/03/13 19:26:49 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	type_x(void *p, t_spec *sp, int big)
{
	t_num	num;

	make_tnum(&num);
	if (sp->type == 'x' || sp->type == 'X')
	{
		if (sp->l || sp->j)
			nbr_struct(ft_itoa_base_uns((unsigned long)p, 16, big), &num);
		else if (sp->ll)
			nbr_struct(ft_itoa_base_uns((unsigned long long)p, 16, big), &num);
		else if (sp->h)
			nbr_struct(ft_itoa_base_uns((unsigned short)p, 16, big), &num);
		else if (sp->hh)
			nbr_struct(ft_itoa_base_uns((unsigned char)p, 16, big), &num);
		else if (sp->z)
			nbr_struct(ft_itoa_base_uns((size_t)p, 16, big), &num);
		else
			nbr_struct(ft_itoa_base_uns((unsigned int)p, 16, big), &num);
	}
	use_prec(sp, &num);
	make_hash_x(p, sp, &num);
	put_together(sp, &num);
	write(1, num.n, ft_strlen(num.n));
	sp->res += num.s;
	free(num.n);
}

void	make_hash_x(void *p, t_spec *sp, t_num *num)
{
	char	*ch;
	char	*tmp;

	if (sp->hash && (int)p != 0)
	{
		num->s += 2;
		if (sp->zero && !sp->minus)
		{
			make_zero(sp, num);
			num->s = ft_strlen(num->n) + 2;
		}
		ch = (char *)malloc(3);
		ch[0] = '0';
		if (sp->type == 'x')
			ch[1] = 'x';
		else
			ch[1] = 'X';
		ch[2] = '\0';
		tmp = num->n;
		num->n = str_add(&ch, num->n);
		free(tmp);
	}
}
