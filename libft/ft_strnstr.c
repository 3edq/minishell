/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaegusa <ksaegusa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:51:17 by ksaegusa          #+#    #+#             */
/*   Updated: 2024/10/26 17:36:16 by ksaegusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!big && !little)
		return (NULL);
	if (*little == '\0')
		return ((char *)big);
	if (!big)
		return (NULL);
	i = 0;
	while (big[i] != '\0' && i < len)
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (big[i + j] == little[j] && (i + j) < len
				&& little[j] != '\0')
				j++;
			if (little[j] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
// #include <stdio.h>

// int	main(void)
// {
// 	char	str1[] = "Hello, World!";
// 	char	to_find1[] = "World";
// 	char	*result1;
// 	char	str2[] = "Hello, World!";
// 	char	to_find2[] = "World";
// 	char	*result2;
// 	char	str3[] = "Hello, World!";
// 	char	to_find3[] = "";
// 	char	*result3;

// 	result1 = ft_strnstr(str1, to_find1, 12);
// 	if (result1)
// 		printf("Test 1 passed: %s\n", result1);
// 	else
// 		printf("Test 1 failed\n");
// 	result2 = ft_strnstr(str2, to_find2, 5);
// 	if (!result2)
// 		printf("Test 2 passed: NULL\n");
// 	else
// 		printf("Test 2 failed\n");
// 	result3 = ft_strnstr(str3, to_find3, 12);
// 	if (result3)
// 		printf("Test 3 passed: %s\n", result3);
// 	else
// 		printf("Test 3 failed\n");
// 	return (0);
// }
