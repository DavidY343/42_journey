
# include "../headers/so_long.h"

int	count_char(char *str, char c)
{
	int	counter;
	int	i;

	i = 0;
	counter = 0;
	while(str && str[i])
	{
		if (str[i] == c)
			counter++;
		i++;
	}
	return (counter);
}