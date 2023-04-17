#include <iostream>
#include "komplex.h"
#include <cassert>

using namespace std;

void assertApprox(Komplex c1, Komplex c2){
    Komplex diff = c1-c2;
    assert(diff.abs()<0.001);
}
void testKod(){
    Komplex c1 = 1 + 3.0_i;
    Komplex c2 = 5 - 5_i;

    assertApprox(c1+c2, Komplex(6,-2));
    assertApprox(c1,(c1*c2)/c2);

    assertApprox(2*c1, Komplex(2,6));
    assertApprox(c1*2, Komplex(2,6));

    Komplex k=1;
    Komplex rotate30 = Komplex::fromAbsArg(1, 30);
    for (int i=0; i<12; ++i){
        k *- rotate30;
        cout << i << '\t' << k << endl;
    }
}

int main()
{
    testKod();
    return 0;
}
