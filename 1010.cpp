#include <iostream>
using namespace std;
/*此题关键在于剪枝，奇偶减枝
 * 010101
 * 101010
 * 010101
 * 101010
 * 如上，0区域和1区域需要到达都会是奇数，00区域相互到达都是偶数
 * 当时间为t，只需要判断横竖相差（最短路径）和T的差距，
 * T-最短 永远只能是偶数，因为 无论为了避免路障，往左或者右走了
 * 一步，都需要按照最短路方向回走。*/
int map[8][8];
char cmap[8][8];
int N,M,T;
int CanSurvive;
int DFS(int x,int y,int value){
    if(x<0 || y <0 || x>=N || y >=M) //超出路径范围退出
        return 0;
    if(cmap[x][y] == 'X')  //遇到墙体 直接退出
        return 0;
    if(value > T || CanSurvive) //超时 或者已经可以即退出
        return 0;
    if(map[x][y]==0)
    {        
        if(cmap[x][y]=='D' && value ==T) //遇到答案 打标志
        {
            CanSurvive=1;
            return 0;
        }
        map[x][y]=value+1;
        DFS(x,y-1,map[x][y]);
        DFS(x+1,y,map[x][y]);
        DFS(x,y+1,map[x][y]);
        DFS(x-1,y,map[x][y]);
        map[x][y]=0;
    }
    return 0;
}
int main(){
    int isx,isy;
    int iex,iey;
    while(1){
        cin >> N >> M >> T;
        CanSurvive=0;
        if(N==0 && M==0 && T==0)
            break;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                cin >> cmap[i][j];
                map[i][j]=0;
                if(cmap[i][j] == 'S')
                {
                    isx=i;
                    isy=j;
                }
                if(cmap[i][j] == 'D')
                {
                    iex=i;
                    iey=j;
                }
            }
        }
        int path= abs(isx-iex)+abs(isy-iey);
        if(T-path < 0 || (T-path)&1)
        {         
            cout << "NO" << endl;
            continue;
        }
        DFS(isx,isy,0);
        if(CanSurvive)
            cout << "YES"<<endl;
        else
            cout << "NO"<<endl;
    }
}
