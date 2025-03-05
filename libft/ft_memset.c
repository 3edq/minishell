/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaegusa <ksaegusa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:52:39 by ksaegusa          #+#    #+#             */
/*   Updated: 2024/10/30 13:26:10 by ksaegusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	if (!s)
		return (NULL);
	ptr = (unsigned char *)s;
	while (n > 0)
	{
		*ptr = (unsigned char)c;
		ptr++;
		n--;
	}
	return (s);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	str[50] = "Hello, World!";

// 	printf("Before memset: %s\n", str);
// 	ft_memset(str + 7, 'X', 5);
// 	printf("After memset: %s\n", str);
// 	return (0);
// }
