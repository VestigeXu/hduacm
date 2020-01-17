#include <iostream>
using namespace std;
int main(){
    int n;
    int tmp,sum;
    while(cin >> n){
        sum=0;
        while(n--){
            cin >> tmp;
            sum += tmp;
        }
        cout << sum << endl;
    }
}
