#include <iostream>
#include <algorithm>
#include <vector>
#include "timecounter.h"
#include "sorting.hpp"
#include "randfiller.h"
using namespace std;

int main(){
	randfiller rf;
	int i=0;
	vector<double> time_bubblesort(12),time_selectionsort(12),
		time_insertionsort(12),time_sort(12);
	vector<int> vec(0);
	cout << "dim = [";
	for (int dim=4; dim <= 8192; dim *=2){
		vec.resize(dim);
		rf.fill(vec, -1000, 1000);
		vector<int> vec_b = vec;
        vector<int> vec_s = vec;
        vector<int> vec_i = vec;
		timecounter tc;
		
		tc.tic();
		bubblesort(vec_b);
		time_bubblesort[i]=tc.toc();
		
		tc.tic();
		selectionsort(vec_s);
		time_selectionsort[i]=tc.toc();
		
		tc.tic();
		insertionsort(vec_i);
		time_insertionsort[i]=tc.toc();
		
		tc.tic();
		sort(vec.begin(), vec.end());
		time_sort[i]=tc.toc();
		i++;
		cout << dim << " ";
	}
	
	cout << "];\nbubble_sort = [" ;
	for (int j = 0; j < 12; j++){
		cout << time_bubblesort[j] << " ";}
	cout << "];\nselection_sort = [" ;
	for (int j = 0; j < 12; j++){
		cout << time_selectionsort[j] << " ";}
	cout << "];\ninsertion_sort = [" ;
	for (int j = 0; j < 12; j++){
		cout << time_insertionsort[j] << " ";}
	cout << "];\nsort = [" ;
	for (int j = 0; j < 12; j++){
		cout << time_sort[j] << " ";}
	cout << "];\n";
		//per stamparli in modo da essere copiati su matlab
	return 0;
}