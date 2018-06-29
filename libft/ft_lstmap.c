/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 13:14:07 by dpetrysh          #+#    #+#             */
/*   Updated: 2017/11/18 13:14:08 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

static void	ft_dellst(t_list **alst)
{
	t_list *nextlst;

	if (alst != NULL && *alst != NULL)
	{
		while (*alst != NULL)
		{
			nextlst = (*alst)->next;
			ft_bzero((*alst)->content, (*alst)->content_size);
			free((*alst)->content);
			free(*alst);
			*alst = NULL;
			*alst = nextlst;
		}
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *firstlst;
	t_list *tmp;

	if (lst != NULL && f != NULL && (firstlst = f(lst)))
	{
		tmp = firstlst;
		lst = lst->next;
		while (lst != NULL)
		{
			if ((tmp->next = f(lst)))
				tmp = tmp->next;
			else
				ft_dellst(&firstlst);
			lst = lst->next;
		}
	}
	else
		return (NULL);
	return (firstlst);
}
