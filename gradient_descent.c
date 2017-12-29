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
     * multiplication is the multiplication over n
     */
    float sum=0.0, multiplication=1.0;
    
    for(int i=0; i<dim; i++)
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
 * @ x - vector of variables
 * @ dx - partial derivative
 * @ dimension - dimension of space, also x/dx size
 */
int gradient(float *x, float *dx, int dimension)
{  
    int dim = dimension;
    
    for(int i=0; i < dim; i++)
    {
        dx[i] = -1.0 / (i+1.0) * sin( x[i] / (i+1.0) );
        
        for(int j=0; j < dim; j++)
        {
            if(j != i)
            {
               dx[i] *= cos(x[j]/(j+1.0));
            }
        }

        dx[i] += 2.0 * x[i] / 40.0; 
    }

   return 0;	
}

/* Returns found minimum, single start
 */

float gradient_descent (inputT in)
{
	int dim = in.dimension;
	int epsilon = in.epsilon;

	float x[dim];
	float dx[dim];

    srand(time(NULL));

    for(int i=0; i<dim; i++)
    {
        x[i] = ((float)rand()/(float)RAND_MAX) * 40.0 - 20.0;
	}

    gradient(x, dx, dim);

    while(gradient_norm(dx, dim) > 0.001)
    {
        //for(int i=0; i<dim; i++)
        //    printf("current gradient: n=%d at x=%lf [%lf]\n", i, x[i], dx[i]);

        for(int i=0; i<dim; i++)
        {
		    x[i] -= in.epsilon * dx[i];
        }

        gradient(x, dx, dim); 
    }

    printf("Minimum found at: [");

    for(int i=0; i<dim; i++)
        printf("x_%d=%f", i, x[i]);


    return function(x, dim);

}


int main() {
	inputT input;
    input.dimension = 2;
    input.epsilon = 0.001;

    printf("Minimum that was found: %f\n", gradient_descent(input));
}




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
