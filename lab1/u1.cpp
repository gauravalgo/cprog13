#include <stdio.h>    /* printf */
#include <stdlib.h>   /* atoi   */

/*
 * returns "hello + list of argv"
 * if argv[i] is a number, prints argv[i+1] argv[i] times.
 */
int main(int argc, const char* argv[])
{
  printf("\nHello");

  if (argc > 2) {

    for (int i = 1; i < argc; i++ ) {
      int number = atoi(argv[i]);
      if (number != 0) {
        i++;
        for (int j = 0; j < number; j++) {
          if (i >= argc) {
            printf(" world");
          } else {
            printf(" %s", argv[i]);
          }
        }
      } else {
        printf(" %s", argv[i]);
      }
    }
    
  } else {
    printf(" world");
  }
  printf("!");
}

/*
 * Makefiles!
 * $* is the params from %
 *
 * gcc options:
 * -Wall: Enables all warnings about construvtions that some users consider questinable.
 *    -g: produce debugging nfomration in the operating systems native format.
 */
