#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	l;
	unsigned int	i;

	if (s == 0 || f == 0)
		return (NULL);
	l = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (l + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
