/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaegusa <ksaegusa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:52:57 by ksaegusa          #+#    #+#             */
/*   Updated: 2024/10/30 12:55:40 by ksaegusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr = (const unsigned char *)s;

	if (!s)
		return (NULL);
	while (n > 0)
	{
		if (*ptr == (unsigned char)c)
		{
			return ((void *)ptr);
		}
		ptr++;
		n--;
	}
	return (NULL);
}
// #include <stdio.h>

// int	main(void)
// {
// 	const char	str[] = "Hello, World!";
// 	char		ch;
// 	char		*result;

// 	ch = 'W';
// 	result = ft_memchr(str, ch, sizeof(str));
// 	if (result)
// 		printf("Character '%c' found at position: %ld\n", ch, result - str);
// 	else
// 		printf("Character '%c' not found\n", ch);
// 	return (0);
// }
