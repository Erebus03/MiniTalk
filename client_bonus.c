/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji <araji@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:38:31 by araji             #+#    #+#             */
/*   Updated: 2025/03/24 00:21:23 by araji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_message(int pid, unsigned char ch)
{
	int	i;
	int	kill_ret;

	i = 7;
	while (i >= 0)
	{
		if ((ch >> i) & 1)
			kill_ret = kill(pid, SIGUSR1);
		else
			kill_ret = kill(pid, SIGUSR2);
		i--;
		if (kill_ret == -1)
		{
			write(1, "Invalid pid\n", 12);
			exit(1);
		}
		usleep(570);
	}
}

void	confirmation(int signal)
{
	if (signal == SIGUSR2)
		write(1, "Message sent seccussfully!\n", 27);
}

int	main(int ac, char **av)
{
	pid_t		pid;
	const char	*msg;
	int			i;

	signal(SIGUSR2, confirmation);
	if (ac != 3)
	{
		write(1, "Try:\n$> ./client_bonus PID MSG\n", 31);
		exit(1);
	}
	pid = ft_atoi(av[1]);
	if (pid == INT_MAX)
		exit(1);
	msg = av[2];
	i = 0;
	while (msg[i])
		send_message(pid, msg[i++]);
	send_message(pid, '\0');
	return (0);
}
