#include <stdio.h>
   int main() {
     char **s;
     //so we should have some array it's will be our var 
     //double pointer wiil work like this d_pointer ->(points) pointer ->(points) var(our array)
     //so we need additional pointer that points to array
     char foo[] = "Hello World";
     char *add_pointer = foo;
     s = &add_pointer;
     printf("s is %s\n", *s);
     s[0] = &foo;
     printf("s[0] is %s\n", s[0]);
     return(0);
}
