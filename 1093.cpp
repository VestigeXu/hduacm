#include <iostream>
using namespace std;
int main(){
    int n,m;
    int sum,input;
    cin >> n;
    while(n--){
        cin >> m;
        sum=0;
        while(m--){
            cin >> input;
            sum += input;
        }
        cout << sum << endl;
    }
}
