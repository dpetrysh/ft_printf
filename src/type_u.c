/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 19:26:57 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/03/13 19:26:58 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "printf.h"

void	type_u(void *p, t_spec *sp, int big)
{
	t_num num;

	make_tnum(&num);
	if (sp->type == 'u')
	{
		if (sp->l || sp->j)
			nbr_struct(ft_itoa_base_uns((unsigned long)p, 10, big), &num);
		else if (sp->ll)
			nbr_struct(ft_itoa_base_uns((unsigned long long)p, 10, big), &num);
		else if (sp->h)
			nbr_struct(ft_itoa_base_uns((unsigned short)p, 10, big), &num);
		else if (sp->hh)
			nbr_struct(ft_itoa_base_uns((unsigned char)p, 10, big), &num);
		else if (sp->z)
			nbr_struct(ft_itoa_base_uns((size_t)p, 10, big), &num);
		else
			nbr_struct(ft_itoa_base_uns((unsigned int)p, 10, big), &num);
	}
	else if (sp->type == 'U')
		nbr_struct(ft_itoa_base_uns((unsigned long)p, 10, big), &num);
	put_together(sp, &num);
	write(1, num.n, ft_strlen(num.n));
	// ft_putstr(num.n);
	sp->res += num.s;
	free(num.n);
}
