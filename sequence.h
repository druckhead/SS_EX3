/**
 * @file sequence.h
 * @author daniel raz (https://github.com/druckhead) amir gill (https://github.com/amirg00)
 * @brief 
 * @version 0.1
 * @date 2021-12-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */


/**
 * @brief finds all minimal sequences in txt with the same gimatric value as word
 * 
 * @param word string
 * @param txt string
 * @return char* containing all said sequences
 */
char* gimatria(char* word, char* txt);

/**
 * @brief finds all minimal sequences in txt that are atbash or the reversed atbash of word
 * 
 * @param word string
 * @param txt string
 * @return char* containing all said sequences
 */
char* atbash(char* word, char* txt);

/**
 * @brief finds all minimal sequences in txt that are constructed ONLY from (all) characters in word and whitespaces
 * 
 * @param word string
 * @param txt string
 * @return char* containing all said sequences
 */
char* anagram(char* word, char* txt);