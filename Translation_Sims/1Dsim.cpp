// James Ragland 9.18.19
// Prototype one-dimensional simulation of mRNA-Ribosome interactions
// Models diffusion only, not translation

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
using namespace std;

void test_jumper(int cycles)
{
	vector <int> rv(10);		// Vector storing location of ribosomes
	vector <int> mv(10);		// Vector storing location of mRNA molecules
	int loc0, loc1,dz;			// Integer to store vector index for seeding molecules
	srand(time(NULL));			// Function invocation to provide pseudo-random numbers


	for (int i = 0; i < 3; i++){ loc0 = rand() % 10; rv[loc0]++;}
	for (int m = 0; m < 10; m++){ loc1 = rand() % 10; mv[loc1]++;}
	

	cout << "\nInitial Ribosome Locations:\n";					// Print out starting  positions
	for (size_t j = 0; j < 10; j++){cout << rv[j] << " ";}
	cout << "\n\nInitial mRNA Positions: \n";
	for (size_t t = 0; t < 10; t++){cout << mv[t] << " ";}
	cout << endl;

	for (int k = 0; k < cycles; k++){						// Iterate over each lattice site, check if ribosome present
		for (size_t j = 0; j < 10; j++){					// If present, use psedo-random number to choose left or right hop
			if (rv[j] != 0){								// Ribosomes at far left or right of volume can only hop
				dz = rand() % 2;							// One direction
				if (dz == 1){
					if (j != 9){rv[j]--; rv[j+1]++;}
				}
				if (dz == 0){
					if (j != 0){rv[j]--; rv[j-1]++;}
				}
			}
		}

		cout << "\n\nStep " << k+1 << " Ribosome Locations\n"; 
		for(size_t j = 0; j < 10; j++){cout << rv[j] << " ";}
		cout << endl;
	}
}
int main()
{
	test_jumper(100);
	return 0;
}

