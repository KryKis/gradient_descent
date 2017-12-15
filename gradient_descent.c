#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "gradient_descent.h"

float function(float *x, int dim){
	int tmp = dim;
	float result=0.0, multiplication=1.0;
	while(dim--)
		result += x[dim]*x[dim];
	result /= 40.0;
	result += 1.0;
	while(tmp--)
		multiplication *= cos(x[tmp]/tmp);
	return result - multiplication;
}

float gradient(float *x, int dim) {
	int tmp = dim;
    float result=0.0, multiplication=1.0;
    while(dim--)
		
        result += x[dim]*x[dim];
    result /= 40.0;
    result += 1.0;
    while(tmp--)
        multiplication *= cos(x[tmp]/tmp);
   return result - multiplication;	
}

float gradient_descent (inputT in) {
	int dimension = in.dimension;
	int epsilon = in.epsilon;
	while(dim--) x[dimension] = rand()/RAND_MAX * 20.0 - 10.0;
	dim  = in.dimension;
	while(dim--) printf("%d, ", x[in.dim-dim]);

	while(derrival>in.epsilon)
		while(dim--) x = function(x, dim) - gradient(x, n); 
	
}
int main() {
	inputT input;
	scanf("%d, %f", &input.dimension, &input.epsilon);
	gradient_descent(input);
	
	
}
