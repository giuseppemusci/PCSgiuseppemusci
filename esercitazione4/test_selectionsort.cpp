#include <vector>
#include <string>
#include <cstdlib> // per EXIT_SUCCESS
#include "sorting.hpp"
#include "randfiller.h"
using namespace std;

int main() {
    randfiller rf; 
    vector<int> random_dim(100);
    rf.fill(random_dim, 10, 1000);
	int dim = 0;
	
    for (int i = 0; i < 100; i++) {
		dim = random_dim[i];
        vector<int> vec_i(dim);
		vector<double> vec_d(dim);
        rf.fill(vec_i, -1000, 1000);
		rf.fill(vec_d, -1000.0, 1000.0);
		
		selectionsort(vec_i);
		selectionsort(vec_d);
        if (!is_sorted(vec_i) or !is_sorted(vec_d)) {
            return EXIT_FAILURE; 
        }
    }
	
    vector<string> str = {"vcxdtyhb", "gtrdfghj", "pqksx", "ogehsj", 
			"qlskse","owkok", "mwlmb", "wpkdme", "musci", "giuseppe"};

    selectionsort(str);
    if (!is_sorted(str)) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}