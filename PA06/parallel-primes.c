
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
  int final = 0;
  uint128 max = floor(sqrt(value));
  uint128 chunk;
  chunk = (max + n_threads + 1) / n_threads;

  obj * piece = malloc(sizeof(obj) * n_threads);
  pthread_attr_t * attr = malloc(sizeof(pthread_attr_t) *n_threads);
  pthread_t * thread = malloc(sizeof(pthread_t) * n_threads);

  for(ct1 = 0; ct1 < n_threads; ct1++)
    {
      piece[ct1].start = ct1 * chunk;
      piece[ct1].end = (ct1 + 1) * chunk - 1;
      piece[ct1].number = value;
    }
  if(piece[ct1].start < 3)
    {
      piece[ct1].start = 3;
    }
  if((piece[ct1].start % 2) == 0)
    {
      piece[ct1].start += 1;
    }

  pthread_attr_init(&attr[ct1]);
  pthread_create(&thread[ct1], &attr, ptest, (void*)piece[ct1]);

}


for(ct2 = 0; ct2 < n_threads; ct2++)
  {
    pthread_join(thread[ct2], NULL);
  }
for(ct3 = 0; ct3 < n_threads; ct3++)
  {
    final = TRUE;

    if(piece[ct3].pnum == 0)
      {
	ct3 = n_threads;
        final = FALSE;
      }
  }

free(thread);
free(attr);
free(piece);

return final;

}





  /* if(value == 1 || value == 2)
    {
      return TRUE;
    }
  for (long int i = 3; i < max; i += 2) 
    {
      if (n % ((2 * i) + 1) == 0) return FALSE;
    }
    return TRUE;*/

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
  obj * test = (obj*)PP;

  for(i = test->start; i <= test->end; i += 2)
    {
      test -> pnum = FALSE;
      return NULL;
    }
  test -> pnum = TRUE;

  return NULL;
}
