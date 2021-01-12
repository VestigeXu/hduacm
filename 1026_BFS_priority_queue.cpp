#include <queue>
#include <iostream>
using namespace std;
#define MAX 1001
/*
 * 本题最大的问题，没有注意到就是 在第一次到达目的地的时候并不一定是最优解，需要全遍历完才能退出
 * 每次遍历到的点都需要进行比较 imap 的当前值 是否比 之前的大，大的话再替换
 * 用了优先队列为什么先到达的还不是最优解，有点想不通，希望大神解答一下。谢谢
 * 本题思路：1用优先队列BFS，同时，用dir 记录 到达这点是如何过来的，即 记录前一个节点step的数值
 * 最后，通过 从0,0 开始回退遍历即可获取 完整路径。
 * 注意，考虑到方便递归，广搜的时候从后往前搜。打结果就可以从前往后打了。当然这个是习惯，也可以dfs先然后打印，调一下即可。
 * */
struct node{
    int x,y,t;
    friend bool operator < (const node &a,const node &b){ //优先队列 比较 在a.t >b.t时进行调换，即小的先
        return a.t > b.t;
    }
};
priority_queue<node> pq;
int n,m,mint;
char cmap[MAX][MAX]; //存放地图
int imap[MAX][MAX];  //存放步数
int dir[MAX][MAX];  //存放当前点过来的路径方向
int step[4][2]={{-1,0},{1,0},{0,-1},{0,1}}; //方向
int judge(int x,int y){  
    /*
     *判断点位是否可以行走，返回点位状态
     * */
    if(cmap[x][y]=='X')
        return 0;
    if(x >= n || x<0 || y>=m || y<0)
        return 0;
    if(imap[x][y]!=0)
        return 2;
    return 1;
}
int BFS(priority_queue<node> &pqtmp)
{
    /*
     *开始广搜
     * */
    if(cmap[n-1][m-1]=='X' || cmap[0][0]=='X')
        return -1;
    node ntmp;
    ntmp.x=n-1;
    ntmp.y=m-1;
    if(cmap[n-1][m-1]>'0' && cmap[n-1][m-1]<='9') //起点遇到怪物需要增加步数
    {
        ntmp.t=cmap[n-1][m-1]-'0' +1;
        imap[n-1][m-1]=ntmp.t;
    }
    else 
    {
        imap[n-1][m-1]=1;
        ntmp.t=1;
    }
    pqtmp.push(ntmp);
    while(!pqtmp.empty()){
        ntmp = pqtmp.top();
        pqtmp.pop();
        if(ntmp.x==0 && ntmp.y==0 && mint>ntmp.t-1){  //如果到达0，0 比最小路径还小，记录一下。
            mint=ntmp.t-1;
        }
        for(int i=0;i<4;i++){
            node tmp;
            int it;
            tmp.x=ntmp.x+step[i][0];
            tmp.y=ntmp.y+step[i][1];
            if(judge(tmp.x,tmp.y)==0)//点位不是障碍物
                continue;
            it=cmap[tmp.x][tmp.y]-'0';
            if(it>0 && it<=9)
                tmp.t=ntmp.t+it+1;
            else
                tmp.t=ntmp.t+1;
            if(imap[tmp.x][tmp.y] <= tmp.t && imap[tmp.x][tmp.y]!=0) //过滤步数差于之前记录的 非常重要
                continue;
            imap[tmp.x][tmp.y]=tmp.t; //记录最优步数
            dir[tmp.x][tmp.y]=i; //记录方向
            pqtmp.push(tmp);
        }
    }
    return imap[0][0]>0?0:-1;
}
int Print(int x,int y){
    /*
     *用循环进行打印，根据dir方向指示，回退，一直到能n-1 m-1
     * */
    for(int itmp=0;itmp<mint;itmp++){
        int it;
        int j=0;
        if(x==n-1 && y==m-1){//遇到终点，如果有怪，打完怪 退出
            it=imap[x][y]-1;
            for(j=0;j<it;j++)
            {
                cout << mint-(imap[x][y]-j)+2 <<"s:FIGHT AT (" << x << ',' << y <<')' << endl;
            }
            return 1;
        }
            int nx=x-step[dir[x][y]][0];
            int ny=y-step[dir[x][y]][1];
            if(judge(nx,ny)) //不需要判断，完全根据路径走了
            {
                it=imap[x][y]-imap[nx][ny]; //计算 怪血量
                for(j=1;j<it;j++)
                {
                    cout << mint-(imap[x][y]-j-1) <<"s:FIGHT AT (" << x << ',' << y <<')' << endl;
                }
                cout << mint - (imap[x][y]-j-1) <<"s:(" << x <<','<< y <<")->(" << nx <<',' <<ny << ')' << endl;

            }
            x=nx;
            y=ny;
    }

    return 0;
}
int dfsPrint(int x,int y){
    int status=0;
    int it;
    int j=0;
    if(x==n-1 && y==m-1){
        it=imap[x][y]-1;
        for(j=0;j<it;j++)
        {
            cout << mint-(imap[x][y]-j)+2 <<"s:FIGHT AT (" << x << ',' << y <<')' << endl;
        }
        return 1;
    }
        int nx=x-step[dir[x][y]][0];
        int ny=y-step[dir[x][y]][1];
        if(judge(nx,ny))
        {
            it=imap[x][y]-imap[nx][ny];
            for(j=1;j<it;j++)
            {
                cout << mint-(imap[x][y]-j-1) <<"s:FIGHT AT (" << x << ',' << y <<')' << endl;
            }
            cout << mint - (imap[x][y]-j-1) <<"s:(" << x <<','<< y <<")->(" << nx <<',' <<ny << ')' << endl;

            status=dfsPrint(nx,ny);
        }
    return status;

}


int main(){
    while(cin >> n >> m){

        int status;
        mint=9999999;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> cmap[i][j];
                imap[i][j]=0;
                dir[i][j]=0;
            }
        }
        status=BFS(pq);/*
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout << imap[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout << dir[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        */
        if(status==0){
            cout << "It takes "<<mint<<" seconds to reach the target position, let me show you the way." <<endl;
            dfsPrint(0,0);  //打印 可以用dfsPrint或者Print
        }
        else{
            cout << "God please help our poor hero." <<endl;
        }
        cout << "FINISH" << endl;
    }
}

