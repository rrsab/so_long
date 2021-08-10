#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	l;

	if (!dst || !src)
		return (0);
	l = ft_strlen(src);
	if (l < dstsize)
		ft_memcpy(dst, src, l + 1);
	else if (dstsize)
	{
		ft_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = '\0';
	}
	return (l);
}
