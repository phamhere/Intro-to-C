#include <stdio.h>

/*
    Given a character pointer x (that points to an array of chars), and a
    character pointer y, copies the character contents of y over to x. Pointer
    arithmetic is necessary here. Also, make sure x points to a null terminator
    at its end to terminate it properly. 

    Example call:

    char buffer[1024];

    string_copy(buffer, "Hello!");
    printf("%s", buffer); // Prints "Hello!"
*/
void string_copy(char *x, char *y)
{
    int i;

    // loop until y string reaches the null char
    for (i = 0; *(y + i) != '\0'; i++)
    {
        // make x pointer values equal y pointer values
        *(x + i) = *(y + i);
    }
    // appending null char to end of *x
    *(x + i + 1) = '\0';
}

/*
    Searches the input string `str` for the first instance of the 
    character `c` (an unsigned char). This function returns a pointer
    that points to the first instance of the character `c` in the
    input string `str`.

    Do not use the `strchr` function from the standard library.
*/
char *find_char(char *str, int c)
{
    // loop until str reaches null char
    while (*str != '\0')
    {
        // if find c in str, return str
        if (*str == c)
            return str;
        // otherwise increase str to look at next value
        str++;
    }
    // return null if c isn't found in *str
    return NULL;
}

/*
    Searches the input string `haystack` for the first instance of
    the string `needle`. This function returns a pointer that points
    to the first instance of the string `needle` in the input
    string `haystack`. 

    Do not use the `strstr` function from the standard library.
*/
char *find_string(char *haystack, char *needle)
{
    // looping until end of haystack string
    while (*haystack != '\0')
    {
        // checking if current haystack char equals start of needle char
        if (*haystack == *needle)
        {
            // making copies of haystack and needle to not alter their position
            char *haystack_copy = haystack;
            char *needle_copy = needle;
            int flag = 0;
            // looping through needle_copy to see if the rest of needle is in haystack
            while (*needle_copy != '\0')
            {
                // changing flag to signal that not all of needle was in haystack
                if (*haystack_copy != *needle_copy)
                    flag = 1;
                haystack_copy++;
                needle_copy++;
            }
            // returning haystack position if all of needle was in haystack
            if (flag == 0)
                return haystack;
        }
        haystack++;
    }
    // returning null if no matches found
    return NULL;
}

#ifndef TESTING
int main(void)
{
    char *found_char = find_char("hello", 'e');
    char *found_string = find_string("world", "or");

    printf("Found char: %s\n", found_char);
    printf("Found string: %s\n", found_string);

    return 0;
}
#endif
