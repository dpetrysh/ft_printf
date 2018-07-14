/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 19:25:54 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/03/13 19:25:55 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	type_o(void *p, t_spec *sp, int big)
{
	t_num	num;

	make_tnum(&num);
	if (sp->type == 'o')
	{
		if (sp->l || sp->j)
			nbr_struct(ft_itoa_base_uns((unsigned long)p, 8, big), &num);
		else if (sp->ll)
			nbr_struct(ft_itoa_base_uns((unsigned long long)p, 8, big), &num);
		else if (sp->h)
			nbr_struct(ft_itoa_base_uns((unsigned short)p, 8, big), &num);
		else if (sp->hh)
			nbr_struct(ft_itoa_base_uns((unsigned char)p, 8, big), &num);
		else if (sp->z)
			nbr_struct(ft_itoa_base_uns((size_t)p, 8, big), &num);
		else
			nbr_struct(ft_itoa_base_uns((unsigned int)p, 8, big), &num);
	}
	else if (sp->type == 'O')
		nbr_struct(ft_itoa_base_uns((unsigned long)p, 8, big), &num);
	make_hash_o(sp, &num);
	put_together(sp, &num);
	ft_putstr(num.n);
	sp->res += num.s;
	free(num.n);
}

void	make_hash_o(t_spec *sp, t_num *num)
{
	char	*ch;
	char	*tmp;

	if (sp->hash && ft_strcmp(num->n, "0"))
	{
		ch = (char *)malloc(2);
		ch[0] = '0';
		ch[1] = '\0';
		tmp = num->n;
		num->n = str_add(&ch, num->n);
		++num->s;
		free(tmp);
	}
}
