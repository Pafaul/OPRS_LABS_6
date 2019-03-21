/* Standard library	*/


#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <math.h>

#include "LA.h"

#define max(a, b) ( ( (a) > (b) ) ? (a) : (b) )
#define min(a, b) ( ( (a) < (b) ) ? (a) : (b) )


#include "integrator.h"
//#include "custom.h"
#include "custom.h"

void calcModel(TModel* model);
void printDate(Date date);
Date createDate(void);

int main()
{

    /*TVector X0(6);
    X0.resize(6);
    X0[0] = -2.566123740124270e+7L; //km
    X0[1] = 1.339350231544666e+8L;
    X0[2] = 5.805149372446711e+7L;
    X0[3] = -2.983549561177192e+1L; //km/c
    X0[4] = -4.846747552523134L;
    X0[5] = -2.100585886567924L;
    Date start, finish, checkDay;
    start.year=2019; start.month=1; start.day=1;
    finish.year=2020; finish.month=3; finish.day=17;
    checkDay.year=2019; checkDay.month=3; checkDay.day=16;
    TMatrix* A = new TMatrix (3, 3);//= new TMatrix(3, 3);
    A->operator() (0, 0) = 1; //- sin(phi) * cos(s);
    A(0, 1) = - sin(0) * sin(0);
    A(0, 2) =   cos(0);
    A(1, 0) =   cos(0) * cos(0);
    A(1, 1) =   cos(0) * sin(0);
    A(1, 2) = - sin(0);
    A(2, 0) = - sin(0);
    A(2, 1) =   cos(0);
    A(2, 2) =   0;
    TVector A (1);
    A[0] = 1;*/
    Date startDate = createDate();
    TModel* model = new EarthSolarRotation( startDate );//, dateChoice());
    TIntegrator* Integrator = new TDormandPrinceIntegrator();
    Integrator->setPrecision(1E-16);
    Integrator->Run( model );
    calcModel(model);
    model->finish();
    delete model;
    delete Integrator;
	return 0;
}


void calcModel(TModel* model){

    std::ofstream file("~/test.txt");

        TMatrix Result = model->getResult();

        for (int i=0; i<Result.rowCount(); i++)
        {
            for (int j=0; j<Result.colCount(); j++)
                file << Result(i, j) << " ";

            file << std::endl;
        }

        file.close();
}

void printDate(Date date)
{
    std::cout << "Year: " << date.year << ", Month: " << date.month << ", Day: " << date.day << ", Time: 00:00:00" << std::endl;
}

Date createDate(void)
{
    Date date;
    std::cout << "Create date." << std::endl;
    std::cout << "Input year: "; std::cin >> date.year;
    std::cout << "Input month: "; std::cin >> date.month;
    std::cout << "Input day: "; std::cin >> date.day;
    std::cout << "Created date: " << std::endl; printDate(date);
    date.hour = 0; date.minute = 0; date.seconds = 0;
    return date;
}
