#include "Kva.h"

int main()
{
    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;
    enum Root_flags nRoots = NULL_Roots;

    Enter(&a, &b, &c);

    nRoots = Eq_solution(a, b, c, &x1, &x2);

    Output(nRoots, x1, x2);

    return 0;
}
