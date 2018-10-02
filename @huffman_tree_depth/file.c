#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *new_file = fopen("totalfile", "wb");
	unsigned char byte;
	int i=0, j=256, g;
	for (i = i; i <= 255; ++i)
	{
		byte = i;
		g=j;
		while(g)
		{
			fputc(byte, new_file);
			g--;
		}
		j=j-1;
	}
}