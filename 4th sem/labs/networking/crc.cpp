#include <iostream>

using namespace std;

int main(){
	int disze, dasze, divisor[100], data[100], rem[100], quo[100], temp[100];
	cout<<"Enter the size of divisor ";
	cin>>disze;
	for (int i = 0; i < disze; ++i){
		cin>>divisor[i];
	}
	cout<<"Enter the size of data ";
	cin>>dasze;
	for (int i = 0; i < dasze; ++i){
		cin>>data[i];
	}
	for (int i = 0; i < disze -1; ++i){
		data[dasze+i] = 0;
	}
	int j = 0, k = 0;
	for(int i = 0; i < disze; ++i){ 
		temp[i] = data[i] ^ divisor[i];
		++k;
	}
	quo[j++] = 1;
	while(k != dasze + disze - 1){
		for(int i = 0; i<disze - 1; ++i){
			temp[i] = temp[i+1];
		}
		temp[disze - 1] = data[k++];
		int ctr = 0;
		while(temp[ctr] != 1){
			for(int i = 0; i<disze - 1; ++i){
				temp[i] = temp[i+1];
			}
			temp[disze - 1] = data[k++];
			quo[j++] = 0;
		}
		for (int i = 0; i < disze; ++i){
			temp[i] = temp[i] ^ divisor[i];
 		}
 		quo[j++]=1;
	}
	for(int i = 0; i < disze - 1; i++){
		data[dasze + i] = temp[i+1];
	}
	cout<<"Transmitted data is"<<endl;
	for (int i = 0; i < dasze + disze - 1 ; ++i)
	{
		cout<<data[i];
	}
	return 0;
}