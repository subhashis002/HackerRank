#include<bits/stdc++.h>

using namespace std; 
int lilysHomeworkUtil(vector<int> arr);
int lilysHomework(vector<int> arr){
	int asc,desc,ans;
	asc = lilysHomeworkUtil(arr);
	reverse(arr.begin(),arr.end());
	desc = lilysHomeworkUtil(arr);
	ans = min(asc,desc);
	return ans;
}
int lilysHomeworkUtil(vector<int> arr){
	int n = arr.size();
	vector<pair<int,int> > vec(n);

	for(int i=0; i<n; i++){
		vec[i].first = arr[i];
		vec[i].second = i;
	}
	sort(vec.begin(),vec.end());
	/*
	for(int i=0;i<n; i++)
		cout<<vec[i].first<<" ";
	cout<<endl;
	for(int i=0;i<n; i++)
		cout<<vec[i].second<<" ";
	cout<<endl;
	*/
	int ans = 0;
	for(int i=0;i<n; i++){
		if(vec[i].second == i)
			continue;
		else{
			swap(vec[i].first,vec[vec[i].second].first);
			swap(vec[i].second,vec[vec[i].second].second);
		}

		if(i != vec[i].second)
			--i;

		ans++;
	}
	return ans;

}
int main(){
	int n,temp;
	vector<int> arr;
	cin>>n;
	for(int i=0;i<n; i++){
		cin >> temp;
		arr.push_back(temp);
	}
	int ans = lilysHomework(arr);
	cout<<ans<<endl;
	return 0;
}
