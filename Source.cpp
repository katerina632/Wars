#include <iostream>
#include <string>
#include <ctime>
#include "CombatVehicle.h"

using namespace std;


int main() {
	srand(time(0));

	const int  size = 3;

	int type;


	CombatVehicle* army1[size];
	CombatVehicle* army2[size];


	cout << "==Army #1==" << endl;
	for (int i = 0; i < size; i++)
	{
		type = 1 + rand() % 3;
		switch (type)
		{
		case 1:
			army1[i] = new Tank(1 + rand() % 3, rand() % 5 + 5, rand() % 10 + 40, "Tank", "tn1", rand() % 50 + 100);
			break;
		case 2:
			army1[i] = new ArmoredCar(1 + rand() % 3, rand() % 10 + 10, "Armored Car", "ar1", rand() % 50 + 100);
			break;
		case 3:
			army1[i] = new AirDefenseVehicle(rand() % 5 + 5, 1 + rand() % 10, 1 + rand() % 3, "Air Defense Vehicle", "air1", rand() % 50 + 100);
			break;
		}

		cout << i + 1 << ") ";
		army1[i]->ShowInfo();
		cout << endl;
	}

	cout << endl;
	cout << "==Army #2==" << endl;
	for (int i = 0; i < size; i++)
	{
		type = 1 + rand() % 3;
		switch (type)
		{
		case 1:
			army2[i] = new Tank(1 + rand() % 3, rand() % 5 + 5, rand() % 10 + 40, "Tank", "tn1", rand() % 50 + 100);
			break;
		case 2:
			army2[i] = new ArmoredCar(1 + rand() % 3, rand() % 10 + 10, "Armored Car", "ar1", rand() % 50 + 100);
			break;
		case 3:
			army2[i] = new AirDefenseVehicle(rand() % 5 + 5, 1 + rand() % 10, 1 + rand() % 3, "Air Defense Vehicle", "air1", rand() % 50 + 100);
			break;
		}

		cout << i + 1 << ") ";
		army2[i]->ShowInfo();
		cout << endl;
	}



	int bm1, bm2;
	int size1 = size, size2 = size;
	do {
		bm1 = rand() % size1;
		bm2 = rand() % size2;
		if (Round(*army1[bm1], *army2[bm2]))
		{
			delete army2[bm2];
			army2[bm2] = nullptr;
			--size2;
			if (size2 == 0)
				break;
			army2[bm2] = army2[size2];

		}
		else
		{
			delete army1[bm1];
			army1[bm1] = nullptr;
			--size1;
			if (size1 == 0)
				break;
			army1[bm1] = army1[size1];
		}

	} while (size1 > 0 && size2 > 0);


	if (size1 > 0) {
		cout << "Army 1 win!" << endl;
		for (int i = 0; i < size1; i++) {
			delete army1[i];
		}
	}
	else {
		cout << "Army 2 win!" << endl;
		for (int i = 0; i < size2; i++) {
			delete army2[i];
		}
	}
	system("pause");
	return 0;
}