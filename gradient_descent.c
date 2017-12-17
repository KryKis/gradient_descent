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
//	scanf("%d, %f", &input.dimension, &input.epsilon);
//	gradient_descent(input);
	//f = open("output", 'w');
	for(int x = -20; x<21; x++){
		float a = (float) x;
		printf("%f, %f", a, function(&a, 1)); 	
	}
	
}
