/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_maker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 15:25:02 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/03/02 15:25:03 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	make_flag(char *str, t_spec *sp)
{
	int i;

	i = 0;
	if (ft_strchr(str, '-'))
		sp->minus++;
	if (ft_strchr(str, '+'))
		sp->plus++;
	if (ft_strchr(str, ' '))
		sp->space++;
	if (ft_strchr(str, '#'))
		sp->hash++;
	while (ft_strstr(str, "0"))
	{
		i = ft_strstr(str, "0") - str;
		if (i != 0 && !ft_isdigit(str[i - 1]))
			sp->zero++;
		str = str + i + 1;
	}
}

void	make_length(char *str, t_spec *sp)
{
	if (ft_strstr(str, "ll"))
		sp->ll++;
	else if (ft_strchr(str, 'l'))
		sp->l++;
	if (ft_strstr(str, "hh"))
		sp->hh++;
	else if (ft_strchr(str, 'h'))
		sp->h++;
	if (ft_strchr(str, 'j'))
		sp->j++;
	if (ft_strchr(str, 'z'))
		sp->z++;
}

void	make_width(char *str, t_spec *sp)
{
	int i;

	i = 1;
	while (str[i])
	{
		if (ft_isdigit(str[i]) && str[i] != '0' && (!ft_isdigit(str[i - 1]) || str[i - 1] == '0') && str[i - 1] != '.')
		{
			sp->width = ft_atoi(str + i);
			i = ft_strlen(str) - 2;
		}
		i++;
	}
}

void	make_precision(char *str, t_spec *sp)
{
	int i;

	i = 1;
	while (str[i])
	{
		if (str[i] == '.' && ft_isdigit(str[i + 1]))
			sp->prec = ft_atoi(str + i + 1);
		if (str[i] == '.' && !ft_isdigit(str[i + 1]))
			sp->prec = 0;
		i++;
	}
}

void	make_type(char *str, t_spec *sp)
{
	sp->type = (int)str[ft_strlen(str) - 1];
}



