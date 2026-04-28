#include <iostream>
#include <algorithm>
#include <vector>
#include "timecounter.h"
#include "sorting.hpp"
#include "randfiller.h"
using namespace std;

int main(){
	randfiller rf;
	vector<double> time_bubblesort(100),time_selectionsort(100),
		time_insertionsort(100),time_mergesort(100),time_quicksort(100),
		time_sort(100);
	
	for (int j=0; j<100;j++){
		vector<vector<int>> vec(100,vector<int>(j*4));
		for (int i=0; i<100 ;i++){
		rf.fill(vec[i], -10000, 10000);}
		
		vector<vector<int>> vec_b = vec;
		vector<vector<int>> vec_s = vec;
		vector<vector<int>> vec_i = vec;
		vector<vector<int>> vec_m = vec;
		vector<vector<int>> vec_q = vec;
		
		timecounter tc;
		tc.tic();
		for (int ib=0; ib<100 ;ib++){
			bubblesort(vec_b[ib]);
			}
			time_bubblesort[j]=tc.toc()/100.0;
			
		tc.tic();
		for (int is=0; is<100 ;is++){
			selectionsort(vec_s[is]);
			}
			time_selectionsort[j]=tc.toc()/100.0;
			
		tc.tic();
		for (int ii=0; ii<100 ;ii++){
			insertionsort(vec_i[ii]);
			}
			time_insertionsort[j]=tc.toc()/100.0;
			
		tc.tic();
		for (int im=0; im<100 ;im++){
			mergesort(vec_m[im],0,vec_m[im].size()-1);
			}
			time_mergesort[j]=tc.toc()/100.0;
			
		tc.tic();
		for (int iq=0; iq<100 ;iq++){
			quicksort(vec_q[iq],0,vec[iq].size()-1);
			}
			time_quicksort[j]=tc.toc()/100.0;
			
		tc.tic();
		for (int ist=0; ist<100 ;ist++){
			sort(vec[ist].begin(),vec[ist].end());
			}
			time_sort[j]=tc.toc()/100.0;
	}
	
	cout << "dim = [" ;
	for (int j = 0; j < 100; j++){
		cout << j*4 << " ";}
	cout << "];\nbubble_sort = [" ;
	for (int j = 0; j < 100; j++){
		cout << time_bubblesort[j] << " ";}
	cout << "];\nselection_sort = [" ;
	for (int j = 0; j < 100; j++){
		cout << time_selectionsort[j] << " ";}
	cout << "];\ninsertion_sort = [" ;
	for (int j = 0; j < 100; j++){
		cout << time_insertionsort[j] << " ";}
	cout << "];\nmerge_sort = [" ;
	for (int j = 0; j < 100; j++){
		cout << time_mergesort[j] << " ";}
	cout << "];\nquick_sort = [";
	for (int j = 0; j < 100; j++){
		cout << time_quicksort[j] << " ";}
	cout << "];\nsort = [" ;
	for (int j = 0; j < 100; j++){
		cout << time_sort[j] << " ";}
	cout << "];\n";
		//per stamparli in modo da essere copiati su matlab
	return 0;
}