/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:18:20 by dpetrysh          #+#    #+#             */
/*   Updated: 2017/11/08 18:18:21 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int min_dig;

	min_dig = -1;
	if (n < 0)
	{
		ft_putchar('-');
		min_dig = -(n % 10);
		if (n < -9)
			n = -(n / 10);
		else
		{
			min_dig = -1;
			n = -n;
		}
	}
	if ((n / 10) == 0)
		ft_putchar((n % 10) + '0');
	else
	{
		ft_putnbr(n / 10);
		ft_putchar((n % 10) + '0');
	}
	if (min_dig >= 0)
		ft_putchar(min_dig + '0');
}
