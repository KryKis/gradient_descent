#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gradient_descent.h"
#include "func.h"

/* Returns found minimum, single start
 */

float gradient_descent (inputT in, float f(float*, int), FILE* trace)
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
	fprintf(trace, "%f, %f, %f\n", x[0], x[1], function(x, 2));
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
        printf("x_%d=%f, ", i, x[i]);
   printf("]\n");

    return f(x, dim);

}


int main() {
    inputT input;
    input.dimension = 2;
    input.epsilon = 0.001;

    FILE *fd = fopen("outputD", "w");
    printf("Minimum that was found: %f\n", gradient_descent(input, function, fd));



    /*

//	*/
    FILE *f = fopen("output", "w");
    
    float *a = malloc(sizeof(float)*2);
	for(int x = -20; x<21; x++)
    {   
        for(int y = -20; y<21; y++)
        {
            a[0] = (float)x;
            a[1] = (float)y;
		 fprintf(f, "%f, %f, %f\n", a[0], a[1], function(a, 2));
		//    fprintf(fd, "%f, %f, %f\n", a[0], a[1], gradient(a, 2));
	    }
	}
    
    free(a);	
    fclose(f);
    fclose(fd);
    //
}
