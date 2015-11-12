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

void oddEven( int n)
{
 
   if (n%2 == 0)
      printf("It is Even\n");
   else
      printf("It is Odd\n");
 
}

int addNumbers(int *a)
{
   int sum = 0, c, value;
 
   
   printf("Enter %d integers\n",*a);
 
   for (c = 1; c <= *a; c++)
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
   printf ("Enter an integer 'a' \n");
   scanf("%d", &a);
   printf ("Enter an integer 'b' \n");
   scanf("%d", &b);
   printf ("a/b =%f\n",division(a,b));

   printf("Enter the number of integers you want to add\n");
   scanf("%d", &n);
   addNumbers(&n);

   int *i;
   i = (int *) malloc(sizeof(int));
   *i=200;
   printf("The content of the memory address %p is %d\n", i,*i);
    
   
    
   return 0;
}
