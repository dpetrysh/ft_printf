/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base_uns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 12:41:59 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/03/15 12:42:00 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		get_rank_uns(unsigned long long n, int base)
{
	int	i;

	i = 1;
	while ((n = ABS(n / base)) != 0)
		i++;
	return (i);
}

char	*ft_itoa_base_uns(unsigned long long n, int base, int big)
{
	int		rank;
	char	*str;

	rank = get_rank_uns(n, base);
	str = (char *)malloc(sizeof(char) * (rank + 1));
	str[rank] = '\0';
	while (--rank != -1)
	{
		str[rank] = get_chardig(ABS(n % base), big);
		n = n / base;
	}
	return (str);
}
