#include "definitions.h"
// #include <stdlib.h>
#include <stdio.h>

int main(void) {
    char* word = malloc(WORD);
    memset(word,0,strlen(word));
    int i=0;
    char c=0;
    while((c=getchar())!=' ' && (c!='\t') && (c!='\n')) {
        word[i++] = c;
    }
    word[i] = '\0';
    char* txt = malloc(TEXT);
    memset(txt,0,strlen(txt));
    i=0;c=0;
    while ((c=getchar())!='~') {
        txt[i++] = c;
    }
    txt[i] = 0;
    while(strlen(stdin->_IO_read_ptr)!=0) getchar();
    char* gim_str = gimatria(word, txt);
    printf("%s\n",gim_str);
    char* atbash_str = atbash(word, txt);
    printf("%s\n", atbash_str);
    char* anagram_str = anagram(word, txt);
    printf("%s\n", anagram_str);
    return 0;
}