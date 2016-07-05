/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newflag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 16:10:18 by tmanet            #+#    #+#             */
/*   Updated: 2016/01/20 15:46:16 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag	*ft_newflag(t_flag *nxt, char *ptn, size_t (*f)(t_str_conv*, char*))
{
	t_flag	*flag;

	flag = (t_flag*)ft_memalloc(sizeof(t_flag));
	if (!flag)
		return (NULL);
	flag->ptn = ptn;
	flag->size = ft_strlen(ptn);
	flag->f = f;
	flag->next = nxt;
	return (flag);
}
