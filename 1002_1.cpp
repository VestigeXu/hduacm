#include<iostream>
#include<string>
using namespace std;
int main(){
    int T;
    string sa,sb;
    int isa,isb;
    int maxlength;
    int sum[2000];
    cin >> T;
    for(int cs=0;cs<T;cs++)
    {
        cin >> sa >>sb;
        isa = sa.length();
        isb = sb.length();
        maxlength = isa>isb?isa:isb;
        sum[0]=0;
        for(int i=0;i<maxlength;i++)
        {
            sum[i+1] = 0;
            sum[i] += ((i+1)>isa?'0':sa[isa-1-i]) - '0' + ((i+1)>isb?'0':sb[isb-1-i]) -'0';
            if(sum[i] > 9){
                sum[i+1] = sum[i]/10;
                sum[i] %=10; 
            }
        }
        cout << "Case " << cs+1 << ":\n" << sa << " + " << sb << " = ";
        for(int i=0;i<maxlength;i++){
            if(i==0 && sum[maxlength]) continue;
            cout << sum[maxlength-i-1];
        }
        cout << endl;
        if(cs!= T-1) cout << endl;
    }
}
