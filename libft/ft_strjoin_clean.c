/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_clean.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 11:08:27 by tmanet            #+#    #+#             */
/*   Updated: 2016/01/29 11:13:57 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_clean(char *s1, char *s2)
{
	char	*ret;

	if (s1 && s2)
	{
		ret = ft_strjoin(s1, s2);
		ft_strdel(&s1);
		ft_strdel(&s2);
	}
	else if (s1)
		ret = s1;
	else
		ret = s2;
	return (ret);
}
