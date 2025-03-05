/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaegusa <ksaegusa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:53:13 by ksaegusa          #+#    #+#             */
/*   Updated: 2024/10/26 14:04:04 by ksaegusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}
// #include <stdio.h>

// int	ft_isalpha(int c);

// int	main(void)
// {
// 	char	test_char1;
// 	char	test_char2;
// 	char	test_char3;

// 	test_char1 = 'A';
// 	test_char2 = 'z';
// 	test_char3 = '1';
// 	printf("%c is alpha: %d\n", test_char1, ft_isalpha(test_char1));
// 	printf("%c is alpha: %d\n", test_char2, ft_isalpha(test_char2));
// 	printf("%c is alpha: %d\n", test_char3, ft_isalpha(test_char3));
// 	return (0);
// }
