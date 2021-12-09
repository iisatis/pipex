/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pflorent <pflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:19:19 by pflorent          #+#    #+#             */
/*   Updated: 2021/12/09 15:57:18 by pflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static size_t	word_len(const char *s, char sep)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != sep)
		i++;
	return (i);
}

static size_t	words_count(char const *s, char sep)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == sep)
			i++;
		if (s[i])
		{
			count++;
			i += word_len(&s[i], sep);
		}
	}
	return (count);
}

static char	*filler(const char *src, unsigned int len)
{
	size_t	i;
	char	*dest;

	i = 0;
	dest = malloc(len + 1 * sizeof(char));
	if (!dest)
		return (NULL);
	while (src[i] && i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	**full_filler(size_t count, char **dest, char const *s, char c)
{
	size_t	n;

	n = 0;
	while (count)
	{
		while (*s && *s == (const char)c)
			s++;
		dest[n] = filler(s, word_len(s, c));
		if (!dest[n])
		{
			clear(dest);
			return (NULL);
		}
		while (*s && *s != (const char)c)
			s++;
		count--;
		n++;
	}
	dest[n] = 0;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	size_t	count;
	char	**dest;

	count = words_count(s, c);
	dest = malloc(sizeof(char *) * (count + 1));
	if (!dest)
		return (NULL);
	dest = full_filler(count, dest, s, c);
	return (dest);
}
