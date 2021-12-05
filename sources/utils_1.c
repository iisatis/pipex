/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pflorent <pflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:15:42 by pflorent          #+#    #+#             */
/*   Updated: 2021/12/05 17:16:13 by pflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int	len_chk(long n)
{
	size_t	estim;
	int		neg;

	estim = 0;
	neg = 0;
	if (n < 0)
	{
		estim++;
		neg++;
		n = -n;
	}
	while (n >= 1)
	{
		estim++;
		n /= 10;
	}
	return (estim);
}

static char	*ft_gen(char *rtn, long nbr, int len, int neg)
{
	if (nbr != 0)
		rtn = malloc(sizeof(char) * (len + 1));
	else
		return (rtn = ft_strdup("0"));
	if (!rtn)
		return (0);
	neg = 0;
	if (nbr < 0)
	{
		neg++;
		nbr = -nbr;
	}
	rtn[len] = '\0';
	while (--len)
	{
		rtn[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (neg == 1)
		rtn[0] = '-';
	else
		rtn[0] = (nbr % 10) + '0';
	return (rtn);
}

char	*ft_uitoa(unsigned int n)
{
	int		len;
	char	*rtn;
	long	nbr;
	int		neg;

	nbr = n;
	len = len_chk(nbr);
	rtn = 0;
	neg = 0;
	rtn = ft_gen(rtn, nbr, len, neg);
	if (!rtn)
		return (0);
	return (rtn);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*rtn;
	long	nbr;
	int		neg;

	nbr = n;
	len = len_chk(nbr);
	rtn = 0;
	neg = 0;
	rtn = ft_gen(rtn, nbr, len, neg);
	if (!rtn)
		return (0);
	return (rtn);
}
