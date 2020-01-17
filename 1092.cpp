#include <iostream>
using namespace std;
int main(){
    int n;
    int sum,i;
    while(1){
        cin >> n;
        sum=0;
        if(!n)break;
        while(n--){
            cin >> i;
            sum += i;
        }
        cout << sum <<endl;
    }
}
