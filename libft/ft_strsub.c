/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:46:55 by dpetrysh          #+#    #+#             */
/*   Updated: 2017/11/10 14:46:56 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ch;
	size_t	i;

	i = 0;
	ch = (char *)malloc(sizeof(char) * (len + 1));
	if (ch != NULL && s != NULL)
	{
		while (i < len)
		{
			ch[i] = s[start + i];
			i++;
		}
		ch[i] = '\0';
		return (ch);
	}
	return (NULL);
}
