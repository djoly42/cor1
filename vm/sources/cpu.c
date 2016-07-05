/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpu.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 12:08:15 by djoly             #+#    #+#             */
/*   Updated: 2016/05/17 18:57:15 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		get_1_arg(t_process *proc)
{
	int		j;

	j = 0;
	while (j < g_op_tab[proc->ir.opcode - 1].att_num)
	{
		if (proc->ir.code_args[j] == T_REG)
			stock_reg(proc, j);
		else if (proc->ir.code_args[j] == T_DIR)
			stock_dir(proc, j);
		else if (proc->ir.code_args[j] == T_IND)
			stock_ind(proc, j);
		else
			proc->ir_error = 1;
		j++;
	}
	return (0);
}

int		decode_ir(t_process *proc)
{
	unsigned char	*ir;

	ir = proc->ir.irstr;
	if (ir[0] < 1 || ir[0] > 16)
	{
		//			printf("ERROR0");
		proc->ir_error = 1;
		//			printf(" ir0:%d  pc:%d irerror:%d ", ir[0], proc->pc, proc->ir_error);
		return (0);
	}
	proc->ir.opcode = ir[0];
	proc->ir.index = g_op_tab[proc->ir.opcode - 1].index;
	proc->pcdelta += 1;
	if (!g_op_tab[proc->ir.opcode - 1].carry)
		proc->ir.code_args[0] = g_op_tab[proc->ir.opcode - 1].att[0];
	else
	{
		if (!check_ocp(ir, &proc->ir))
		{
			proc->pcdelta = check_code(ir[1], g_op_tab[proc->ir.opcode - 1].index);
			/*proc->pcdelta = check_code(ir[1], 0) + check_code(ir[1], 2) +
			  check_code(ir[1], 4) + check_code(ir[1], 6);*/
			//proc->pc += proc->pcdelta;  // DATA[i].pc ==1 ??
			//proc->pcdelta = 0;
			proc->ir_error = 1;
			return (0);
		}
		proc->pcdelta += 1;
	}
	get_1_arg(proc);
	return (1);
}
//  FETCH IR
int		fetch_ir(t_process *tmp, unsigned char *core)
{
	int		i;
	i = 0;
	while (i < 14)
	{
		tmp->ir.irstr[i] = core[(tmp->pc + i) % MEM_SIZE];
		i++;
	}
	return(0);
}

void	run(t_vm *vm, t_process *proc)
{
	int	opcode;
	int	i;

	i = 0;
	opcode = proc->ir.irstr[0];
	if (opcode > 0 && opcode < 17)
		vm->ftab[proc->ir.irstr[0]](vm, proc);
}

int		parse_proc(t_vm *vm)
{
	t_process	*tmp;
	int		i;

	i = 0;
	tmp = vm->proc;
	//	ft_putendl("debut cycle");
	while (tmp)
	{
		//		ft_putnbrendl((int)tmp);
		//		ft_putendl("debut proc                        ");
		//		ft_putstr("                                         ");
		//		ft_putnbrendl((int)tmp->cycle_to_wait);

		if (tmp->cycle_to_wait == vm->cpu.cur_cycle) // 1520 = 1520
		{
			//			ft_putendl("\n\n__________DANS DECODE_______\n\n");
			fetch_ir(tmp, vm->core);
			//			ft_putnbrendl((int)vm->core[tmp->pc]);
			if (decode_ir(tmp))
				run(vm, tmp);
			//ft_print(vm);
		}
		if (tmp->cycle_to_wait <= vm->cpu.cur_cycle)
		{
			//			ft_putchar('b');
			ft_fetch_next(vm, tmp);
		}

		//		ft_putendl("fin while");
		tmp = tmp->next;
	}

	//ft_putendl("fin cycle");
	return (0);
}

//proc->pc += proc->pcdelta;
//proc->pcdelta = 0;

//Chooo-Chooo
int		cpu(t_vm *vm)
{
	CPU.cur_cycle = 0;

	while ((vm->cpu.cycle2die != 0) && (vm->dump != vm->cpu.cur_cycle))
	{
		CPU.cur_cycle += 1;
		if (vm->verbose & 2)
			ft_printf("It is now cycle %d\n", vm->cpu.cur_cycle);
		parse_proc(vm);
		//print_t_proc(vm);
		//ft_printf(">>%d<<", vm->cpu.cycle2die);
		if (check_cycle(vm)) // modifie cur_delta cycle2die nbchecks dans T_cpu
			break ;
		if ((vm->step) && (vm->cpu.cur_cycle % vm->step == 0))
		{
			print_core(vm);
			ft_wait();
		}
	}

	return (0);
}
