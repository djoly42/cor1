/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 12:16:43 by tmanet            #+#    #+#             */
/*   Updated: 2016/01/29 13:13:08 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_last_char(char *str, size_t size)
{
	size_t	i;

	i = size;
	while (i && str[i] && str[i] < 0 && (unsigned char)str[i] <= 192)
		i--;
	return (i);
}
