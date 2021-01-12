#include <queue>
#include <iostream>
using namespace std;
#define MAX 1001
struct node{
    int x,y,t;
    friend bool operator < (const node &a,const node &b){
        return a.t > b.t;
    }
};
priority_queue<node> pq;
int n,m,mint;
char cmap[MAX][MAX];
int imap[MAX][MAX];
int dir[MAX][MAX];
int step[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
bool judge(int x,int y){
    if(cmap[x][y]=='X')
        return false;
    if(x >= n || x<0 || y>=m || y<0)
        return false;
    return true;
}
int BFS(priority_queue<node> &pqtmp)
{
    if(cmap[n-1][m-1]=='X' || cmap[0][0]=='X')
        return -1;
    node ntmp;
    ntmp.x=n-1;
    ntmp.y=m-1;
    if(cmap[n-1][m-1]>'0' && cmap[n-1][m-1]<='9')
    {
        ntmp.t=cmap[n-1][m-1]-'0';
        imap[n-1][m-1]=ntmp.t;
    }
    else 
    {
        imap[n-1][m-1]=0;
        ntmp.t=0;
    }
    pqtmp.push(ntmp);
    while(!pqtmp.empty()){
        ntmp = pqtmp.top();
        pqtmp.pop();
        if(ntmp.x==0 && ntmp.y==0 && mint > ntmp.t){
            mint=ntmp.t;
        }
        for(int i=0;i<4;i++){
            node tmp;
            int it;
            tmp.x=ntmp.x+step[i][0];
            tmp.y=ntmp.y+step[i][1];
            if(!judge(tmp.x,tmp.y))
                continue;
            if(tmp.x == n-1 &&tmp.y==m-1)
                continue;
            it=cmap[tmp.x][tmp.y]-'0';
            if(it>0 && it<=9)
                tmp.t=ntmp.t+it+1;
            else
                tmp.t=ntmp.t+1;
            if(imap[tmp.x][tmp.y]>tmp.t || imap[tmp.x][tmp.y]==0)
            {
                imap[tmp.x][tmp.y]=tmp.t;
                dir[tmp.x][tmp.y]=i;
                pqtmp.push(tmp);
            }
        }
    }
    return imap[0][0]>0?0:-1;
}
int main(){
    int x=0,y=0;
    int nx;
    int ny;
    int distance;
    int j=0;
    while(cin >> n >> m){
        int status;
        mint=999999;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> cmap[i][j];
                imap[i][j]=0;
                dir[i][j]=0;
            }
        }
        status=BFS(pq);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout << imap[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout << dir[i][j] << "  ";
            }
            cout << endl;
        }
        cout << endl;
        x=y=0;
        if(status==0){
            cout << "It takes "<<mint<<" seconds to reach the target position, let me show you the way." <<endl;
            for(int i=0;i<mint;i++){
                nx=x-step[dir[x][y]][0];
                ny=y-step[dir[x][y]][1];
                distance = cmap[x][y]-'0';
                j=0;
                if(cmap[x][y] >'0' && cmap[x][y]<='9'){
                    if(x==n-1 && y==m-1 && distance >0)
                    {
                        imap[x][y]=distance;
                        for(j=0;j<distance;j++,i++){
                            cout << mint-(imap[x][y]-j)+1 <<"s:FIGHT AT (" << x << ',' << y <<')'<<endl;
                        }
                        break ;
                    }
                    for(j=0;j<distance;j++,i++){
                        cout << mint-(imap[x][y]-j)+1 <<"s:FIGHT AT (" << x << ',' << y <<')'<<endl;
                    }
                }
                if(x!=n-1 || y!=m-1)
                {
                cout << mint - (imap[x][y]-j)+1 <<"s:(" << x <<','<< y <<")->(" << nx <<',' <<ny << ')' << endl;
                }

                x=nx;
                y=ny;
            }
        }
        else{
            cout << "God please help our poor hero." <<endl;
        }
        cout << "FINISH" << endl;
    }
}
