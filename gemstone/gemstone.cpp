#include<bits/stdc++.h>
using namespace std;

int gemstones(vector<string> arr) {
	string a2z = "abcdefghijklmnopqrstuvwxyz";
	int count = 0;
	for(int i=0;i<a2z.length();i++){
		bool flag = true;
		for(int j=0;j<arr.size();j++){
			size_t idx = arr[j].find(a2z[i]);
			if(idx == string::npos){
				flag = false;
				break;
			}
		}
		if(flag) count++;
	}
	return count;
}


int main(){
	int n;
	cin>>n;
	vector<string> str;
	string temp;
	while(n--){
		cin>>temp;
		str.push_back(temp);
	}
	cout<<gemstones(str)<<endl;
	return 0;

}
