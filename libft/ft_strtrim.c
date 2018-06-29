/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:57:59 by dpetrysh          #+#    #+#             */
/*   Updated: 2017/11/10 17:58:00 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	int		i;
	int		start;
	int		end;
	char	*ch;

	i = 0;
	if (s == NULL)
		return (NULL);
	start = ft_strbegin(s);
	end = ft_strend(s);
	if (end < start)
		return (ft_strnew(0));
	else
		ch = ft_strsub(s, start, end - start + 1);
	if (ch == NULL)
		return (NULL);
	return (ch);
}
