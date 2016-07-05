/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 10:18:34 by tmanet            #+#    #+#             */
/*   Updated: 2016/05/17 17:55:57 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	ft_aff(t_vm *vm, t_process *proc)
{
	int arg[3];

	arg[0] = proc->ir.args[0];
	if (vm->aff)
		ft_putchar(proc->reg[proc->ir.args[0]] % 256);
	if (vm->verbose & 4)
		ft_print_operations(proc, arg);
}
