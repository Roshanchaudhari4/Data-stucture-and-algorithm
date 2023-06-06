/*Read the marks obtained by students of second year in an online examination of 
particular subject. Find out minimum marks obtained in that subject. Use 
Heap data structure. */









//min heap
#include<iostream>
using namespace std;
void insert(int arr[],int i)
{
	int parent=(i-1)/2;
	int current=i;
	while(parent>=0 && arr[parent]>arr[current])
	{
		swap(arr[parent],arr[current]);
		current=parent;
		parent=(current-1)/2;
		
	}
	
	
}
int main()
{
	int i;
	int arr[]={20,30,15,2,5,10};
	for(int i=0;i<6;i++)
	{
		insert(arr,i);
	}
	cout<<"\n after inserting all"<<endl;
	for(int i=0;i<6;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}