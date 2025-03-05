/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enkwak <enkwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:11:42 by enkwak            #+#    #+#             */
/*   Updated: 2024/11/01 12:31:48 by enkwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && *(unsigned char *)s1 == *(unsigned char *)s2)
	{
		i++;
		s1++;
		s2++;
	}
	if (i == n)
		return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

// int main()
// {
// 	char str61[] ="nesugosita!!!";
//     char str62[] ="nesugosita!!!";
//     char str63[] = "nesugosita!!!";
//     printf("zisaku  : %d\n", ft_memcmp(str61, str62, 15));
//     printf("library : %d\n", memcmp(str61, str62, 15));
// 	printf("zisaku  : %d\n", ft_memcmp(str63, str61, 15));
//     printf("library : %d\n", memcmp(str63, str61, 15));
//     printf("zisaku  : %d\n", ft_memcmp("aiueo", "aiue1", 5));
//     printf("library : %d\n", memcmp("aiueo", "aiue1", 5));
//     printf("zisaku  : %d\n", ft_memcmp("aiueo", "aiueo", 5));
//     printf("library : %d\n", memcmp("aiueo", "aiueo", 5));
//     printf("zisaku  : %d\n", ft_memcmp("aiueo", "1iueo", 5));
//     printf("library : %d\n", memcmp("aiueo", "1iueo", 5));
// 	return (0);
// }