#pragma once//---------------------------------------------------------------------------

#include "model.h"

//---------------------------------------------------------------------------
// Задача Аренсторфа (начальные условия 1)

class TArenstorfModel  : public TModel
{
    protected:
        static const long double m;
		long double D1, D2;
    public:
        TArenstorfModel(  );
		void getRight( const TVector& X, long double t, TVector& Y );
};


//---------------------------------------------------------------------------
// Задача Аренсторфа (начальные условия 2)

class TArenstorfModel2 : public TArenstorfModel
{
    public:
        TArenstorfModel2(  );
};
//---------------------------------------------------------------------------
class TSattelites : public TModel
{
protected:
    long double mu = 132712.43994e+6; //km^3/c^2
    long double ro = 1.0;
public:
    TSattelites();
    //TSattelites(double t0, double tk);
    void getRight( const TVector& X, long double t, TVector& Y);
};
