//This one is for counting the inversion 
//https://www.geeksforgeeks.org/counting-inversions/

#include<bits/stdc++.h>
#define N 100000
using namespace std;


int mergeSortUtil(vector<int> &arr,int temp[],int left,int right);
int merge(vector<int> &arr,int temp[],int left,int mid,int right);
void printArray(vector<int> arr);
int mergeSort(vector<int> &arr,int array_size){
	int temp[N];
	return mergeSortUtil(arr,temp,0,array_size-1);
}

int mergeSortUtil(vector<int> &arr,int temp[],int left,int right){
	int mid,inv_count = 0;
	if(right > left){
		mid = (right + left)/2;

		inv_count += mergeSortUtil(arr,temp,left,mid);
		inv_count += mergeSortUtil(arr,temp,mid+1,right);
		inv_count += merge(arr,temp,left,mid+1,right);
	}
	return inv_count;
}

int merge(vector<int> &arr,int temp[],int left,int mid,int right){
	int i,j,k;
	long inv_count = 0;
	i = left;
	j= mid;
	k = left;

	while((i<=mid-1) && (j<=right)){
		if(arr[i] <= arr[j]){
			temp[k++] = arr[i++];
		}else{
			temp[k++] = arr[j++];
			inv_count = inv_count + (mid-i);
		}

	}

	while(i<=mid-1){
		temp[k++] = arr[i++];
	}
	while(j<=right){
		temp[k++] = arr[j++];
	}

	for(int counter=left; counter<=right; counter++){
		arr[counter] = temp[counter];
	}

	return inv_count;
}

void printArray(vector<int> arr){
//	cout<<endl;
	for(int i=0;i<7;i++){
		cout<<" "<<arr[i]<<" ";
	}
	cout<<endl;
}

int main(){
	vector<int> arr;
	ifstream fin("input07.txt");
	if(!fin.is_open()){
		cout<<"Not able to opne input.txt";
		exit(1);
	}
	int no_of_input,n;
	long inversion;
	fin>>no_of_input;
	for(int i=0;i<no_of_input;i++){
		arr.clear();
		fin>>n;
		for(int j=0;j<n;j++){
			int temp;
			fin>>temp;
			arr.push_back(temp);
		}
		inversion = mergeSort(arr,n);
		cout<<inversion<<endl;
	}
	fin.close();
	return 0;
}
