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

    int i = 0, counter = 0;
    char c, str[MAX_CHAR];
    FILE *fr = fopen (filename, "w+");
    FILE *f_old = fopen( temp_file, "r");

    if( f_old != NULL ) {

        while ( (c = fgetc(f_old)) != EOF && i <= MAX_CHAR ) {
            str[ i ++ ] = c;
            str[ i ] = '\0';

            if ( c == '\n' ){

                if ( !counter ){
                    printf("%s", str);
                }else{
                    fprintf( fr, "%s", str );
                }

                i = 0;
                counter ++;
            }
        }

        if( !counter ){
            str[ i ] = '\0';
            fprintf( fr, "%s", str );
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
    char c, str[MAX_CHAR];
    int i = 0;
    FILE *fr = fopen (filename, "r");

    if( fr != NULL ){

        while ( (c = fgetc(fr)) != EOF && c != '\n' && i <= MAX_CHAR ) {
            str[ i ++ ] = c;
        }

        str[ i ] = '\n';
        printf("%s", str);
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

    int i = 0, counter = 0;
    char c, str[MAX_CHAR], top[MAX_CHAR];
    FILE *fr = fopen (filename, "w+");
    FILE *f_old = fopen( temp_file, "r");

    if( f_old != NULL ) {

        while ( (c = fgetc(f_old)) != EOF && i <= MAX_CHAR ) {
            str[ i ++ ] = c;
            str[ i ] = '\0';

            if ( c == '\n' ){

                if ( counter <= 1){
                    if ( !counter ) {
                        strcpy(top, str);
                    }else {
                        fprintf( fr, "%s", str );
                        fprintf( fr, "%s", top );
                    }
                }else{
                    fprintf( fr, "%s", str );
                }

                i = 0;
                counter ++;
            }
        }

        if( !counter ){
            fprintf( fr, "%s", str );
        }
        if( counter == 1){
            fprintf( fr, "%s", str );
            fprintf( fr, "%s", top );
        }
    }

    fclose(fr);
    fclose(f_old);
    remove(temp_file);

    return;
}
