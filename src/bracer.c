/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bracer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 12:54:38 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/03/21 12:54:39 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	put_together(t_spec *sp, t_num *num)
{
	if (sp->prec != -1 && sp->type != 'c')
	{
		use_prec(sp, num);
		if (sp->width > num->s)
		{
			if (sp->minus)
				minus_flag_in(sp, num);
			else
				minus_flag_off(sp, num);
		}
	}
	else
	{
		if (sp->width > num->s)
		{
			if (sp->minus)
				noprec_minus_in(sp, num);
			else
				noprec_minus_off(sp, num);
		}
		else if (!is_unsigned_type(sp->type))
			make_sign(sp, num);
	}
	num->s = ft_strlen(num->n);
}

void	noprec_minus_in(t_spec *sp, t_num *num)
{
	make_sign(sp, num);
	minus_flag_in(sp, num);
}

void	noprec_minus_off(t_spec *sp, t_num *num)
{
	if (sp->zero)
	{
		make_zero(sp, num);
	}
	else
	{
		make_sign(sp, num);
		minus_flag_off(sp, num);
	}
}

void	make_zero(t_spec *sp, t_num *num)
{
	int		i;
	int		j;
	char	*tmp;

	i = -1;
	j = 0;
	tmp = num->n;
	if ((sp->plus || num->m))
		sp->width--;
	num->n = (char *)malloc(sizeof(char) * (sp->width + 1));
	while (++i < (sp->width - num->s))
		num->n[i] = '0';
	while (i < sp->width)
		num->n[i++] = tmp[j++];
	num->n[i] = '\0';
	make_sign(sp, num);
	free(tmp);
}

void	minus_flag_in(t_spec *sp, t_num *num)
{
	int i;
	char *tmp;

	i = -1;
	tmp = num->n;
	num->n = (char *)malloc(sizeof(char) * (sp->width + 1));
	while (++i < num->s && tmp[i])
		num->n[i] = tmp[i];
	while (i < sp->width)
		num->n[i++] = ' ';
	num->n[i] = '\0';
	free(tmp);
}

void	minus_flag_off(t_spec *sp, t_num *num)
{
	int		i;
	int		j;
	char	*tmp;

	i = -1;
	tmp = num->n;
	num->n = (char *)malloc(sizeof(char) * sp->width + 1);
	while (++i < (sp->width - num->s))
		num->n[i] = ' ';
	j = -1;
	while (i < sp->width && tmp[++j])
		num->n[i++] = tmp[j];
	num->n[i] = '\0';
	free(tmp);
}




