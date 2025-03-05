/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaegusa <ksaegusa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:53:01 by ksaegusa          #+#    #+#             */
/*   Updated: 2024/10/26 14:08:29 by ksaegusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
// #include <stdio.h>

// int	ft_isprint(int c);

// int	main(void)
// {
// 	printf("'z' is printable: %d\n", ft_isprint('z'));
// 	printf("'A' is printable: %d\n", ft_isprint('A'));
// 	printf("' ' is printable: %d\n", ft_isprint(' '));
// 	printf("'~' is printable: %d\n", ft_isprint('~'));
// 	printf("127 is printable: %d\n", ft_isprint(127));
// 	printf("31 is printable: %d\n", ft_isprint(31));
// 	printf("Newline is printable: %d\n", ft_isprint('\n'));
// 	return (0);
// }
