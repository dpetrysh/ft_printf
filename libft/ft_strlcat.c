/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:01:58 by dpetrysh          #+#    #+#             */
/*   Updated: 2017/11/08 17:01:59 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int		i;
	size_t	dst_s;

	i = 0;
	dst_s = ft_strlen(dst);
	while (i < (int)(dstsize - dst_s - 1) && src[i] != '\0')
	{
		dst[dst_s + i] = src[i];
		i++;
	}
	while (i < (int)(dstsize - dst_s))
	{
		dst[dst_s + i] = '\0';
		i++;
	}
	if (dst_s < dstsize)
		return (ft_strlen(src) + dst_s);
	else if (dst_s >= dstsize)
		return (ft_strlen(src) + dstsize);
	return (0);
}
