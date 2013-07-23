#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pa05.h"
//#include "tree.h"
//#include "utility.h"

//void CloseFile(FILE * fptr)

int main (int argc , char ** argv )
{
  FILE *fptr;
  HuffNode *head;

  if(argc < 3)
    {
      printf("Not enough arguments read!\n");
      return EXIT_FAILURE;
    }

  head = read_head(fptr);

  Huff_postOrderPrint(head);
  fclose(fptr);
  //CloseFile(fptr);

  destroy(head);

  return EXIT_SUCCESS;

}

