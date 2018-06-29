/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 18:47:01 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/03/01 18:47:03 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_flag(char c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '#' | c == '0')
		return (1);
	return (0);
}

int		is_length(char c)
{
	if (c == 'l' || c == 'h' || c == 'j' || c == 'z')
		return (1);
	return (0);
}

int		is_type(char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' ||
		c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U' ||
		c == 'x' || c == 'X' || c == 'c' || c == 'C')
		return (1);
	return (0);
}

int		is_unsigned_type(char c)
{
	if (c == 'o' || c == 'O' || c == 'x' || c == 'X' ||
		c == 'u' || c == 'U')
		return (1);
	return (0);
}





