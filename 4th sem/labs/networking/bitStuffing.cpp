#include <iostream>

using namespace std;

int main(){
	int a[20],b[20],i,j,k,count,n;
	cout<<"Enter frame size : ";
	cin>>n;
	cout<<"Enter the frame in the form of 0s & 1s : ";
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	i=0;
	count=1;
	j=0;
	while(i<n){
		b[j]=a[i];
		if(a[i]==1){
			for(k=i+1;a[k]==1 && count<5 && k<n;k++){
				j++;
				b[j]=a[k];
				count++;
				if(count==5){
					j++;
					b[j]=0;
				}
				i=k;
			}
		}
		i++;
		j++;
	}
	cout<<"Afer bit stuffing : ";
	for(i=0;i<j;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}