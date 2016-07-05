#include "../includes/corewar.h"

void	memrev(char  *buf, size_t count)
{
	char	*r;

	r = buf + count - 1;
	while (buf < r)
	{
		*buf ^= *r;
		*r   ^= *buf;
		*buf ^= *r;
		buf++;
		r--;
	}
}
