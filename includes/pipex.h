/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pflorent <pflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:45:13 by pflorent          #+#    #+#             */
/*   Updated: 2021/12/05 15:04:45 by pflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>
# include <string.h>
# include <sys/wait.h>
# include <errno.h>
# include <fcntl.h>

void		err_display(int err);
void		clear(char **to_free);
char		**ft_split(char const *s, char c);
int			ft_strncmp(const char *s1, const char *s2, size_t len);
char		**paths_split(char *envp[]);
char		*ft_join(char const *s1, char link, char const *s2);
int			ft_printf(const char *input, ...);
int			treat_save(const char *save, va_list args);
int			treatment(char c, va_list args);
int			type_chk(int c);
int			treat_char(char c);
int			treat_str(char *s);
int			treat_pnt(unsigned long long unll);
int			treat_int(int i);
int			treat_uint(unsigned int uni);
int			treat_hexa(unsigned int uni, int lower);
int			treat_percent(void);
int			ft_put_str(char *str, int lgt);
int			ft_put_char(char c);
char		*ft_str_tolower(char *s);
int			ft_tolower(int c);
char		*ft_unll_base(unsigned long long unll, int base);
char		*ft_itoa(int n);
char		*ft_uitoa(unsigned int n);
char		*ft_strdup(const char *s1);
void		*ft_memcpy(void *dst, const void *src, size_t n);
size_t		ft_strlen(const char *s);
#endif