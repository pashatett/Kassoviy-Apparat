#include "Kassoviy_Apparat.h"
#include <iostream>
#include <algorithm>



int apple = 5, potato = 4, lemon = 26, melon = 14, garlic = 11, tomato = 20;

string ap[10] = { "Apple" }; string po[10] = { "Potato" }; string le[10] = { "Lemon" };
string me[10] = { "Melon" }; string ga[10] = { "Garlic" }; string to[10] = { "Tomato" };

int kol_tov = 6;//количество товаров в меню

string** arr = new string* [kol_tov];
int* arrKol = new int[kol_tov];

int appleCen = 20; int potatoCen = 20; int lemonCen = 20; int melonCen = 20; int garlicCen = 20; int tomatoCen = 20;//цены

int* arrCen = new int[kol_tov];//цены

string** checkPeople = new string*;//чек чела
int peopleCheck = 0;

int temp = -1;

int sumBuy = 0;//сумма в чеке

int ALLViruchka;

void delete_tovar(int* arrKol) {
	int tempp = -1;
	for (int i = 0; i < kol_tov; i++) {
		if (arrKol[i] == 0) {
			tempp = i;
		}
	}
	if (tempp != -1) {
		kol_tov--;
		int* arrKol1 = arrKol;
		string** arr1 = arr;
		int* arrCen1 = arrCen;
		delete[] arrKol;
		delete[] arrCen;
		delete[] arr;
		for (int i = 0; i < kol_tov; i++) {
			for (int j = 0; j <= kol_tov; j++) {
				if (j == tempp) {
					continue;
				}
				else {
					arrKol[i] = arrKol1[j];
					arrCen[i] = arrCen1[j];
					arr[i] = arr1[j];
				}
			}
		}
	}
}

void Kassoviy_Apparat::tovari() {
	for (int i = 0; i < kol_tov; i++) {
		if (i == 0)cout << "-----------Spisok--------" << endl;
		cout << *arr[i] << " " << arrKol[i] << " " << arrCen[i] << '$' << endl;
		if (i == kol_tov - 1)cout << "-------------------------" << endl;
	}
}

void Kassoviy_Apparat::buy_tovar() {
	{arr[0] = ap;
	arr[1] = po;
	arr[2] = le;
	arr[4] = ga;
	arr[3] = me;
	arr[5] = to;

	arrCen[0] = appleCen;
	arrCen[1] = potatoCen;
	arrCen[2] = lemonCen;
	arrCen[3] = melonCen;
	arrCen[4] = garlicCen;
	arrCen[5] = tomatoCen;

	arrKol[0] = apple;
	arrKol[1] = potato;
	arrKol[2] = lemon;
	arrKol[3] = melon;
	arrKol[4] = garlic;
	arrKol[5] = tomato; }

	for (int i = 0; i < kol_tov; i++) {
		if (i == 0)cout << "-----------Spisok--------" << endl;
		cout << *arr[i] << " " << arrKol[i] << " " << arrCen[i] << '$' << endl;
		if (i == kol_tov - 1)cout << "-------------------------" << endl;
	}

	string wantBuy;
	string otvet;
	int oplata;
	int wantBuyKol;
	cout << endl << "if you want to pay, write 'oplata', else write item from the list" << endl;
	cin >> otvet;

	while (otvet != "oplata") {
		wantBuy = otvet;
		for (int i = 0; i < kol_tov; i++)
			if (transform(wantBuy.begin(),wantBuy.end(), wantBuy.begin(), tolower) == *arr[i]) {//////////////////////////////////////////////
				temp = i;
				break;
			}
		checkPeople[peopleCheck] = arr[temp];
		cout <<endl<< "check people " << checkPeople<<endl;
		if (temp == -1)cout << "net takogo" << endl;
		cout << "temp " << temp << endl;
		if (temp != -1 && temp < kol_tov) {
			cout << "Kakoe kol-vo hotite? " << endl; cin >> wantBuyKol;
			if (arrKol[temp] < wantBuyKol) cout << "Y nas net takogo kol-va" << endl;
			else {
				arrKol[temp] -= wantBuyKol;
				delete_tovar(arrKol);
				sumBuy += arrCen[temp] * wantBuyKol;
				system("cls");
				tovari();
				cout << "dobavleno" << endl << endl;
				cout << "hotite li eshe dobavit' tovar or go to pay?(tovar | oplata)" << endl; cin >> otvet;
				temp = -1;
				cout << "sumbuy " << sumBuy << endl;
			}
		}
	}
	if (otvet == "oplata") {
		if (sumBuy!=0) {
			cout << "opllatite tovar " << endl; cin >> oplata;
			if (oplata < sumBuy) {
				while (oplata < sumBuy) {
					cout << "y vas nedostatochno sredstv" << endl;
					cin >> oplata;
				}
			}
			else {
				cout << "vasha sdacha = " << oplata - sumBuy;
			}
		}
		if (sumBuy == 0) {
			cout << "vi nichego ne kupili((" << endl;
			cout << "if you want buy smth, write item from the list"<<endl;
			cin >> otvet;
			while (otvet != "oplata") {
				wantBuy = otvet;
				for (int i = 0; i < kol_tov; i++)
					if (wantBuy == *arr[i]) {
						temp = i;
						break;
					}
				if (temp == -1)cout << "net takogo" << endl;
				cout << "temp " << temp << endl;
				if (temp != -1 && temp < kol_tov) {
					cout << "Kakoe kol-vo hotite? " << endl; cin >> wantBuyKol;
					if (arrKol[temp] < wantBuyKol) cout << "Y nas net takogo kol-va" << endl;
					else {
						arrKol[temp] -= wantBuyKol;
						sumBuy += arrCen[temp] * wantBuyKol;
						system("cls");
						tovari();
						cout << "dobavleno" << endl << endl;
						cout << "hotite li eshe dobavit' tovar or go to pay?(tovar | oplata)" << endl; cin >> otvet;
						temp = -1;
						cout << "sumbuy " << sumBuy << endl;
					}
				}
			}
			if (otvet == "oplata") {
				if (sumBuy != 0) {
					cout << "opllatite tovar " << endl; cin >> oplata;
					if (oplata < sumBuy) {
						while (oplata < sumBuy) {
							cout << "y vas nedostatochno sredstv" << endl;
							cin >> oplata;
							if (oplata >=sumBuy)cout << "vasha sdacha = " << oplata - sumBuy;
						}
					}
					else {
						cout << "vasha sdacha = " << oplata - sumBuy;
					}
				}
			}
		}
	}
}

void Kassoviy_Apparat::all_viruchka() {

}

void Kassoviy_Apparat::check() {

}

void Kassoviy_Apparat::people() {

}
