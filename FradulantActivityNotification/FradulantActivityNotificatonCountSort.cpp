#include<bits/stdc++.h>

using namespace std;
/*
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
*/

double findMedian(vector<int> &arr,int start,int d,int *count){
	double median = 0.0;
	if(start==0){
		
	}else{
		int add_element = arr[start+d];
		int delete_element = arr[start-1];
		count[add_element]++;
		count[delete_element]--;
	}
	if(d%2 != 0){
		int k = d/2;
		int j = 0;
		for(int i=0;i<201;i++){
			if(count[i] != -1){
				j+= count[i];
			}		
			if(j>=k){
				median = i * 1.0;
				//return median;
				break;
			}
		}
	}else{
		int k = (d-1)/2;
		int j = 0;
		double sum = 0.0;
		bool flag = false;
		for(int i=0;i<201;i++){
			if(count[i] != 0){
				j+= count[i];
			}		
			if(j==k){
				sum += i;
				flag = true;
			}
			
			if(j>k && flag == true){
				sum += i;
				//sum = sum / 2.0;
				median = sum / 2.0;
				//return median;
				break;
			}
			if(j>k && flag == false){
				sum += i;
				//sum = sum / 2.0;
				median = sum;
				//return median;
				break;
			}
		}
	}

	return median;	
}
int activityNotifications(vector<int> expenditure, int d) {
	int expenditure_length = expenditure.size();
	int result = 0;
	int count[201]={0};
	for(int i=0;i<d;i++){
		count[expenditure[i]]++;
	}

	for(int i=0;i<expenditure_length-d;i++){
		double median;
		median = findMedian(expenditure,i,d,count);	
		if(expenditure[i+d]>=2.0*median)
		//if((expenditure[i+d] - 2*median)>0.000000001)
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
