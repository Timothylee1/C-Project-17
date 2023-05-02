/*!
@file       q.c
@author     Timothy Lee (timothykexin.lee@digipen.edu.sg)
@course     RSE 1201
@section    Laboratory 10
@Laboratory Text string related functions
@date       20/11/2021
@brief      This file contains definitions of the functions build_path, compare_string,
            describe_string, find_string. These functions are used to allocate and create 
            a path directory. The length of the path can be measured and used for 
            comparsion with another string of text. Comparison includes, locating substring
            within string and locale-character comparison. Results and strings used for 
            comparison will be printed to the stdout.
*//*______________________________________________________________________________________*/
#include "q.h"

/*!
@brief  This function takes in a path to a parent folder, a path separator sequence (for 
        Linux paths it is "/" , for Windows paths it is "\\" ), and an array of 
        subdirectories with its element count. It combines the parent folder and the 
        subdirectories into a single path using the separator.

@param  parent, separator are function parameters of a pointer to const char
        folders is a function parameter of a const that points to a const char
        count is a function parameter of size_t or long unsigned int
        sz_parent, sz_sep, sz_folders, i are declared as a size_t or long unsigned int
        path is declared as a pointer to char

@return word 
*//*_______________________________________________________________________________________*/
const char* build_path(const char* parent, const char* separator,
	                const char* const folders[], size_t count) {
    //implement STRCPY and STRCAT
    //STRCPY copies a string to another and ends with a null-terminated byte
    //STRCAT appends a copy and places a null terminator at the end.
    //Output should be parent folder separator folder separator
    //Like " c:\home\user\files\ "
    size_t sz_parent = STRLEN(parent), sz_sep = STRLEN(separator);
    size_t sz_folders = 0;
	for (size_t i = 0; i < count; i++) {
		sz_folders += STRLEN(folders[i]);					//sum of length of each string
	}
	
	char* path = debug_malloc(sz_folders + sz_parent + sz_sep * count + 1);         //Allocate path memory size
	STRCPY(path, parent);								//Assign parent 
	for (size_t i = 0; i < count; i++) {
		STRCAT(path, folders[i]);
		STRCAT(path, separator);
	}
	return (const char*) (path);
}

/*!
@brief  This function prints out a statement about a 3-way (-1, 0, 1) comparison of two 
        strings. Through the implementation of STRCMP which compares two null-terminated 
        byte strings which checks for alphabetical order. lhs apppear before rhs == 
        negative, 0 if same, positive if lhs appears after rhs.

@param  lhs, rhs are function parameters of a pointer to const char
        result is declared as a data type int

@return nothing 
*//*_______________________________________________________________________________________*/
void compare_string(const char* lhs, const char* rhs) {
    int result = STRCMP(lhs, rhs);
    switch (result) {
        case -1:
                printf("Left string goes first.\n");
                break;
        case 1:
                printf("Right string goes first.\n");
                break;
        default:
                printf("Both strings are equal.\n");
    }
}

/*!
@brief  This function prints out the length of a provided string of text.

@param  text is a function parameter of a pointer to const char
        length is declared as a size_t or long unsigned int

@return nothing 
*//*_______________________________________________________________________________________*/
void describe_string(const char* text) {
    //implement STRLEN; STRLEN returns the length of the given null-terminated byte string
    //it counts the length of the string from the first character to before the null
    size_t length = STRLEN(text);
    printf("The length of the path \"%s\" is %ld.\n", text, length);
}

/*!
@brief  This function prints out a statement describing a result of searching a string 
        of text (substring).

@param  string, substring are function parameters of a pointer to const char
        locate is declared as a pointer to a char

@return nothing 
*//*_______________________________________________________________________________________*/
void find_string(const char* string, const char* substring) {
    //implement STRSTR; STRSTR(str, substr)
    //str = "one two three"; (str, "two"); found two at position 4
    char* locate = STRSTR(string, substring);
    printf("Searching for a string:\n\tText:     %s\n\tSub-text: %s\n", string, substring);

    if (locate)
        printf("\tResult:   found %zu characters at a position %zu.\n", 
                STRLEN(substring), locate-string);
    else
	    printf("\tResult:   not found\n");
}
