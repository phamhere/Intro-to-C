#include <stdio.h>
#include <stdlib.h>

/*
    Given a character array s (as a pointer), return the number of 
    characters in the string.
    
    Do not just use the `strlen` function from the standard libary.
*/
int string_length(char *s)
{
    int i, length = 0;
    // looping through s until hitting null char and incrementing length each time
    for (i = 0; s[i] != '\0'; i++)
    {
        length++;
    }
    // returning length of s
    return length;
}

/*
    Write a function that reverses the order of string s and outputs 
    the reversed string to the input array rv. The rv array will have 
    enough space for the reversed string. Don't forget to terminate 
    the reversed string with a null character. Return the rv array.
*/
char *reverse_string(char *rv, char *s)
{
    int i, length = string_length(s);

    // setting the end of rv to a null char
    rv[length] = '\0';
    length--;

    // looping through s backwards and building up rv with the values
    for (i = 0; length >= 0; length--, i++)
    {
        rv[i] = s[length];
    }
    // returning a filled out string rv
    return rv;
}

#ifndef TESTING
int main(void)
{
    char quote1[] = "Don't forget to be awesome";
    char quote2[] = "a man a plan a canal panama";

    char rv[512];

    printf("The string 'Don't forget to be awesome' has %d characters.\n", string_length(quote1));
    printf("The string 'a man a plan a canal panama' reversed is: '%s'\n", reverse_string(rv, quote2));

    return 0;
}
#endif
