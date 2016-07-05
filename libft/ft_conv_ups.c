/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_ups.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 13:55:16 by tmanet            #+#    #+#             */
/*   Updated: 2016/01/29 12:57:20 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_ups(t_str_conv *sub)
{
	wchar_t	*str;

	str = va_arg(sub->ap, wchar_t*);
	if (!str)
		sub->str_out = ft_strdup("(null)");
	while (str && *str)
	{
		sub->str_out = ft_strjoin_clean(sub->str_out, ft_wchartostr(*str));
		str++;
	}
	if (sub->str_out)
		sub->size = ft_strlen(sub->str_out);
	sub->plus = 0;
	sub->space = 0;
	if (sub->point && sub->size > sub->prec)
		sub->size = ft_last_char(sub->str_out, sub->prec);
	return (sub->str_out);
}
