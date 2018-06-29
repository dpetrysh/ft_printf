/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:05:52 by dpetrysh          #+#    #+#             */
/*   Updated: 2017/11/08 18:05:53 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int i;
	int flag;
	int res;

	i = 0;
	res = 0;
	flag = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' ||
		*str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-')
	{
		flag = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (str[i] != '\0' && str[i] > 47 && str[i] < 58 && i < 20)
	{
		res = res * 10 + str[i] - '0';
		if (i == 19)
			return ((flag == -1) ? 0 : -1);
		i++;
	}
	return (res * flag);
}
