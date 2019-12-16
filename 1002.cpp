#include <iostream>
#include <string>
using namespace std;
int main(){
    int T,Case;
    int ia,ib;
    int ij=0;
    int i,j; 
    string a,b;
    char sum[2002];
    cin >> T;
    for(Case=1;Case<=T;Case++){
        cin >> a >> b;
        ia=a.length();
        ib=b.length();
        for(i=1;i <= (ia>ib?ia:ib) || ij!=0;i++){
            sum[i-1] = (i>ia?'0':a[ia-i]) + (i>ib?'0':b[ib-i]) -'0';
            sum[i]='\0';
        }
        for(j=0;sum[j]!='\0';j++){
            if(sum[j]>'9'){
                sum[j] -= 10;
                sum[j+1] +=1;
            }
        }
        cout << "Case " << Case << ':' << endl;
        cout << a << " + " << b << " = ";
        while(j--){
            cout << sum[j];
        }
        cout << endl;
        if(Case != T)cout << endl;
    }
}
