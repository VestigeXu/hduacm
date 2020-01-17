#include<iostream>
using namespace std;
int arr[21];
int tmpArr[21];
int n;
int cs;
int dfs(int in,int d){
    for(int i=2;i<=n;i++){
        if(arr[i]==0)
        switch(in+i){
            case 3:
            case 5:case 7: case 11:case 13:case 17:case 19:
            case 23:case 29:case 31:case 37:
                tmpArr[d]=i;
                arr[i]=1;
                if(n==d){
                    switch(tmpArr[d]+1){
                        case 3:
                        case 5:case 7: case 11:case 13:case 17:case 19:
                        case 23:case 29:case 31:case 37:
                            tmpArr[d]=i;
                            tmpArr[1]=1;
                            for(int j=1;j<=n;j++){
                                cout << tmpArr[j];
                                if(j<n)cout << ' ';
                                else cout << endl;
                            }
                    }
                }
                else{
                    dfs(i,d+1);
                }
                arr[i]=0;
        }
    }
    return 0;
}
int main(){
    cs=0;
    while(cin >> n){
        if(n%2 != 0)
        {
            cout << "Case " << ++cs <<':' <<endl;
            cout << endl;
            continue;
        }
        cout << "Case " << ++cs <<':' <<endl;
        dfs(1,2);
        cout << endl;
    }
}
