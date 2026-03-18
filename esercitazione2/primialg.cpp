#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	static const int N = 5;
	double arr[N] = {0.0,1.0,2.0,3.0,4.0};
	
	double min_arr = arr[0];
	for (int i = 1; i <N; i++){
		min_arr = min(min_arr,arr[i]);
	}
	double max_arr = arr[0];
	for (int i = 1; i <N; i++){
		max_arr = max(min_arr,arr[i]);
	}
	double media = 0.0;
	for (int i = 0; i <N; i++) {
					double valore = arr[i];
					media += valore/5.0;
				}
	double dev_std = 0.0;
	for (int i = 0; i <N; i++) {
					double scarto = arr[i] - media;
					dev_std += (scarto*scarto)/5.0;
				}
	dev_std = sqrt(dev_std);	
	
	
	cout << "min: " << min_arr << "\n";
	cout << "max: " << max_arr << "\n";
	cout << "media: " << media << "\n";
	cout << "dev_std: " << dev_std << "\n";
	
	return 0;
}