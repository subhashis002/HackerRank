#include<bits/stdc++.h>

using namespace std;
void printVector(vector<string> x){
	cout<<"Printing the vector value"<<endl;
	for(vector<string>::iterator itr = x.begin(); itr != x.end(); itr++){
		cout<<*itr<<endl;
	}
}
void findStrings(vector<string> w, vector<int> queries) {
	vector<string> dupset;
	vector<string> result;
	//printVector(w);
	for(int i=0;i<w.size();i++){
		int string_length = w[i].length();
		for(int j=0;j<pow(2,string_length);j++){
			string temp="";
			for(int k=0;k<string_length;k++){
				if((j & (1<<k)) != 0){
					temp += w[i][k];
				}
			}
			//cout<<temp<<endl;
			if(temp.length()==0) continue;	
			if(find(dupset.begin(),dupset.end(),temp)==dupset.end())
				dupset.push_back(temp);
		}
	}
	/*
	for(int i=0;i<dupset.size();i++){
		cout<<dupset[i]<<endl;
	}
	*/
	sort(dupset.begin(),dupset.end());
	int dupset_length = dupset.size();
	for(int i=0;i<dupset.size();i++){
		cout<<dupset[i]<<endl;
	} 
	for(int i=0;i<queries.size();i++){
		cout<<queries[i]<<endl;
	} 
	for(int i=0; i<queries.size();i++){
		if(dupset_length>=queries[i])
			cout<<dupset[queries[i]-1]<<endl;
		else
			cout<<("INVALID")<<endl;
	}
	/*
	for(int i=0; i<queries.size();i++){
		if(dupset_length<=queries[i])
			result.push_back(dupset[queries[i]-1]);
		else
			result.push_back("INVALID");
	}
	*/
}
int main(){
	int n;
	vector<string> str;
	int nq;
	vector<int> queries;
	cin>>n;
	string temp;
	int temp1;
	while(n--){
		cin>>temp;
		str.push_back(temp);
	}
	cin>>nq;
	while(nq--){
		cin>>temp1;
		queries.push_back(temp1);
	}
	findStrings(str,queries);
/*	vector<string> result = findStrings(str,queries);
	for(int i=0;i<result.size(); i++){
		cout<<result[i]<<endl;
	}
*/
	return 0;
}
