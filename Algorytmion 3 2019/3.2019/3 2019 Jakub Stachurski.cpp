/*Napisz program, który dla zadanej liczby naturalnej 𝑛 wypisywał będzie tablicę
dwuwskaźnikową wymiaru 𝑛 × 𝑛, której elementami (kolejno wierszami) są kolejne
cyfry rozwinięcia liczby 𝜋 (począwszy od jej cyfry jedności) oraz kolejne sumy tych
„przekątnych” tej tablicy, które w przykładzie wyróżnione są odpowiednimi kolorami.*/

//Wyniki mogą się różnić ze względu na użytą liczbę Pi która w zależności od wielkości liczby n może mieć inne przybliżenie

#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <sstream>
#include <iomanip>

using namespace std;

void tablica(string pi, int n) {
	int licznik = 0;
	int suma = 0;

	//dynamimczna alkoacja pamięci dla tablicy dwuwymiarowej
	int** tab = nullptr;
	tab = new int*[n];
	for (int i = 0; i < n; i++) {
		tab[i] = new int[n];
	}

	//wpisanie do tablicy dwuwymiarowej kolejnych znaków liczby pi (pomijamy ',')
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (pi[licznik] == '.') {
				licznik++;
			}
			tab[i][j] = pi[licznik]-48;
			licznik++;
		}
	}

	//wypisanie tablicy dwuwymiarowej
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << tab[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	//liczenie sumy przekatnych od prawo-góra do środka włącznie
	for (int i = n - 1; i > -1; i--) {
		suma = 0;
		for (int j = 0; j < n - i; j++) {
			suma += tab[j][i+j];
		}
		cout << suma << " ";
	}

	//liczenie sumy przekątnych od śrdoka do lewo-dół
	for (int i = 1; i < n; i++) {
		suma = 0;
		for (int j = 0; j < n - i; j++) {
			suma += tab[i+j][j];
		}
		cout << suma << " ";
	}

	//zwolnienie dynamicznie zalokowanej pamięci dla tablicy dwuwymiarowej
	for (int i = 0; i < n; i++) {
		delete[] tab[i];
	}
	delete[] tab;
}

int main() {
	ostringstream liczbaPi;
	int n = 0;
	cout << "Podaj liczbe n(wielkosc tablicy): ";
	cin >> n;
	//ustalanie jak duże ma być rozwinięcie liczby Pi, a następnie jej wpisanie do stringa pi
	liczbaPi << setprecision(pow(n,2)) << M_PI;
	string pi = liczbaPi.str();
	tablica(pi, n);
	system("pause");
}