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
        char input[100];
        char alphabet[100];
        char accept_states[100];
        char states[100];
        char *state;
        int rules[100][100];
        char *rule;
        int i, j;
        FILE *fr = fopen (argv[1], "r"); /* abc.csv */

        if (fr != NULL) {
            /* Input alphabet */
            fscanf(fr, "%s", alphabet);
            printf("why %s\n", alphabet);


            /* Accept states */
            i = 0;
            fscanf(fr, "%s", accept_states);
            //printf("this %s\n", accept_states);

            state = strtok(accept_states, ",");
            while( state != NULL ) {
                 //printf("%d\n", atoi(state));
                 states[i] = state;
                 printf("here state = %s\n", state);
                 state = strtok( NULL, ",");
                 i ++;
             }

            /* Matrix implementation */
            while ((fscanf(fr, "%s", input)) != EOF) {
                //printf("%s\n", input);
                i = 0;
                rule = strtok(input, ",");
                while( rule != NULL ){
                    rules[i][j] = atoi(rule);
                    rule = strtok(NULL, ",");
                    i ++;
                }
                j++;

            }

int k, p;
            for (p = 0; p < 5; p++) {
                for (k = 0; k < 5; k++) {
                    printf(" %d", rules[k][p]);
                }
                printf("\n");
            }


            char *input_str = argv[2];
            printf(" this is accept states %s\n", accept_states);
            printf("the value of fsm = %d\n\n", fsm(alphabet,i,j,rules,input_str) );
            if ( (indexOf(accept_states, fsm(alphabet,i,j,rules,input_str) + '0')) != -1 ) {
              printf ( "accept\n");
            } else {
              printf ( "reject\n");
            }

        }
        fclose(fr);
    }

}
