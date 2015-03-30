#include <iostream>
#include <cmath>
using namespace std;

void mergesort(int array[],int left,int mid,int right){
	int firstnum=mid-left,secondnum=right-mid;
	int array1[firstnum+1],array2[secondnum+1];
	for(int i=0;i<firstnum;i++){
		array1[i]=array[left+i];
	}
	for(int i=0;i<secondnum;i++){
		array2[i]=array[mid+i];
	}
	array1[firstnum]=INFINITY;	array2[secondnum]=INFINITY;
	
	int counter1=0,counter2=0;
	for(int i=left;i<right;i++){
		if(array1[counter1]>=array2[counter2]){
			array[i]=array1[counter1];
			counter1++;
		}
		else{
			array[i]=array2[counter2];
			counter2++;
		}
	}
}

void merge(int array[],int left,int right){
	if(left+1>=right)	return;
	int mid=(left+right)/2;
	merge(array,left,mid);
	merge(array,mid,right);
	mergesort(array,left,mid,right);
}

int main(){
	int n;
	cout<<"How many numbers do you want to sort?"<<endl;
	cin>>n;
	int array[n];
	for(int i=0;i<n;i++){
		cout<<"Tell me one of numbers you want to sort."<<endl;
		cin>>array[i];
	}
	merge(array,0,n);
	cout<<"It's result."<<endl;
	for(int i=0;i<n;i++){
		cout<<(i==0?"":" ")<<array[i];
	}
	cout<<endl;
	return 0;
}
