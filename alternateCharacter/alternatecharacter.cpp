#include<bits/stdc++.h>

using namespace std;

int alternatingCharacters(string s) {
	int count = 0;
	for(int i=0;i<s.length()-1;i++){
		if(s[i]==s[i+1])
			count++;
	}
	return count;
}

int main(){
	int n;
	vector<string> str;
	cin>>n;
	for(int i=0;i<n; i++){
		string temp;
		cin>>temp;
		str.push_back(temp);
	}
	for(int i=0;i<n;i++){
		cout<<alternatingCharacters(str[i])<<endl;
	}
	return 0;
}
