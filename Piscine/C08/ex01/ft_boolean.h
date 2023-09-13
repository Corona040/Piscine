/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 19:19:18 by ecorona-          #+#    #+#             */
/*   Updated: 2023/09/06 19:33:57 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define SUCCESS 0
#define EVEN(nbr) (nbr + 1) % 2
#define EVEN_MSG "I have an even number of arguments."
#define ODD_MSG "I have an odd number of arguments."

typedef enum bool{FALSE, TRUE}	t_bool;
