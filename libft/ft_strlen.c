/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaegusa <ksaegusa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:51:28 by ksaegusa          #+#    #+#             */
/*   Updated: 2024/10/30 14:51:36 by ksaegusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
// #include <stdio.h>

// int	main(void)
// {
// 	const char	*test_str = "Hello, world!";
// 	size_t		len;

// 	len = ft_strlen(test_str);
// 	printf("Length: %zu\n", len);
// 	return (0);
// }
