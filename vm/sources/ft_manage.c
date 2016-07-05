/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 18:10:10 by eozdek            #+#    #+#             */
/*   Updated: 2016/05/18 12:08:51 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"


/*
   checker si cest un ".cor" return 1, sinon 0
   */

int		ft_check_args(char *av)
{
	char *str;

	//	ft_putstr(av);
	str = ft_strstr(av, ".cor");
	if (!str)
		return (0);
	if (ft_strcmp(str, ".cor\0") == 0)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/*
   fonction check si le dump et num_plr est bien un nombre
   */

int		ft_is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/*
   fonction recupere le dump et stock dans la T_vm
   */


int		ft_stock_color(t_vm *vm)
{
	vm->color = 1;
	return (1);
}

int		ft_stock_aff(t_vm *vm)
{
	vm->aff = 1;
	return (1);
}

int		ft_stock_verb(char **av, int *i, t_vm *vm)
{
	(*i)++;
	ft_putendl("av check");
	if (!av[*i] || ft_isnumber(av[*i]) == 0)
		ft_error("ARG is not a number");
	vm->verbose = vm->verbose | (ft_atoi(av[*i]) & 63);
	return (1);
}

int		ft_stock_step(char **av, int *i, t_vm *vm)
{
	(*i)++;
	if (!av[*i] || ft_isnumber(av[*i]) == 0)
		ft_error("ARG is not a number");
	vm->step = ft_atoi(av[*i]);
	if (vm->step < 1)
		ft_error("step can't be fewer than 1");
	return (1);
}

int		ft_stock_dump(char **av, int *i, t_vm *vm)
{
	(*i)++;
	if (!av[*i] || ft_isnumber(av[*i]) == 0)
		ft_error("ARG is not a number");
	vm->dump = ft_atoi(av[*i]);
	if (vm->dump < 1)
		ft_error("dump can't be fewer than 1");
	return (1);
}
/*
   fonction recupere le verbose et stock dans la T_vm
   */

int		ft_stock_verbose(char **av, int *i, t_vm *vm)
{
	(*i)++;
	if (!av[*i] || ft_is_number(av[*i]) == 0)
		ft_error("ARG is not a number");
	vm->verbose = ft_atoi(av[*i]);
	return (1);
}

/*
   Change les autre num de plr en cas de doublon
   */

void	ft_check_other_num(t_base_player bplr)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if ((i != bplr.i_plr) && (bplr.tab[bplr.i_plr] == bplr.tab[i]))
			bplr.tab[i] = bplr.tmpnum;
		i++;
	}
}
