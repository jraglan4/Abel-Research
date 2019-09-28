// James Ragland 9.18.19
// Prototype one-dimensional simulation of mRNA-Ribosome interactions
// Models diffusion only, not translation

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

void test_jumper(int cycles)
{
	vector <int> rv(10,0);		// Vector storing location of ribosomes
	vector <int> mv(10,0);		// Vector storing location of mRNA molecules
	int loc0,loc1,dz,k,j;		// Integer to store vector index for seeding molecules
	srand(time(NULL));			// Function invocation to provide pseudo-random numbers
	ofstream r_out;

	for (int i = 0; i < 3; i++){ loc0 = rand() % 10; rv[loc0]++;}
	for (int m = 0; m < 10; m++){ loc1 = rand() % 10; mv[loc1]++;}
	

	cout << "\nInitial Ribosome Locations:\n";					// Print out starting  positions
	for (size_t j = 0; j < 10; j++){cout << rv[j] << " ";}
	cout << "\n\nInitial mRNA Positions: \n";
	for (size_t t = 0; t < 10; t++){cout << mv[t] << " ";}
	cout << endl;

	for (int k = 0; k < cycles; k++){
		for (size_t j = 0; j < 10; j++){
				dz = rand() % 2;	
				if (dz == 1){
					if (j != 9 && rv[j] != 0){rv[j]--; rv[j+1]++;}
				}
				if (dz == 0){
					if (j != 0 && rv[j] != 0){rv[j]--; rv[j-1]++;}
				}
			}
	}		
		cout << "\nFinal Ribosome Locations: \n";
			for(size_t j = 0; j < 10; j++){cout << rv[j] << " ";}
		cout << endl;
		r_out.open("r_out.txt",ios::app);
			for(size_t j = 0; j < 10; j++){r_out << rv[j] << " ";}
			r_out << endl;
}

int main()
{
	test_jumper(100);
	return 0;
}

