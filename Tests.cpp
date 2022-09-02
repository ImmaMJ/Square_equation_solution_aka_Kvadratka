#include "Kva.h"

static bool double_eq (const double p, const double q)
{
    if (isnan(p) && isnan (q))
        return true;
    if (isinf(p) && isinf (q))
        return true;
    if (Is_zero(p - q))
        return true;
    return false;
}

int lin_test (struc* str)
{
        double x1 = NAN;

        enum Root_flags answ = Sol_lineal (str->b, str->c, &x1);

        if(!(str->nRoots == answ && double_eq(x1, str->x1)))
        {
            printf("Test number %d failed");
            return 0;
        }
        return 1;
}

int sqr_test (struc* str)
{
        double x1 = NAN, x2 = NAN;

        enum Root_flags answ = Sol_square (str->a, str->b, str->c, &x1, &x2);

        if(!(str->nRoots == answ && double_eq(x1, str->x1) && double_eq(x2, str->x2)))
        {
            printf("Test number %d failed");
            return 0;
        }
        return 1;
}

int EQ_test (struc* str)
{
        double x1 = NAN, x2 = NAN;
        enum Root_flags answ = Eq_solution (str->a, str->b, str->c, &x1, &x2);

        if(!(str->nRoots == answ && x1 == str->x1 && x2, str->x2))
        {
            printf("Test number %d failed");
            return 0;
        }
        return 1;
}

void Test_Stat(const int Right_Tests_int, const int All_Tests_int)
{
    printf("There is %d ", Right_Tests, " / %d", All_Tests, "tests run right");
}
