/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaegusa <ksaegusa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:51:06 by ksaegusa          #+#    #+#             */
/*   Updated: 2024/10/26 16:30:07 by ksaegusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
// #include <stdio.h>

// int	ft_tolower(int c);

// int	main(void)
// {
// 	char	test_char1;
// 	char	test_char2;
// 	char	test_char3;
// 	char	test_char4;

// 	test_char1 = 'A';
// 	test_char2 = 'Z';
// 	test_char3 = 'a';
// 	test_char4 = '1';
// 	printf("'%c' -> '%c'\n", test_char1, ft_tolower(test_char1));
// 	printf("'%c' -> '%c'\n", test_char2, ft_tolower(test_char2));
// 	printf("'%c' -> '%c'\n", test_char3, ft_tolower(test_char3));
// 	printf("'%c' -> '%c'\n", test_char4, ft_tolower(test_char4));
// 	return (0);
// }
