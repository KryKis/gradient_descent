#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "gradient_descent.h"

float function(float *x, int dim){
	float sum=0.0, multiplication=1.0;
    int n = dim;
    for(int i=0; i<n; i++)
    {
		sum += x[i]*x[i];
		multiplication *= cos(x[i]/(i+1));
	}
    sum /= 40.0;
    sum += 1.0;

	return sum - multiplication;
}

float gradient(float *x, int dim) {
	int n = dim;
    float sum_d=0.0, multiplication_d=1.0;
    for(int i=0; i<n; i++)
    {
        sum_d += 2.0*x[i];
        float partial_d = -1.0/(i+1)*sin(x[i]/(i+1));
        for(int j=0; j<n; j++)
        {
            if(j != i)
                partial_d *= cos(x[j]/(j+1));
        }
        multiplication_d += partial_d;
    }
    sum_d /= 40.0;
   return sum_d - multiplication_d;	
}

float gradient_descent (inputT in) {
	int dimension = in.dimension;
	int epsilon = in.epsilon;
	float *x = calloc(0, sizeof(float)*dimension);
	while(dimension--) x[dimension] = rand()/RAND_MAX * 20.0 - 10.0;
//	dimension  = in.dimension;
	while(dimension--) printf("%f, ", x[in.dimension-dimension]);
	float min_y;
	while(gradient(x, dimension) > 0.001)
		while(dimension--) min_y = function(x, dimension) - in.epsilon * gradient(x, dimension); 
	
}
int main() {
	inputT input;
	//scanf("%d, %f", &input.dimension, &input.epsilon);
    input.dimension = 1;
    input.epsilon = 0.01;
//	gradient_descent(input);
	FILE *f = fopen("output", "w");
	FILE *fd = fopen("outputD", "w");
    
    float *a = malloc(sizeof(float)*2);
	for(int x = -20; x<21; x++)
    {   
        for(int y = -20; y<21; y++)
        {
            a[0] = (float)x;
            a[1] = (float)y;
		    fprintf(f, "%f, %f, %f\n", a[0], a[1], function(a, 2));
		    fprintf(fd, "%f, %f, %f\n", a[0], a[1], gradient(a, 2));
	    }
	}
    free(a);	
    fclose(f);
    fclose(fd);
	
}
