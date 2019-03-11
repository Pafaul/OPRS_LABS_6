/* Standard library	*/


#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>

#include "LA.h"

#define max(a, b) ( ( (a) > (b) ) ? (a) : (b) )
#define min(a, b) ( ( (a) < (b) ) ? (a) : (b) )


#include "integrator.h"
//#include "custom.h"
#include "custom.h"


void showResult(TModel* model);

int main()
{
    TModel* Model1 = new TSattelites();
    showResult(Model1);
    delete Model1;

    printf("\n===========================================================================\n");

    /*TModel* Model2 = new TArenstorfModel2();
    showResult(Model2);
    delete Model2;*/

	return 0;
}


void showResult(TModel* model){

    std::ofstream file("test.txt");

    TIntegrator* Integrator = new TDormandPrinceIntegrator();
        Integrator->setPrecision(1E-2);
        //printf ("1");
        Integrator->Run( model );
        //printf ("2");
        TMatrix Result = model->getResult();


        TVector Res = model->getInitialConditions();


        printf ("\nVector Res: \n");
        for (int z=0; z<4; z++)
        {
            printf("%f   ", Res[z]);
        }
        printf("\n---------------------------------------------------------------------------");


        printf("\nCount string Matrix_x = %i",Result.rowCount());
        printf("\nCount column Matrix_x = %i", Result.colCount());

        printf("\n---------------------------------------------------------------------------");

        printf("\nResult: \n");
        for (int i=0; i<Result.rowCount(); i++)
        {
            for (int j=0; j<Result.colCount(); j++)
            {
                //printf("%10.7Lf ; ", Result(i, j));
                file << Result(i, j) << "|";
            }
            //printf("\n");
            file << std::endl;
        }

        file.close();
        delete Integrator;
}
