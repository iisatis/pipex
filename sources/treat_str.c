/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pflorent <pflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 15:30:46 by pflorent          #+#    #+#             */
/*   Updated: 2021/12/05 14:48:33 by pflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_put_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_put_str(char *str, int lgt)
{
	int	count;

	count = 0;
	while (str[count] && count < lgt)
		ft_put_char(str[count++]);
	return (count);
}

int	treat_percent(void)
{
	ft_put_char('%');
	return (1);
}

int	treat_str(char *s)
{
	int	count;

	count = 0;
	if (!s)
		s = "(null)";
	count += ft_put_str(s, ft_strlen(s));
	return (count);
}

int	treat_char(char c)
{
	int	count;

	count = 0;
	ft_put_char(c);
	return (count + 1);
}
