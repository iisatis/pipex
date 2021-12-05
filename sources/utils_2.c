/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pflorent <pflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:15:54 by pflorent          #+#    #+#             */
/*   Updated: 2021/12/05 17:16:13 by pflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dc;
	const char	*sc;

	if ((dst == src) || n == 0)
		return (dst);
	if (!dst && !src)
		return (0);
	dc = (char *)dst;
	sc = (const char *)src;
	while (n--)
		dc[n] = sc[n];
	return (dst);
}

char	*ft_strdup(const char *s)
{
	char	*rtn;
	size_t	len;

	len = ft_strlen(s) + 1;
	rtn = malloc(sizeof(char) * len);
	if (!rtn)
		return (0);
	rtn = ft_memcpy(rtn, s, len);
	return (rtn);
}
