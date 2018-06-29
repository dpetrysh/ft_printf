/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:21:01 by dpetrysh          #+#    #+#             */
/*   Updated: 2017/11/08 18:21:02 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	size_t	i;
	void	*a;

	i = -1;
	a = malloc(sizeof(char) * size);
	if (a != NULL)
	{
		while (++i < size)
			((char *)a)[i] = 0;
		return (a);
	}
	else
		return (NULL);
}
