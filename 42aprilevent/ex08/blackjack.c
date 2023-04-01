#include <stdio.h>
#include <ctype.h>

int aces_point(char **av, int point)
{
	int i;

	i = 0;
	while (av[1][i])
	{
		if(av[1][i] == 'A')
		{
			if((point + 11) >= 21)
				point += 1;
			else
				point += 11;
		}
		i++;
	}
	return (point);
}

int get_point(char **av)
{
	int i;
	int point;

	i = 0;
	point = 0;
	while (av[1][i])
	{
		if (av[1][i] == 'J' || av[1][i] == 'Q' || av[1][i] == 'K')
			point += 10;
		else if (isdigit(av[1][i]) && av[1][i] != '1')
			point += av[1][i] - 48;
		i++;
	}
	return(point);
}

int main(int ac, char **av)
{
	int i;
	int j;
	int point;

	if(ac == 2)
	{
		point = 0;
		point += get_point(av);
		point = aces_point(av, point);
		if(point == 21)
			printf("Blackjack!");
		else
			printf("%d", point);
	}
	return (0);
}