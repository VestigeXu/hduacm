#include <iostream>
using namespace std;
int main(){
    int T;
    int N,in[100001];
    int i1;
    int maxs,maxe;
    int maxSum,tmpSum;
    cin >> T;
    for(int i=1;i<=T;i++)
    {
        cin >> N;
        for(int j=0;j<N;j++){
            cin >> in[j];
        }
        maxs=maxe=tmpSum=0;
        maxSum=in[0];
        //需注意边界，比如只有一个元素的时候，循环就不执行了
        for(i1=1;i1<N;i1++)
        {
            if(in[i1]+in[i1-1]>=in[i1])
                in[i1] += in[i1-1];
            else
                tmpSum=i1;
            if(in[i1]> maxSum){
                maxSum=in[i1];
                maxs=tmpSum;
                maxe=i1;
            }
        }
        cout << "Case " << i << ':' << endl;
        cout << maxSum << ' ' << maxs+1 << ' ' << maxe+1 <<endl;
        if(i<T) cout << endl;
    }
}
