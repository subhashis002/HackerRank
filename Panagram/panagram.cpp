#include<bits/stdc++.h>

using namespace std;

string pangrams(string s) {
	string abc = "abcdefghijklmnopqrstuvwxyz";
	transform(s.begin(),s.end(),s.begin(),::tolower);
	cout<<s<<endl;
	for(int i=0;i<abc.length();i++){
		int idx = s.find(abc[i]);
		if(idx == string::npos)
			return "not pangram";	
	}
	return "pangram";
}

int main(){
	string s;
	//cin>>s;
	getline(cin,s);
	cout<<pangrams(s)<<endl;
	return 0;
}
