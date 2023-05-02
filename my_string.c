/*!
@file       my_string.c
@author     Timothy Lee (timothykexin.lee@digipen.edu.sg)
@course     RSE 1201
@section    Laboratory 10
@Laboratory Text string related functions
@date       20/11/2021
@brief      This file contains definitions of the functions my_strlen, my_strcpy, my_strcat,
            my_strcmp, my_strstr. These functions mimics how strlen, strcpy, strcat, strcmp,
            strstr functions in the string.h library.
*//*______________________________________________________________________________________*/
#include "my_string.h"

/*!
@brief  This function returns a length of the string as a number of characters before the 
        null-terminator.

@param  length is declared as data type long unsigned int
		str is a function parameter of a pointer to const char
        
@return length
*//*_______________________________________________________________________________________*/
size_t my_strlen(const char* str) {
    size_t length;
    for(length = 0; str[length] != '\0'; length++);             //length of string including null terminator
    return (length--);                                          //returns length without inclusion of null terminator
}

/*!
@brief  This function copies a source string of text (including its null-terminator) into 
        a destination buffer and returns a pointer to that buffer. In a way, the copying
        replaces existing data in the dest with the current src string

@param  src is a function parameter of a pointer to const char
        dest is a function parameter of a pointer to a char
        scrlen, i are declared as size_t or unsigned long int

@return dest
*//*_______________________________________________________________________________________*/
char* my_strcpy(char* dest, const char* src) {
    size_t srclen = my_strlen(src), i;
    for(i = 0; i < srclen; i++) {
        dest[i] = src[i];           //copies char by char till before null of src
    }
    dest[i] = '\0';                 //includes null terminator into destinated array

   return dest; 
}

/*!
@brief  This function concatenates (appends) a source string of text (including its 
        null-terminator) at the end of a destination buffer and returns a pointer to that 
        buffer. 

@param  src is a function parameter of a pointer to const char
        dest is a function parameter of a pointer to a char
        destlen, srclen, i are declared as size_t

@return dest
*//*_______________________________________________________________________________________*/
char* my_strcat(char* dest, const char* src) {
    
    size_t destlen = my_strlen(dest), srclen = my_strlen(src), i;

    for(i = 0; i < srclen; i++) {
        dest[destlen++] = src[i];    //appends char by char till before null of src
    }
    dest[destlen] = '\0';            //includes null terminator into destinated array

   return dest;                      //return pointer
}

/*!
@brief  This function compares two strings of text and returns 0 if they are equal, a 
        negative number if the first string should be alphabetically sorted first, or a 
        positive number if the second string should be alphabetically sorted first. 
        Essentially, this function starts comparing the first character of each string. 
        If they are equal to each other, it continues with the following pairs until the 
        characters differ or until a terminating null-character is reached.

@param  lhs, rhs are function parameters of a pointer to const char
        i, count are declared as data type int
        
@return count
*//*_______________________________________________________________________________________*/
int my_strcmp(const char* lhs, const char* rhs) {
    int count = 0;
    for(int i = 0; lhs[i] != '\0' || rhs[i] != '\0'; i++) {
        if(lhs[i] == rhs[i])
            count = 0;
        else if(lhs[i] < rhs[i])
            return count = -1;                                  //returns when locale-char differs
        else if(lhs[i] > rhs[i])
            return count = 1;                                   //returns when locale-char differs
    }
    return count;
}

/*!
@brief  This function searches for a string of text in another string of text and returns 
        a pointer to the beginning of its first occurrence, or NULL if it cannot be found.
        This process is done through iteration of char comparison.

@param  str, substr are function parameters of a pointer to const char
        sz_str, sz_substr, i, a are declared as long unsigned int or size_t
        locate is declared as a pointer to a const char
        
@return locate
*//*_______________________________________________________________________________________*/
char* my_strstr(const char* str, const char* substr) {
    size_t sz_str = my_strlen(str), sz_substr = my_strlen(substr), i = 0, a = 0;
    while (sz_str > i) 
    {                    
        if(str[i] == substr[a]) {                               //if first occurence is found
            const char* locate = (str+i);                       //pointer to beginning of first occurence 
            
            while(sz_str > i)                                   //prevents reading from undefined memory addresses
            {    
                if(str[i] == substr[a]) {                       //checks if entire string matches, char for char
                    i++;
                    a++;
                }
                else {                                          //restarts check 
                    a = 0;  
                    break;
                }
                if(a == sz_substr)                              //found match
                    return (char*) locate;
            }
        } else
            i++;
    }
    return NULL;
}
