/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:03:59 by dpetrysh          #+#    #+#             */
/*   Updated: 2017/11/08 18:04:00 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *big, const char *little)
{
	int		i;

	i = 0;
	while (little[i] != '\0')
		i++;
	if (i == 0)
		return ((char *)big);
	while (*big != '\0')
	{
		i = 0;
		if (*big == little[i])
		{
			while (little[i] != '\0' && big[i] == little[i])
				i++;
			if (little[i] == '\0')
				return ((char *)big);
		}
		big++;
	}
	return (NULL);
}
