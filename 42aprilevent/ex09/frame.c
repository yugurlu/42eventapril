
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void	build_wall(int frame_len)
{
	int	i;

	i = 0;
	while (i < frame_len)
	{
		printf("*");
		i++;
	}
	printf("\n");
}

int	max_frame(char **input)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	j = 0;
	max = 0;
	while (input[1][j])
	{
		while (input[1][j] && input[1][j] != ' ')
		{
			j++;
			i++;
		}
		if (i > max)
			max = i;
		if (input[1][j] == ' ')
		{
			j++;
			i = 0;
		}
	}
	return ((max + 4));
}

int word_counter(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != ' ')
		{
			j++;
			while (str[i] && str[i] != ' ')
				i++;
		}
		else
			i++;
	}
	return (j);
}

int	main(int ac, char **av)
{
	int	i;
	int	j;
	int word_count;
	int	frame_len;

	if (ac == 2)
	{
		i = 0;
		frame_len = max_frame(av);
		word_count = word_counter(av[1]);
		build_wall(frame_len);
		while (word_count && av[1][i])
		{
			j = 0;
			printf("* ");
			while (av[1][i] && av[1][i] != ' ')
			{
				printf("%c", av[1][i]);
				i++;
				j++;
			}
			if (j < (frame_len + 1) / 2)
			{
				while ((j + 2) < (frame_len - 2))
				{
					printf(" ");
					j++;
				}
				printf("*\n");
			}
			else
				printf(" *\n");
			i++;
			word_count--;
		}
		build_wall(frame_len);
	}
}
