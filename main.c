/**
 * @file main.c
 * @author daniel raz (https://github.com/druckhead) amir gill (https://github.com/amirg00)
 * @brief 
 * @version 0.1
 * @date 2021-12-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/**************************************
*********** MY HEADERS ****************
**************************************/

#include "definitions.h"
#include "sequence.h"
#include "seq_helper.h"

/**************************************
******** C STANDARD HEADERS ***********
***************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/**************************************
************ MAIN DRIVER **************
***************************************/

int main(void) {
    char* word = malloc(WORD);
    
    int i=0;
    char c=0;
    
    // get input from user until whitespace character is received
    while((c=getchar())!=' ' && (c!='\t') && (c!='\n')) {
        word[i++] = c;
    }
    word[i] = '\0';
    
    char* txt = malloc(TEXT);
    memset(txt,0,strlen(txt));
    
    i=0;
    c=0;

    // get input from user until ~ is received
    while ((c=getchar())!='~') {
        txt[i++] = c;
    }
    txt[i] = '\0';

    /*
     clear redundant input inside input buffer
     useful if received input after '~' character
     we need to clear this.
    */
    while(strlen(stdin->_IO_read_ptr)!=0) getchar();
    if (strlen(stdin->_IO_read_base)!=0) {
        memset(stdin->_IO_read_base,0,strlen(stdin->_IO_read_base));
    }
    
    char* gim_str = gimatria(word, txt);
    printf("%s\n",gim_str);
    char* atbash_str = atbash(word, txt);
    printf("%s\n", atbash_str);
    char* anagram_str = anagram(word, txt);
    printf("%s", anagram_str);

    // free all pointers created in main driver
    free(word);
    free(txt);
    free(gim_str);
    free(atbash_str);
    free(anagram_str);

    // reached end of program
    return 0;
}