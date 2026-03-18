#include <iostream>

using namespace std;

int main(){
	static const int N = 6;
	double arr[N] = {10.4, 2.4, 5.6, 4.3, 0.1, 4.5};
	bool flag = 1;
	while (flag){
		flag = 0;
		for (int i = 0; i<N-1; i++) {
			if (arr[i]>arr[i+1]) {
				double val = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = val;
				flag = 1;
			}
		}
	}
	for (int i = 0; i<N; i++){
		cout << arr[i] << "\n";
	}
	return 0;
}
