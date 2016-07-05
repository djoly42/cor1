#include "../includes/corewar.h"

static void	ft_read_champion(int fd, t_bin *plr)
{
	char	*buff;
	int		ret;

if (!(buff = ft_memalloc(sizeof(char) * 4 + 1)))
	ft_error("allocation of players failed");
	ft_stock_magic(fd, buff, plr);
	ft_stock_name(fd, plr);
	if (!(ret = read(fd, buff, 4)))
		ft_error("read error at first SEPARATOR");
	if (*((int *)buff))
		ft_error("error wrong first SEPARATOR");
	ft_stock_prog_size(fd, buff, plr);
	ft_stock_comment(fd, plr);
	if (!(ret = read(fd, buff, 4)))
		ft_error("read error at second SEPARATOR");
	if (*((int *)buff))
		ft_error("error wrong second SEPARATOR");
	ft_stock_program(fd, plr);
}

void		ft_open_champion(char *line, t_bin *plr)
{
	int		fd;

	plr->magic = 0;
	plr->prog_size = 0;
	if ((fd = open(line, O_RDONLY)) == -1)
		ft_error("error open failed");
	ft_read_champion(fd, plr);
}
