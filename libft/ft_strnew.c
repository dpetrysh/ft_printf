/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:26:09 by dpetrysh          #+#    #+#             */
/*   Updated: 2017/11/08 18:26:10 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*ch;

	i = 0;
	ch = (char *)malloc(sizeof(char) * (size + 1));
	if (ch != NULL)
	{
		while (i <= size)
		{
			ch[i] = '\0';
			i++;
		}
		return (ch);
	}
	return (NULL);
}
