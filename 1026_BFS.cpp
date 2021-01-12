#include <queue>
#include <iostream>
using namespace std;
#define MAX 201
struct node{
    int x,y,t;
};
queue<node> pq;
int n,m,mint;
char cmap[MAX][MAX];
int imap[MAX][MAX];
int dir[MAX][MAX];
int step[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int BFS(queue<node> &pqtmp)
{
    if(cmap[n-1][m-1]=='X')
        return 0;
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
        ntmp = pqtmp.front();
        pqtmp.pop();
        if(ntmp.x==0 && ntmp.y==0){
            mint=ntmp.t;
        }
        for(int i=0;i<4;i++){
            node tmp;
            int it;
            tmp.x=ntmp.x+step[i][0];
            tmp.y=ntmp.y+step[i][1];
            it=cmap[ntmp.x+step[i][0]][ntmp.y+step[i][1]]-'0';
            if(it>0 && it<=9)
                tmp.t=ntmp.t+it+1;
            else
                tmp.t=ntmp.t+1;
            if((tmp.t>=imap[tmp.x][tmp.y] && imap[tmp.x][tmp.y]>0) || cmap[tmp.x][tmp.y]=='X')
                continue;
            if(tmp.x==n-1 && tmp.y==m-1 )
                continue;
            if(tmp.x >= 0 && tmp.x < n && tmp.y >= 0 && tmp.y < m)
            {
                pqtmp.push(tmp);
                imap[tmp.x][tmp.y]=tmp.t;
                dir[tmp.x][tmp.y]=i;

            }
        }
    }
    return imap[0][0]>0?0:-1;
}
void print(int x,int y){
    int nx=x-step[dir[x][y]][0];
    int ny=y-step[dir[x][y]][1];
    int distance = imap[x][y]-imap[nx][ny];
    int i;

    if(x==n-1 && y==m-1){
        distance=imap[x][y];
        for(i=0;i<distance;i++){
            cout << mint-(imap[x][y]-i-1) <<"s:FIGHT AT (" << x << ',' << y <<')' << endl;
        }
        return;
    }
    for(i=1;i<distance;i++){
        cout << mint-(imap[x][y]-i) <<"s:FIGHT AT (" << x << ',' << y <<')'<<endl;
    }
    cout << mint - (imap[x][y]-i) <<"s:(" << x <<','<< y <<")->(" << nx <<',' <<ny << ')' << endl;
    print(nx,ny);
}
int main(){
    while(cin >> n >> m){
        int status;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> cmap[i][j];
                imap[i][j]=0;
            }
        }
        status=BFS(pq);
        ///*
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
//*/
        if(status==0){
            cout << "It takes "<<mint<<" seconds to reach the target position, let me show you the way." <<endl;
            print(0,0);
        }
        else{
            cout << "God please help our poor hero." <<endl;
        }
        cout << "FINISH" << endl;
    }
}

