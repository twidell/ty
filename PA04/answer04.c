/*
 * Please fill the functions in this file.
 * You can add additional functions. 
 *
 * Hint: 
 * You can write additonal functions.
 * You can test your functions with your own input file.
 * See details in README or typing command ./pa04 in terminal after make.
 * See output format examples in any of the files in directory expected.
 * 
 * You may create additional arrays if needed.  The maximum size
 * needed is specified by MAXLENGTH in pa04.h.
 */

#include "pa04.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printPart(int *, int);
void partition(int * , int, int);
void inchelp(int * , int, int);
void dechelp(int *, int, int);
void oddhelp(int *, int, int);
void evenhelp(int *, int, int);
void oddnevenhelp(int *, int, int);
void primehelp(int *, int, int);
int primetest(int);

void printPart(int * part, int length)
{
  printf("= ");

  int ind;
 
  for(ind = 0; ind < length - 1; ind++)
    {
      printf("%d + ", part[ind]);
    }
  printf("%d\n", part[length - 1]);
}


void partition(int * part, int ind, int left)
{
  int val;

  if(left == 0)
    {
      printPart(part, ind);
      return;
    }
  for(val = 1; val <= left; val++)
    {
      part[ind] = val;
      partition(part, ind + 1, left - val);
    }
}

/*
 * =================================================================
 * This function prints all partitions of a positive integer value
 * For example, if the value is 3:
 *
 * partitionAll 3
 * = 1 + 1 + 1
 * = 1 + 2
 * = 2 + 1
 * = 3
 */


void partitionAll(int value)
{
  int * part;
  part = malloc(sizeof(int) * value);
  printf("partitionAll %d\n", value);
  partition(part, 0, value);
  free(part);
 
  
}
/*
 * =================================================================
 * This function prints the partitions that use increasing values.
 *
 * For example, if value is 5
 * 2 + 3 and
 * 1 + 4 are valid partitions
 *
 * 5 is a valid partition
 * 
 * 1 + 1 + 3 and
 * 2 + 1 + 2 and
 * 3 + 2 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 *
 */
void partitionIncreasing(int value)
{
  int * part;
  part = malloc(sizeof(int) * value);
  printf("partitionIncreasing %d\n", value);
  inchelp(part, 0, value);
  free(part);
}

void inchelp(int * part, int ind, int left)
{
  int val;

  if(left == 0)
    {
      printPart(part, ind);
      return;
    }
  for(val = 1; val <= left; val++)
    {
      part[ind] = val;

      if(ind == 0)
	{
	  inchelp(part, 1, left - val);
	}
      else if(part[ind - 1] < val)
	{
	  inchelp(part, ind + 1, left - val);
	}
    }

}

/*
 * =================================================================
 * This function prints the partitions that use Decreasing values.
 *
 * For example, if value is 5
 * 3 + 2 and
 * 4 + 1 are valid partitions
 *
 * 5 is a valid partition
 * 
 * 1 + 1 + 3 and
 * 2 + 1 + 2 and
 * 2 + 3 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 *
 */


void partitionDecreasing(int value)
{
  int * part;
  //printf("partitionDecreasing %d\n", value);
  part = malloc(sizeof(int) * value);
  printf("partitionDecreasing %d\n", value);
  dechelp(part, 0, value);
  // printf("partitionDecreasing %d\n", value);
  free(part);
}
void dechelp(int * part, int ind, int left)
{
  int val;

  //printf("partitionDecreasing %d\n", left);

   if(left == 0)
    {
      printPart(part, ind);
      // dechelp(part, ind += 1, left -= 1);
      }

  for(val = 1; val <= left; val++)
    {

      part[ind] = val;

      if(ind == 0)
	{
	  dechelp(part, 1, left - val);
	}
       if(part[ind - 1] > val)
	{
	  dechelp(part, ind + 1, left - val);
	}
    }

}

/*
 * =================================================================
 * This function prints odd number only partitions of a positive integer value
 * For example, if value is 5
 * 1 + 1 + 1 + 1 + 1 and
 * 1 + 3 + 1 are valid partitions
 *
 * 5 is a valid partition
 * 
 * 1 + 1 + 1 + 2 and
 * 2 + 1 + 2 and
 * 2 + 3 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 */


void partitionOdd(int value)
{
  int * part;
  part = malloc(sizeof(int) * value);
  printf("partitionOdd %d\n", value);
  oddhelp(part, 0, value);
  free(part);
}
void oddhelp(int * part, int ind, int left)
{
  int val;

  if(left == 0)
    {
      printPart(part, ind);
      return;
    }
  for(val = 1; val <= left; val += 2)
    {
      part[ind] = val;
      oddhelp(part, ind + 1, left - val);
    }

}

/*
 * =================================================================
 * This function prints even number only partitions of a positive integer value
 * For example, if value is 8
 * 2 + 2 + 2 + 2and
 * 2 + 4 + 2 are valid partitions
 *
 * 8 is a valid partition
 *
 * 2 + 1 + 1 + 2 + 2and
 * 2 + 1 + 2 + 3and
 * 5 + 3 are invalid partitions.
 *
 * if the value is 5, there will be no result generated
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 */

void partitionEven(int value)
{
  int * part;
  part = malloc(sizeof(int) * value);
  printf("partitionEven %d\n", value);
  evenhelp(part, 0, value);
  free(part);
}
void evenhelp(int * part, int ind, int left)
{
  int val;

  if(left == 0)
    {
      printPart(part, ind);
      return;
    }
  for(val = 2; val <= left; val += 2)
    {
      part[ind] = val;
      evenhelp(part, ind + 1, left - val);
    }

}

/*
 * =================================================================
 * This function prints alternate ood and even number partitions of a positive integer value. Each partition starts from and odd number, even number, ood number again, even number again...etc.
 *
 * For example, if value is 6
 * 1 + 2 + 1 + 2 and
 * 3 + 2 + 1 are valid partitions
 *
 * 6 is not a valid partition
 *
 * 2 + 1 + 1 + 2 and
 * 2 + 1 + 3and
 * 5 + 1 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 */


void partitionOddAndEven(int value)
{
  int * part;
  part = malloc(sizeof(int) * value);
  printf("partitionOddAndEven %d\n", value);
  oddnevenhelp(part, 0, value);
  free(part);  
}
void oddnevenhelp(int * part, int ind, int left)
{
  int val;

  if(left == 0)
    {
      printPart(part, ind);
      return;
    }
  for(val = 1; val <= left; val++)
    {
      part[ind] = val;

      if(part[0] % 2 != 0)
	{
	   if((part[ind] % 2 != 0 && part[ind - 1] % 2 == 0))
	    {
	      oddnevenhelp(part, ind + 1, left - val);
	    }
	   else if((part[ind] % 2 == 0 && part[ind - 1] % 2 != 0))
	    { 
	      oddnevenhelp(part, ind + 1, left - val);
	    }
	}
    }
}
/*
 * =================================================================
 * This function prints prime number only partitions of a positive integer value
 * For example, if value is 6
 * 2 + 2 + 2 and
 * 3 + 3 are valid partitions
 *
 * 6 is not a valid partition
 * 
 * 2 + 4 and
 * 1 + 5 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 */



void partitionPrime(int value)
{
  int * part;
  part = malloc(sizeof(int) * value);
  printf("partitionPrime %d\n", value);
  primehelp(part, 0, value);
  free(part);
}
void primehelp(int * part, int ind, int left)
{
  int val;
  int test;

  if(left == 0)
    {
      printPart(part, ind);
      return;
    }

  for(val = 2; val <= left; val++)
    {
      part[ind] = val;

      //printf("Prime? %d\n\n", test);
      test = primetest(val);

      if(test != 0)
	{
	  primehelp(part, ind + 1, left - val);
	}
    }

}
int primetest(int value)
{

  if(value == 2 || value == 3)
    {
      return 1;
    }

  if(value % 2 == 0)
    {
      return 0;
    }

  int i;
  int max;

  max = floor(sqrt(value));

  for(i = 3; i <= max; i+=2)
    {
      if(value % i == 0)
	{
	  return 0;
	}
    }
  return 1;

}
