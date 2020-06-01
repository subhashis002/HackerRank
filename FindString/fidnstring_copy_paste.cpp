#include<bits/stdc++.h>
using namespace std;

vector findStrings(vector w, vector queries) { vector r; for(int i=0;i<queries.size();i++){

        for(int k=j;k<w[i].size();k++){
            int m=0;
            char c[k-j+1];
            for(int g=j;g<=k;g++){
                 c[m]=w[i][g];
                m++;

            }  c[m]='\0';
            r.push_back(c);               
        }              
    }     
}
sort(r.begin(),r.end());  
vector<string>::iterator ip;
ip = unique(r.begin(), r.end() );      
r.resize(std::distance(r.begin(), ip));
vector<string> ret;
for(int i=0;i<queries.size();i++){
        if(queries[i] <= r.size()){

        ret.push_back( r[queries[i]-1]);
    }`	
    else{
        ret.push_back("INVALID");
    }
}
return ret;
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
	vector<string> result = findStrings(str,queries);
	for(int i=0;i<result.size(); i++){
		cout<<result[i]<<endl;
	}
	return 0;
}
