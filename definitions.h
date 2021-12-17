/**
 * @file definitions.h
 * @author daniel raz (https://github.com/druckhead) amir gill (https://github.com/amirg00)
 * @brief 
 * @version 0.1
 * @date 2021-12-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */


/* 
 * 30*26=780 -> highest gimatric value for a word of lenth 30
    ex: 30 times 'z' with gimatric value of 26 -> 780 times 'a' with gimatric value of 1
*/
#ifndef MIN_SEQ
    #define MIN_SEQ !((tmp_wrd[0] == ' ' || tmp_wrd[strlen(tmp_wrd)-1] == ' ')\
                            || (tmp_wrd[0] == '\t' || tmp_wrd[strlen(tmp_wrd)-1] == '\t')\
                            || (tmp_wrd[0] == '\n' ||  tmp_wrd[strlen(tmp_wrd)-1] == '\n')\
                            || (isalpha(tmp_wrd[0])==0 || isalpha(tmp_wrd[strlen(tmp_wrd)-1])==0)\
                        )
#endif

#ifndef SEQUENCE
    #define TEXT 1024
    #define WORD 30
    #define MAX_CHAR 780
#endif