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
		if ((ch >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		usleep(50);
	}
}

int	main(int argc, char *argv[])
{
	pid_t		server_pid;
	const char	*message;
	int			i;

	if (argc != 3)
	{
		write(1, "Try:\n$> ./client PID MSG\n", 25);
		exit(1);
	}
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	i = 0;
	while (message[i])
		send_message(server_pid, message[i++]);
	send_message(server_pid, '\0');
	return (0);
}
