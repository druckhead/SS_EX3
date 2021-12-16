#include "definitions.h"
#include "seq_helper.h"
#include "sequence.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char* gimatria(char *word, char *txt) {
    printf("Gematria Sequences: ");

    char* gim_str = malloc(MAX_CHAR);
    memset(gim_str,0,strlen(gim_str));

    // int wrd_len = strlen(word);
    // int txt_len = strlen(txt);

    int wrd_val = word_val(word), curr_len = 0, j=0;
    char* tmp_wrd = malloc(MAX_CHAR);
    memset(tmp_wrd, 0, strlen(tmp_wrd));

    for (int i = 0; i < strlen(txt); i++) {
        tmp_wrd[j] = txt[i];
        j++;
        curr_len++;
        if (word_val(tmp_wrd) > wrd_val) {
            j=0;
            i=i-curr_len+1;
            curr_len=0;
            memset(tmp_wrd,0,strlen(tmp_wrd));
        }
        else if (word_val(tmp_wrd)==wrd_val) {
            if (MIN_SEQ) {
                tmp_wrd=strcat(tmp_wrd, "~");
                gim_str=strcat(gim_str, tmp_wrd);
                j=0;
                i=i-curr_len+1;
                curr_len=0;
                memset(tmp_wrd,0,strlen(tmp_wrd));
            }
            else {
                j=0;
                i=i-curr_len+1;
                curr_len=0;
                memset(tmp_wrd,0,strlen(tmp_wrd));
            }
        }
    }
    memset(tmp_wrd,0,strlen(tmp_wrd));
    tmp_wrd=strncpy(tmp_wrd, gim_str, strlen(gim_str)-1);
    return tmp_wrd;
}


/*
******
*bugs* 
******
abcd -> cdaa


abcd
a-bc,dbca-zwxyzabzyxw0dcba~
(not printing b substrings)
*/
char* atbash(char *word, char* txt) {
    printf("Atbash Sequences: ");

    int curr_len = 0, j=0;

    // input word in atbash for evaluation
    char* atbash_str = malloc(MAX_CHAR);
    memset(atbash_str,0,strlen(atbash_str));
    atbash_str = atbash_wrd(word);

    int atbash_str_val = word_val(atbash_str);

    // reverse of word for finding reverse atbash string
    char* rev_wrd = malloc(MAX_CHAR);
    memset(rev_wrd, 0, strlen(rev_wrd));
    rev_wrd = reverse_str(word);

    // atbash of reverse word
    char* rev_wrd_atbash = malloc(MAX_CHAR);
    memset(rev_wrd_atbash, 0, strlen(rev_wrd_atbash));
    rev_wrd_atbash = atbash_wrd(rev_wrd);

    // for eval current sequence
    char* tmp_wrd = malloc(MAX_CHAR);
    memset(tmp_wrd, 0, strlen(tmp_wrd));

    // for final answer to print
    char* atbash_prnt = malloc(MAX_CHAR);
    memset(atbash_prnt,0,strlen(atbash_prnt));

    for (int i=0; i<strlen(txt); i++) {
        tmp_wrd[j] = txt[i];
        j++;
        curr_len++;
        if (word_val(tmp_wrd) > atbash_str_val) {
            j=0;
            i=i-curr_len+1;
            curr_len=0;
            memset(tmp_wrd,0,strlen(tmp_wrd));
        }
        else if (word_val(tmp_wrd)==atbash_str_val) {
            if (MIN_SEQ) {
                char* tmp = malloc(sizeof(char)*strlen(tmp_wrd));
                memset(tmp, 0, strlen(tmp));
                tmp = strcpy(tmp, tmp_wrd);
                tmp = remove_whtspc(tmp, ' ');
                if (strcmp(tmp, atbash_str)==0 || strcmp(tmp, rev_wrd_atbash)==0) {
                    tmp_wrd=strcat(tmp_wrd, "~");
                    atbash_prnt=strcat(atbash_prnt, tmp_wrd);
                    j=0;
                    i=i-curr_len+1;
                    curr_len=0;
                    memset(tmp_wrd,0,strlen(tmp_wrd));
                }
            }
            else {
                j=0;
                i=i-curr_len+1;
                curr_len=0;
                memset(tmp_wrd,0,strlen(tmp_wrd));
            }
        }
    }
    memset(tmp_wrd,0,strlen(tmp_wrd));
    if (strlen(atbash_prnt) != 0) {
        tmp_wrd=strncpy(tmp_wrd, atbash_prnt, strlen(atbash_prnt)-1);
    }
    return tmp_wrd;
}

char* anagram(char* word, char* txt) {
    printf("Anagram Sequences: ");

    int curr_len=0;

    int wrd_len = strlen(word);
    int txt_len = strlen(txt);

    // suppose to hold strings for the print
    char* anagram_str = malloc(MAX_CHAR);
    memset(anagram_str,0,strlen(anagram_str));

    // for current sequence
    char* tmp_wrd = malloc(MAX_CHAR);
    memset(tmp_wrd,0,strlen(tmp_wrd));

    char* tmp_wrd_spc = malloc(MAX_CHAR);
    memset(tmp_wrd_spc,0,strlen(tmp_wrd_spc));

    for (int i=0; i<txt_len;i++) {
        int contains = contains_char(word, txt[i]);
        if (contains) {
            tmp_wrd[curr_len] = txt[i];
            tmp_wrd_spc[curr_len] = txt[i];
            curr_len++;
            if (curr_len >= wrd_len) {
                if (MIN_SEQ) {
                    anagram_str = strcat(anagram_str, tmp_wrd_spc);
                    anagram_str = strcat(anagram_str, "~");
                }
            }
        }
        else if (txt[i] == ' ') {
            tmp_wrd_spc[i] = txt[i];
        }
        else {
            i-=curr_len;
            if (curr_len>0) {
                i++;
            }
            curr_len=0;
            memset(tmp_wrd,0,strlen(tmp_wrd));
            memset(tmp_wrd_spc,0,strlen(tmp_wrd_spc));
        }
    }
    memset(tmp_wrd,0,strlen(tmp_wrd));
    if(strlen(anagram_str)!=0) {
        tmp_wrd=strncpy(tmp_wrd, anagram_str, strlen(anagram_str)-1);
    } 
    return tmp_wrd;
}