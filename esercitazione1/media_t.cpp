#include <fstream>
#include <iostream>

using namespace std;

int main(int argc,const char *argv[]) {
	string filename = argv[1];
	ifstream ifs(filename); //apre il file di input
	if ( ifs.is_open() ){ //controlla che sia aperto correttamente
		while ( !ifs.eof() ) {  //fino alla fine del file
			string citta;
			ifs >> citta;
			if (ifs.fail()) { // per gestire errore
			break;
			}
			else {
				double sum = 0;
				for (int i = 1; i <=4; i++) {
					double temp = 0;
					ifs >> temp;
					sum += temp; // somma temperature
				}
			
			double media = sum/4.0; 
			cout << citta << " " << media << "\n";
			}
		}
		
	}
	else {
		cerr << "Errore nell'apertura del file\n";
	}
	return 0;
}
