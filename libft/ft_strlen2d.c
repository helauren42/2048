#include "libft.h"

int	ft_strlen2d(char **str)
{
	int	i;

	i = 0;
	if (str == NULL || str[i] == 0)
		return (0);
	while (str[i] != NULL)
		i++;
	return (i);
}
