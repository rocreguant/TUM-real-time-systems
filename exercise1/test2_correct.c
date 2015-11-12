/*
  Tasks:
  1-write a function sum() which takes an integer number n and calculate
  the sum of n,n-1,n-2, ...,0 RECURSIVELY

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
  

  //TODO
  // define a function pointr to your sum() function
  long int (*sumPtr)(int);
  // initialize your function pointer
  sumPtr=&sum;  // without & also correct
  //define a function pointer to your fibonacci() function
  long int (*fibPtr)(int);
  //initialize your function pointer
  fibPtr=&fibonacci;

  printf("Enter a number to calculate the execution time of sum() and fibonacci()\n");
  scanf("%d", &number);

  printf("Sum (%d) = %ld\n", number, sum(number));
  printf("Flibonacci(%d) = %ld\n", number, fibonacci(number));
  
  //TODO
  // print the calculation_execution_time () result for sum() and fibonacci()
  printf("Execution time of sum(%d) = %f Milliseconds\n", number, calculate_execution_time(sumPtr,number));
  printf("Execution time of fibonacci(%d) = %f Milliseconds\n", number, calculate_execution_time(fibPtr,number));

  return 0;
}

double calculate_execution_time (long int (*func)(int),int n)
{
  //TODO
  //use clock_t data type and clock() function to get the current time  (START Time)
  clock_t start = clock();
  //call your functions sum() and fibonacci() 
  (*func)(n);//func(n) is also correct
  //use clock_t data type and clock() function to get the current time  (END Time)
  clock_t stop = clock();

  //Use CLOCKS_PER_SEC to calculate Start time - End time in Millisecons
  double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
  return elapsed;

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
    //write a recursive function
    if(n==0)
       return n;
    else
       return n+sum(n-1);    /*self call  to function sum() */
}

