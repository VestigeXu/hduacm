#include <iostream>

using namespace std;
int main(){
    int T=1;
    int iarr[101];
    int icost;
    while(T!=0){
        cin >> T;
        icost=0;
        for(int i=0;i<T;i++){
            cin >> iarr[i];
            if(i==0)
            {
                icost=(iarr[0]-0)*6+5;
            }
            else {
                if(iarr[i]>iarr[i-1])
                    icost += (iarr[i]-iarr[i-1])*6+5;
                else
                    icost += (iarr[i-1]-iarr[i])*4+5;
            }
        }
        if(T)cout << icost << endl;
    }
    return 0;
}
