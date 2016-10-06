#include <stdio.h>

int main ( int argc, char* argv[]){

	if(argc < 2)
		printf ( "invalid number of argument\n" );
	else{
		FILE *fr = fopen (argv[1], "rt");
		char ch;
		int n = 1;

		if( fr == NULL ) {
			printf ("Error in opening file.\n");
			return -1;
		};

		/* fseek return 0 if successful */
		while (fseek(fr,-n,SEEK_END) == 0) {
			ch = fgetc(fr);
			printf("%c", ch);
			n++;
		}

		fclose(fr);
    }
    return 0;
}
