/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_modifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 10:56:40 by tmanet            #+#    #+#             */
/*   Updated: 2016/01/26 14:20:26 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_string_modifier(t_str_conv *sub)
{
	if (sub->plus)
		ft_plus_modifier(sub);
	if (sub->space)
		ft_space_modifier(sub);
	if (sub->width > sub->size)
		ft_width_modifier(sub);
}
