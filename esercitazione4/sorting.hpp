#include <vector>

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