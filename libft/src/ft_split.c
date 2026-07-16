/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjacinto <hjacinto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 18:16:49 by hjacinto          #+#    #+#             */
/*   Updated: 2026/05/14 18:16:49 by hjacinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c);
static int		find_word(char const *s, char c, size_t *i, size_t *start);
static void		free_all(char **arr, size_t i);

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	i;
	size_t	j;
	size_t	start;

	if (!s)
		return (NULL);
	arr = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] && find_word(s, c, &i, &start))
	{
		arr[j] = ft_substr(s, start, i - start);
		if (!arr[j])
		{
			free_all(arr, j);
			return (NULL);
		}
		j++;
	}
	arr[j] = NULL;
	return (arr);
}

static size_t	count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s && (*s == c))
			s++;
		if (*s)
		{
			count++;
			while (*s && (*s != c))
				s++;
		}
	}
	return (count);
}

static int	find_word(char const *s, char c, size_t *i, size_t *start)
{
	while (s[*i] == c && s[*i] != '\0')
		(*i)++;
	if (s[*i] != '\0')
	{
		*start = *i;
		while (s[*i] && (s[*i] != c))
			(*i)++;
		return (1);
	}
	return (0);
}

static void	free_all(char **arr, size_t i)
{
	while (i > 0)
		free(arr[--i]);
	free(arr);
}

/*
#include <stdio.h>

int	main(void)
{
	char **array = ft_split("banana_amarela_macaco", '_');

	if (!array)
		return (1);
	while (*array)
	{
		printf("%s\n", *array);
		array++;
	}
	free_all(array, 3);
	return (0);
}
*/
