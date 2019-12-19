#include <iostream>
using namespace std;
int main(){
    int T;
    int M,sum,tmp;
    cin >> T;
    while(T--){
        cin >> M;
        sum=0;
        while(M--){
            cin >> tmp;
            sum +=tmp;
        }
        cout << sum << endl;
        if(T)cout << endl;
    }
}
