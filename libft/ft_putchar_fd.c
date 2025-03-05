/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enkwak <enkwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:54:21 by enkwak            #+#    #+#             */
/*   Updated: 2024/10/25 17:54:42 by enkwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

// int main()
// {
//     char test_chars[] = {'H', 'e', 'l', 'l', 'o', ' '};
//     for (size_t i = 0; i < sizeof(test_chars); i++)
//     {
//         ft_putchar_fd(test_chars[i], 1);
//     }
//     return 0;
// }