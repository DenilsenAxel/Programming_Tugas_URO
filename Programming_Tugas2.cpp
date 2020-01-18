#include<bits/stdc++.h>
using namespace std;

int koefisien_polinom_1[100000], koefisien_polinom_2[100000], koefisien_polinom_hasil[100000];
int polynomial_container[100000];
int perintah, derajat_polinom_1, derajat_polinom_2;
int derajat;
bool masih_mau = true;

void daftar_perintah(){
	cout << "LIST PERINTAH : " << endl;
	cout << "1. Penjumlahan Polinom" << endl;
	cout << "2. Pengurangan Polinom" << endl;
	cout << "3. Perkalian Polinom" << endl;
	cout << "4. Turunan Polinom" << endl;
	cout << "PILIH PERINTAH SESUAI DENGAN NOMOR YANG TERTERA!!!" << endl;
	cout << "======================================================" << endl;
}

void input_polinom(){
	for(int i = 0; max(derajat_polinom_1, derajat_polinom_2); i++){
		koefisien_polinom_1[i] = 0;
	}
	for(int i = 0; max(derajat_polinom_1, derajat_polinom_2); i++){
		koefisien_polinom_2[i] = 0;
	}
	cout << "Input derajat polinom pertama : ";
	cin >> derajat_polinom_1;
	for(int i = 0; i<=derajat_polinom_1; i++){
		cout << "Masukkan koefisien derajat ke - " << i << " : ";
		cin >> koefisien_polinom_1[i];
	}
	cout << "Input derajat polinom kedua : ";
	cin >> derajat_polinom_2;
	for(int i = 0; i<=derajat_polinom_2; i++){
		cout << "Masukkan koefisien derajat ke - " << i << " : ";
		cin >> koefisien_polinom_2[i];
	}
}

void cetak(){
	for(int i = max(derajat_polinom_1, derajat_polinom_2); i>=0; i--){
		if(i == 0 && koefisien_polinom_hasil[i] > 0){
			cout << " + " << koefisien_polinom_hasil[i] << endl;
		}
		else if(i == 0 && koefisien_polinom_hasil[i] < 0){
			cout << " - " << koefisien_polinom_hasil[i] << endl;
		}
		else if(koefisien_polinom_hasil[i] == 0){
			cout << "";
		}
		else if(koefisien_polinom_hasil[i] < 0 && i == max(derajat_polinom_1, derajat_polinom_2)){
			cout << "-" << koefisien_polinom_hasil[i] << "x^" << i;
		}
		else if(koefisien_polinom_hasil[i] < 0 && i != max(derajat_polinom_1, derajat_polinom_2)){
			cout << " - " << koefisien_polinom_hasil[i] << "x^" << i;
		}
		else if(koefisien_polinom_hasil[i] > 0 && i != max(derajat_polinom_1, derajat_polinom_2)){
			cout << " + " << koefisien_polinom_hasil[i] << "x^" << i;
		}
		else{
			cout << koefisien_polinom_hasil[i] << "x^" << i;
		}
	}
}

void cetak2(){
	for(int i = derajat; i>=0; i--){
		if(i == 0 && koefisien_polinom_hasil[i] > 0){
			cout << " + " << koefisien_polinom_hasil[i] << endl;
		}
		else if(i == 0 && koefisien_polinom_hasil[i] < 0){
			cout << " - " << koefisien_polinom_hasil[i] << endl;
		}
		else if(koefisien_polinom_hasil[i] == 0){
			cout << "";
		}
		else if(koefisien_polinom_hasil[i] < 0 && i == derajat){
			cout << " - " << koefisien_polinom_hasil[i] << "x^" << i;
		}
		else if(koefisien_polinom_hasil[i] < 0 && i != derajat){
			cout << " - " << koefisien_polinom_hasil[i] << "x^" << i;
		}
		else if(koefisien_polinom_hasil[i] > 0 && i != derajat){
			cout << " + " << koefisien_polinom_hasil[i] << "x^" << i;
		}
		else{
			cout << koefisien_polinom_hasil[i] << "x^" << i;
		}
	}
}

void penjumlahan(){
	input_polinom();
	for(int i = 0; i<=max(derajat_polinom_1, derajat_polinom_2); i++){
		koefisien_polinom_hasil[i] = koefisien_polinom_1[i] + koefisien_polinom_2[i];
	}
	cetak();
}

void pengurangan(){
	input_polinom();
	for(int i = 0; i<=max(derajat_polinom_1, derajat_polinom_2); i++){
		koefisien_polinom_hasil[i] = koefisien_polinom_1[i] - koefisien_polinom_2[i];
	}
	cetak();
}

void perkalian(){
    input_polinom();
    for(int i = 0; i<=derajat_polinom_1 ; i++){
        for(int j=0; j<=derajat_polinom_2; j++){
            koefisien_polinom_hasil[i+j] = koefisien_polinom_hasil[i+j] + koefisien_polinom_1[i]*koefisien_polinom_2[j];
            derajat = i+j;
        }
    }
    cetak2();
}

void kerja(int x){
	if(x == 1){
		penjumlahan();
	}
	else if(x == 2){
		pengurangan();
	}
	else if(x == 3){
		perkalian();
	}
	else if(x == 4){
		//turunan();
	}
	else{
		cout << "Mohon maaf perintah tidak dapat dikenali" << endl;;
	}
}

int main(){
	daftar_perintah();
	cout << "Masukkan Perintah : ";
	cin >> perintah;
	kerja(perintah);
}
