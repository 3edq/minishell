/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaegusa <ksaegusa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:53:09 by ksaegusa          #+#    #+#             */
/*   Updated: 2024/10/26 14:04:38 by ksaegusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

// #include <stdio.h>

// int	ft_isascii(int c);

// int	main(void)
// {
// 	printf("'A' is ASCII: %d\n", ft_isascii('A'));
// 	printf("'z' is ASCII: %d\n", ft_isascii('z'));
// 	printf("'0' is ASCII: %d\n", ft_isascii('0'));
// 	printf("Space is ASCII: %d\n", ft_isascii(' '));
// 	printf("0 is ASCII: %d\n", ft_isascii(0));
// 	printf("127 is ASCII: %d\n", ft_isascii(127));
// 	printf("128 is ASCII: %d\n", ft_isascii(128));
// 	printf("200 is ASCII: %d\n", ft_isascii(200));
// 	printf("255 is ASCII: %d\n", ft_isascii(255));
// 	printf("-1 is ASCII: %d\n", ft_isascii(-1));
// 	printf("-100 is ASCII: %d\n", ft_isascii(-100));
// 	printf("Newline is ASCII: %d\n", ft_isascii('\n'));
// 	printf("Tab is ASCII: %d\n", ft_isascii('\t'));
// 	printf("'!' is ASCII: %d\n", ft_isascii('!'));
// 	return (0);
// }
