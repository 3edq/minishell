/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaegusa <ksaegusa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:53:24 by ksaegusa          #+#    #+#             */
/*   Updated: 2024/10/26 13:18:38 by ksaegusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n > 0)
	{
		*ptr = 0;
		ptr++;
		n--;
	}
}
// #include <stdio.h>

// int	main(void)
// {
// 	char str[50] = "Hello, World!";

// 	printf("Before bzero: %s\n", str);
// 	ft_bzero(str + 7, 6);
// 	printf("After bzero: %s\n", str);

// 	return (0);
// }
