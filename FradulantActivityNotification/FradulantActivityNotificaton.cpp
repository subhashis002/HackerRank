#include<bits/stdc++.h>

using namespace std;
double findMedian(vector<int> &arr,int start,int d){
	vector<int> temp(d);
	//copy(arr.begin()+start,arr.begin()+(start+d),back_inserter(temp));
	//sort(temp.begin(),temp.end());
	partial_sort_copy(arr.begin()+start,arr.begin()+(start+d),temp.begin(),temp.end());
	if(d%2 != 0){
		return (double)temp[d/2];
	}
	return (double)(temp[(d-1)/2] + temp[d/2])/2.0;

}
int activityNotifications(vector<int> expenditure, int d) {
	int expenditure_length = expenditure.size();
	int result = 0;
	
	for(int i=0;i<expenditure_length-d;i++){
		double median;
		median = findMedian(expenditure,i,d);	
		if(expenditure[i+d]>=2*median)
			result++;
	}
	return result;
}

int main(){
	int n,d;
	int temp;
	vector<int> arr;
	cin >> n;
	cin >> d;
	for(int i=0;i<n;i++){
		cin>>temp;
		arr.push_back(temp);
	}

	int result = activityNotifications(arr,d);
	cout<<result<<endl;
	return 0;
}
