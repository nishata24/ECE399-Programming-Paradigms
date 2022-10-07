//
//  Assignment2_V2.c
//  ECE-399 Programming Paradigms
//  Professor Sable
//  Created by Nishat Ahmed on 6/29/22.
//

//#include "IS_Project2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gi1 = 100;
char gc1 = 'X';

void hello()
{
  printf("Hello World!\n");
  exit(0);
}

void f1(int pi1, char pc1)
{
  static int count = 0; // Counts the number of times we get to f1
  if (++count == 5)
    exit(1); // Exit the program if we get to f1 5 times
  
  /* Here, we are changing the values of global varaibles */
  gi1 = 200;
  gc1 = 'Z';

  /* Here, we are setting and initializing local variables -
     These are different than the local variables in "main" */
  int li1 = 10;
  char lc1 = 'B';
  void *lvp1;

  /* Here, we are printing memory addresses of variables */
  printf("\nIn f1:\n");
  printf("  gi1 is at address %p\n", &gi1);
  printf("  gc1 is at address %p\n", &gc1);
  printf("  li1 is at address %p\n", &li1);
  printf("  lc1 is at address %p\n", &lc1);
  printf("  lvp1 is at address %p\n", &lvp1);
  printf("  pi1 is at address %p\n", &pi1);
  printf("  pc1 is at address %p\n", &pc1);

  /* You will insert some unusual code here! */

  /* YOUR CODE GOES HERE */
  lvp1 = &lvp1;
  //make lvp1 point to memory address where return address is stored
  while(*(void**)lvp1 != __builtin_return_address(0)){
      lvp1 = lvp1 + 1;
    }
  //modify return address to call hello
  *(void**)lvp1 = hello;
  
  return;
}

int main()
{
  int li1 = 50;
  char lc1 = 'C';

  /* Here, we are printing memory addresses of variables */
  printf("\nIn main, before calling f1:\n");
  printf("  gi1 is at address %p\n", &gi1);
  printf("  gc1 is at address %p\n", &gc1);
  printf("  li1 is at address %p\n", &li1);
  printf("  lc1 is at address %p\n", &lc1);

  f1(li1, lc1);
  
  /* Here, we are printing memory addresses of variables */
  printf("\nIn main, after calling f1:\n");
  printf("  gi1 is at address %p\n", &gi1);
  printf("  gc1 is at address %p\n", &gc1);
  printf("  li1 is at address %p\n", &li1);
  printf("  lc1 is at address %p\n", &lc1);

  /* Here, we are printing values of variables */
  printf("  gi1 has value %d\n", gi1);
  printf("  gc1 has value %c\n", gc1);
  printf("  li1 has value %d\n", li1);
  printf("  lc1 has value %c\n", lc1);
}
