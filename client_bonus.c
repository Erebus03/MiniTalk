#include "libft/libft.h"
#include <signal.h>
#include <stdio.h>
#include <string.h>

void	send_message(int pid, unsigned char ch)
{
	int				i;

	i = 7;
	while (i >= 0)
	{
		if (ch >> i & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		usleep(700);
	}
}

void	confirmation(int signal)
{
	if (signal == SIGUSR2)
		ft_printf("Message received seccussfully!\n");
}

int	main(int argc, char **argv)
{
	pid_t		pid;
	const char	*msg;
	int			i;

	signal(SIGUSR2, confirmation);
	if (argc != 3)
	{
		write(1, "Try:\n$> ./client_bonus PID MSG\n", 31);
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	msg = argv[2];
	i = 0;
	while (msg[i])
		send_message(pid, msg[i++]);
	send_message(pid, '\0');
	return (0);
}
