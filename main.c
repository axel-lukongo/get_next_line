#include"get_next_line.h"

int main()
{
	int fd;
	char *str;

	fd = open("file1", O_RDONLY);
	str = get_next_line(fd);
	printf("%s\n",str);
	str = get_next_line(fd);
	printf("%s\n",str);

}