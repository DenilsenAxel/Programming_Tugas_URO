#include<bits/stdc++.h>
using namespace std;

int main(){
	string kata;
	bool palindrom;
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		cin >> kata;
		int j=0;
		int k = kata.length();
		palindrom = true;
		while(palindrom && j<k){
			if(kata[j] != kata[k-1]){
				palindrom = false;
				break;
			}
			j++;
			k--;
		}
		if(palindrom){
			printf("YA\n");
		}
		else{
			printf("TIDAK\n");
		}
	}
}
