#include <stdio.h>
#include <string.h>

int main (int argc, char * argv[]) {

    if (argc < 3)
        printf ( "invalid number of argument\n" );
    else{
        char *filename = argv[1];
        char *action = argv[2];

        if( strcmp(argv[2], "pop") == 0 ){
            pop(filename);
        }

        if( strcmp(argv[2], "print_top") == 0 ){
            print_top(filename);
        }

        if( strcmp(argv[2], "swap_top") == 0 ){
            swap_top(filename);
        }


    }

    return 0;
}
