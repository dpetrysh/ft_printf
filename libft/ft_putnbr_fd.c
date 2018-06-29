/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:20:26 by dpetrysh          #+#    #+#             */
/*   Updated: 2017/11/08 18:20:27 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int min_dig;

	min_dig = -1;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
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
		ft_putchar_fd((n % 10) + '0', fd);
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd((n % 10) + '0', fd);
	}
	if (min_dig >= 0)
		ft_putchar_fd(min_dig + '0', fd);
}
