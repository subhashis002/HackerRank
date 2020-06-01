#include<bits/stdc++.h>

using namespace std;
vector<string> weightedUniformStrings(string s, vector<int> queries) {
	vector<string> result;
	map<int,char> abc;
	map<int,char>::iterator itr;
	int str_length = s.length();
	//Motherchode : M-0,o-1,t-2,h-3,e-4,r-5,c-6,h-7,o-8,d-9,e-10
	//below loop will evaluate length = 11 so it will evaluate 9
	/*
	for(int i=0;i<s.length()-1;i++){ 
		int temp = 1;
		if(s[i]==s[i+1]){
			while(s[i]==s[i+1]&& i!=s.length()-2){
				temp++;
				i++;
			}
			abc.insert(pair<int,char>(temp,s[i]));
		}else{
			abc.insert(pair<int,char>(temp,s[i]));
		}
	}
	if(s[str_length-1]!=s[str_length-2]){
		abc.insert(pair<int,char>(1,s[str_length-1]));
	}
	*/
	int temp =1;
	bool flag = false;
	int mulitplier = 1;
	for(int i=0;i<str_length-1; i++){
		if(s[i]==s[i+1]){
			mulitplier = s[i] - 'a'+1;
			abc.insert(pair<int,char>(temp*mulitplier,s[i]));
			temp++;
			flag = true;

		}else{
			mulitplier = s[i] - 'a'+1;
			abc.insert(pair<int,char>(temp*mulitplier,s[i]));
			temp = 1;
			flag = false;
		}
		
	}
	mulitplier = s[str_length-1] -'a'+1;
	abc.insert(pair<int,char>(temp * mulitplier,s[str_length-1]));

	for(auto abc_itr = abc.begin(); abc_itr != abc.end(); abc_itr++){
		cout<<abc_itr->first<<" ";
	}
	for(vector<int>::iterator itr1 = queries.begin(); itr1 != queries.end(); itr1++){
		auto abc_itr = abc.find(*itr1);
		//cout<<*itr1<<endl;
		if(abc_itr == abc.end())
			result.push_back("NO");
		else
			result.push_back("YES");
	}
	return result;
		
}

int main(){
	string s;
	int count;
	vector<int> query;
	int temp,n;
	cin>>s;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>temp;
		query.push_back(temp);
	}
	vector<string> result = weightedUniformStrings(s,query);
	for(int i=0;i<n;i++)
		cout<<result[i]<<endl;
	return 0;
}
