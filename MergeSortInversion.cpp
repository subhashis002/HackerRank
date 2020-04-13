//This one is for counting the inversion 
//https://www.geeksforgeeks.org/counting-inversions/

#include<bits/stdc++.h>
using namespace std;

int _mergeSort(int arr[],int temp[],int left,int right);
int merge(int arr[],int temp[],int left,int mid,int right);
void printArray(int arr[]);
int mergeSort(int arr[],int array_size){
	int temp[array_size];
	return _mergeSort(arr,temp,0,array_size-1);
}

int _mergeSort(int arr[],int temp[],int left,int right){
	int mid,inv_count = 0;
	if(right > left){
		mid = (right + left)/2;

		inv_count += _mergeSort(arr,temp,left,mid);
		//printArray(arr);
		
		inv_count += _mergeSort(arr,temp,mid+1,right);
		//printArray(arr);
		inv_count += merge(arr,temp,left,mid+1,right);
		printArray(arr);
	}
	return inv_count;
}

int merge(int arr[],int temp[],int left,int mid,int right){
	int i,j,k;
	int inv_count = 0;
	i = left;
	j= mid;
	k = left;
    	//cout<<"i : "<<i<<" j: "<<j<<" k: "<<k<<endl;

	while((i<=mid-1) && (j<=right)){
		if(arr[i] <= arr[j]){
			temp[k++] = arr[i++];
		}else{
			temp[k++] = arr[j++];
			inv_count = inv_count + (mid-i);
			//cout<<"inv_count :"<<inv_count<<endl;
		}
		//printArray(arr);
		cout<<"left: "<<left<<" mid: "<<mid<<" right: "<<right<<" i : "<<i<<" arr[i]: "<<arr[i]<<" j: "<<j<<" arr[j]: "<<arr[j]<<" k: "<<k<<" inv_count: "<<inv_count<<endl;

	}

	while(i<=mid-1){
		temp[k++] = arr[i++];
	}
	while(j<=right){
		temp[k++] = arr[j++];
	}

	for(int counter=left; counter<=right; counter++){
//		temp[counter] = arr[counter];
		arr[counter] = temp[counter];
	}

	return inv_count;
}

void printArray(int arr[]){
//	cout<<endl;
	for(int i=0;i<7;i++){
		cout<<" "<<arr[i]<<" ";
	}
	cout<<endl;
}

int main(){
	//int arr[] = {1,20,6,4,5};
	int arr[] = {12,15,1,5,6,14,11};
	int n = sizeof(arr)/sizeof(arr[0]);
	//cout<<"Array size :"<<n<<endl;
	int ans = mergeSort(arr,n);
	cout<<"Number of inversions are "<<ans;
	return 0;
}
