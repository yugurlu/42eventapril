
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void put_space(int space_size)
{
	int i;

	i = 0;
	while (i < space_size)
	{
		printf(" ");
		i++;
	}
}

int		calc_base(int size)
{
	int floor;
	int width;
	int floor_step;

	floor = 1;
	width = 1;
	floor_step = 4;
	while (floor <= size)
	{
		width += 2 * (2 + floor);
		floor++;
		width += floor_step;
		if (floor % 2 && floor < size)
			floor_step += 2;
	}
	width -= floor_step;
	return (width);
}

void put_character(int step, int width)
{
	if(step == 1)
	{
		printf("/");
		return ;
	}
	else if (step == width)
	{
		printf("\\");
		return ;
	}
	printf("*");
}

int ft_lengt(int nb)
{
	int i = 0;
	int flag = 3;
	int sum = 0;
	while(i < nb)
	{
		sum += flag;
		flag++;
		i++;
	}
	return (sum);
}

int main(int ac, char **av)
{
	int i;
	int size;
	int step;
	int door;
	int flag;
	int count;
	int width;
	int layer;
	int door_temp;
	int door_knob;
	int door_layer;
	int curr_floor;
	int curr_floor_rows;
	int curr_floor_space;

	if (ac != 2 || !isdigit(av[1][0]))
		return (0);

	flag = 0;
	size = 3;
	width = 3;
	door_layer = 1;
	curr_floor = 1;
	count = atoi(av[1]);
	curr_floor_rows = 1;
	while (count)
	{
		layer = 1;
		curr_floor_rows = 1;
		while (curr_floor_rows <= size)
		{
			step = 1;
			curr_floor_space = ((calc_base(atoi(av[1])) - width) / 2);
			put_space(curr_floor_space);
			while(width >= step)
			{
				put_character(step, width);
				if(curr_floor == atoi(av[1]) && ((atoi(av[1]) % 2 == 0 ? 3:2) == layer - 1 || flag))
				{
					if(atoi(av[1]) == 1 || atoi(av[1]) == 2)
						door = 1;
					else if(atoi(av[1]) % 2 == 0)
						door = atoi(av[1]) - 1;
					else
						door = atoi(av[1]);
					door_temp = door;
					if(door == 1 && (width / 2) == step)
					{
						printf("|");
						step++;
					}
					else if (door > 1 && ((step * 2) + door) == width)
					{
						door_knob = 1;
						while(door)
						{
							if (atoi(av[1]) > 4 && door_knob + 1 == door_temp && (door_temp / 2) + 1 == door_layer)
								printf("$");
							else
								printf("|");
							door--;
							step++;
							door_knob++;
						}
						flag = 1;
						door_layer++;
					}
				}
				step++;
			}
			printf("\n");
			layer++;
			width += 2;
			curr_floor_rows++;
		}
		curr_floor++;
		width += 4 + 2 * ((curr_floor - 2) / 2);
		size++;
		count--;
	}
}

