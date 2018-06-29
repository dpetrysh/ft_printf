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
	t_num	num;

	make_tnum(&num);
	printf("%s\n", ft_itoa_base_uns(*(intmax_t*)p, 16, 0));
}
