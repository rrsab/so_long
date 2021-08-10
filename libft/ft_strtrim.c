#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	l;

	if (!s1)
		return (NULL);
	i = 0;
	l = 0;
	j = ft_strlen(s1);
	while (ft_strchr(set, s1[i]) && s1[i])
		i++;
	while (ft_strchr(set, s1[j - 1]) && j > i)
		j--;
	str = (char *)malloc(sizeof(char) * (j - i + 1));
	if (!str)
		return (NULL);
	while (i < j)
		str[l++] = s1[i++];
	str[l] = '\0';
	return (str);
}
