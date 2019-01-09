#include <iostream>
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k){
  deque<int> d;
  for (int i = 0; i < k; i++) {
    while (d.size() > 0 && arr[i] >= arr[d.back()]) {
      d.pop_back();
    }
    d.push_back(i);
  }

  for (int i = k; i < n; i++) {
    cout << arr[d.front()] << " ";
    while (d.size() > 0 && d.front() <= i-k) {
      d.pop_front();
    }

    while(d.size() > 0 && arr[i] >= arr[d.back()]) {
      d.pop_back();
    }
    d.push_back(i); 
  }
  cout << arr[d.front()] << endl;
}

int main(){
  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}

