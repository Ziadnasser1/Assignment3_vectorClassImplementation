#include <bits/stdc++.h>
using namespace std;
#include "YZVector.cpp"
int main(){
    YZVector <string> vec(1);
    vec.push_back("hello");
    vec.push_back("world");
    cout<<vec[0] + vec[1]<<endl;

}
