#include<iostream>
using namespace std;
int main(){
    int T;
    int n;
    int arr[1001];
    cin >> T;
    while(T--){
        cin >> n;
        for(int i=0;i<n;i++){
            int tmp;
            cin >> tmp;
            for(int j=0;j<=i;j++){
                int wap;
                if(i==j || arr[j] > tmp){
                    wap=tmp;
                    tmp=arr[j];
                    arr[j]=wap;
                }
            }
        }
        for(int i=0;i<n;i++){
            cout << arr[i];
            if(i<(n-1))cout << ' ';
            else cout << endl;
        }
    }
}
