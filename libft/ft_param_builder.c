/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_builder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 12:58:16 by tmanet            #+#    #+#             */
/*   Updated: 2016/01/19 13:04:31 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_param	*ft_param_builder(void)
{
	t_param	*param;

	param = (t_param*)ft_memalloc(sizeof(t_param));
	if (!param)
		return (NULL);
	param->conv = ft_conv_lister();
	param->flag = ft_flag_lister();
	return (param);
}
