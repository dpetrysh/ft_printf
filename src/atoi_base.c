/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 16:32:18 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/03/08 16:32:19 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"


void	add_char(char **s1, char c)
{
	char	*ch;

	ch = (char *)malloc(sizeof(char) * 2);
	ch[0] = c;
	ch[1] = '\0';
	str_add(s1, ch);
	if (ch)
		free(ch);
}

char	*str_add(char **s1, char *s2)
{
	char *ch;

	ch = *s1;
	*s1 = ft_strjoin(*s1, s2);
	if (ch)
		free(ch);
	return (*s1);
}

char	get_chardig(int n, int big)		//big == 0 ---> small letters // big == 1 ---> big letters
{
	if (n > 9)
	{
		if (big)
			n = n - 10 + 'A';
		else
			n = n - 10 + 'a';
		return (n);
	}
	else
	{
		n = n + '0';
		return (n);
	}
}

int		get_rank(long long n, int base)
{
	int i;

	i = 1;
	if (n < 0)
		i++;
	while ((n = ABS(n / base)) != 0)
		i++;
	return (i);
}

char	*ft_itoa_base(long long n, int base, int big)
{
	int		rank;
	char	*str;

	rank = get_rank(n, base);
	str = (char *)ft_memalloc(sizeof(char) * (rank + 1));   //ft_memalloc
	if (n < 0)
		str[0] = '-';
	str[rank] = '\0';
	while (str[--rank] != '-' && rank != -1)
	{
		str[rank] = get_chardig(ABS(n % base), big);
		n = n / base;
	}
	return (str);
}
