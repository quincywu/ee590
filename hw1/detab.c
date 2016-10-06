#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if(argc < 3)
		printf ( "invalid number of argument\n" );
	else{
		FILE *fr = fopen (argv[1], "rt");
		int n = atoi(argv[2]);
		char ch;

		if( fr == NULL ) {
			printf ("Error in opening file.\n");
			return -1;
		};

		while ((ch = fgetc(fr)) != EOF) {
			int k = 0;
			if( ch == '\t' ) {
				/* print n space */
                for (k = 0; k < n; k ++)
					printf(" ");
			}else
            	printf("%c", ch);
		}
		
		fclose(fr);
    }
    return 0;
}
