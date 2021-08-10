#include "libft.h"

int	ft_toupper(int s1)
{
	if ((s1 >= 97) && (s1 <= 122))
		return (s1 - 32);
	else
		return (s1);
}
