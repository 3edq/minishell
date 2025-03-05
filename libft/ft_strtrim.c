/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaegusa <ksaegusa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:09:47 by ksaegusa          #+#    #+#             */
/*   Updated: 2024/10/28 17:36:32 by ksaegusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trimmed_str;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	trimmed_str = (char *)malloc(end - start + 1);
	if (!trimmed_str)
		return (NULL);
	i = 0;
	while (start < end)
	{
		trimmed_str[i++] = s1[start++];
	}
	trimmed_str[i] = '\0';
	return (trimmed_str);
}

// #include <stdio.h>

// int	main(void)
// {
// 	const char *str = "Hello, World!";
// 	const char *set = "Hd!";
// 	char *result;

// 	result = ft_strtrim(str, set);
// 	if (result)
// 	{
// 		printf("Trimmed string: %s\n", result);
// 		free(result);
// 	}
// 	else
// 	{
// 		printf("Failed to trim\n");
// 	}
// 	return (0);
// }