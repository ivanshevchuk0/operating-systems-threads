#include <stdio.h> // printf, etc
#include <stddef.h> // size_t, SIZE_MAX, etc
#include <stdlib.h> // exit, strtoull
#include <ctype.h> // isdigit
#include <errno.h> // defines the integer variable errno, which is
    //    set by system calls and some library functions in the event of an error
    //    to indicate what went wrong
#include <stdint.h> // SIZE_MAX

size_t positive_parse(const char *str){
    if(*str == '\0'){
        fprintf(stderr, "Invalid number\n"); 
        exit(1);
    }

    // arrays in c are stored in contiguous memory, therefore, the elements are stored directly next to each other
    for(const char *p = str; *p != '\0'; p++){
        if(!isdigit((unsigned char) *p)){
            fprintf(stderr, "Invalid number: %s\n", str); // receives the address stored in str and reads consecutive characters until it reaches \0 
            exit(1);
        }
    }

    // convert string to the integer
    errno = 0;  // reset 
    unsigned long long value;
    if(errno == ERANGE || value > SIZE_MAX || value == 0){ // ERANGE - result too large
        fprintf(stderr, "Invalid number: %s\n", str);
        exit(1);
    }
    return (size_t)value; 
}

int main(int argc, char *argv[]){
    
}