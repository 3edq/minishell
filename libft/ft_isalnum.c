/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaegusa <ksaegusa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:53:17 by ksaegusa          #+#    #+#             */
/*   Updated: 2024/10/26 14:03:11 by ksaegusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a'
			&& c <= 'z'))
		return (1);
	return (0);
}
// #include <stdio.h>

// int	main(void)
// {
// 	char	test_char1;
// 	char	test_char2;
// 	char	test_char3;
// 	char	test_char4;
// 	int		test_char5;

// 	test_char1 = '5';
// 	test_char2 = 'A';
// 	test_char3 = '!';
// 	test_char4 = 'z';
// 	test_char5 = -5;
// 	printf("%c is alnum: %d\n", test_char1, ft_isalnum(test_char1));
// 	printf("%c is alnum: %d\n", test_char2, ft_isalnum(test_char2));
// 	printf("%c is alnum: %d\n", test_char3, ft_isalnum(test_char3));
// 	printf("%c is alnum: %d\n", test_char4, ft_isalnum(test_char4));
// 	printf("%d is alnum: %d\n", test_char5, ft_isalnum(test_char5));
// 	return (0);
// }
