#include <iostream>
#include "main.h"

using namespace std;

int main() 
{
    constexpr Polynom<3> pol = { StructOfPolynom{0, 1}, StructOfPolynom{1, 2}, StructOfPolynom{2, 3} };
    constexpr int res = pol.mean(1);
    cout << res;
    //cout << pol;
    return 0;
}
