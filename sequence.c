#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "sequence.h"

#define TEXT 1024
#define WORD 30
#define END_SEQ "~"

int word_val(char* word) {
    // char curr = 0;
    int gim_sum = 0;
    for (int i = 0 ; i < strlen(word); ++i) {
        if (islower(word[i])) {
            gim_sum += (int)(word[i] - 'a' + 1);
        } else if (isupper(word[i])) {
            gim_sum += (int)(word[i] - 'A' + 1);
        }
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


void print_gimatria(char *word, char *txt) {
    printf("Gematria Sequences: ");
    int wrd_val = word_val(word), curr_val=0, curr_len = 0, j=0;
    char tmp_wrd[WORD] = "";
    for (int i = 0; i < strlen(txt); ++i) {
        curr_val += char_val(txt[i]);
        if (strlen(tmp_wrd)==0) {
            if (isalpha(txt[i]) != 0) {
                tmp_wrd[j++] = txt[i];
            }
            else {
                // do nothing
            }
        }
        else {
            tmp_wrd[j++] = txt[i];
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
            i -= 1;
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
    char* txt = "a-bc,dbca-zwxyzabzyxw0dcba~";
    printf("%s\n%s\n", word, txt);
    // printf("%ld", strlen(txt));
    print_gimatria(word, txt);
    return 0;
}
