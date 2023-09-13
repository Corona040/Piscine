/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 19:52:06 by ecorona-          #+#    #+#             */
/*   Updated: 2023/09/05 11:12:50 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_hex(char c)
{
	char	*hex;

	hex = "0123456789abcdef";
	write(1, "\\", 1);
	if (c < 0)
	{
		write(1, "-", 1);
		c *= -1;
	}
	write(1, hex + (c / 16), 1);
	write(1, hex + (c % 16), 1);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;

	i = 0;
	while (*(str + i) != '\0')
	{
		if (*(str + i) < 32)
			write_hex(*(str + i));
		else if (*(str + i) < 127)
			write(1, str + i, 1);
		else if (*(str + i) > 127)
			write_hex(*(str + i));
		else
			write(1, "\\7f", 3);
		i++;
	}
}

int	main(void)
{
	char str[] = "Couc   á   ou\ntu vas \177bien?";

	ft_putstr_non_printable(str);
}
