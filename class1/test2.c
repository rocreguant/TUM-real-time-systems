/*
  Tasks:
  1-write a function sum() which takes an integer number n and calculate
  the sum of n,n-1,n-2, ...,0 RECURSIVELY
  Use the give function signature!

  2-Write a function to calculate the execution time of sum() and fibonacci() in milliseconds.
  Use the given function signature. FOLLOW the instructions
    
  3-Test this function with n=20,30,40,41,42,43,44,45 for sum() and fibonacci() and explain why fibonacci() takes longer.

  4-Test fibonacci(46)! Why the result is negative and nonsence? :) 
*/
#include <stdio.h>
#include <time.h>

long int fibonacci(int n);
long int sum(int n);
double calculate_execution_time (long int (*func)(int),int n);

 
int main()
{
  int number;
  

  //TODO (Each comment requires one line code!)
 
  // define a function pointer to your sum() function
  long int (*fPtrS)(int);
  // initialize your function pointer
 fPtrS = &sum;
 
  // define a function pointer to your fibonacci() function
    long int (*fPtrF)(int);
  // initialize your function pointer
  fPtrF = &fibonacci;

  printf("Enter a number to calculate the execution time of sum() and fibonacci()\n");
  scanf("%d", &number);

  printf("Sum (%d) = %ld\n", number, sum(number));
  printf("Flibonacci(%d) = %ld\n", number, fibonacci(number));
  
  //TODO (Hint: Two lines with printf)
  // print the calculation_execution_time() result for sum() and fibonacci()
  printf("Execution time sum: %f\n", calculate_execution_time(fPtrS, number));
  printf("Execution time sum: %f\n", calculate_execution_time(fPtrF, number));

  return 0;
}

double calculate_execution_time (long int (*func)(int),int n)
{
  //TODO (Each comment requires one line code!)
  //use clock_t data type and clock() function to get the current time  (START Time)
  clock_t start = clock();
  
  //Use the pointer to call your functions sum() or fibonacci() 
  (*func)(n);
  
  //use clock_t data type and clock() function to get the current time  (END Time)
  clock_t end = clock();
  
  //Use CLOCKS_PER_SEC to calculate Start time - End time in Millisecons
  double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  
  //return the execution time instead of 0!
  return cpu_time_used;

}

long int fibonacci(int n)
{
  if (n == 0 || n == 1)
     return 1;
  else
     return fibonacci(n - 1) + fibonacci(n - 2);
}

//TODO
long int sum(int n){
    if(n>0) return sum(n-1) + n;
    return 0;
}

