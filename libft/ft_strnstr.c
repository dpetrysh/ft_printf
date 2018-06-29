/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:04:28 by dpetrysh          #+#    #+#             */
/*   Updated: 2017/11/08 18:04:28 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	while (little[i] != '\0')
		i++;
	if (i == 0)
		return ((char *)big);
	while (*big != '\0' && j < len)
	{
		i = 0;
		if (*big == little[i])
		{
			while (little[i] != '\0' && big[i] == little[i] && (j + i) < len)
				i++;
			if (little[i] == '\0')
				return ((char *)big);
		}
		big++;
		j++;
	}
	return (NULL);
}
