//---------------------------------------------------------------------------

#include "custom.h"
#include <math.h>

#include "LA.h"
//---------------------------------------------------------------------------

const long double TArenstorfModel::m  = 0.012277471;

TArenstorfModel::TArenstorfModel() : TModel()
{
	X0.resize(4);
    X0[0] = 0.994;
    X0[1] = 0;
    X0[2] = 0;
    X0[3] = -2.0015851063790825224053786222;
}

//---------------------------------------------------------------------------

void TArenstorfModel::getRight( const TVector& X, long double t, TVector& Y )
{
    Y.resize(4);
	D1 = pow( pow( X[0] + m, 2 ) + pow( X[1], 2 ), 1.5 );
	D2 = pow( pow( X[0] + m - 1, 2 ) + pow( X[1], 2 ), 1.5 );
    Y[0] = X[2];
    Y[1] = X[3];
    Y[2] = X[0] + 2 * X[3] - (1 - m)*(X[0] + m) / D1 - m * (X[0] + m - 1) / D2;
	Y[3] = X[1] - 2 * X[2] - (1 - m)*X[1] / D1 - m * X[1] / D2;
}

//---------------------------------------------------------------------------

TArenstorfModel2::TArenstorfModel2() : TArenstorfModel()
{
	X0.resize(4);
    X0[0] = 0.994;
    X0[1] = 0;
    X0[2] = 0;
    X0[3] = -2.0317326295573368357302057924;
}
//---------------------------------------------------------------------------

TSattelites::TSattelites() : TModel()
{
    X0.resize(6);
    X0[0] = -2.566123740124270e+7; //km
    X0[1] = 1.339350231544666e+8;
    X0[2] = 5.805149372446711e+7;
    X0[3] = -2.983549561177192e+1; //km/c
    X0[4] = -4.846747552523134;
    X0[5] = -2.100585886567924;
}

void TSattelites::getRight( const TVector& X, long double t, TVector& Y)
{
    Y.resize(6);
    Y[0] = X[3];
    Y[1] = X[4];
    Y[2] = X[5];
    ro = sqrt(X[0]*X[0] + X[1]*X[1] + X[2]*X[2]);
    Y[3] = -mu*X[0]/pow(ro, 3.);
    Y[4] = -mu*X[1]/pow(ro, 3.);
    Y[5] = -mu*X[2]/pow(ro, 3.);
}
