/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pflorent <pflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:29:00 by pflorent          #+#    #+#             */
/*   Updated: 2021/12/05 14:48:33 by pflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	err_display(int err)
{
	if (err == 1)
		ft_printf("Error, correct usage: ./pipex file1 cmd1 cmd2 file2\n");
	else if (err == 2)
		ft_printf("Error, something went wrong");
	else if (err == 3)
		ft_printf("Input file error");
	else if (err == 4)
		ft_printf("Output file error");
	else if (err == 5)
		ft_printf("Path error");
	exit(EXIT_FAILURE);
}

void	clear(char **to_free)
{
	int	n;

	n = 0;
	while (to_free[n])
	{
		free(to_free[n]);
		n++;
	}
	free(to_free);
}

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && ((unsigned char)s1[i] == (unsigned char)s2[i])
		&& i < len)
		i++;
	if (i == len)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	**paths_split(char *envp[])
{
	int		n;
	char	**paths;

	n = 0;
	while (envp[n])
	{
		if (!ft_strncmp(envp[n], "PATH=", 5))
		{
			paths = ft_split(envp[n] + 5, ':');
			return (paths);
		}
		n++;
	}
	return (NULL);
}

char	*ft_join(char const *s1, char link, char const *s2)
{
	char	*str;
	size_t	x;
	size_t	y;

	if (!s1 || !s2)
		return (NULL);
	str = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!str)
		return (NULL);
	x = 0;
	y = 0;
	while (s1[y])
		str[x++] = s1[y++];
	str[x++] = link;
	y = 0;
	while (s2[y])
		str[x++] = s2[y++];
	str[x] = '\0';
	return (str);
}
