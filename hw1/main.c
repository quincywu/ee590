#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fsm.h"

#define ACCEPT 2
#define REJECT 3
#define MAX_CHAR 100

int main ( int argc, char * argv[] ) {
    if(argc < 3)
        printf ( "invalid number of argument\n" );
    else{
        char input[MAX_CHAR];
        char alphabet[MAX_CHAR];
        char accept_states[MAX_CHAR];
        char states[MAX_CHAR];
        char *state;
        int rules[MAX_CHAR][MAX_CHAR];
        char *rule;
        int i, j;
        FILE *fr = fopen (argv[1], "r"); /* abc.csv */

        if (fr != NULL) {
            /* Input alphabet */
            fscanf(fr, "%s", alphabet);

            /* Accept states */
            i = 0;
            fscanf(fr, "%s", accept_states);

            /* Matrix implementation */
            while ((fscanf(fr, "%s", input)) != EOF) {
                i = 0;
                rule = strtok(input, ",");
                while( rule != NULL ){
                    rules[i][j] = atoi(rule);
                    rule = strtok(NULL, ",");
                    i ++;
                }
                j++;

            }

            char *input_str = argv[2];
            if ( (indexOf(accept_states, fsm(alphabet,i,j,rules,input_str) + '0')) != -1 ) {
              printf ( "accept\n");
            } else {
              printf ( "reject\n");
            }

        }
        fclose(fr);
    }

}
