/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_upd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 17:40:58 by tmanet            #+#    #+#             */
/*   Updated: 2016/01/27 18:10:55 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_upd(t_str_conv *sub)
{
	sub->str_out = ft_ltoa_base(va_arg(sub->ap, long), 10);
	sub->size = ft_strlen(sub->str_out);
	return (sub->str_out);
}
