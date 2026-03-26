#include <iostream>
#include "rational.hpp"
using namespace std;

int main() {
    rational<int> r1(1, 2), r2(1, 3), r3(1, -2), r4(10,1);
	rational<int> inf(1, 0), zero(0, 1), nan(0, 0);

    cout << "\n" << r1 << " + " << r2 << " = " << (r1 + r2);
    cout << "\n" << r1 << " + (" << r3 << ") = " << (r1 + r3);
	cout << "\n" << r4 << " - " << r2 << " = " << (r4 - r2) ;
    cout << "\n" << r4 << " * " << r1 << " = " << (r4 * r1) <<"\n";
	
    cout << "\n-1/0: " << inf*rational(-1,1);
    cout << "\n0/0: " << nan;
    cout << "\nInf + Inf = " << (inf + inf);
    cout << "\nInf + (-Inf) = " << (inf + rational(-1,1)*inf);
	cout << "\nInf / Inf = " << (inf / inf);
    cout << "\nInf * 0 = " << (inf * zero) <<"\n\n";

    return 0;
}
