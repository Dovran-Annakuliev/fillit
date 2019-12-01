#include "fillit.h"

int	main(int argc, char **argv)
{
	int fd;
	char		buf[BUFF_SIZE + 1];
	int ret;
	char *tmp;
	char *tmp2;
	int len;
	int heg;
	int dve_grani;
	char **arr;
	int count;
	int x_min;
	int y_min;
	int i;
	int j;
	int smeshenie;
	int kol_resh;

	if (argc != 2 || (((fd = open(argv[1], O_RDONLY)) < 0) && (read(fd, buf, 0)) < 0))
	{
		write(1, "usage: ./fillit [file name]\n", 29);
		exit(0);
	}
	tmp = ft_strnew(0);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(tmp2 = ft_strjoin(tmp, buf)))
		{
			write(1, "error\n", 6);
			exit(0);
		}
		free(tmp);
		tmp = tmp2;
	}
	ret = 0;
	len = 0;
	count = 1;
	dve_grani = 0;
	kol_resh = 0;
	while(tmp[ret])
	{
		if (tmp[ret] == '.' || tmp[ret] == '#' || (tmp[ret] == '\n' && ((len + 1)%5 == 0))) // проверка на правильность символов
		{
			if (tmp[ret] == '#')
			{
				kol_resh++;
				if (!(tmp[ret - 1] == '#' || tmp[ret + 1] == '#' || tmp[ret - 5] == '#' || tmp[ret + 5] == '#')) // проверка на наличее соединений гранями
				{
					write(1, "error\n", 6);
					exit(0);
				}
				if ((tmp[ret - 1] == '#' && tmp[ret + 1] == '#') ||    // проверка на наличие нескольких соединений граней
					(tmp[ret - 5] == '#' && tmp[ret + 5] == '#') ||
					(tmp[ret - 5] == '#' || tmp[ret - 1] == '#') ||
					(tmp[ret - 5] == '#' || tmp[ret + 1] == '#') ||
					(tmp[ret - 1] == '#' || tmp[ret + 5] == '#') ||
					(tmp[ret + 1] == '#' || tmp[ret + 5] == '#'))
					dve_grani++;
				if (!dve_grani && tmp[ret] == '\n' && ((len + 1)%5 == 0 && tmp[ret + 1] == '\n')) // вывод ошибки по граням
				{
					write(1, "error\n", 6);
					exit(0);
				}
				if (kol_resh > 4)
				{
					write(1, "error\n", 6);
					exit(0);
				}
			}
			if (tmp[ret] == '\n' && ((len + 1)%5 == 0 && tmp[ret + 1] == '\n'))
			{
				write(1, "\n\n", 2);
				ret = ret + 2;
				len = 0;
				dve_grani = 0;
				count++;
				kol_resh = 0;
			}
			write(1, &tmp[ret], 1);
			ret++;
			len++;
		}
		else
		{
			write(1,"\n", 1);
			write(1, "error\n", 6);
			exit(0);
		}
	}
	if (count < 1 || count > 26)
	{
		write(1, "error\n", 6);
		exit(0);
	}
	ret = 0;
	heg = 0;
	write(1,"\n\n\n\n\n\n\n\n\n\n", 10);
	arr = (char**)malloc(sizeof(char*) * (count + 1)); // создание массива строк, где строки это карты с тетрамино
	while (heg != count + 1)
	{
		if (heg == count)
		{
			arr[heg] = NULL;
			ret++;
			heg++;
		}
		else
		{
			arr[heg] = (char*)malloc(sizeof(char) * 21);
			len = 0;
			while (len != 20)
			{
				if (tmp[ret] == '\n' && tmp[ret + 1] == '\n')
				{
					arr[heg][len] = '\0';
					ret++;
				}
				arr[heg][len] = tmp[ret];
				len++;
				ret++;
			}
			heg++;
		}
	}
	i = 0;
	smeshenie = 0;
	while (arr[i])
	{
		j = 0;
		heg = 0;
		len = 0;
		x_min = 0;
		y_min = 0;
		while (arr[i][j]) // нахождение минимальных координат
		{
			if (arr[i][j] == '\n')
			{
				len = 0;
				heg++;
			}
			else
			{
				if (arr[i][j] == '#')
				{
					if ((j / 5) < y_min)
						y_min = (j / 5);
					if ((j / 5) < x_min)
						x_min = (j % 5);
				}
					len++;
				}
				if (!arr[i][j + 1] && !arr[i + 1][0])
				{
					write(1, "0\n", 1);
					smeshenie = 1;
				}
				j++;
			}
			else // смещение по координатам
			{
				j = 0;
				if (arr[i][j] == '#')
				{
					write(1, "1", 1);
					arr[i][j - (y_min * 5) - x_min] = '#';
					arr[i][j] = '.';
				}
				j++;
				write(1, "\n", 1);
			}
		}
		i++;
	}
	i = 0; // test
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}
	return (0);
}

