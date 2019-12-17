#include <iostream>
using namespace std;
int sum(int i){
    if(i==1)return  1;
    return i+sum(i-1);
}
int main(){
    int ia;
    while(cin >> ia){
        cout << sum(ia) << endl;
        cout << endl;
    }
}
