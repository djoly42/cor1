/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_picker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 15:38:25 by tmanet            #+#    #+#             */
/*   Updated: 2016/01/13 17:49:36 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_str_picker(char *str, t_str_conv **elem)
{
	size_t		i;
	t_str_conv	*sub;

	i = 0;
	sub = *elem;
	while (str[i] && str[i] != '%')
		i++;
	sub->str_out = ft_strncpy(ft_strnew(i), str, i);
	if (!sub->str_out)
		return (0);
	sub->size = i;
	return (i);
}
