#include "Kassoviy_Apparat.h"
#include <iostream>

int apple = 5, potato = 4, lemon = 26, melon = 14, garlic = 11, tomato = 20;

string ap[10] = { "Apple" }; string po[10] = { "Potato" }; string le[10] = { "Lemon" };
string me[10] = {"Melon"}; string ga[10] = {"Garlic"}; string to[10] = {"Tomato"};

string** arr = new string* [6];
int* arrKol = new int[6];

int appleCen = 20; int potatoCen = 20; int lemonCen = 20; int melonCen = 20; int garlicCen = 20; int tomatoCen = 20;

int* arrCen = new int[6];

char* checkPeolpe = new char;

int temp=-1;

int sumBuy = 0;

void Kassoviy_Apparat::tovari() {
	arr[0] = ap;
	arr[1] = po;
	arr[2] = le;
	arr[4] = ga;
	arr[3] = me;
	arr[5] = to;
	
	arrKol[0] = apple;
	arrKol[1] = potato;
	arrKol[2] = lemon;
	arrKol[3] = melon;
	arrKol[4] = garlic;
	arrKol[5] = tomato;

	arrCen[0] = appleCen;
	arrCen[1] = potatoCen;
	arrCen[2] = lemonCen;
	arrCen[3] = melonCen;
	arrCen[4] = garlicCen;
	arrCen[5] = tomatoCen;

	for (int i = 0; i < 6; i++) {
		if (i == 0)cout << "-----------Spisok--------- "<<endl;
		cout << *arr[i] << " " << arrKol[i]<<" " << arrCen[i] << '$' << endl;
		if (i == 5)cout << "------------------------";
	}
}

void Kassoviy_Apparat::buy_tovar() {
	string wantBuy;
	int wantBuyKol;
	
	cout <<endl<< "Chto vi hotite buy? "; cin >> wantBuy;

	for (int i = 0; i < 6; i++)
		if (wantBuy == *arr[i]) {
			temp = i;
			break;
		}

	if (temp)cout << "net takogo";

	cout << temp;

	if(temp!=-1) {
		cout << "Kakoe kol-vo hotite? "; cin >> wantBuyKol;
		if (arrKol[temp] < wantBuyKol) cout << "Y nas net takogo kol-va";
		else cout << "dobavleno";
							
	}
}

void Kassoviy_Apparat::delete_tovar(char* delete_tovar) {

}

void Kassoviy_Apparat::tovar_zero() {

}

void Kassoviy_Apparat::all_viruchka() {

}

void Kassoviy_Apparat::check() {

}

void Kassoviy_Apparat::people() {

}