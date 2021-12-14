#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "sequence.h"


/* 
 * 30*26=780 -> highest gimatric value for a word of lenth 30
    ex: 30 times 'z' with gimatric value of 26 -> 780 times 'a' with gimatric value of 1
*/
#define TEXT 1024
#define WORD 30
#define MAX_CHAR 780
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

char* atbash_wrd(char* word) {
    char* wrd = malloc(sizeof(char)*strlen(word));
    memset(wrd, 0, strlen(wrd));
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
    int j = 0;
    for (int i = strlen(word)-1; i>=0; i--) {
        str[j] = word[i];
        j++;
    }
    return str;
}

void print_gimatria(char *word, char *txt) {
    printf("Gematria Sequences: ");

    int wrd_len = strlen(word);
    int txt_len = strlen(txt);

    int wrd_val = word_val(word), curr_val=0, curr_len = 0, j=0;
    char* tmp_wrd = malloc(MAX_CHAR);
    memset(tmp_wrd, 0, strlen(tmp_wrd));

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
        }
        else if (curr_val > 0 && curr_val == wrd_val) {
            printf("%s", tmp_wrd);
            if (i + curr_len + wrd_len < txt_len) {
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
    free(tmp_wrd);
}

void print_atbash(char *word, char *txt) {
    printf("Atbash Sequences: ");

    int wrd_len = strlen(word);
    int txt_len = strlen(txt);

    char *wrd = malloc(sizeof(char)*strlen(word)),
        *wrd_atbash = malloc(sizeof(char)*strlen(word)),
        *rev_wrd = malloc(sizeof(char)*strlen(word)),
        *rev_wrd_atbash = malloc(sizeof(char)*strlen(word));
    
    wrd = strcpy(wrd, word);
    wrd_atbash = atbash_wrd(wrd);
    rev_wrd = reverse_str(word);
    rev_wrd_atbash = atbash_wrd(rev_wrd);
    
    int curr_val = 0, curr_len = 0, j=0;
    char* tmp_wrd = malloc(MAX_CHAR);
    memset(tmp_wrd, 0, strlen(tmp_wrd));

    int wrd_atbash_val = word_val(wrd_atbash);

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

        curr_len = strlen(tmp_wrd);
        if (curr_val > wrd_atbash_val) {
            i -= curr_len;
            i+=1;
            curr_len = 0;
            curr_val = 0;
            j=0;
            memset(tmp_wrd, 0, strlen(tmp_wrd));
        }
        else if (curr_val > 0 && curr_val==wrd_atbash_val) {
            char* tmp = malloc(sizeof(char)*strlen(tmp_wrd));
            memset(tmp, 0, strlen(tmp));
            tmp = strcpy(tmp, tmp_wrd);
            tmp = remove_whtspc(tmp, ' ');
            if (strcmp(tmp, wrd_atbash)==0 || strcmp(tmp, rev_wrd_atbash)==0) {
                printf("%s", tmp_wrd);
                if (i + curr_len + wrd_len < txt_len) {
                    printf("~");
                }
            }
        }
    }
    free(wrd);
    free(wrd_atbash);
    free(rev_wrd);
    free(rev_wrd_atbash);
    free(tmp_wrd);
    printf("\n");
}

void print_anagram(char* word, char* txt) {

}

int main(void) {
    char* word = "abcd";
    char* txt = "a-bc,dbca-zwxyzabzyxw0dcba~";
    printf("%s\n%s\n", word, txt);
    print_gimatria(word, txt);
    print_atbash(word, txt);
    // print_anagram(word, txt);
    return 0;
}