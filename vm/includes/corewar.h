/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 16:56:52 by tmanet            #+#    #+#             */
/*   Updated: 2016/05/18 12:09:08 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include "struct_types.h"
/*# include "../../libft/libft.h"*/
# include "../../libft/ft_printf.h"
# include "op.h"
# include "process.h"
# include "reverse_octet.h"
# include "player.h"
# include "ir.h"
# include "vm_init.h"
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# define BPLR vm->bplr
# define CPU vm->cpu

struct s_cpu
{
	//int		ir; //instruction registre
	int		cur_cycle; // cycle en cours
	int		cycle_to_check;
	int		cycle2die; // cylcle to die a decrementer
						//	tout les CYCLE_DELTA OU MAX_CHECKS
	int		nbchecks; // comparer avec MAX_CHECKS

};

struct s_octet
{
	int		num_plr; // numero du dernier player a ecrire
	int		pc; // bool, pc sur loctet ou non
};

struct s_vm
{
	int				dump; //  -dump aff et exit apres nbr cycles
	int				step;
	int				aff;
	int				verbose; //  -v affiche les action
	int				color;
	t_cpu			cpu;

	unsigned char	core[MEM_SIZE];
	t_octet			data[MEM_SIZE];
	//unsigned char	pcs[MEM_SIZE];

	t_base_player	bplr;

	int				nb_proc;
	t_process		*proc;
	int				num_last_plr_live;
	int				nbr_live;
	void	(*ftab[17])(t_vm*, t_process*);
};


void			print_core(t_vm *vm);

/*
	ft_manage
*/

int				ft_check_args(char *av);
int				ft_is_number(char *str);
int				ft_stock_dump(char **av, int *i, t_vm *vm);
int				ft_stock_color(t_vm *vm);
int				ft_stock_step(char **av, int *i, t_vm *vm);
int				ft_stock_verb(char **av, int *i, t_vm *vm);
int				ft_stock_aff(t_vm *vm);
int				ft_stock_verbose(char **av, int *i, t_vm *vm);
void			ft_check_other_num(t_base_player bplr);

/*
	init
*/

t_process	*	ft_add_link(t_process *proc, int plr, int pc, t_process *father);
void			ft_init_pc(int plr, int pc, t_vm *vm, t_process *proc);
int				ft_init_lst_proc(t_vm *vm);
int				copy_plr(t_vm *vm, t_bin *plr, int i);
int				ft_init_arena(t_vm *vm);

/*
init_2
*/
int				ft_init_proc(t_bin	*plr, t_process *proc);
void			vm_init(t_vm *vm);
int				ftab_init(t_vm *vm);
void			core_zero(t_vm *vm);

/*
	ft_init_arena
*/
int				ft_init_arena(t_vm *vm);

/*
	ft_check_champion.c
*/

void			ft_open_champion(char *line, t_bin *plr);

/*
	ft_stock_champion.c
*/

void			ft_stock_program(int fd, t_bin *plr);
void			ft_stock_comment(int fd, t_bin *plr);
void			ft_stock_prog_size(int fd, char *buff, t_bin *plr);
void			ft_stock_name(int fd, t_bin *plr);
void			ft_stock_magic(int fd, char *buff, t_bin *plr);

/*
	ft_handle.c
*/

void			ft_handle_args(int ac, char **av, t_vm *vm);
int				ft_check_args(char *av);
void			ft_handle_bonus(char **av, int *i, t_vm *vm);
void			ft_mem_champs(t_base_player *player, char *av);
int				ft_stock_num_plr(char **av, int *i, t_vm *vm);

/*
	ft_memrev.c
*/

void			memrev(char  *buf, size_t count);

/*
ft_print_champion.c
*/

void			print_prog(t_bin plr);
void			print_magic(t_bin plr, char *buff);
void			print_prog_name(t_bin plr);
void			print_prog_size(t_bin plr, char *buff);
void			print_comment(t_bin plr);

/*
cpu.c
*/
int				cpu(t_vm *vm);
int				stock_types_args(t_process *proc, int i);
int				decode_ir(t_process *proc);
//int		fetch_ir(t_list_process *tmp, unsigned char *core, int pc);
int				parse_proc(t_vm *vm);


/*
ocp.c
*/
int				check_code(unsigned char ocp, int idx);
int				stock_code_args(t_ir *pir, unsigned char ocp, int u, int i);
int				j_init(int i, t_ir *pir, int *j);
int				get_args(t_process *proc, t_vm *vm);
int				check_ocp(unsigned char *ir, t_ir *pir);

/*
stock_types.c
*/

int				stock_reg(t_process *proc, int i);
int				stock_dir(t_process *proc, int i);
int				stock_ind(t_process *proc, int i);

/*
put_mem.c
*/

void			put_mem(t_vm *vm, t_process *proc, int off, int val);
void			put_memlong(t_vm *vm, t_process *proc, int val);

/*
get_mem.c
*/

int				get_mem(t_vm *vm, int idx, int off);
int		get_mem_idx(t_vm *vm, short int idx, short int off);
int				get_memlong(t_vm *vm, int idx);
int		get_memlong_idx(t_vm *vm, short int idx);

/*
ft_store.c
*/

void			ft_st(t_vm *vm, t_process *proc);
void			ft_sti(t_vm *vm, t_process *proc);

/*
ft_load.c
*/

void			ft_ld(t_vm *vm, t_process *proc);
void			ft_lld(t_vm *vm, t_process *proc);
void			ft_ldi(t_vm *vm, t_process *proc);
void			ft_lldi(t_vm *vm, t_process *proc);

/*
ft_aff.c
*/

void			ft_aff(t_vm *vm, t_process *proc);

/*
ft_b, t_process *procasic_functions.c
*/
void			ft_add(t_vm *vm, t_process *proc);
void			ft_sub(t_vm *vm, t_process *proc);
void			ft_or(t_vm *vm, t_process *proc);
void			ft_xor(t_vm *vm, t_process *proc);
void			ft_and(t_vm *vm, t_process *proc);


void			ft_zjmp(t_vm *vm, t_process *proc);
void			ft_fork(t_vm *vm, t_process *proc);
void			ft_lfork(t_vm *vm, t_process *proc);

void			ft_live(t_vm *vm, t_process *proc);

/*
ft_fetch_next.c
*/
void			ft_fetch_next(t_vm *vm, t_process *proc);

void			ft_print(t_vm *vm);
int				check_cycle(t_vm *vm);

void	print_t_proc(t_vm *vm);

/*
ft_wait
*/
int				ft_wait(void);
int			to_kill_or_not_to_kill_proc(t_vm *vm);

void		ft_print_operations(t_process *proc, int arg[3]);

void		ft_print_header(t_vm *vm);
#endif
