#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double F(double x);

long randomGenerator(void);

int main(){

	double x;

	printf("%lf\n",F(5));
     //   printf("%ld\n",randomGenerator());
	return 0;
}


long randomGenerator(void){

	srand (time(NULL));
        return rand()%1000000;

}

double F( double x){

return ((pow(x,0.2)+sin(x*3.14/180))/(x-(double)1/3))*((pow(x,8))/(-1*cos(x*3.14/180)));

}
