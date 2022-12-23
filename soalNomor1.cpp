#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main(){	
	int line = 4, deleteLine;
	string kalimat[line + 1];
  char namaFile[100];
  char extention[] = ".txt"; 

  cout << "=========================================================" << endl;
  cout << "----------  PROGRAM MENGHAPUS BARIS PADA FILE  ----------" << endl;
  cout << "=========================================================" << endl << endl << endl;

  cout << "  =>  Masukkan nama file  :  "; cin >> namaFile; 

  strcat(namaFile, extention);

  cout << endl << endl;
  cout << "          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~        " << endl;
  cout << "         : Menampilkan isi dari (" << namaFile << ") :    " << endl;
  cout << "          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~        " << endl << endl;

	ifstream datafile;
	ofstream updatedata;

	datafile.open(namaFile, ios::in );
	if (!datafile){
		cout << "========================================================" << endl;
		cout << "-------  FILE YANG DIPILIH TIDAK DAPAT DIBUKA!!  -------" << endl;
		cout << "========================================================" << endl << endl;

		return 0;
	}

	//menampilkan seluruh isi file sebelum penghapusan

	for (int i = 0 ; i < line; i++){
		getline( datafile , kalimat[i] );
		cout << "  " << i + 1 << ". " << kalimat[i] << endl;
	}

  cout << endl;
	cout << "=========================================================" << endl << endl;

	// meminta user untuk memilih baris yang akan dihapus

	ulang:

  cout << endl;
	cout << "  =>  Pilih baris yang akan di hapus  :  "; cin >> deleteLine;

	if (deleteLine > line || deleteLine < 1) {
    cout << endl;
    cout << "========================================================" << endl;
		cout << "-----------  BARIS YANG DIPILIH TIDAK SESUAI  ----------" << endl;
		cout << "========================================================" << endl << endl;
		goto ulang;
	};

	cout << "  =>  Anda menghapus baris ke-" << deleteLine << "  :  " << kalimat[deleteLine - 1] << endl << endl;

	// proses penghapusan salah satu baris (mengganti array yang dihapus dengan array berikutnya)

	bool condition = false;

	for (int i = 0; i < line; i++){
		if (deleteLine - 1 == i){
			condition = true;
		}

		if (condition == true){
			kalimat[i] = kalimat[i+1];
      line--;
		}
	}

	// menampilkan seluruh isi file setelah penghapusan salah satu baris

	updatedata.open( namaFile, ios::out );

	cout << "=========================================================" << endl << endl;

	cout << "          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~        " << endl;
  cout << "         : Menampilkan isi dari (" << namaFile << ") :    " << endl;
  cout << "          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~        " << endl << endl;

	for (int i = 0 ; i < line; i++){
		cout << " " << i + 1 << "  " << kalimat[i] << endl;
		updatedata << kalimat[i] << endl;
	}

  cout << endl;
	cout << "=========================================================" << endl << endl;
	cout << "  =>  Data berhasil diupdate..." << endl << endl;
  cout << "========================================================" << endl;
  cout << "---------   PROGRAM MENAMPILKAN HARI SELESAI   ---------" << endl;
  cout << "========================================================" << endl << endl;

	datafile.close();
	updatedata.close();

  cout << "source code by : Faizahel Joasa Ariesta";

	return 0;
}
