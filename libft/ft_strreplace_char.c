/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 18:40:00 by tmanet            #+#    #+#             */
/*   Updated: 2016/04/29 18:45:07 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strreplace_char(char *str, char from, char to)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == from)
			str[i] = to;
		i++;
	}
	return (str);
}
