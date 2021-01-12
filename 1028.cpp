#include<iostream>
using namespace std;
int cnt;
int n;
int ileft;
int hmap[121];
int ii;
int main(){
    while(cin >> n){
        cnt=0;
        ii=0;
        ileft=n;
        for(int i=n;i>0;i--){
            ileft -= i;
            hmap[ii++]=i;
            for(int k=i;k>0 && ileft>=0;k--)
            {
                int sumj=0;
                k=ileft>k?k:ileft;
                for(int j=k;j>=0;)
                {
                    ileft -= j;
                    hmap[ii++]=j;
                    sumj += j;
                    j=ileft>j?j:ileft;
                    if(j==0){
                        cnt++;
                        break;
                    }
                }
                ileft+=sumj;
            }
            ileft +=i;
        }
        cout<< cnt<<endl;
    }
}
