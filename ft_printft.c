/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaby <tsaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:44:58 by tsaby             #+#    #+#             */
/*   Updated: 2024/11/18 14:44:55 by tsaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

// NEED FONCTION POUR ANALYSER CE QU'IL Y A APRES LE %
// FONCTION POUR DEFINIR LES FORMATS   : %c %s %p %d %i %u %x %X %%

void	getafterpercent(va_list args, const char *format, int i, int j)
{
	return ;
}
void	getformat(void)
{
	return ;
}
int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		j;

	i = 0;
	j = 0;
	va_start(args, format);
	while (format[j])
	{
		if (format[j] == '%')
		{
			i = getafterpercent(args, format, int i, int j);
			if (i == 'c')
				i = getformat();
			else if (i == 'd')
				i = getformat();
			else if (i == 'u')
				i = getformat();
			else if (i == 's')
				i = getformat();
			else if (i == 'o')
				i = getformat();
		}
		j++;
	}
	va_end();
	return (i);
}

int	main(void)
{
	int	i;

	ft_printf("ploppp\n\n");
	printf("ploppp\n");
	return (0);
}
