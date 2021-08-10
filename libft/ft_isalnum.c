#include "libft.h"

int	ft_isalnum(int ch)
{
	if ((ch >= 48) && (ch <= 57))
		return (1);
	else if ((ch >= 65) && (ch <= 90))
		return (1);
	else if ((ch >= 97) && (ch <= 122))
		return (1);
	else
		return (0);
}
