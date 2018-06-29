/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:15:22 by dpetrysh          #+#    #+#             */
/*   Updated: 2017/11/14 11:15:24 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

static char	**clean_array(char ***ch)
{
	if ((*ch) != NULL)
	{
		while (**ch != NULL)
		{
			free(**ch);
			**ch = NULL;
			(*ch)++;
		}
		free(*ch);
		*ch = NULL;
	}
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**ch;
	char	**ch1;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(ch = (char **)malloc(sizeof(char *) * (ft_wordnum(s, c) + 1))))
		return (NULL);
	ch1 = ch;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			*ch = ft_strsub(s, i, ft_wordlen(s + i, c));
			if (*ch == NULL)
				return (clean_array(&ch1));
			ch++;
			i += ft_wordlen(s + i, c);
		}
	}
	*ch = NULL;
	return (ch - ft_wordnum(s, c));
}
