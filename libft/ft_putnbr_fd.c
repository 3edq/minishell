/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enkwak <enkwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:02:13 by enkwak            #+#    #+#             */
/*   Updated: 2024/10/26 21:31:38 by enkwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		ft_putnbr_fd(147483648, fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd((n * -1), fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd((n / 10), fd);
		ft_putnbr_fd((n % 10), fd);
	}
	else
		ft_putchar_fd((n % 10) + '0', fd);
}

// int main()
// {
//     int test_numbers[] = {42, -42, 0, 12345, -6789};
//     for (size_t i = 0; i < 5; i++)
//     {
//         ft_putnbr_fd(test_numbers[i], 1);
//         ft_putchar_fd('\n', 1);
//     }
//     return 0;
// }