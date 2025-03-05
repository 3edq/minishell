/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enkwak <enkwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:01:40 by enkwak            #+#    #+#             */
/*   Updated: 2024/10/28 16:18:01 by enkwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	word_count(const char *s, char c)
{
	unsigned int	count;

	count = 0;
	if (!*s)
		return (0);
	while (*s && *s == c)
		s++;
	while (*s)
	{
		if (*s == c)
		{
			count++;
			while (*s && *s == c)
				s++;
		}
		else
			s++;
	}
	if (*(s - 1) && *(s - 1) != c)
		count++;
	return (count);
}

static void	get_next_str(char **tmp, unsigned int *tmp_len, char c)
{
	*tmp += *tmp_len;
	*tmp_len = 0;
	while (**tmp && **tmp == c)
		(*tmp)++;
	while ((*tmp)[*tmp_len] && (*tmp)[*tmp_len] != c)
	{
		(*tmp_len)++;
	}
}

static char	**free_str(char **str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		free (str[i]);
		str[i] = NULL;
		i++;
	}
	free (str);
	return (NULL);
}

static char	**make_split(char **str, const char *s, char c)
{
	unsigned int	i;
	char			*tmp;
	unsigned int	tmp_len;
	unsigned int	count;

	i = 0;
	tmp = (char *)s;
	tmp_len = 0;
	count = word_count(s, c);
	while (i < count)
	{
		get_next_str(&tmp, &tmp_len, c);
		str[i] = (char *)malloc(sizeof(char) * (tmp_len + 1));
		if (!str[i])
			return (free_str(str));
		ft_strlcpy(str[i], tmp, tmp_len + 1);
		str[i][tmp_len] = '\0';
		i++;
	}
	str[i] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;

	if (!s)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!str)
		return (NULL);
	return (make_split(str, s, c));
}

// #include<stdio.h>
// int main()
// {
//     char str[] = "Hello,World!This,is,a,test.";
//     char charset[] = ",.! ";
//     char **result = ft_split(str, charset);
//     if (result) {
//         for (int i = 0; result[i]; i++) {
//             printf("Part %d: '%s'\n", i, result[i]);
//             free(result[i]);
//         }
//         free(result);
//     } else {
//         printf("Memory allocation failed\n");
//     }
// 	return 0;
// }