#include <iostream>
#include<cstring>
#include<string>
using namespace std;
 
int main() {
        char s[1001];
        int count;
        int iarr[1001];
        char *p;
        while(cin >> s){
            const char *delim = "5";
            count=0;
            p = strtok(s, delim);
            while(p) {
                count++;
                int tmp=stoi(p);
                for(int i=0;i<count-1;i++){
                    if(tmp < iarr[i])
                    {
                        int swt=tmp;
                        tmp=iarr[i];
                        iarr[i]=swt;
                    }
                }
                iarr[count-1]=tmp;
                p = strtok(NULL, delim);

            }
            for(int i=0;i<count;i++){
                if(i!=0)cout<< ' ';
                cout << iarr[i];
            }
            cout << endl;

        }
        return 0;

}
