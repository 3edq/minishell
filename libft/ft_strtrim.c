/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enkwak <enkwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:02:47 by enkwak            #+#    #+#             */
/*   Updated: 2024/10/25 18:19:44 by enkwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1) != NULL)
		s1++;
	i = ft_strlen(s1);
	while (i > 0 && ft_strchr(set, s1[i]) != NULL)
		i--;
	return (ft_substr(s1, 0, i + 1));
}

// int main()
// {
//     const char *test_string = "!!Hello, World!!";
//     const char *set = "! ";
//     char *trimmed_string = ft_strtrim(test_string, set);
//     if (trimmed_string)
//     {
//         printf("Original string: '%s'\n", test_string);
//         printf("Trimmed string: '%s'\n", trimmed_string);
//         free(trimmed_string);
//     }
//     else
//     {
//         printf("Memory allocation failed.\n");
//     }
//     return 0;
// }