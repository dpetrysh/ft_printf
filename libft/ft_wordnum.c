/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:24:20 by dpetrysh          #+#    #+#             */
/*   Updated: 2017/11/14 11:24:21 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int	ft_wordnum(char const *s, char c)
{
	int i;
	int len;

	i = 0;
	len = 0;
	if (s == NULL || !ft_strcmp(s, ""))
		return (0);
	if (s[0] != c)
		len++;
	i++;
	while (s[i] != '\0')
	{
		if (s[i - 1] == c && s[i] != c)
			len++;
		i++;
	}
	return (len);
}
