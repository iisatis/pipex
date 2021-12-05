/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pflorent <pflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 15:26:24 by pflorent          #+#    #+#             */
/*   Updated: 2021/12/05 14:48:33 by pflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	treat_uint(unsigned int uni)
{
	char	*s;
	int		count;

	count = 0;
	s = ft_uitoa(uni);
	count += ft_put_str(s, ft_strlen(s));
	free(s);
	return (count);
}

int	treat_int(int i)
{
	char	*s;
	int		count;

	count = 0;
	s = ft_itoa(i);
	count += ft_put_str(s, ft_strlen(s));
	free(s);
	return (count);
}
