#include<bits/stdc++.h>
using namespace std;

int theLoveLetterMystery(string s) {
	int ans = 0;
	int j=s.length()-1;
	for(int i =0;i<j;){
		ans += abs(s[i]-s[j]);
		i++;
		j--;
	}
	return ans;	
}

int main(){
	int n;
	vector<string> str;
	cin>>n;
	string temp;
	for(int i=0;i<n; i++){
		cin>>temp;
		str.push_back(temp);
	}
	for(int i=0;i<n;i++){
		cout<<theLoveLetterMystery(str[i])<<endl;
	}
	return 0;
}
