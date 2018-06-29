/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 13:10:32 by dpetrysh          #+#    #+#             */
/*   Updated: 2017/12/11 13:10:35 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"

void	change_cont(t_list **list, int fd, int *ret)
{
	char	buf[BUFF_SIZE + 1];
	char	*temp;

	ft_bzero(buf, BUFF_SIZE + 1);
	*ret = read(fd, buf, BUFF_SIZE);
	if (*ret != 0)
	{
		temp = (*list)->content;
		(*list)->content = ft_strjoin(temp, buf);
		free(temp);
	}
}

t_list	*find_list(t_list **head, int fd)
{
	t_list *temp;

	temp = *head;
	while (temp)
	{
		if (temp->content_size == (size_t)fd)
		{
			return (temp);
		}
		temp = temp->next;
	}
	ft_lstadd(head, ft_lstnew("", fd));
	return (*head);
}

int		make_content(t_list **list, int fd, char **line)
{
	int		ret;
	char	*ch;

	ret = 1;
	if (!ft_strchr((*list)->content, '\n'))
		while (!ft_strchr((*list)->content, '\n') && ret != 0)
			change_cont(list, fd, &ret);
	ch = (*list)->content;
	if (ft_strchr(ch, '\n'))
	{
		*line = ft_strsub(ch, 0, ft_strchr(ch, '\n') - ch);
		(*list)->content = ft_strdup(ft_strchr(ch, '\n') + 1);
		free(ch);
	}
	else if (ft_strlen((*list)->content) != 0)
	{
		*line = ft_strsub(ch, 0, ft_strchr(ch, '\0') - ch);
		(*list)->content = ft_memalloc(0);
		free(ch);
		return (1);
	}
	if (ret > 0 || ft_strlen((*list)->content) != 0)
		return (1);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	char			c;
	static t_list	*head;
	t_list			*temp;

	if ((read(fd, &c, 0)) == -1 || BUFF_SIZE < 1 || line == NULL)
		return (-1);
	if (!(temp = find_list(&head, fd)))
		return (-1);
	return (make_content(&temp, fd, line));
}
