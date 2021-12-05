/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pflorent <pflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 15:24:13 by pflorent          #+#    #+#             */
/*   Updated: 2021/12/05 14:48:33 by pflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	type_chk(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
		|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}

int	treatment(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = treat_char(va_arg(args, int));
	else if (c == 's')
		count = treat_str(va_arg(args, char *));
	else if (c == 'p')
		count = treat_pnt(va_arg(args, unsigned long long));
	else if (c == 'd' || c == 'i')
		count = treat_int(va_arg(args, int));
	else if (c == 'u')
		count += treat_uint((unsigned int)va_arg(args, unsigned int));
	else if (c == 'x')
		count += treat_hexa(va_arg(args, unsigned int), 1);
	else if (c == 'X')
		count += treat_hexa(va_arg(args, unsigned int), 0);
	else if (c == '%')
		count += treat_percent();
	return (count);
}

int	treat_save(const char *save, va_list args)
{
	int			i;
	int			count;

	i = 0;
	count = 0;
	while (1)
	{
		if (!save[i])
			break ;
		else if (save[i] == '%' && save[i + 1])
		{
			i++;
			if (type_chk(save[i]))
				count += treatment(save[i], args);
			else if (save[i])
				count += ft_put_char(save[i]);
		}
		else if (save[i] != '%')
			count += ft_put_char(save[i]);
		i++;
	}
	return (count);
}

int	ft_printf(const char *input, ...)
{
	const char	*save;
	va_list		args;
	int			count;

	save = ft_strdup(input);
	count = 0;
	va_start(args, input);
	count += treat_save(save, args);
	va_end(args);
	free((char *)save);
	return (count);
}
