/*
  Time: 20 min
  Tasks:
  1- How many functions do you see in this C-code?  
  2- Compile with gcc test1.c -o test1 -Wall
  3- Try to fix the "compile" errors first
  4- Eliminate all warnings 
  5- Find the runtime error. (What is the problem?)
  6- How can you fix the runtime error? Hint: dynamic memory allocation!
*/



#include <stdio.h>
#include <stdlib.h>
void prime (void) {
int n, i = 3, count, c;
 
   printf("Enter the number of prime numbers required\n");
   scanf("%d",&n);
 
   if ( n >= 1 )
   {
      printf("First %d prime numbers are :\n",n);
      printf("2\n");
   }
 
   for ( count = 2 ; count <= n ;  )
   {
      for ( c = 2 ; c <= i - 1 ; c++ )
      {
         if ( i%c == 0 )
            break;
      }
      if ( c == i )
      {
         printf("%d\n",i);
         count++;
      }
      i++;
   }
}

float division(int a, int b){
   return (float)a/b;
}

void oddEven( double n)
{
 
   if ((int)n%2 == 0)
      printf("It is Even\n");
   else
      printf("It is Odd\n");
}

int addNumbers(double a)
{
   int sum = 0, value;
 
   
   printf("Enter %d integers\n",(int)a);
 
   for (int c = 1; c <= a; c++)
   {
      scanf("%d", &value);
      sum = sum + value;
   }

   printf("Sum of entered integers = %d\n",sum);
   return 0;
}

int main ()
{
   int n;
   printf("Enter an integer to check Odd/Even\n");
   scanf("%d", &n);
   oddEven(n);


   prime();

   int a,b;
   printf ("Enter an integer 'a' \n");;
   scanf("%d", &a);
   printf ("Enter an integer 'b' \n");
   scanf("%d", &b);
   printf ("a/b =%f\n",division(a,b));

   printf("Enter the number of integers you want to add\n");
   scanf("%d", &n);
   addNumbers(n);
   int *i;
   i = malloc(sizeof(int));
   *i=200;
   //i= 0;
   printf("The content of the memory address %p is %d\n", i,*i);
    
   
    
   return 0;
}
