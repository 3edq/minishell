/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaegusa <ksaegusa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:18:17 by ksaegusa          #+#    #+#             */
/*   Updated: 2024/10/30 15:51:34 by ksaegusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	free_all(char **res, size_t i)
{
	while (i > 0)
		free(res[--i]);
	free(res);
}

static size_t	count_words(char const *s, char c)
{
	size_t	count;

	if (!s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static char	**allocate_words(char const *s, char c, char **res, size_t wc)
{
	size_t	i;
	size_t	word_length;
	size_t	j;

	i = 0;
	while (i < wc)
	{
		while (*s == c)
			s++;
		word_length = 0;
		while (s[word_length] && s[word_length] != c)
			word_length++;
		res[i] = (char *)malloc(word_length + 1);
		if (!res[i])
			return (free_all(res, i), NULL);
		j = 0;
		while (j < word_length)
		{
			res[i][j] = s[j];
			j++;
		}
		res[i++][word_length] = '\0';
		s += word_length;
	}
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	wc;

	if (!s)
		return (NULL);
	wc = count_words(s, c);
	if (wc == 0)
	{
		res = (char **)malloc(sizeof(char *));
		if (!res)
			return (NULL);
		res[0] = NULL;
		return (res);
	}
	res = (char **)malloc((wc + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	if (!allocate_words(s, c, res, wc))
		return (NULL);
	res[wc] = NULL;
	return (res);
}
// #include <stdio.h>
// #include <stdlib.h>

// void	print_split_result(char **result)
// {
// 	int	i;

// 	i = 0;
// 	if (result == NULL)
// 	{
// 		printf("Result: NULL\n");
// 		return ;
// 	}
// 	while (result[i] != NULL)
// 	{
// 		printf("Result[%d]: \"%s\"\n", i, result[i]);
// 		i++;
// 	}
// }

// void	free_split_result(char **result)
// {
// 	int	i;

// 	i = 0;
// 	while (result[i] != NULL)
// 	{
// 		free(result[i]);
// 		i++;
// 	}
// 	free(result);
// }

// int	main(void)
// {
// 	char	**result;

// 	result = ft_split("Hello World! How are you?", ' ');
// 	print_split_result(result);
// 	free_split_result(result);
// 	return (0);
// }
