/*

space_size

2 8 15 24 34
1 2  3  4  5

1-2 -> ((7 - 1) / 2) - 1;

2-8 -> ((19 - 1) / 2) - 1;

3-15 -> ((33 - 1) / 2) - 1;

4-24 -> ((51 - 1) / 2) - 1;


*/
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

void put_characters(int size)
{
	int i;

	printf("/");
}


int main(int ac, char **av)
{
	int size;
	int step;
	int count;
	int width;
	int curr_floor_space;
	int next_floor_space;
	int start_space_size;

	if (ac != 2 || !isdigit(av[1][0]))
		return (0);
	size = atoi(av[1]);
	count = atoi(av[1]) + 2;

	curr_floor_space = (((calc_base(size) - 1) / 2) - 1);
    next_floor_space = (((calc_base(size - 1) - 1) / 2) - 1);

	width = 3;
	while (count)
	{
		step = 0;
		while (step < width)
		{
			put_space(curr_floor_space);
			put_characters(size, step, width);
			step++;
		}
		count--;
		width += 2;
	}




}
