#include <iostream>

using namespace std;

int main(void){

    double x;
    
    cin >> x;

    double l = -1e4, r = 1e4;
    while(r - l > 1e-8){
        double mid = (l + r) / 2;
        if(mid * mid * mid >= x) r = mid;
        else l = mid;
    }

    printf("%lf\n", l);

    return 0;
}