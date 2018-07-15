/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_pers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 14:48:41 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/06/28 14:48:43 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	type_pers(t_spec *sp)
{
	t_num	num;

	make_tnum(&num);
	num.s = 1;
	num.n = ft_strdup("%");
	put_together(sp, &num);
	write(1, num.n, ft_strlen(num.n));
	sp->res += num.s;
	free(num.n);
}
