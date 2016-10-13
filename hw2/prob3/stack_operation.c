#include <stdio.h>
#include <string.h>
#include "stack_operation.h"

#define MAX_CHAR 100

void pop ( char *filename ) {

    char temp_file[] = "temp.csv";
    int ret = rename(filename, temp_file);

    if( ret != 0 ) {
        printf("Error: unable to rename file: %s\n", filename);
        return;
    }

    int counter = 0;
    char str[MAX_CHAR];
    FILE *fr = fopen (filename, "w+");
    FILE *f_old = fopen( temp_file, "r");

    if( f_old != NULL ) {

        while ( (fscanf(f_old, "%s", str)) != EOF ) { // can ch be \t, \n or space

            if ( counter == 0 ) {
                printf("%s\n", str);
                counter ++;
            } else {
                fprintf( fr, "%s\n", str );
            }

        }

    }

    fclose(fr);
    fclose(f_old);
    remove(temp_file);

    return ;
}

void push ( char *filename, char *elem ) {

    char temp_file[] = "temp.csv";
    int ret = rename(filename, temp_file);

    if( ret != 0 ) {
        printf("Error: unable to rename file: %s\n", filename);
        return;
    }

    int counter = 0;
    char str[MAX_CHAR];
    FILE *fr = fopen (filename, "w+");
    FILE *f_old = fopen( temp_file, "r");

    if( f_old != NULL ) {

        while ( (fscanf(f_old, "%s", str)) != EOF ) { // can ch be \t, \n or space

            if ( counter == 0 ) {
                fprintf( fr, "%s\n", elem );
                counter ++;
            } else {
                fprintf( fr, "%s\n", str );
            }

        }

    }

    fclose(fr);
    fclose(f_old);
    remove(temp_file);

    return;
}

void print_top ( char *filename ) {
    char str[MAX_CHAR];
    FILE *fr = fopen (filename, "r");

    if( fr != NULL && (fscanf(fr, "%s", str)) != EOF ){
        printf("%s\n", str);
    }

    fclose( fr );
    return;
}

void swap_top ( char *filename ) {

    char temp_file[] = "temp.csv";
    int ret = rename(filename, temp_file);

    if( ret != 0 ) {
        printf("Error: unable to rename file: %s\n", filename);
        return;
    }

    int counter = 0;
    char str[MAX_CHAR];
    char top[MAX_CHAR];
    FILE *fr = fopen (filename, "w+");
    FILE *f_old = fopen( temp_file, "r");

    if( f_old != NULL ) {

        while ( (fscanf(f_old, "%s", str)) != EOF ) { // can ch be \t, \n or space

            if ( counter <= 1 ) {
                if ( !counter ) {
                    strcpy(top, str);
                }else {
                    fprintf( fr, "%s\n", str );
                    fprintf( fr, "%s\n", top );
                }
                counter ++;
            } else {
                fprintf( fr, "%s\n", str );
            }

        }

    }

    fclose(fr);
    fclose(f_old);
    remove(temp_file);

    return;
}
