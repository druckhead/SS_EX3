#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "sequence.h"

#define TEXT 1024
#define WORD 30
#define END_SEQ "~"

int word_val(char* word) {
    int gim_sum = 0;
    for (int i = 0 ; i < strlen(word); ++i) {
        gim_sum += char_val(word[i]);
    }
    return gim_sum;
}

int char_val(char ch) {
    if (isupper(ch)) {
        return (ch - 'A' + 1);
    } else if (islower(ch)) {
        return (ch - 'a' + 1);
    } else return 0;
}

int atbash_char(char ch) {
    int a = 0, b=0;
    a = char_val(ch);
    b = ((-1)*a)%26 +1;
    if (isupper(ch)) {
        b+= 'A';
        b--;
    }
    else if (islower(ch)) {
        b = ((-1)*a)+26 +1;
        b+= 'a';
        b--;
    }
    return b;
}

char* atbash_wrd(char* word) {
    char* wrd = malloc(sizeof(char)*strlen(word));
    for (int i=0; i<strlen(word); i++) {
        wrd[i] = atbash_char(word[i]);
    }
    return wrd;
}

char* reverse_str(char* word) {
    char* str = (malloc(sizeof(char)*strlen(word)));
    int j = 0;
    for (int i = strlen(word)-1; i>=0; i--) {
        str[j] = word[i];
        j++;
    }
    return str;
}

void print_gimatria(char *word, char *txt) {
    printf("Gematria Sequences: ");
    int wrd_val = word_val(word), curr_val=0, curr_len = 0, j=0;
    char tmp_wrd[WORD] = "";
    for (int i = 0; i < strlen(txt); ++i) {
        curr_val += char_val(txt[i]);
        if (strlen(tmp_wrd)==0) {
            if (isalpha(txt[i]) != 0) {
                tmp_wrd[j] = txt[i];
                ++j;
            }
        }
        else {
            tmp_wrd[j] = txt[i];
            ++j;
        }
        curr_len++;
        if (curr_val > wrd_val) {
            curr_val = 0;
            i -= curr_len;
            i+=1;
            curr_len = 0;
            j=0;
            memset(tmp_wrd, 0, strlen(tmp_wrd));
        } else if (curr_val > 0 && curr_val == wrd_val) {
            printf("%s", tmp_wrd);
            if (i < strlen(txt)-1-1) {
                printf("~");
            }
            curr_val = 0;
            if (curr_len!=1) {
                i -= 1;
            }
            curr_len = 0;
            j=0;
            memset(tmp_wrd, 0, strlen(tmp_wrd));
        }
    }
    printf("\n");
}

void print_atbash(char *word, char *txt) {
    printf("Atbash Sequences: ");
    int wrd_val = word_val(word), curr_val=0, curr_len = 0, j=0;
    char tmp_wrd[WORD] = "";
    char *wrd = malloc(sizeof(char)*strlen(word)), *rev_wrd = reverse_str(word);
    char *atbash_wrd, *atbash_rev_wrd;
    wrd = strcpy(wrd, word);
    for (int i = 0; i < strlen(txt); ++i) {
        curr_val += char_val(txt[i]);
        if (strlen(tmp_wrd)==0) {
            if (isalpha(txt[i]) != 0) {
                tmp_wrd[j] = txt[i];
                ++j;
            }
        }
        else {
            if (isalpha(txt[i]) != 0) {
                tmp_wrd[j] = txt[i];
                ++j;
            }
        }
        curr_len++;
        if (curr_val > wrd_val) {
            curr_val = 0;
            i -= curr_len;
            i+=1;
            curr_len = 0;
            j=0;
            memset(tmp_wrd, 0, strlen(tmp_wrd));
        }
        else if (curr_val > 0 && curr_val == wrd_val) {
            printf("%s", tmp_wrd);
            if (i < strlen(txt)-1-1) {
                printf("~");
            }
            curr_val = 0;
            if (curr_len!=1) {
                i -= 1;
            }
            curr_len = 0;
            j=0;
            memset(tmp_wrd, 0, strlen(tmp_wrd));
        }
    }
    printf("\n");

}

int main(void)
{
    char* word = "abcd";
    // char* txt = "a-bc,dbca-zwxyzabzyxw0dcba~";
    // printf("%s\n%s\n", word, txt);
    // print_gimatria(word, txt);
    // print_atbash(word, txt);
    char *w = atbash_wrd(word);
    printf("%s\n%s\n",word, w);
    return 0;
}