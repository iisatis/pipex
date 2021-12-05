/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pflorent <pflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 16:33:26 by pflorent          #+#    #+#             */
/*   Updated: 2021/12/05 14:48:33 by pflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}

char	*ft_str_tolower(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		s[i] = ft_tolower(s[i]);
	return (s);
}

int	treat_hexa(unsigned int uni, int lower)
{
	char	*hexa;
	int		count;

	count = 0;
	hexa = ft_unll_base((unsigned long long)uni, 16);
	if (lower == 1)
		hexa = ft_str_tolower(hexa);
	count += ft_put_str(hexa, ft_strlen(hexa));
	free(hexa);
	return (count);
}
