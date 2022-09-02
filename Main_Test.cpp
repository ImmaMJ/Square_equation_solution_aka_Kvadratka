#include "Kva.h"

int main()
{
    struc str = {NAN, NAN, NAN, NULL_Roots, NAN, NAN};

    Test_lin(0, 0, 1, NULL_Roots, NAN, NAN);
    Test_lin(0, 1, 0, ONE_Root, 0, NAN);
    Test_lin(0, 0, 0, INF_Roots, NAN, NAN);

    Test_sqr(1, 2, 3,NULL_Roots, NAN, NAN);
    Test_sqr(1, 0, 0,ONE_Root, 0, NAN);
    Test_sqr(1, 2, 1,ONE_Root, 1, NAN);
    Test_sqr(1, -2, -3,TWO_Roots, -1, 3);

    Test_Eq(0, 0, 1, NULL_Roots, NAN, NAN);
    Test_Eq(9, 1, 91, NULL_Roots, NAN, NAN);
    Test_Eq(4, 4, 1, NULL_Roots, 0.5, NAN);
    Test_Eq(1, -7, 10, NULL_Roots, 2, 5);

    Test_Stat(Right_Tests, All_Tests);
}
