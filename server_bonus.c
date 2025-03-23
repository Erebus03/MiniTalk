#include "libft/libft.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	handle_signal(int signal, siginfo_t *info, void *context)
{
	static unsigned char	ch;
	static int				index;
	int						bit_received;

	(void)context;

	if (signal == SIGUSR1)
		bit_received = 1;
	else
		bit_received = 0;
	ch = (ch << 1) + bit_received;

	index++;

	if (index == 8)
	{
		if (ch == '\0')
			kill(info->si_pid, SIGUSR2);
		else
			write(1, &ch, 1);
			//ft_printf("%c", ch);
		index = 0;
		ch = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &handle_signal;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&sa.sa_mask);
	printf("%d\n", getpid());
	// make putnbr()
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
