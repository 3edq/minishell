/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaegusa <ksaegusa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:53:05 by ksaegusa          #+#    #+#             */
/*   Updated: 2024/10/26 14:07:40 by ksaegusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
// #include <stdio.h>

// int	main(void)
// {
// 	printf("%c is digit: %d\n", '5', ft_isdigit('5'));
// 	printf("%c is digit: %d\n", 'A', ft_isdigit('A'));
// 	printf("%c is digit: %d\n", '9', ft_isdigit('9'));
// 	printf("%c is digit: %d\n", '0', ft_isdigit('0'));
// 	printf("%c is digit: %d\n", '!', ft_isdigit('!'));
// 	printf("%d is digit: %d\n", 128, ft_isdigit(128));
// 	printf("%d is digit: %d\n", -1, ft_isdigit(-1));
// 	return (0);
// }
