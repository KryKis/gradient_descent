#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "gradient_descent.h"

/* Returns value of function for passed variables x_i,
 * dim is equal to number of those variables/dimension of 
 * resolved problem
 */
float function(float *x, int dim){
    /* sum is the first element of equation and + 1
     * multiplication is the last one
     */
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


float gradient_norm(float *dx, int dim)
{
    float sum = 0.0;
    for(int i=0; i<dim; i++)
    {
        sum += dx[i]*dx[i];
    }
    return sqrt(sum);
}

/* Returns value of gradient in position given by x vector
 * It equals to sum of partial derrivatives of all function variables
 */
float *gradient(float *x, int dim) {
	int n = dim;
    float *partial_derrivatives = malloc(sizeof(float)*dim);
    float multiplication_d[dim];
    for(int i=0; i<n; i++)
    {
        partial_derrivatives[i] = 2.0*x[i]/40.0;
        multiplication_d[i] = -1.0/(i+1)*sin(x[i]/(i+1));
        
        for(int j=0; j<n; j++)
        {
            if(j != i)
            {
               multiplication_d[i] *= cos(x[j]/(j+1));
            }
        }

        partial_derrivatives[i] -= multiplication_d[i]; 
    }
   return partial_derrivatives;	
}

/* Returns found minimum
 */

float gradient_descent (inputT in) {
	int dimension = in.dimension;
	int epsilon = in.epsilon;
	float x[dimension];
	float *dx = malloc(sizeof(dx)*in.dimension);

    srand(time(NULL));
	while(dimension--)
    {
        x[dimension] = rand()/RAND_MAX * 40.0 - 20.0;
	}
    while(gradient_norm(x, dimension) > 0.001) {
        dx = gradient(x, dimension);
        for(int i=0; i<in.dimension; i++)
		    x[i] -= in.epsilon * dx[i]; 
    }
    printf("Minimum found at: [");
    for(int i=0; i<in.dimension; i++)
        printf("%f, ", x[i]);
    printf("]\n");

    return function(x, in.dimension);

}


int main() {
	inputT input;
    input.dimension = 2;
    input.epsilon = 0.01;

/*	FILE *f = fopen("output", "w");
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
*/	
    printf("Minimum that was found: %f\n", gradient_descent(input));
}
