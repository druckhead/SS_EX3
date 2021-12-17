/**
 * @file seq_helper.h
 * @author daniel raz (https://github.com/druckhead) amir gill (https://github.com/amirg00)
 * @brief 
 * @version 0.1
 * @date 2021-12-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/**
 * @brief calculate gimatric value of a single character
 * 
 * @param ch char
 * @return int gimatric value of ch
 */
int char_val(char ch);

/**
 * @brief calculate gimatric value of a string
 * 
 * @param word string
 * @return int gimatric value of word
 */
int word_val(char* word);

/**
 * @brief converts single character with atbash cypher
 * 
 * @param ch char
 * @return int - new ascii value of a single character in atbash cypher
 */
int atbash_char(char ch);

/**
 * @brief converts string with atbash cypher
 * 
 * @param word string
 * @return char* converted word in atbash cyper
 */
char* atbash_wrd(char *word);

/**
 * @brief removes a single instance of c from word
 * 
 * @param word string
 * @param c unsigned int
 * @return char* word - w/o the frist instance of c
 */
char* remove_char(char* word, int c);

/**
 * @brief removes all instances of c from word
 * 
 * @param word string
 * @param c unsigned char
 * @return char* word - w/o all instances of c
 */
char* remove_allchars(char* word, int c);

/**
 * @brief reverses a string
 * 
 * @param word 
 * @return char* word - reversed
 */
char* reverse_str(char* word);

/**
 * @brief checks if c exists in word
 * 
 * @param word string
 * @param c unsigned char
 * @return int : if contains -> 1 else -> 0
 */
int contains_char(char* word, int c);