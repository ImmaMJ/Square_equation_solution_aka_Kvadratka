#include "Kva.h"

void Enter(double* const a, double* const b, double* const c)
{
    assert(a != NULL && "a is NULL");
    assert(b != NULL && "b is NULL");
    assert(c != NULL && "c is NULL");

    printf("Quadratic Equation format: aX^2 + bX + c = 0 \n");

    printf("Enter the coefficient a  \n");
    while(scanf("%lg", a) != 1)
        printf("Input Error. Try again.");
        while(getchar() != '\n'){};

    printf("Enter the coefficient b  \n");
    while(scanf("%lg", b) != 1)
        printf("Input Error. Try again.");
        while(getchar() != '\n'){};

    printf("Enter the coefficient c  \n");
    while(scanf("%lg", c) != 1)
        printf("Input Error. Try again.");
        while(getchar() != '\n'){};
}

int Is_zero(const double n)
{
    assert(isfinite(n));

    const double Epsilon = 1E-10;
    return(!(fabs(n) < Epsilon));
}

enum Root_flags Sol_lineal(const double b,const double c, double* const x1)
{
    assert(isfinite(b));
    assert(isfinite(c));
    assert(x1 != NULL && "x1 is NULL");

    if (Is_zero(c) == 0)
    {
        if (Is_zero(b) == 0)
            return INF_Roots;
        else *x1=0;
            return ONE_Root;
    }
    else
    {
        if (Is_zero(b) == 0)
            return NULL_Roots;
        else
            *x1 = -c/b;
            return ONE_Root;
    }
}

enum Root_flags Sol_square(const double a, const double b, const double c, double* const x1, double* const x2)
{
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));
    assert(x1 != NULL && "x1 is NULL");
    assert(x2 != NULL && "x2 is NULL");
    assert(x1 != x2);


        double D = (b * b) - ( 4 * a * c);

        if(Is_zero(D) == 0)
            {
                *x1 = -b/(2 * a);
                return ONE_Root;
            }
        else if(D < 0)
            return NULL_Roots;

        else



        {
            double sqrtD = sqrt(D);
            *x1 = (-b - sqrtD)/(2 * a);
            *x2 = (-b + sqrtD)/(2 * a);
            return TWO_Roots;
        }
   // }
}

void Output(enum Root_flags nRoots, const double x1, const double x2)
{
    switch(nRoots)
    {
        case NULL_Roots:
            printf("There are no roots");
            break;

        case ONE_Root:
            printf("One real solution: %f", x1);
            break;

        case TWO_Roots:
            printf("There two real solutions: %f, %f", x1, x2);
            break;

        case INF_Roots:
            printf("There are an infinite number of solutions");
            break;
    }
}

enum Root_flags Eq_solution(const double a, const double b, const double c, double* const x1, double* const x2)
{
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));
    assert(x1 != NULL && "x1 is NULL");
    assert(x2 != NULL && "x2 is NULL");
    assert(x1 != x2);

    enum Root_flags nRoots = NULL_Roots;
    if(Is_zero(a) == 0)
        nRoots = Sol_lineal(b, c, x1);
    else
        nRoots = Sol_square(a,  b,  c, x1, x2);
    return nRoots;
}

