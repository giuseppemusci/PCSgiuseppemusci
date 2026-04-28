#include <vector>
#include <utility>

template<typename T>
void bubblesort(std::vector<T>& vec){
	int dim = vec.size(); //inizializzato prima perchè mi dava warning
	if (dim <= 1){return;}
	for(int i=0; i<dim-1;i++){ 
		for(int j=dim-1; j>i; j--){
			if (vec[j-1] > vec[j]) { // se elementi j e j-1 non sono in ordine
					T val = vec[j];
					vec[j] = vec[j-1]; //swap
					vec[j-1] = val;
			}
		}
	}
}

template<typename T>
void insertionsort(std::vector<T>& vec){
	int dim = vec.size();
	if (dim <= 1){return;} //vettori di dim=0,1 sono già ordinati
	for(int j=1; j<dim; j++){
		T key = vec[j];
		int i = j - 1;
		while(i>=0 and vec[i]>key){
			vec[i+1] = vec[i]; //key salta indietro fino a quando non 
			i--;             // è maggiore di vec[i]
			}
		vec[i+1] = key;
		}              
	}

template<typename T>
void selectionsort(std::vector<T>& vec){
	int dim = vec.size();
	if (dim <= 1){return;}
	for(int i=0; i<dim-1;i++){
		int min = i; 
		for(int j=i+1; j<dim; j++){//per ogni i cerca il min tra i rimanenti a destra
			if(vec[j] < vec[min]){
			min = j;
			}
		}
		T val = vec[min]; //swap tra vec[i] e il minimo degli elementi
		vec[min] = vec[i];// a destra di vec[i]
		vec[i] = val;
	}
}

template<typename T>
bool is_sorted(const std::vector<T>& vec){
	if (vec.size() <= 1) {
		return true;
	}
	int dim = vec.size();
	for(int i=0; i<dim-1;i++){
		if(vec[i]>vec[i+1]){ // se c'è un elemento maggiore del successivo
			return false;}  // significa che non è ordinato
	}
	return true;
}

template<typename T>
void merge(std::vector<T>& vec, int p, int q, int r){
	int n_1 = q - p + 1;
	int n_2 = r - q;
	std::vector<T> L(n_1);
    std::vector<T> R(n_2);
	for(int i=0; i<n_1; i++){
		L[i] = vec[p+i];
	}
	for(int j=0; j<n_2; j++){
		R[j] = vec[q+j+1];
	}
	int i = 0;
	int j = 0;
	for (int k=p; k<=r; k++){
		if (i==n_1){
			vec[k] = R[j];
			j++;}
		else if (j==n_2){
			vec[k] = L[i];
			i++;}
		else {
			if (L[i] <= R[j]){
				vec[k] = L[i];
				i++;}
			else {
				vec[k] = R[j];
				j++;}
		}
	}
}
template<typename T>
void mergesort(std::vector<T>& vec, int p, int r){
	if (p < r){
		int q = (p+r)/2;
		mergesort(vec,p,q);
		mergesort(vec,q+1,r);
		merge(vec,p,q,r);
	}
}


template<typename T>
void insertionsort_2(std::vector<T>& vec, int p, int r){
	int dim = r-p+1;
	if (dim <= 1){return;} //vettori di dim=0,1 sono già ordinati
	for(int j=p+1; j<r+1; j++){ //j<r+1 perchè j<p+dim
		T key = vec[j];
		int i = j - 1;
		while(i>=p and vec[i]>key){
			vec[i+1] = vec[i]; //key salta indietro fino a quando non 
			i--;             // è maggiore di vec[i]
			}
		vec[i+1] = key;
		}
	}
template<typename T>
int partition(std::vector<T>& vec, int p, int r){
	T x = vec[r];
	int i = p-1;
	for(int j = p; j<r; j++){
		if (vec[j]<=x){
			i++;
			std::swap(vec[i],vec[j]);
		}
	}
	std::swap(vec[i+1],vec[r]);
	return i+1;
}
template<typename T>
void quicksort(std::vector<T>& vec, int p, int r){
	if (p < r){
		if (r - p + 1 <= 50) {
			insertionsort_2(vec,p,r);
		}
		else{
			int q = partition(vec,p,r);
			quicksort(vec,p,q-1);
			quicksort(vec,q+1,r);
		}
	}
}