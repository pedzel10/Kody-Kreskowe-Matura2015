#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int liczby[500];
void odczyt(int liczby[]) {
	ifstream in("kody.txt");
	for(int i=0; i<500; i++)
		in >> liczby[i];

	in.close();
}

int sumaNieParzystych(int liczba) {
  int suma = 0;
	string liczbaString = to_string(liczba);
	for(int i=0; i<liczbaString.size(); i+=2) {
    char znak = liczbaString[i];
    int cyfra = znak - '0';
    suma += cyfra;
  }
  return suma;
}

int sumaParzystych(int liczba) {
	int suma = 0;
	string liczbaString = to_string(liczba);
	for(int i=1; i<liczbaString.size(); i+=2) {
    char znak = liczbaString[i];
    int cyfra = znak - '0';
    suma += cyfra;
  }
  return suma;
}

void parzysteNieparzyste(int liczby[]) {
    ofstream out("kody1.txt");
  for(int i=0; i<500; i++)
  out<<sumaParzystych(liczby[i])<<" "<<sumaNieParzystych(liczby[i])<<endl;

  out.close();
}

int cyfraKontrolna(int liczba) {
  return (10 - ( ( (sumaParzystych(liczba) * 3) + sumaNieParzystych(liczba) ) % 10 )) % 10;
}

string cyfraNaKod(int cyfra) {
  string ciag = "";
  switch(cyfra) {
     case 0:
      ciag = "10101110111010";
      break;

    case 1:
      ciag = "11101010101110";
      break;

    case 2:
      ciag = "10111010101110";
      break;

    case 3:
      ciag = "11101110101010";
      break;

    case 4:
      ciag = "10101110101110";
      break;

    case 5:
      ciag = "11101011101010";
      break;

    case 6:
      ciag = "10111011101010";
      break;

    case 7:
        ciag = "10101011101110";
    break;

    case 8:
      ciag = "11101010111010";
      break;

    case 9:
      ciag = "10111010111010";
      break;
  }
  return ciag;
}

void cyfryKontrolne(int liczby[]) {
    ofstream out("kody2.txt");
  for(int i=0; i<500; i++) {
    out<<cyfraKontrolna(liczby[i])<<" "<<cyfraNaKod(cyfraKontrolna(liczby[i]))<<endl;
  }
  out.close();
}

string standardCode(int liczba) {
  string standardCode = "";
  string start = "11011010";
  string kod= "";
  string kontrolna = cyfraNaKod(cyfraKontrolna(liczba));
  string stop = "11010110";

  for(int i=0; i<to_string(liczba).size(); i++) {
    char znak = to_string(liczba)[i];
    int cyfra = znak - '0';
    kod += cyfraNaKod(cyfra);
  }
  standardCode = start + kod + kontrolna + stop;
  return standardCode;
}

void kodyWSystemie(int liczby[]) {
    ofstream out("kody3.txt");
  for(int i=0; i<500; i++) {
    out<<standardCode(liczby[i])<<endl<<endl;
  }
  out.close();
}

int main() {
	odczyt(liczby);
  parzysteNieparzyste(liczby);
  cyfryKontrolne(liczby);
  kodyWSystemie(liczby);
}
