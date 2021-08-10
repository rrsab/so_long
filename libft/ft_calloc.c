#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc(count * size);
	if (!str)
		return (NULL);
	while (i < (count * size))
	{
		str[i] = 0;
		i++;
	}
	return ((void *)str);
}
