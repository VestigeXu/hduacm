#include <iostream>
#include <string>
/*此题最大的问他就是输入的时候数据非常非常大。无法存下，只能用字符串
 * 还有一个关键问题要注意，while语句内 不要写 赋值和判断 混用，极大
 * 影响AC结果，会超时*/
using namespace std;
int deepAdd(int aa){
    int sum=0;
    do{
        sum += aa%10;
        aa /= 10;
    }
    while(aa>0);
    if(sum <10)
        return sum;
    else
        return deepAdd(sum);
}
int main(){
    int n;
    string str;
    while(1){
        cin >> str;
        for(int i=n=0;i<str.length();i++){
            n += str[i]-'0';
        }
        if(!n)
            break;
        cout << deepAdd(n)<< endl;
    }
}
