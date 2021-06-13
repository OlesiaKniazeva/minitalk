#include "minitalk.h"

static void	ft_error(int i)
{
	if (i == 1)
		ft_putstr_fd("Wrong number of arguments\n", 0);
	if (i == 2)
		ft_putstr_fd("Message wasn't send, check if PID is right\n", 0);
	exit(i);
}

static int	*to_bits(int symb)
{
	int	*bits;
	int	a;

	a = 0;
	bits = NULL;
	bits = ft_calloc(sizeof(int), 7);
	while (symb)
	{
		if (symb % 2 == 0)
			bits[a] = 0;
		else
			bits[a] = 1;
		a++;
		symb /= 2;
	}
	return (bits);
}

static void	send_message(int pid, char *message)
{
	int		a;
	int		*bits;

	while (*message)
	{
		bits = to_bits(*message);
		a = 0;
		while (a < 7)
		{
			if (bits[a] == 0)
			{
				if (kill(pid, SIGUSR1) == -1)
					ft_error(2);
			}
			else if (bits[a] == 1)
			{
				if (kill(pid, SIGUSR2) == -1)
					ft_error(2);
			}
			a++;
			usleep(100);
		}
		free(bits);
		message++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*message;

	if (argc != 3)
		ft_error(1);
	pid = ft_atoi(argv[1]);
	if (pid == 0)
		ft_error(2);
	message = argv[2];
	send_message(pid, message);
	send_message(pid, "\n");
	return (0);
}
