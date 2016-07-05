/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_s_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 09:07:57 by ssicard           #+#    #+#             */
/*   Updated: 2016/05/17 12:49:25 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char		**ft_get_lbl(char **tab, t_champ *cmp)
{
	int		i;
	char	*end;

	i = 1;
	if ((end = ft_strchr(tab[0], ':')))
	{
		ft_add_label(cmp, ft_strsub(tab[0], 0, end - tab[0]));
		if (!tab[0][(int)end - (int)tab[0] + 1])
		{
			tab[0][0] = 0;
			while (tab[i])
			{
				tab[i - 1] = tab[i];
				tab[i] = 0;
				i++;
			}
		}
		else
			tab[0] = ft_strtrim(end + 1);
	}
	return (tab);
}

void		get_attr(int i, char **tab, t_champ *c)
{
	int		j;
	int		ret;

	j = 1;
	while (tab[j])
	{
		if (!(tab[j][0] == ',' && tab[j][1] == 0))
		{
			ret = ret_type(tab[j]);
			if (ret == T_DIR)
				get_dir(c, tab[j] + 1, i);
			else if (ret == T_IND)
				get_ind(c, tab[j]);
			else if (ret == T_REG)
				get_reg(c, tab[j] + 1);
		}
		j++;
	}
}

void		op_types_read(int i, char **tab, t_champ *c)
{
	int		j;
	int		ret;
	char	ocp;

	ocp = 0;
	j = 1;
	get_inst(i, tab, c);
	while (tab[j] && tab[j][0] != ';')
	{
		ret = ret_type(tab[j]);
		//	ft_error(ft_strjoin("Invalid parameter count for instruction line ", ft_itoa(c->line)));
		if (!(g_op_tab[i].att[j - 1] & ret))
			ft_error(ft_strjoin("Wrong attr type line ", ft_itoa(c->line)));
		ocp = (ret == T_IND) ? (ocp | (3 << (8 - j * 2))) :
			(ocp | ((char)ret << (8 - j * 2)));
		j++;
	}
	if (j - 1 != g_op_tab[i].att_num)
	{
		ft_printf("Invalid parameter count for instruction %s line %d", g_op_tab[i].name, c->line);
		ft_error("");
	}
	if (g_op_tab[i].carry)
		ft_write_bin(c, c->pos, ocp);
	get_attr(i, tab, c);
}

void		find_instr(t_champ *c, char *tmp)
{
	char	**tab;
	int		i;
	size_t	len;

	tab = ft_strsplit(ft_strreplace_char(ft_strreplace_char(tmp, 9, ' ')
				, ',', ' '), ' ');
	if (tab && tab[0] && tab[0][0])
	{
		i = 0;
		tab = ft_get_lbl(tab, c);
		len = ft_strlen(tab[0]);
		while (i < 16 && ft_strncmp(g_op_tab[i].name, tab[0], len))
			i++;
		if (tab[0] && tab[0][0] && i < 16)
			op_types_read(i, tab, c);
		else if (tab[0] && tab[0][0])
			ft_error(ft_strjoin(ft_strjoin(ft_strjoin("unknown instruction '",
								tab[0]), "' at line "), ft_itoa(c->line)));
	}
}

void		ft_print_bin(t_champ *chp)
{
	write(chp->fd_out, &chp->bin, chp->pos);
}
