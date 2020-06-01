#include<bits/stdc++.h>

using namespace std;
string funnyString(string s) {
	string s1(s);
	bool flag = true;
	reverse(s1.begin(),s1.end());
	for(int i=0;i<s.length()-1;i++){	
		if(abs(s[i]-s[i+1])!=abs(s1[i]-s1[i+1])){
			return "Not Funny";
		}
	}
	return "Funny";
}

int main(){
	int n;
	string s;
	cin>>n;
	while(n--){
		cin>>s;
		cout<<funnyString(s)<<endl;
	}
	return 0;
}
