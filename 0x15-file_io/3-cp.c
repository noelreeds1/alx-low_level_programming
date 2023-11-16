#include "main.h"
/**
  * main - copies file_from to file_to.
  *
  *@argc: argument count.
  *
  *@argv: argument array.
  *
  *Return: Always 1 on success and -1 on error.
  */
int main(int argc, char *argv[])
{
	int fd, fd2, m, n, num;
	char buf[BUF_SIZE];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	fd2 = open(argv[1], O_RDONLY);
	if (fd2 == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
	while ((num = read(fd2, buf, BUF_SIZE)) > 0)
	{
		if (num == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			exit(99);
		}
		write(fd, buf, num);
	}
	m = close(fd);
	n = close(fd2);
	if (m == -1 || n == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd FD_VALUE\n");
		exit(100);
	}
	return (num);
}
