#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	l;

	l = 0;
	while (s[l])
		l++;
	while (l >= 0)
	{
		if (s[l] == (unsigned char)c)
			return ((char *)s + l);
		l--;
	}
	return (0);
}
