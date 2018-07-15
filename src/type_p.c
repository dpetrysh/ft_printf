/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 22:47:42 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/06/28 22:47:44 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	type_p(void *p, t_spec *sp)
{
	char	*tmp;
	char	*ch;
	t_num	num;

	make_tnum(&num);
	num.n = ft_itoa_base_uns((uintmax_t)p, 16, 0);
	num.s = ft_strlen(num.n);
	use_prec(sp, &num);
	if (!p && sp->width > num.s + 2 && sp->zero)
	{
		num.s += 2;
		make_zero(sp, &num);
	}
	ch = (char *)malloc(3);
	ch[0] = '0';
	ch[1] = 'x';
	ch[2] = '\0';
	tmp = num.n;
	num.n = str_add(&ch, num.n);
	num.s = ft_strlen(num.n);
	free(tmp);
	put_str_simp(sp, &num);
}
