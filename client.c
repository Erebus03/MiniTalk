/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji <araji@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:38:28 by araji             #+#    #+#             */
/*   Updated: 2025/03/24 00:37:39 by araji            ###   ########.fr       */
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
			write(1, "Kill coudn't reach PId\n", 23);
			exit(1);
		}
		usleep(570);
	}
}

int	main(int ac, char *av[])
{
	pid_t		pid;
	const char	*message;
	int			i;

	if (ac != 3)
	{
		write(1, "Try:\n$> ./client PID MSG\n", 25);
		exit(1);
	}
	pid = ft_atoi(av[1]);
	if (pid == INT_MAX)
		exit(1);
	message = av[2];
	i = 0;
	while (message[i])
		send_message(pid, message[i++]);
	send_message(pid, '\0');
	return (0);
}
