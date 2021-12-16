#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "sequence.h"


/* 
 * 30*26=780 -> highest gimatric value for a word of lenth 30
    ex: 30 times 'z' with gimatric value of 26 -> 780 times 'a' with gimatric value of 1
*/
#define MINIMAL_SEQ !((tmp_wrd[0] == ' ' || tmp_wrd[strlen(tmp_wrd)-1] == ' ')\
                        || (tmp_wrd[0] == '\t' || tmp_wrd[strlen(tmp_wrd)-1] == '\t')\
                        || (tmp_wrd[0] == '\n' ||  tmp_wrd[strlen(tmp_wrd)-1] == '\n')\
                        || (isalpha(tmp_wrd[0])==0 || isalpha(tmp_wrd[strlen(tmp_wrd)-1])==0)\
                    )
#define TEXT 1024
#define WORD 30
#define MAX_CHAR 780
#define END_SEQ "~"
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
            if (MINIMAL_SEQ) {
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

    // for (int i = 0; i < strlen(txt); ++i) {
    //     curr_val += char_val(txt[i]);
    //     if (strlen(tmp_wrd)==0) {
    //         if (isalpha(txt[i]) != 0) {
    //             tmp_wrd[j] = txt[i];
    //             ++j;
    //         }
    //     }
    //     else {
    //         tmp_wrd[j] = txt[i];
    //         ++j;
    //     }
    //     curr_len++;
    //     if (curr_val > wrd_val) {
    //         curr_val = 0;
    //         i -= curr_len;
    //         i+=1;
    //         curr_len = 0;
    //         j=0;
    //         memset(tmp_wrd, 0, strlen(tmp_wrd));
    //     }
    //     else if (curr_val > 0 && curr_val == wrd_val) {
    //         printf("%s", tmp_wrd);
    //         if (i + curr_len + wrd_len < txt_len) {
    //             printf("~");
    //         }
    //         curr_val = 0;
    //         if (curr_len!=1) {
    //             if (curr_len == j) {
    //                 i--;
    //             }
    //             else {
    //                 i -= (curr_len-j);  
    //             }   
    //         }
    //         curr_len = 0;
    //         j=0;
    //         memset(tmp_wrd, 0, strlen(tmp_wrd));
    //     }
    // }

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
                // i=i-curr_len+1;
                curr_len=0;
                memset(tmp_wrd,0,strlen(tmp_wrd));
            }
            else if (word_val(tmp_wrd)==atbash_str_val) {
                if (MINIMAL_SEQ) {
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

// char* atbash(char *word, char *txt) {
//     printf("Atbash Sequences: ");

//     int wrd_len = strlen(word);
//     int txt_len = strlen(txt);

//     char *wrd = malloc(sizeof(char)*strlen(word)),
//         *wrd_atbash = malloc(sizeof(char)*strlen(word)),
//         *rev_wrd = malloc(sizeof(char)*strlen(word)),
//         *rev_wrd_atbash = malloc(sizeof(char)*strlen(word));
    
//     wrd = strcpy(wrd, word);
//     wrd_atbash = atbash_wrd(wrd);
//     rev_wrd = reverse_str(word);
//     rev_wrd_atbash = atbash_wrd(rev_wrd);
    
//     int curr_val = 0, curr_len = 0, j=0;
//     char* tmp_wrd = malloc(MAX_CHAR);
//     memset(tmp_wrd, 0, strlen(tmp_wrd));

//     int wrd_atbash_val = word_val(wrd_atbash);

//     for (int i = 0; i < strlen(txt); ++i) {
//         curr_val += char_val(txt[i]);
//         if (strlen(tmp_wrd)==0) {
//             if (isalpha(txt[i]) != 0) {
//                 tmp_wrd[j] = txt[i];
//                 ++j;
//             }
//         }
//         else {
//             tmp_wrd[j] = txt[i];
//             ++j;
//         }

//         curr_len = strlen(tmp_wrd);
//         if (curr_val > wrd_atbash_val) {
//             i -= curr_len;
//             i+=1;
//             curr_len = 0;
//             curr_val = 0;
//             j=0;
//             memset(tmp_wrd, 0, strlen(tmp_wrd));
//         }
        // else if (curr_val > 0 && curr_val==wrd_atbash_val) {
            // char* tmp = malloc(sizeof(char)*strlen(tmp_wrd));
            // memset(tmp, 0, strlen(tmp));
            // tmp = strcpy(tmp, tmp_wrd);
            // tmp = remove_whtspc(tmp, ' ');
            // if (strcmp(tmp, wrd_atbash)==0 || strcmp(tmp, rev_wrd_atbash)==0) {
            //     printf("%s", tmp_wrd);
            //     if (i + curr_len + wrd_len < txt_len) {
            //         printf("~");
            //     }
            // }
        // }
//     }
    // free(wrd);
    // free(wrd_atbash);
    // free(rev_wrd);
    // free(rev_wrd_atbash);
    // free(tmp_wrd);
//     printf("\n");
//     return 0;
// }

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
                if (MINIMAL_SEQ) {
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
    while((c=getchar()) != '~') {
        txt[i++] = c;
    }
    txt[i] = '\0';
    
    char* gim_str = gimatria(word, txt);
    printf("%s\n",gim_str);
    char* atbash_str = atbash(word, txt);
    printf("%s\n", atbash_str);
    char* anagram_str = anagram(word, txt);
    printf("%s\n", anagram_str);
    return 0;
}