/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaegusa <ksaegusa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:52:53 by ksaegusa          #+#    #+#             */
/*   Updated: 2024/10/30 12:54:30 by ksaegusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptr1 = (const unsigned char *)s1;
	const unsigned char	*ptr2 = (const unsigned char *)s2;

	if (!s1 || !s2)
		return (0);
	while (n > 0)
	{
		if (*ptr1 != *ptr2)
		{
			return (*ptr1 - *ptr2);
		}
		ptr1++;
		ptr2++;
		n--;
	}
	return (0);
}
// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	str1[] = "Hello, World!";
// 	char	str2[] = "Hello, World!";
// 	char	str3[] = "Hello, Xorld!";

// 	printf("Compare str1 and str2: %d\n", ft_memcmp(str1, str2, strlen(str1)));
// 	printf("Compare str1 and str3: %d\n", ft_memcmp(str1, str3, strlen(str1)));
// 	return (0);
// }
