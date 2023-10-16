#include <stdio.h>
#include <stdlib.h>
#include <string.h>
size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}
char	*ft_strdup(const char *s)
{
	char	*result;
	int		pos;

	pos = ft_strlen(s);
	result = (char *)malloc((pos + 1) * sizeof(char));
	if (!result)
		return (0);
	pos = 0;
	while (s[pos] != '\0')
	{
		result[pos] = s[pos];
		pos++;
	}
	result[pos] = '\0';
	return (result);
}
static int	ft_stringcount(char *str, char sep)
{
	int	i;
	int	counter;
	int	new_string;
	int	inside_quotes;

	inside_quotes = 0;
	new_string = 1;
	counter = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == sep)
			new_string = 1;
		else
		{
			if (new_string == 1)
			{
				counter++;
				new_string = 0;
			}
		}
		i++;
	}
	return (counter);
}
static char	*put_string(char *str, char charset)
{
    int		len;
    char	*string;
    int		i;

    len = 0;
    i = 0;
    while (str[len] != '\0' && *(str + len) != charset)
    {
        if (str[len] == '\'')
        {
            len++;
            while (str[len] != '\0' && str[len] != '\'')
                len++;
            if (str[len] == '\'')
                len++;  // Increment len if a closing quote is found
        }
        len++;
    }
    string = (char *)malloc(sizeof(char) * (len + 1));
    if (!string)
        return (0);
    i = 0;
    while (i < len)
    {
        if (*str == '\'')
        {
            str++;
            while (*str != '\0' && *str != '\'')
                string[i++] = *(str++);
            if (*str == '\'')
                str++;
        }
        else
            string[i++] = *(str++);
    }
    string[i] = '\0';
    return (string);
}

static char	*process_string(char **sol, char *str, char charset, int i)
{
    sol[i] = put_string(str, charset);
    if (!sol[i])
    {
        while (i >= 0)
        {
            free(sol[i]);
            i--;
        }
        free(sol);
        return (0);
    }
    return (str);
}

static char	**ft_split_aux(char **sol, char *str, char charset)
{
    int	i;
    int	new_string;

    new_string = 1;
    i = 0;
    while (*str != '\0')
    {
        if (*str == charset)
            new_string = 1;
        else
        {
            if (new_string == 1)
            {
                str = process_string(sol, str, charset, i);
                if (!str)
                    return (0);
                i++;
                new_string = 0;
            }
        }
        str++;
    }
    sol[i] = 0;
    return (sol);
}

char	**ft_split(char const *s, char c)
{
    char	**sol;
    char	*copy;

    copy = ft_strdup(s);
    if (!copy)
        return (0);
    sol = malloc(sizeof(char *) * (ft_stringcount(copy, c) + 1));
    if (!sol)
    {
        free(copy);
        return (0);
    }
    sol = ft_split_aux(sol, copy, c);
    free(copy);
    return (sol);
}

int main() {
    char cadena[] = "Hola 'que tal' estas";
    char **resultado = ft_split(cadena, ' ');

    for (int i = 0; resultado[i] != NULL; i++) {
        printf("%s\n", resultado[i]);
        free(resultado[i]); // Free each string
    }

    free(resultado); // Free the array of strings

    return 0;
}