/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaegusa <ksaegusa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:51:01 by ksaegusa          #+#    #+#             */
/*   Updated: 2024/10/26 16:29:58 by ksaegusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

// #include <stdio.h>

// int	ft_toupper(int c);

// int	main(void)
// {
// 	char	test_char1;
// 	char	test_char2;
// 	char	test_char3;
// 	char	test_char4;

// 	test_char1 = 'a';
// 	test_char2 = 'z';
// 	test_char3 = 'A';
// 	test_char4 = '1';
// 	printf("'%c' -> '%c'\n", test_char1, ft_toupper(test_char1));
// 	printf("'%c' -> '%c'\n", test_char2, ft_toupper(test_char2));
// 	printf("'%c' -> '%c'\n", test_char3, ft_toupper(test_char3));
// 	printf("'%c' -> '%c'\n", test_char4, ft_toupper(test_char4));
// 	return (0);
// }
