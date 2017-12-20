#include <unistd.h>

void 		my_putchar(char c)
{
	write(1, &c, 1);
}

int			base(int x, int y, char filler[])
{
	int		i;
	int 		j;
	int		k;
	int		n;
	int		p;
	int		r;
	int		z;
	int		w;
	char		tab[x][y];

	if (x > 0 && y > 0 && filler[4] != '\0')
	{
		if (x > 1 && y > 1)
		{
			tab[0][0] = filler[0];
			tab[x - 1][y - 1] = filler[0];
			tab[x - 1][0] = filler[1];
			tab[0][y - 1] = filler[1];
			k = 1;
			while (k < (y - 1))
			{
				tab[0][k] = filler[3];
				tab[x - 1][k] = filler[3];
				++k;
			}
			n = 1;
			while (n < (x - 1))
			{
				tab[n][0] = filler[2];
				tab[n][y - 1] = filler[2];
				++n;
			}
			p = 1;
			r = 1;
			while (p < (x - 1))
			{
				while (r < (y - 1))
				{
					tab[p][r] = filler[4];
					r++;
				}
				p++;
				r = 1;
			}
		}
		else
		{
			z = 0;
			w = 0;
			while (w < y)
			{
				while (z < x)
				{
					tab[z][w] = filler[4];
					z++;
				}
				w++;
				z = 0;
			}
		}
		i = 0;
		j = 0;
		while (j < y)
		{
			while (i < x)
			{
				my_putchar(tab[i][j]);
				i++;
			}
			j++;
			i = 0;
			my_putchar('\n');
		}
		return (0);
	}
	else
	{
		return (-1);
	}
}
