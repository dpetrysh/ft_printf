/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 19:11:18 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/03/13 19:11:19 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	type_d(void *p, t_spec *sp, int big)
{
	t_num	num;

	make_tnum(&num);
	if (sp->type == 'd' || sp->type == 'i')
	{
		if (sp->l || sp->j)
			nbr_struct(ft_itoa_base((long)p, 10, big), &num);
		else if (sp->ll)
			nbr_struct(ft_itoa_base((long long)p, 10, big), &num);
		else if (sp->h)
			nbr_struct(ft_itoa_base((short)p, 10, big), &num);
		else if (sp->hh)
			nbr_struct(ft_itoa_base((char)p, 10, big), &num);
		else if (sp->z)
			nbr_struct(ft_itoa_base((size_t)p, 10, big), &num);
		else
			nbr_struct(ft_itoa_base((int)p, 10, big), &num);
	}
	else if (sp->type == 'D')
		nbr_struct(ft_itoa_base((long)p, 10, big), &num);
	put_together(sp, &num);
	write(1, num.n, ft_strlen(num.n));
	sp->res += num.s;
	free(num.n);
}
