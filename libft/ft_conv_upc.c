/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_upc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 12:43:12 by tmanet            #+#    #+#             */
/*   Updated: 2016/01/29 15:23:52 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_upc(t_str_conv *sub)
{
	wchar_t	wide;

	wide = va_arg(sub->ap, wchar_t);
	if ((sub->str_out = ft_wchartostr(wide)))
	{
		if (!(sub->size = ft_strlen(sub->str_out)))
			sub->size = 1;
	}
	else
		sub->error = 1;
	sub->plus = 0;
	sub->space = 0;
	return (sub->str_out);
}
