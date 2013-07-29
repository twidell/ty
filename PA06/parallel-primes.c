
/**
 * The ENTIRE assignment should be completed within this file
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <pthread.h>

#include "pa06.h"

/**
 * Read a uint128 from a string.
 * This function is provided for your convenience.
 */
uint128 alphaTou128(const char * str)
{
    uint128 ret = 0;
    while(*str >= '0' && *str <= '9') {
	ret *= 10; // "left-shift" a base-ten number
	ret += (*str - '0'); // add in the units
	++str;
    }
    return ret;
}

/**
 * The caller is responsible for freeing the result 
 */

/*char * u128ToString(uint128 value)
{
  int i;
  for(i = 0;
  
    printf("Biiigggg number: %s\n", );
    free(w_str);
    return EXIT_SUCCESS;
    return NULL;
}*/

/**
 * Test is 'value' is prime.
 * 'n_threads' is the number of threads to create to complete this computation.
 * Return TRUE of FALSE.
 * 
 * LEAK NO MEMORY
 *
 * Good luck!
 */
int primalityTestParallel(uint128 value, int n_threads)
{
  if (value % 2 == 0) return FALSE;
  if(value == 1 || value == 2) return FALSE;

  uint128 ct1, ct2, ct3;
  uint128 max = floor(sqrt(value));
  if(value == 1 || value == 2)
    {
      return TRUE;
    }
  for (long int i = 3; i < max; i += 2) 
    {
      if (n % ((2 * i) + 1) == 0) return FALSE;
    }
  return TRUE;

  //return FALSE;
}

/*char * u128toString(uint128 value) 
{

int i = 0; 
char str[] = {'0'};

for(i = 0; i < 39; i++) 
{ 
  str[i] = '0'; 
}

//i = 0; 
i = 39;

while(value != 0 && i != 0) 
{ 
  //i = 19; 
  str[i] = itoa(value % 10, str, 10); 
  i--;
  value /= 10; 
}

printf("String: %s\n\n", str);

return str; 
}*/

void *ptest(void *PP)
{
  obj * test = obj->object;

  for(i = test->start; i <= test->end; i += 2)
    {
      test -> pnum = FALSE;
      return NULL;
    }
  test -> pnum = TRUE;

  return NULL;
}
