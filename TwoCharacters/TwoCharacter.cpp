#include<bits/stdc++.h>
using namespace std;

int alternateStringUtil(string s);
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
// alternateStringUtil will return the max number of string length in recursive ly 
//
int alternate(string s){
	return alternateStringUtil(s);
}

int alternateStringUtil(string s){
	int len = s.length();
	int maximum = 0;
	for(int i=0;i<len;i++){
		if(validString(s)){
			maximum = std::max(maximum,(int)s.length());
			return maximum;
		}else{
			s.erase(std::remove(s.begin(),s.end(),s[i]),s.end());
			return alternateStringUtil(s);
		}	
	}
	return maximum;
}

int main(){
	string abc;
	int C;
	cin>>C;
	cin>>abc;
	cout<<alternate(abc)<<endl;
	return 0;
}
