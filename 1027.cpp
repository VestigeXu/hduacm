#include<iostream>
using namespace std;
int n,m,cnt;
int hmap[1001];
int dmap[1001];
int dfs(int dep){
    int status=0;
    for(int i=1;i<=n;i++){
        if(hmap[i]==0 ){
            hmap[i]=1;
            dmap[dep+1]=i;
            if(dep+1==n){
                cnt++;
                if(cnt==m)
                {
                    for(int j=1;j<=n;j++)
                    {
                        cout << dmap[j];
                        if(j<n)cout << ' ';
                    }
                    cout << endl;
                    return 1;
                }

            }
            status=dfs(dep+1);
            if(status==1){
                return 1;
            }
            hmap[i]=0;
            dmap[dep+1]=0;
        }
    }
    return 0;
}
int main(){
    while(cin >> n>>m){
        for(int i=0;i<1001;i++)
            hmap[i]=dmap[i]=0;
        cnt=0;
        dfs(0);
    }
}
