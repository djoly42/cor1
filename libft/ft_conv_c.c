/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 15:47:23 by tmanet            #+#    #+#             */
/*   Updated: 2016/01/28 16:49:07 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_c(t_str_conv *sub)
{
	if (ft_strequ("l", sub->type))
		sub->str_out = ft_conv_upc(sub);
	else
	{
		sub->str_out = ft_strnew(1);
		sub->str_out[0] = (char)va_arg(sub->ap, int);
		sub->size = 1;
		sub->plus = 0;
		sub->space = 0;
	}
	return (sub->str_out);
}
