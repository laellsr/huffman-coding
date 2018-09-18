
#include "./@functions/default.h"
#include "./@functions/compress.h"
#include "./@functions/decompress.h"

int main()
{
	int entry; 
	
	printf("\n########################################\n");
	printf("\n                HUFFMAN                 \n");
	printf("\n########################################\n");
	printf("\n(1) to COMPRESS OR (2) to DECOMPRESS\n\nEntry:	");
	
	scanf("%d", &entry);
	
	switch (entry)
	{
		case 1:
			compress();
		break;

		case 2:
		//	decompress();
		break;

		default:
			printf("\nInvalid entry.\n\n##########  END OF EXECUTION  ###########\n");
		return 0;
	
	}
}

