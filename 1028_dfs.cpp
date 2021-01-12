#include<iostream>
using namespace std;
int hmap[121];
int cnt;
int n;
void dfs(int max,int left,int n)
{
        /*
        for(int i=0;i<=n;i++)
            cout << hmap[i]<<' ';
        cout << endl;
        */
    max= max>left?left:max;
    for(int i=max;i>0 ;i--){
        if(left-i>0){

            //hmap[n]=i;
            dfs(i,left-i,n+1);
        }
        else if(left-i ==0){
            cnt++;
        }
    }
}
int main(){
    while(cin >> n){
        cnt=0;
        dfs(n,n,0);
        for(int i=1;i<=10;i++)
        {
            cnt=0;
            dfs(i,i,0);
            cout << cnt <<',';
        }
        cout<< cnt<<endl;
    }
}
