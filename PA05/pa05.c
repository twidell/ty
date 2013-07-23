#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pa05.h"
//#include "utility.h"

//void CloseFile(FILE * fptr)

int main (int argc , char ** argv )
{
  FILE * fptr_in = NULL;
  FILE * fptr_out = NULL;
  HuffNode * tree;
  char length;

  if(argc != 3)
    {
      printf("Not enough arguments read!\n");
      return EXIT_FAILURE;
    }

  length = strlen(argv[1]);

  fptr_in = fopen(argv[1], "r");
  fptr_out = fopen(argv[2], "w");

  if(fptr_in == NULL)
    {
      printf("File Error 1, stopping program!\n");
      return EXIT_FAILURE;
    }

if(fptr_out == NULL)
    {
      printf("File Error 2, stopping program!\n");
      return EXIT_FAILURE;
    }

  /*if(argv[1][length - 1] == 'h')
    {
      tree = read_head(fptr_in);
      Huff_postOrderPrint(head);
      }*/

  if(argv[1][length - 1] == 'h')
    {
      tree = create_chartree(fptr_in);
      Huff_postOrderPrint(tree, fptr_out);
      destroy_tree(tree);
    }
  else
    {
      tree = create_bittree(fptr_in);
      Huff_postOrderPrint(tree, fptr_out);
      destroy_tree(tree);
    }

  fclose(fptr_in);
  fclose(fptr_out);

  return EXIT_SUCCESS;

}

