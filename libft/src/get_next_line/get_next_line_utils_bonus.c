#include "libft.h"

size_t	line_length(char const *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len] && s[len] != '\n')
		len++;
	if (s[len] == '\n')
		len++;
	return (len);
}

int	has_newline(char const *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static void	str_copy(char *str, char const *s, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
}

char	*join_buffer(char *s1, char const *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;

	if (!s2)
		return (NULL);
	len1 = line_length(s1);
	len2 = line_length(s2);
	str = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!str)
		return (free(s1), NULL);
	if (s1)
		str_copy(str, s1, len1);
	str_copy(str + len1, s2, len2);
	str[len1 + len2] = '\0';
	free(s1);
	return (str);
}

void	update_buffer(char *buffer)
{
	size_t	i;
	size_t	j;

	i = line_length(buffer);
	j = 0;
	while (buffer[i])
		buffer[j++] = buffer[i++];
	buffer[j] = '\0';
}
