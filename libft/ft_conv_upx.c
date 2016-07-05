/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_upx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 13:00:15 by tmanet            #+#    #+#             */
/*   Updated: 2016/01/29 16:02:18 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_upx(t_str_conv *sub)
{
	if (ft_strequ("ll", sub->type) || (ft_strequ("j", sub->type)))
		sub->str_out = ft_ulltoa_base(va_arg(sub->ap, unsigned long long), 16,
				'A');
	else if (ft_strequ("l", sub->type))
		sub->str_out = ft_ultoa_base(va_arg(sub->ap, unsigned long), 16, 'A');
	else if (ft_strequ("z", sub->type))
		sub->str_out = ft_ultoa_base(va_arg(sub->ap, size_t), 16, 'A');
	else if (ft_strequ("hh", sub->type))
		sub->str_out = ft_uitoa_base((unsigned char)va_arg(sub->ap,
					unsigned int), 16, 'A');
	else
		sub->str_out = ft_uitoa_base(va_arg(sub->ap, unsigned int), 16, 'A');
	sub->size = ft_strlen(sub->str_out);
	sub->plus = 0;
	sub->space = 0;
	if (sub->point)
		ft_prec_modifier(sub);
	if (sub->hash)
		ft_hash_for_hex(sub, "0X");
	return (sub->str_out);
}
