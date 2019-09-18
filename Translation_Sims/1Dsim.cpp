// James Ragland 9.18.19
// Prototype one-dimensional simulation of mRNA-Ribosome interactions
// Models diffusion only, not translation

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
using namespace std;

void ribo_jumper(int cycles)
{
	vector <int> rv(10);		// Vector storing location of ribosomes
	vector <int> mv(10);		// Vector storing location of mRNA molecules
	int loc0,dz;				// Integer to store vector index for seeding molecules
	srand(time(NULL));			// Function invocation to provide pseudo-random numbers

	for (int i = 0; i < 3; i++) {
		loc0 = rand() % 10;
		rv[loc0]++;
	}
	
	cout << "Initial Ribosome locations\n" << "---------------\n";
	for (size_t j = 0; j < rv.size(); j++){cout << rv[j] << " ";}
	cout << endl << "-----------" << endl;
	
	for (size_t j = 0; j < rv.size(); j++){
		if (rv[j] != 0){
			dz = rand() % 2;
			if (dz == 1){rv[j]--; rv[j+1]++;}
			if (dz == 0){rv[j]--; rv[j-1]++;}
		}
	}
	
	cout << "Ribosome locations\n" << "------------\n" << endl;
	for(size_t j = 0; j < rv.size(); j++){cout << rv[j] << " ";}
	cout << endl;
}

int main()
{
	ribo_jumper(10);
	return 0;
}

