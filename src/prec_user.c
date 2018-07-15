/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_user.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 11:18:58 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/03/19 11:19:00 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	make_tnum(t_num *num)
{
	num->m = 0;
	num->s = 0;
	num->n = NULL;
}

int		make_specific(char **str, t_spec *sp)
{
	t_num	num;

	make_flag(*str, sp);
	make_length(*str, sp);
	make_width(*str, sp);
	make_precision(*str, sp);
	make_type(*str, sp);
	free(*str);
	*str = NULL;
	if (sp->type)
		return (1);
	else
	{
		make_tnum(&num);
		put_char_simp(sp, &num, (char)sp->other);
		return (0);
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
	if ((sp->plus || num->m || sp->space))
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

void	nbr_struct(char *str, t_num *num)
{
	int	i;

	i = 0;
	if (str[0] == '-')
	{
		num->m = 1;
		str++;
	}
	while (str[i])
		i++;
	num->s = i;
	num->n = (char *)malloc(sizeof(char) * i + 1);
	i = -1;
	while (str[++i])
		num->n[i] = str[i];
	num->n[i] = '\0';
	if (num->m)
		free(str - 1);
	else
		free(str);
}

void	use_prec(t_spec *sp, t_num *num)
{
	char	*tmp;
	int		i;

	i = -1;
	if (!sp->prec && !ft_strcmp(num->n, "0") &&
		!((sp->type == 'o' || sp->type == 'O') && sp->hash))
	{
		free(num->n);
		num->n = ft_strdup("");
		num->s = 0;
	}
	if (sp->prec > num->s)
	{
		tmp = num->n;
		num->n = (char *)malloc(sizeof(char) * sp->prec + 1);
		num->n[sp->prec] = '\0';
		while (++i < num->s)
			num->n[sp->prec - i - 1] = tmp[num->s - i - 1];
		--i;
		while (++i < sp->prec)
			num->n[sp->prec - i - 1] = '0';
		num->s = ft_strlen(num->n);
		free(tmp);
	}
	make_sign(sp, num);
}
