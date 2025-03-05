/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaegusa <ksaegusa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:37:01 by ksaegusa          #+#    #+#             */
/*   Updated: 2024/10/28 19:36:02 by ksaegusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	new = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*result;

// 	result = ft_strjoin("Hello, ", "World!");
// 	printf("Result 1: %s\n", result);
// 	free(result);
// 	result = ft_strjoin(NULL, "Only second string.");
// 	printf("Result 2: %s\n", result);
// 	free(result);
// 	result = ft_strjoin("Only first string.", NULL);
// 	printf("Result 3: %s\n", result);
// 	free(result);
// 	result = ft_strjoin(NULL, NULL);
// 	printf("Result 4: %s\n", result);
// 	return (0);
// }
