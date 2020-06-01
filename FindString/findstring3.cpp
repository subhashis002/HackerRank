#include<bits/stdc++.h>

using namespace std;
/*
bool CompareVector(string first,string  second){
	int first_length = first.length();
	int second_length = second.length();

	    for (int i=0; i< first.length(); i++)
		           if (first[i] < second[i])
				            return true;
	        return false;
}
*/

bool CompareVector(string first, string second){
	if(first <= second)
		return true;
	return false;
}

// A function objecto to do lexicographical comparisons
template <typename Container>
bool LexCompare(const Container& a, const Container& b) {
    return std::lexicographical_compare(a.begin(), a.end(),
                                        b.begin(), b.end());
}

// Use that comparison function to sort a range:
template <typename ContainerIterator>
void sort_by_lexicographical_comapre(ContainerIterator beg,
                                     ContainerIterator end)
{
    std::sort(beg, end, LexCompare<typename ContainerIterator::value_type>);
}
vector<string> findStrings(vector<string> w, vector<int> queries) {
	vector<string> dupset;
	vector<string> result;
	for(int i=0;i<w.size();i++){
		int string_length = w[i].length();
		for(int j=0;j<string_length;j++){
			string temp="";
			for(int k=j;k<string_length;k++){
				temp += w[i][k];
				if(temp.length()==0) continue;
				//if(find(dupset.begin(),dupset.end(),temp)==dupset.end())
				dupset.push_back(temp);
			}
		}
	}

	sort(dupset.begin(),dupset.end());
	vector<string>::iterator ip;
	ip = unique(dupset.begin(),dupset.end());
	dupset.resize(std::distance(dupset.begin(),ip));
	//sort_by_lexicographical_comapre(dupset.begin(),dupset.end());	
	int dupset_length = dupset.size();
	/*for(int i=0;i<dupset.size();i++){
		cout<<dupset[i]<<endl;
	}*/

       	
	for(int i=0; i<queries.size();i++){
		if(dupset_length>=queries[i])
			result.push_back(dupset[queries[i]-1]);
		else
			result.push_back("INVALID");
	}
	return result;	
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

