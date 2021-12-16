#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "seq_lib.h"
#include "sequence.h"
#include "definitions.h"

#define TRUE 1
#define FALSE 0

int char_val(char ch) {
    if (isupper(ch)) {
        return (ch - 'A' + 1);
    } else if (islower(ch)) {
        return (ch - 'a' + 1);
    } else return 0;
}

int word_val(char* word) {
    int gim_sum = 0;
    for (int i = 0 ; i < strlen(word); ++i) {
        gim_sum += char_val(word[i]);
    }
    return gim_sum;
}

int atbash_char(char ch) {
    if (isalpha(ch)!=0) {
        int a = 0, b=0;
        a = char_val(ch);
        b = ((-1)*a)+26 +1;
        if (isupper(ch)) {
            b += 'A';
            b--;
        }
        else if (islower(ch)) {
            b += 'a';
            b--;
        }
        return b;
    }
    return ch;
}

char* atbash_wrd(char* word) {
    char* wrd = malloc(sizeof(char)*strlen(word));
    memset(wrd, 0, strlen(wrd));
    wrd = strcpy(wrd, word);
    for (int i=0; i<strlen(word); i++) {
        wrd[i] = atbash_char(word[i]);
    }
    return wrd;
}

char* remove_whtspc(const char* str, int c) {
    char* new_str = malloc(sizeof(char)*strlen(str));
    memset(new_str, 0, strlen(new_str));
    new_str = strcpy(new_str,str);

    int del_index=0, amnt_del=0;
    for (int k=0; k<strlen(new_str); k++) {
        if (new_str[k]==c) {
            ++amnt_del;
        }
    }
    for (int i = 0; i < amnt_del; i++) {
        for (int j = 0; j<strlen(new_str); j++) {
            if (new_str[j] == c) {
                del_index=j;
                break;
            }
        }
        memmove(&new_str[del_index], &new_str[del_index+1], strlen(new_str) - del_index);
    }
    return new_str;
}

char* reverse_str(char* word) {
    char* str = (malloc(sizeof(char)*strlen(word)));
    memset(str, 0, strlen(str));
    str = strcpy(str, word);
    int j = 0;
    for (int i = strlen(word)-1; i>=0; i--) {
        str[j] = word[i];
        j++;
    }
    return str;
}

int contains_char(char* str, int ch) {
    int len = strlen(str);
    char *ptr = str;
    while (ptr != &str[len]) {
        if (*ptr == ch) {
            return TRUE;
        }
        ptr++;
    }
    return FALSE;
}