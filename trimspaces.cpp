#include <cstdio>
#include <iostream>
#include <cstring>
#include <cctype>

char *trim(char *str)
{
    size_t len = 0;
    char *frontp = str;
    char *endp = NULL;

    if( str == NULL ) { return NULL; }
    if( str[0] == '\0' ) { return str; }

    len = strlen(str);
    endp = str + len;

    /* Move the front and back pointers to address the first non-whitespace
     * characters from each end.
     */
    while( isspace((unsigned char) *frontp) ) { ++frontp; }
    if( endp != frontp )
    {
        while( isspace((unsigned char) *(--endp)) && endp != frontp ) {}
    }

    if( str + len - 1 != endp )
            *(endp + 1) = '\0';
    else if( frontp != str &&  endp == frontp )
            *str = '\0';

    /* Shift the string so that it starts at str so that if it's dynamically
     * allocated, we can still free it on the returned pointer.  Note the reuse
     * of endp to mean the front of the string buffer now.
     */
    endp = str;
    if( frontp != str )
    {
            while( *frontp ) { *endp++ = *frontp++; }
            *endp = '\0';
    }


    return str;
}

int main(int argc, char **argv)
{
    char str[512 + 1];

    if (argc < 2)
    {
        printf("Insufficient arguements\n");
	return 0;
    }
    
    strcpy(str, argv[0]);
    for (int i = 1; i < argc; ++i)
    {
	strcat(str, " ");
        printf("argv[%d]: %s\n", i, argv[i]);
        strcat(str, argv[i]);
    }
    printf("Complete string is %d: %s\n", (int)(strlen(str)), str);
    char * trimmedStr = trim(str);
    printf("Complete string is %d: %s\n", (int)(strlen(trimmedStr)), trimmedStr);
    
}

