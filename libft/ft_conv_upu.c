/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_upu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 18:17:06 by tmanet            #+#    #+#             */
/*   Updated: 2016/01/27 18:11:39 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_upu(t_str_conv *sub)
{
	sub->str_out = ft_ultoa_base(va_arg(sub->ap, long), 10, 'A');
	sub->size = ft_strlen(sub->str_out);
	return (sub->str_out);
}
