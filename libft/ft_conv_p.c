/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 14:20:35 by tmanet            #+#    #+#             */
/*   Updated: 2016/01/29 16:04:26 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_p(t_str_conv *sub)
{
	sub->str_out = ft_ultoa_base(va_arg(sub->ap, unsigned long), 16, 'a');
	sub->size = ft_strlen(sub->str_out);
	sub->plus = 0;
	sub->space = 0;
	if (sub->point)
		ft_prec_modifier(sub);
	if (sub->zero && (sub->size + 2 < sub->width))
	{
		sub->width = sub->width - 2;
		ft_width_modifier(sub);
	}
	sub->str_out = ft_strjoin_clean(ft_strdup("0x"), sub->str_out);
	sub->size = ft_strlen(sub->str_out);
	return (sub->str_out);
}
