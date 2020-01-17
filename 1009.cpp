#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
typedef struct{
    int beans;
    int catfood;
}javabeans;
bool compare(javabeans &a,javabeans &b){
    return (a.beans*1.0/a.catfood) > (b.beans*1.0/b.catfood) ;
}
int main(){
    javabeans jb[1001];
    int M,N;
    double sum;
    while(1){
        cin >> M >> N;
        if(M==-1 && N==-1)
            break;
        for(int i=0;i<N;i++)
        {
            cin>> jb[i].beans >> jb[i].catfood;
        }
        sort(jb,jb+N,compare);
        sum=0;
        for(int k=0;k<N && M > 0;k++){
            if((M -= jb[k].catfood) > 0){
                sum += jb[k].beans;
            }
            else {
                sum += jb[k].beans * 1.0*(M+jb[k].catfood)/jb[k].catfood;
                break;
            }
        }
        cout << fixed<<setprecision(3) << sum <<endl;
    }
}
