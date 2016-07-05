/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 20:08:32 by tmanet            #+#    #+#             */
/*   Updated: 2016/05/09 16:43:48 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include "libft.h"
# include "op.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "../vm/includes/reverse_octet.h"

typedef struct s_label		t_label;
typedef struct s_instr		t_instr;
typedef struct s_champ		t_champ;

struct						s_label
{
	char					*name;
	int						pos;
	int						inst_pos;
	int						att_type;
};

struct						s_champ
{
	char					*file_n;
	char					name[PROG_NAME_LENGTH];
	char					comment[COMMENT_LENGTH];
	char					bin[CHAMP_MAX_SIZE];
	int						pos;
	int						inst_pos;
	t_list					*labels;
	t_list					*miss;
	int						fd;
	int						fd_out;
	int						line;
	int						com;
};

struct						s_instr
{
	char					*name;
	char					opcode;
	int						*tab;
};

/*
** get_s_file.c
*/
char						**ft_get_lbl(char **tab, t_champ *cmp);
void						get_attr(int i, char **tab, t_champ *c);
void						op_types_read(int i, char **tab, t_champ *c);
void						find_instr(t_champ *c, char *tmp);
void						ft_print_bin(t_champ *chp);
/*
** champ.c
*/
void						ft_print_champ(t_champ *chp);
void						ft_print_magic(t_champ *c);
void						ft_print_name(t_champ *chp);
void						ft_print_bin_size(t_champ *chp);
void						ft_print_comment(t_champ *chp);
/*
** structure.c
*/
void						init_structure(t_champ *chp);
char						*epur_file_name(char *str);
/*
** label.c
*/
void						ft_find_labels(t_champ *chp);
void						ft_add_label(t_champ *chp, char *lbl);
void						ft_add_miss(t_champ *chp, char *lbl, int i);
void						check_lbl(char	*str);
/*
** get_type.c
*/
void						get_inst(int i, char **tmp, t_champ *cmp);
int							ret_type(char *str);
void						get_dir(t_champ *c, char *str, int i);
void						get_reg(t_champ *c, char *str);
void						get_ind(t_champ *c, char *str);
/*
** read.c
*/
int							check_str(t_champ *c);
void						get_str(t_champ *c, char *tmp, char *str);
char						*ft_strtrim_com(char *line);
void						read_s_file(t_champ *c, char *file);
/*
** ft_check_champ.c
*/
void						ft_check_champ(t_champ *chp);
void						ft_write_bin(t_champ *c, int pos, char ocp);
int							check_flags(t_champ *c, char **av);
#endif
