/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_upo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 18:14:03 by tmanet            #+#    #+#             */
/*   Updated: 2016/01/29 16:06:00 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_upo(t_str_conv *sub)
{
	if (ft_strequ("ll", sub->type) || (ft_strequ("j", sub->type)))
		sub->str_out = ft_ulltoa_base(va_arg(sub->ap, unsigned long long),
				8, 'A');
	else if (ft_strequ("l", sub->type))
		sub->str_out = ft_ultoa_base(va_arg(sub->ap, unsigned long), 8, 'A');
	else if (ft_strequ("z", sub->type))
		sub->str_out = ft_ultoa_base(va_arg(sub->ap, size_t), 8, 'A');
	else if (ft_strequ("hh", sub->type))
		sub->str_out = ft_uitoa_base((unsigned int)va_arg(sub->ap,
					unsigned int), 8, 'A');
	else if (ft_strequ("h", sub->type))
		sub->str_out = ft_uitoa_base((unsigned short)va_arg(sub->ap,
					unsigned int), 8, 'A');
	else
		sub->str_out = ft_ultoa_base(va_arg(sub->ap, long), 8, 'A');
	sub->size = ft_strlen(sub->str_out);
	sub->plus = 0;
	sub->space = 0;
	if (sub->point)
		ft_prec_modifier(sub);
	if (sub->hash && sub->str_out[0] != '0')
		sub->str_out = ft_strjoin_clean(ft_strdup("0"), sub->str_out);
	sub->size = ft_strlen(sub->str_out);
	return (sub->str_out);
}
