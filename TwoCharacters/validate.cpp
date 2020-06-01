#include<bits/stdc++.h>
using namespace std;


bool validString(string str){
	if(str.length()==1) return false;
        if(str.length()==2){
		if(str[0]==str[1])
			return false;

        }
	for(int i=1;i<str.size()-1;i++){
                if(str[i-1]!=str[i] && str[i-1]==str[i+1]) continue;
                else return false;
        }
        return true;
}

int main(){
	string s = "a";
	cout<<validString(s)<<endl;
}
