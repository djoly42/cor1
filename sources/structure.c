/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 17:20:34 by ssicard           #+#    #+#             */
/*   Updated: 2016/05/09 16:48:04 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	init_structure(t_champ *c)
{
	c->file_n = NULL;
	c->pos = 0;
	c->inst_pos = 0;
	c->labels = NULL;
	c->miss = NULL;
	c->fd = 0;
	c->fd_out = 0;
	c->line = 1;
	c->com = 0;
}

char	*epur_file_name(char *str)
{
	size_t len;

	len = ft_strlen(str);
	if (str[len - 1] == 's' && str[len - 2] == '.')
		str = ft_strsub(str, 0, len - 2);
	return (str);
}
