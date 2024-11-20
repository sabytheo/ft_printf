/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaby <tsaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:44:58 by tsaby             #+#    #+#             */
/*   Updated: 2024/11/20 20:18:23 by tsaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

// NEED FONCTION POUR ANALYSER CE QU'IL Y A APRES LE %
// FONCTION POUR DEFINIR LES FORMATS   : %c %s %p %d %i %u %x %X %%

int	ft_printchar(int c, int i)
{
	i++;
	write(1, &c, 1);
	return (i);
}

int	ft_printstr(char *s, int i)
{
	if (!s)
		return (ft_printstr("(null)", i));
	while (*s)
	{
		i = ft_printchar(*s++, i);
	}
	return (i);
}
int	ft_printptr(void *ptr, int i)
{
	unsigned long	addr;
	char			*base = "0123456789abcdef";

	if (!ptr)
		return (ft_printstr("(nil)", i));
	addr = (unsigned long)ptr;
	if (addr >= 16)
		i = ft_printptr((void *)(addr / 16), i);
	i = ft_printchar(base[addr % 16], i);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		j;

	i = 0;
	j = -1;

	va_start(args, format);
	while (format[++j])
	{
		if (format[j] == '%')
		{
			j++;
			if (format[j] == 'c')
				i = ft_printchar(va_arg(args, int), i);
			if (format[j] == 's')
				i = ft_printstr(va_arg(args, char *), i);
			if (format[j] == 'p')
			{
				ft_printstr("0x", i);
				i = (ft_printptr(va_arg(args, void *), i) + 3);
			}
		}
		else
		{
			i = ft_printchar(format[j], i);
		}
	}
	va_end(args);
	return (i);
}

int	main(void)
{

	int a;
	int b;

	 a = ft_printf("my printf --> \n c: %c s: %s p: %p voila ", 'j', "ploplaguilde", 15);
	 b = printf("son printf --> \n c: %c s: %s p: %p voila ", 'j', "ploplaguilde", 15);


	printf("\nmon printf a = %i  \n  le vrai b = %i \n", a, b);
	return (0);
}
