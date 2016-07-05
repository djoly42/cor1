/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 16:19:10 by tmanet            #+#    #+#             */
/*   Updated: 2016/05/17 17:28:28 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	ft_st(t_vm *vm, t_process *proc)
{
	int	arg[3];

	arg[0] = proc->ir.args[0];
	arg[1] = proc->ir.args[1];
	if (proc->ir.code_args[1] == T_IND)
		put_mem(vm, proc, proc->ir.args[1], proc->reg[proc->ir.args[0]]);
	else
		proc->reg[proc->ir.args[1]] = proc->reg[proc->ir.args[0]];
	if (vm->verbose & 4)
		ft_print_operations(proc, arg);
	proc->carry = !proc->reg[proc->ir.args[0]];
}

void	ft_sti(t_vm *vm, t_process *proc)
{
	int	sum;
	int	arg[3];

	if (proc->ir.code_args[2] == T_REG)
		arg[2] = proc->reg[proc->ir.args[2]];
	else
		arg[2] = proc->ir.args[2];
	if (proc->ir.code_args[1] == T_IND)
		arg[1] = get_mem_idx(vm, proc->pc, proc->ir.args[1]);
	else if (proc->ir.code_args[1] == T_REG)
		arg[1] = proc->reg[proc->ir.args[1]];
	else
		arg[1] = proc->ir.args[1];
	sum = arg[1] + arg[2];
	arg[0] = proc->ir.args[0];
	put_mem(vm, proc, sum, proc->reg[proc->ir.args[0]]);
	proc->carry = !proc->reg[proc->ir.args[0]];
	if (vm->verbose & 4)
		ft_print_operations(proc, arg);
}

//-255
