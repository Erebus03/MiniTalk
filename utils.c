/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji <araji@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:38:23 by araji             #+#    #+#             */
/*   Updated: 2025/03/24 00:38:39 by araji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd >= 0)
		write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd(-n, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + 48, fd);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_atoi(const char *s)
{
	int (sign), (result);
	sign = 1;
	result = 0;
	while (*s == 32 || (*s >= 9 && *s <= 13))
		s++;
	if (*s == 43 || *s == 45)
	{
		if (*s == 45)
			sign *= -1;
		s++;
	}
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (write(1, "Pid should be a number\n", 23), INT_MAX);
		result = (result * 10) + (*s - 48);
		if ((result * sign) > 4194304 || (result * sign) < -4194304)
			break ;
		s++;
	}
	if (result == 0 || (result * sign) == -1
		|| (result * sign) > 4194304 || (result * sign) < -4194304)
		return (write(1, "Invalid PId\n", 13), INT_MAX);
	return (result * sign);
}
