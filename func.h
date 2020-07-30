
#include <math.h>
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
float simpleFunction() {
	
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

