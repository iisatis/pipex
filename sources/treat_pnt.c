/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_pnt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pflorent <pflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 16:35:44 by pflorent          #+#    #+#             */
/*   Updated: 2021/12/05 14:48:33 by pflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	*treat_base(unsigned long long unll_save, int base, char *rtn,
		int count)
{
	while (unll_save != 0)
	{
		if ((unll_save % base) < 10)
			rtn[count - 1] = (unll_save % base) + 48;
		else
			rtn[count - 1] = (unll_save % base) + 55;
		unll_save /= base;
		count--;
	}
	return (rtn);
}

char	*ft_unll_base(unsigned long long unll, int base)
{
	char				*rtn;
	unsigned long long	unll_save;
	int					count;

	rtn = 0;
	count = 0;
	unll_save = unll;
	if (unll == 0)
		return (ft_strdup("0"));
	while (unll != 0)
	{
		unll /= base;
		count++;
	}
	rtn = malloc(sizeof(char) * (count + 1));
	if (!rtn)
		return (0);
	rtn[count] = '\0';
	rtn = treat_base(unll_save, base, rtn, count);
	return (rtn);
}

static int	ft_put_pnt(char *pnt)
{
	int	count;

	count = 0;
	count += ft_put_str("0x", 2);
	count += ft_put_str(pnt, ft_strlen(pnt));
	return (count);
}

int	treat_pnt(unsigned long long unll)
{
	char	*pnt;
	int		count;

	count = 0;
	pnt = ft_unll_base(unll, 16);
	pnt = ft_str_tolower(pnt);
	count += ft_put_pnt(pnt);
	free(pnt);
	return (count);
}
