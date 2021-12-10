/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pflorent <pflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:45:13 by pflorent          #+#    #+#             */
/*   Updated: 2021/12/10 17:59:13 by pflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <sys/wait.h>
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>

void		err_display(int err);
void		clear(char **to_free);
char		**ft_split(char const *s, char c);
int			ft_strncmp(const char *s1, const char *s2, size_t len);
char		**paths_split(char *envp[]);
char		*ft_join(char const *s1, char link, char const *s2);
size_t		ft_strlen(const char *s);
#endif