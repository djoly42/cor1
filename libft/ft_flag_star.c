/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_star.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 14:05:37 by tmanet            #+#    #+#             */
/*   Updated: 2016/01/27 14:53:41 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_flag_star(t_str_conv *sub, char *str)
{
	int	size;

	if (str)
	{
		size = va_arg(sub->ap, int);
		if (size >= 0)
			sub->width = size;
		else
		{
			sub->width = -size;
			sub->minus = 1;
		}
	}
	return (1);
}
