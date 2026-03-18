# include <iostream>

int main()
{
	double ad[4] = {0.0, 1.1, 2.2, 3.3};
	float af[8] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
	int ai[3] = {0, 1, 2};
	
	int x = 1;
	float y = 1.1;
	std::cout << "&ai0: " << &ai[0] << "\n"; 
	std::cout << "&ai1: " << &ai[1] << "\n";
	std::cout << "&ai2: " << &ai[2] << "\n";
	std::cout << "&x:   " << &x << "\n";
	std::cout << "&y:   " << &y << "\n";
	std::cout << "&af0: " << &af[0] << "\n";
	std::cout << "&ad0: " << &ad[0] << "\n";
	(&y)[1] = 0;
    std::cout << "stampa x: "<< x << "\n";
	return 0;
}