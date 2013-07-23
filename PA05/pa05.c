#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "utility.h"


int main ( int argc , char ** argv )
{
  FILE *fptr;
  HUffNode *head;

  if(!argcount(argc))
    {
      return EXIT_FAILURE;
    }

  head = load_head(fptr);

  Huff_postOrderPrint(head);
  CloseFile(fptr);

  destroy(head);

  return EXIT_SUCCESS;

}
