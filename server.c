#include "minitalk.h"

static int	ft_power(int a)
{
	int	c;

	if (a == 0)
		c = 1;
	else
		c = 2;
	while (a > 1)
	{
		c *= 2;
		a--;
	}
	return (c);
}

static char	convert_to_symb(int *bits)
{
	int	a;
	int	c;

	a = 0;
	c = 0;
	while (a < 7)
	{
		c = c + (*bits - '0') * ft_power(a);
		bits++;
		a++;
	}
	return (c);
}

static void	signal_handle(int signal)
{
	static int	bits[7];
	static int	a = 0;

	if (signal == SIGUSR1)
	{
		bits[a] = '0';
	}
	else if (signal == SIGUSR2)
	{
		bits[a] = '1';
	}
	a++;
	if (a == 7)
	{
		ft_putchar_fd(convert_to_symb(bits), 1);
		a = 0;
	}
}

int	main(void)
{
	signal(SIGUSR1, signal_handle);
	signal(SIGUSR2, signal_handle);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	while (1)
		pause();
}
