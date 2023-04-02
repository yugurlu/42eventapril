
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void	build_wall(int frame_len)
{
	int	i;

	i = 0;
	if(frame_len == 0)
		return ;
	while (i < frame_len)
	{
		printf("*");
		i++;
	}
	printf("\n");
}

int	max_frame(char **input, int y)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	j = 0;
	max = 0;
	while (input[y][j])
	{
		while (input[y][j] && input[y][j] != ' ')
		{
			j++;
			i++;
		}
		if (i > max)
			max = i;
		if (input[y][j] == ' ')
		{
			j++;
			i = 0;
		}
	}
	return (max == 0 ? 0 : max + 4);
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
	int y;
	int	j;
	int word_count;
	int	frame_len;

	if (ac != 1)
	{
		y = 1;
		while(ac > y)
		{
			i = 0;
			frame_len = max_frame(av , y);
			word_count = word_counter(av[y]);
			build_wall(frame_len);
			while (word_count && av[y][i] && frame_len)
			{
				j = 0;
				printf("* ");
				while (av[y][i] && av[y][i] != ' ')
				{
					printf("%c", av[y][i]);
					i++;
					j++;
				}
				if (j <= (frame_len - 5))
				{
					while (j < (frame_len - 3))
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
			y++;
		}
	}
}
