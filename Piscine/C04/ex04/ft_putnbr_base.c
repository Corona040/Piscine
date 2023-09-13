/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:53:28 by ecorona-          #+#    #+#             */
/*   Updated: 2023/09/08 11:28:48 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	check_args(char *base)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (*(base + i) != '\0')
	{
		j = 0;
		while (*(base + j) != '\0')
		{
			if (*(base + i) == *(base + j) && i != j)
				return (-1);
			j++;
		}
		if (*(base + i) == '+' || *(base + i) == '-')
			return (-1);
		i++;
	}
	if (i <= 1)
		return (0);
	return (i);
}

void	ft_printnbr(long u_nbr, char *base, int base_len)
{
	if ((u_nbr / base_len) != 0)
		ft_printnbr(u_nbr / base_len, base, base_len);
	ft_putchar(base[u_nbr % base_len]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			base_len;
	long int	u_nbr;

	base_len = check_args(base);
	u_nbr = nbr;
	if (nbr < 0 && base_len > 1)
	{
		u_nbr *= -1;
		write(1, "-", 1);
	}
	if (base_len > 1)
	{
		ft_printnbr(u_nbr, base, base_len);
	}
}

/*
int	main(void)
{
	ft_putnbr_base(-654321, "flavio");
}
*/
