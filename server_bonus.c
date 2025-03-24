/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji <araji@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:38:42 by araji             #+#    #+#             */
/*   Updated: 2025/03/23 23:14:35 by araji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal_bns(int signal, siginfo_t *info, void *context)
{
	static unsigned char	ch;
	static int				index;
	int						bit_received;
	static pid_t			last_pid;

	if (last_pid != info->si_pid && (context || !context))
	{
		ch = 0;
		index = 0;
		last_pid = info->si_pid;
	}
	bit_received = 0;
	if (signal == SIGUSR1)
		bit_received = 1;
	ch = (ch << 1) + bit_received;
	index++;
	if (index == 8)
	{
		if (ch == '\0')
			kill(info->si_pid, SIGUSR2);
		else
			write(1, &ch, 1);
		index = 0;
		ch = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	sa.sa_sigaction = &handle_signal_bns;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&sa.sa_mask);
	pid = getpid();
	ft_putnbr_fd(pid, 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
