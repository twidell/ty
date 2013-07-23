#include <stdio.h>
#include <stdlib.h>
#include "pa05.h"

int main ( int argc , char ** argv )
{
  if(argc != 3)
    {
      printf("pa05 does not receive correct amount of arguments!\n");
      return EXIT_FAILURE;
    }

  //initializing input file
  FILE * fptr = NULL;
  fptr = fopen(argv[1], "r");
  if (fptr == NULL)
    {
      printf("File error!\n");
      return EXIT_FAILURE;
    }
}
