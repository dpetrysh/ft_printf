/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sign_maker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 12:17:33 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/03/21 12:17:35 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	make_sign(t_spec *sp, t_num *num)
{
	if (num->m)
		make_minus(num);
	else if (sp->plus)
		make_plus(num);
	else if (sp->space && sp->type != '%' && sp->type != 'c')
		make_inv_plus(num);
	//else if (sp->zero && !sp->plus && !sp->minus && sp->prec == -1)
		//make_more_zero(num);
}

void	make_minus(t_num *num)
{
	char	*sign;
	char	*tmp;

	sign = (char *)malloc(sizeof(char) * 2);
	sign[0] = '-';
	sign[1] = '\0';
	tmp = num->n;
	num->n = str_add(&sign, num->n);
	free(tmp);
	num->s++;
}

void	make_plus(t_num *num)
{
	char	*sign;
	char	*tmp;

	sign = (char *)malloc(sizeof(char) * 2);
	sign[0] = '+';
	sign[1] = '\0';
	tmp = num->n;
	num->n = str_add(&sign, num->n);
	free(tmp);
	num->s++;
}

void	make_inv_plus(t_num *num)
{
	char	*sign;
	char	*tmp;

	sign = (char *)malloc(sizeof(char) * 2);
	sign[0] = ' ';
	sign[1] = '\0';
	tmp = num->n;
	num->n = str_add(&sign, num->n);
	free(tmp);
	num->s++;
}

void	make_more_zero(t_num *num)
{
	char	*sign;
	char	*tmp;

	sign = (char *)malloc(sizeof(char) * 2);
	sign[0] = '0';
	sign[1] = '\0';
	tmp = num->n;
	num->n = str_add(&sign, num->n);
	free(tmp);
	num->s++;
}