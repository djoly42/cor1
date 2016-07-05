/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 10:26:25 by tmanet            #+#    #+#             */
/*   Updated: 2016/05/17 17:45:35 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	ft_ld(t_vm *vm, t_process *proc)
{
	int	arg[3];

	arg[1] = proc->ir.args[1];
	if (proc->ir.code_args[0] == T_IND)
		arg[0] = get_mem(vm, proc->pc, proc->ir.args[0]);
	else
		arg[0] = proc->ir.args[0];
	proc->reg[arg[1]] = arg[0];
	if (vm->verbose & 4)
		ft_print_operations(proc, arg);
	proc->carry = !arg[0];
}

int	lldget_memlong(t_vm *vm, int idx)
{
	union u_4o	val;
	int			i;
	int			j;

	i = 0;
	val.i = 0;
	while (i < 2)//2
	{
		j = (idx + i) % MEM_SIZE;
		while (j < 0)
			j = j + MEM_SIZE;
		val.c[1 - i] = vm->core[j];//1
		i++;
	}
	if ((short)val.i < 0)
		val.i = (short)val.i;
	return (val.i);
}

void	ft_lld(t_vm *vm, t_process *proc)
{
	int	arg[3];

	arg[1] = proc->ir.args[1];
	if (proc->ir.code_args[0] == T_IND)
		arg[0] = lldget_memlong(vm, proc->pc + proc->ir.args[0]);
	else
		arg[0] = proc->ir.args[0];
	proc->reg[arg[1]] = arg[0];
	if (vm->verbose & 4)
		ft_print_operations(proc, arg);
	proc->carry = !arg[0];
}

void	ft_ldi(t_vm *vm, t_process *proc)
{
	int			val;
	int	arg[3];

	arg[2] = proc->ir.args[2];
	if (proc->ir.code_args[0] == T_IND)
		arg[0] = get_mem_idx(vm, proc->pc, proc->ir.args[0]);
	else if (proc->ir.code_args[0] == T_REG)
		arg[0] = proc->reg[proc->ir.args[0]];
	else
		arg[0] = proc->ir.args[0];
	if (proc->ir.code_args[1] == T_REG)
		arg[1] = proc->reg[proc->ir.args[1]];
	else
		arg[1] = proc->ir.args[1];
	val = get_mem(vm, proc->pc, arg[0] + arg[1]);
	proc->reg[proc->ir.args[2]] = val;
	if (vm->verbose & 4)
		ft_print_operations(proc, arg);
	proc->carry = !val;
}

void	ft_lldi(t_vm *vm, t_process *proc)
{
	int	val;
	int	arg[3];

	arg[2] = proc->ir.args[2];
	if (proc->ir.code_args[0] == T_IND)
		arg[0] = get_mem_idx(vm, proc->pc, proc->ir.args[0]); // lldi avec un int plus grand que max short int ? zaz
	else if (proc->ir.code_args[0] == T_REG)
		arg[0] = proc->reg[proc->ir.args[0]];
	else
		arg[0] = proc->ir.args[0];
	if (proc->ir.code_args[1] == T_REG)
		arg[1] = proc->reg[proc->ir.args[1]];
	else
		arg[1] = proc->ir.args[1];
	val = get_memlong(vm, proc->pc + arg[0] + arg[1]);
	proc->reg[proc->ir.args[2]] = val;
	if (vm->verbose & 4)
		ft_print_operations(proc, arg);
	proc->carry = !val;
}
