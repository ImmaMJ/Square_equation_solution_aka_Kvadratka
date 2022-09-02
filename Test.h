#include  "Kva.h"
#define Test_lin(a, b, c, nRoots, x1, x2)                              \
        str = {a, b, c, nRoots, x1, x2};                               \
        Wrong_Tests += lin_test(&str);                                 \
        All_Tests += 1;                                                \
        Right_Tests = All_Tests - Wrong_Tests;                         \

#define Test_sqr(a, b, c, nRoots, x1, x2)                              \
        str = {a, b, c, nRoots, x1, x2};                               \
        Wrong_Tests += sqr_test(&str);                                 \
        All_Tests += 1;                                                \
        Right_Tests = All_Tests - Wrong_Tests;                         \

#define Test_Eq(a, b, c, nRoots, x1, x2)                               \
        str = {a, b, c, nRoots, x1, x2};                               \
        Wrong_Tests = EQ_test(&str);                                   \
        All_Tests += 1;                                                \
        Right_Tests = All_Tests - Wrong_Tests;                         \


typedef     struct
            {
                double a;
                double b;
                double c;
                enum Root_flags nRoots;
                double x1;
                double x2;
            }                  struc;


static bool double_eq (const double p, const double q);

int lin_test (struc* str);

int sqr_test (struc* str);

int EQ_test (struc* str);

int All_Tests = 0;

int Wrong_Tests = 0;

int Right_Tests = 0;

void Test_Stat(const int All_Tests, const int Wrong_Tests);
