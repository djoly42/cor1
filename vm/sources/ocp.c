#include "../includes/corewar.h"

int		check_code(unsigned char ocp, int idx)
{
	int	decal;
	int	ret;
	int	arg;

	ret = 0;
	decal = 0;
	while (decal < 8)
	{
		arg =  (ocp >> decal) & 3;
		if (arg == DIR_CODE && !idx)
			ret = ret + 4;
		else if (arg == REG_CODE)
			ret = ret + (arg != 0);
		else
			ret = ret + (arg != 0) * 2;
		decal = decal + 2;
	}
	return (ret);
}
/*
   int 	get_args(t_process *proc, t_vm *vm)
   {
   int i;
   int j;

   i = 0;
   j = 2;
   while (i < 3)
   {
//j_init(i, ir, &j);
if (proc->ir.code_args[i] == 0x02)
{
stock_dir(&proc->ir, i, j);
j += 4;
}
else if (proc->ir.code_args[i] == 0x03)
{
stock_ind(proc, vm, i, j);
j += 2;
}
// else if (pir->code_args[i] == 0x04)
// {
// 	stock_reg();
// }
i++;
}
return (0);
}
*/
int		check_code2(unsigned char *ir, int j)
{
	int	i;

	i = (ir[1] >> (6 - (2 * j))) & 3;
	if (i == 3)
		i = 4;
	if (i & g_op_tab[ir[0] - 1].att[j])
	{
		return (i);
	}
	return(0);
}


int		check_ocp(unsigned char *ir, t_ir *pir)
{
	int		ret;
	int	j;

	j = 0;
	ret = 1;
	while (j < 4 && ret)
	{
		if (j < g_op_tab[ir[0] - 1].att_num)
		{
			if ((ret = check_code2(ir, j)))
				pir->code_args[j] = ret;  // STOCK T_REG T_IND TDIR
		}
		else
			ret = !(ir[1] >> (6 - (2 * j)) & 3);
		j++;
	}
	return (ret);
}
