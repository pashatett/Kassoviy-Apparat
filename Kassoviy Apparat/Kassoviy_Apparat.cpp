#include "Kassoviy_Apparat.h"
#include <iostream>


int apple = 5, potato = 4, lemon = 26, melon = 14, garlic = 11, tomato = 20;

string ap[10] = { "Apple" }; string po[10] = { "Potato" }; string le[10] = { "Lemon" };
string me[10] = {"Melon"}; string ga[10] = {"Garlic"}; string to[10] = {"Tomato"};

const int kol_tov = 6;//количество товаров в меню

string** arr = new string* [kol_tov];
int* arrKol = new int[kol_tov];

int appleCen = 20; int potatoCen = 20; int lemonCen = 20; int melonCen = 20; int garlicCen = 20; int tomatoCen = 20;//цены

int* arrCen = new int[kol_tov];//цены

char* checkPeolpe = new char;//чек чела

int temp=-1;

int sumBuy = 0;//сумма в чеке

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

	for (int i = 0; i < kol_tov; i++) {
		if (i == 0)cout << "-----------Spisok--------"<<endl;
		cout << *arr[i] << " " << arrKol[i]<<" " << arrCen[i] << '$' << endl;
		if (i == kol_tov-1)cout << "-------------------------";
	}
}

void Kassoviy_Apparat::buy_tovar() {
	string wantBuy;
	string otvet;
	int wantBuyKol;
	cout << endl<<"if you want to pay, write 'oplata', else write item from the list"<<endl;
	cin >> otvet;
	
	while (otvet != "oplata") {
		wantBuy = otvet;

		for (int i = 0; i < kol_tov; i++)
			if (wantBuy == *arr[i]) {
				temp = i;
				break;
			}
		if (temp==-1)cout << "net takogo"<<endl;
		cout << "temp " << temp<<endl;
		if (temp != -1 && temp<kol_tov) {
			cout << "Kakoe kol-vo hotite? "<<endl; cin >> wantBuyKol;
			if (arrKol[temp] < wantBuyKol) cout << "Y nas net takogo kol-va"<<endl;
			else {
				arrKol[temp]= arrKol[temp] - wantBuyKol;///////////////////////////////////////////////////////////////////
				sumBuy += arrCen[temp] * wantBuyKol;
				system("cls");
				tovari();
				cout << "dobavleno"<<endl<<endl;
				cout << "hotite li eshe dobavit' tovar or go to pay?(tovar | oplata)"<<endl; cin >> otvet;
				temp = -1;
				cout << "sumbuy"<<sumBuy << endl;
			}
		}
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
