/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeja-ne <jbeja-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:04:01 by jbeja-ne          #+#    #+#             */
/*   Updated: 2023/09/13 10:58:38 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BSQlib.h"

int	main(int argc, char **argv)
{
	int			i;
	t_charset	charset;
	char		**strs;

	i = 0;
	if (argc == 1)
	{
		if (init(argv[i], &strs, &charset, 1) == 0)
			solve_game(strs, charset);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			if (init(argv[i], &strs, &charset, 0) == 0)
				solve_game(strs, charset);
			if (i + 1 != argc)
				write(1, "\n", 1);
			++i;
		}
	}
	return (0);
}
