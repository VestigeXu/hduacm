#include <iostream>
#include <map>
#include <string>
using namespace std;
int main(){
    int T;
    int populer;
    string populercol;
    map<string,int> color;
    map<string,int>::iterator iter;
    string strcolor;
    while(1){
        cin >> T;
        if(!T)break;
        color.erase(color.begin(),color.end());
        while(T--){
            cin >> strcolor;
            color[strcolor]++;
        }
        populer=0;
        for(iter = color.begin();iter != color.end(); iter++){
            if(iter->second > populer){
                populercol=iter->first;
                populer=iter->second;
            }

        }
        cout << populercol << endl;
    }
}
