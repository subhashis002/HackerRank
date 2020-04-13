#include<bits/stdc++.h>
using namespace std;

int _mergeSort(vector<int> arr, int temp[], int left, int right); 
int merge(vector<int> arr, int temp[], int left, int mid, int right);
void printArray(vector<int> arr); 
void printArray(int arr[]);  

int insertionSort(vector<int> arr) 
{ 
    int array_size = arr.size();
    cout<<"array_size :"<<array_size<<endl;
    int temp[array_size]; 
    return _mergeSort(arr, temp, 0, array_size - 1); 
} 
  

int _mergeSort(vector<int> arr, int temp[], int left, int right) 
{ 
    int mid, inv_count = 0; 
    if (right > left) { 
        
        mid = (right + left) / 2; 
  
        
        inv_count += _mergeSort(arr, temp, left, mid); 
        inv_count += _mergeSort(arr, temp, mid + 1, right); 
  
        
        inv_count += merge(arr, temp, left, mid + 1, right); 
//	printArray(arr);
	printArray(temp);
    } 
    return inv_count; 
} 
  

int merge(vector<int> arr, int temp[], int left, 
          int mid, int right) 
{ 
    int i, j, k; 
    int inv_count = 0; 
  
    i = left; /* i is index for left subarray*/
    j = mid; /* j is index for right subarray*/
    k = left; /* k is index for resultant merged subarray*/
    //cout<<"i : "<<i<<" j: "<<j<<" k: "<<k<<endl;
    while ((i <= mid - 1) && (j <= right)) { 
        if (arr[i] <= arr[j]) { 
            temp[k++] = arr[i++]; 
        } 
        else { 
            temp[k++] = arr[j++]; 
            inv_count = inv_count + (mid - i); 
//	    cout<<"inv_count :"<<inv_count<<endl;
        }
        cout<<"left: "<<left<<" mid: "<<mid<<" right: "<<right<<" i : "<<i<<" arr[i]: "<<arr[i]<<" j: "<<j<<" arr[j]: "<<arr[j]<<" k: "<<k<<" inv_count: "<<inv_count<<endl;
    } 
  
    
    while (i <= mid - 1) 
        temp[k++] = arr[i++]; 
  
    
    while (j <= right) 
        temp[k++] = arr[j++]; 
  
    
    for (i = left; i <= right; i++) 
        arr[i] = temp[i]; 
  
    return inv_count; 
}
void printArray(vector<int> arr){
//      cout<<endl;
        for(int i=0;i<7;i++){
                cout<<" "<<arr[i]<<" ";
        }
        cout<<endl;
}
void printArray(int arr[]){
//      cout<<endl;
        for(int i=0;i<7;i++){
                cout<<" "<<arr[i]<<" ";
        }
        cout<<endl;
}

int main(){
	vector<int> arr{12,15,1,5,6,14,11};
	int ans = insertionSort(arr);
	cout<<ans<<endl;
	return 0;
}
