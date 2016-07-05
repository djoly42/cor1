/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 19:14:41 by ssicard           #+#    #+#             */
/*   Updated: 2016/05/09 16:41:44 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void			get_inst(int i, char **tmp, t_champ *cmp)
{
	ft_write_bin(cmp, cmp->pos, (char)g_op_tab[i].opcode);
	cmp->inst_pos = cmp->pos - 1;
	tmp++;
}

int				ret_type(char *str)
{
	if (str[0] == DIRECT_CHAR)
		return (T_DIR);
	else if (str[0] == 'r')
		return (T_REG);
	return (T_IND);
}

void			get_dir(t_champ *c, char *str, int i)
{
	union u_4o	dir;
	int			k;

	k = 3;
	if (g_op_tab[i].index)
		k = 1;
	if (str[0] == LABEL_CHAR)
	{
		ft_add_miss(c, str + 1, k + 1);
		c->pos = c->pos + k + 1;
	}
	else
	{
		dir.i = ft_atoi(str);
		while (k >= 0)
		{
			ft_write_bin(c, c->pos, dir.c[k]);
			k--;
		}
	}
}

void			get_reg(t_champ *c, char *str)
{
	int			reg;

	reg = ft_atoi(str);
	if (reg <= 0 || reg > 16)
		ft_error(ft_strjoin(ft_strjoin(ft_strjoin("Reg '", str),
						"' does not exist line "), ft_itoa(c->line)));
	ft_write_bin(c, c->pos, (char)reg);
}

void			get_ind(t_champ *c, char *str)
{
	union u_2o	ind;
	int			i;
	int			prov;

	if (str[0] == LABEL_CHAR)
	{
		ft_add_miss(c, str + 1, 2);
		c->pos = c->pos + IND_SIZE;
	}
	else
	{
		prov = ft_atoi(str);
		ind.i = (short int)(prov);
		i = 0;
		while (i < IND_SIZE)
		{
			ft_write_bin(c, c->pos, ind.c[IND_SIZE - i - 1]);
			i++;
		}
	}
}
