#include "../includes/corewar.h"

void print_magic(t_bin plr, char *buff)
{
	int	i;

	i = 0;
	(void)buff;
	// putchar('\n');
	// while (i < 4)
	// {
	// 	printf("|%x|", buff[i]);
	// 	i++;
	// }
	printf("\n%x\n", plr.magic);
}

void print_prog_name(t_bin plr)
{
	int i;

	i = 0;
	while (plr.prog_name[i])
	{
		printf("%x", plr.prog_name[i]);
		i++;
	}
	putchar('\n');
}

void print_prog_size(t_bin plr, char *buff)
{
	int i;

	i = 0;
	(void)buff;
	// while (i < 4)
	// {
	// 	printf("[%x]", buff[i]);
	// 	i++;
	// }
	printf("\n%x\n", plr.prog_size);
}

void print_comment(t_bin plr)
{
	int i;

	i = 0;
	putchar('\n');
	printf("commentaire\n");
	while (i < COMMENT_LENGTH)
	{
		printf("%X", plr.comment[i]);
		i++;
	}
	putchar('\n');
}

void print_prog(t_bin plr)
{
	int i;

	i = 0;
	printf("programme\n");
	while (i < r4oi(plr.prog_size))
	{
		printf("%0x", plr.program[i]);
		i++;
	}
	putchar('\n');
}
