#include <stdio.h>
/**
* Main: Entry point of a C program.
*
*Return: Return o for successful execution.
*/
int main(void)
{
	int ch;
	char cha;

	ch = 'a';
	cha = 48;
	while (ch <= 'f')
	{
		putchar(ch);
		ch++;
	}
	while (cha <= 57)
	{
		putchar(cha);
		cha++;
	}
	putchar('\n');
	return (0);
}

