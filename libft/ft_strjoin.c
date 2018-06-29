/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:06:53 by dpetrysh          #+#    #+#             */
/*   Updated: 2017/11/10 17:07:00 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*ch;

	i = -1;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	ch = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (ch != NULL)
	{
		while (s1[++i] != '\0')
			ch[i] = s1[i];
		while (s2[j] != '\0')
		{
			ch[i] = s2[j];
			i++;
			j++;
		}
		ch[i] = '\0';
		return (ch);
	}
	return (NULL);
}
