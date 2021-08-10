#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*dst;
	size_t			i;

	i = 0;
	dst = b;
	while (i < len)
	{
		dst[i] = c;
		i++;
	}
	return (dst);
}
