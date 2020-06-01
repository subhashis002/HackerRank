#include<bits/stdc++.h>

using namespace std;

void separateNumbers(string s) {
	bool valid = false;
	long firstx = -1;
	for(int i=1;i<=s.length()/2;i++){
		long x = stol(s.substr(0,i));
		firstx = x;
		string test = to_string(x);
		//cout<<i<<" "<<test<<" s.length()/2 "<<s.length()/2<<endl;
		//cout<<x<<" "<<test<<" "<<test.length()<<" "<<s.length()<<endl;
		while(test.length()<s.length()){
			test += to_string(++x);
			//cout<<i<<" "<<test<<endl;
		}
		if(test == s){
			valid = true;
			break;
		}
	}
	valid ? cout<<"YES "<<firstx<<endl : cout<<"NO"<<endl;	
}

int main(){
	int n;
	string s;
	cin>>n;
	while(n--){
		cin>>s;
		separateNumbers(s);
	}
	return 0;
}
