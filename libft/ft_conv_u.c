/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 18:53:52 by tmanet            #+#    #+#             */
/*   Updated: 2016/01/28 11:46:25 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_u(t_str_conv *sub)
{
	if (ft_strequ("ll", sub->type) || (ft_strequ("j", sub->type)))
		sub->str_out = ft_ulltoa_base(va_arg(sub->ap, unsigned long long), 10,
				'a');
	else if (ft_strequ("l", sub->type))
		sub->str_out = ft_ultoa_base(va_arg(sub->ap, unsigned long), 10, 'a');
	else if (ft_strequ("z", sub->type))
		sub->str_out = ft_ultoa_base(va_arg(sub->ap, size_t), 10, 'a');
	else if (ft_strequ("hh", sub->type))
		sub->str_out = ft_uitoa_base((unsigned char)va_arg(sub->ap,
					unsigned int),
				10, 'a');
	else
		sub->str_out = ft_uitoa_base(va_arg(sub->ap, unsigned int), 10, 'a');
	sub->size = ft_strlen(sub->str_out);
	sub->plus = 0;
	sub->space = 0;
	if (sub->point)
		ft_prec_modifier(sub);
	return (sub->str_out);
}
