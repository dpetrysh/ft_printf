/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 13:29:00 by dpetrysh          #+#    #+#             */
/*   Updated: 2017/11/14 13:29:01 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_sizeofnum(int n)
{
	int size;

	size = 1;
	if (n > 0)
		while (n > 9)
		{
			n = n / 10;
			size++;
		}
	if (n < 0)
	{
		while (n != 0)
		{
			n = n / 10;
			size++;
		}
	}
	return (size);
}

char		*ft_itoa(int n)
{
	int		i;
	char	*ch;

	i = ft_sizeofnum(n);
	ch = (char *)malloc(sizeof(char) * (ft_sizeofnum(n) + 1));
	if (ch == NULL)
		return (NULL);
	ch[i] = '\0';
	if (n >= 0)
		while (i-- > 0)
		{
			ch[i] = n % 10 + '0';
			n = n / 10;
		}
	else
	{
		while (i-- > 1)
		{
			ch[i] = -(n % 10) + '0';
			n = n / 10;
		}
		ch[0] = '-';
	}
	return (ch);
}
