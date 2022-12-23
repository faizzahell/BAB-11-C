#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct dataMahasiswa {
  string nama;
  string NIM;
  string tempatLahir;
  string tanggalLahir;
  string alamat;
};

int main() {
  dataMahasiswa dataPertama;
  char namaFilePertama[100];
  char namaFileKedua[100];
  char namaFileKetiga[100];
  char extention[] = ".txt";
  string pilihan;
  string biodata;
  string output;
  string buffer1, buffer2;
  bool kondisi1, kondisi2, kondisi3 = false;

  fstream dataFile;

  cout << "=========================================================" << endl;
  cout << "-----------  PROGRAM COPY DARI ISI SUATU FILE  ----------" << endl;
  cout << "=========================================================" << endl << endl << endl;

  cout << "          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~        " << endl;
  cout << "         :           Buat File Pertama           :       " << endl;
  cout << "          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~        " << endl << endl;

  cin.ignore(100, '\n');
  
  cout << "  =>  Masukkan nama file  :  "; cin >> namaFilePertama; 

  strcat(namaFilePertama, extention);
  dataFile.open(namaFilePertama, ios::out);

  cout << endl << endl;

  cout << "=========================================================" << endl << endl;

  cout << "          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~        " << endl;
  cout << "         :       Masukkan Isi File Pertama       :       " << endl;
  cout << "          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~        " << endl << endl;

  cout << "  =>  Data diri mahasiswa (pribadi)" << endl << endl;
  

  cout << "  Masukkan Nama Anda      :  " << endl; getline(cin, dataPertama.nama);
  cout << "  Masukkan NIM Anda       :  " << endl; getline(cin, dataPertama.NIM);
  cout << "  Masukkan Tempat Lahir   :  " << endl; getline(cin, dataPertama.tempatLahir);
  cout << "  Masukkan Tanggal Lahir  :  " << endl; getline(cin, dataPertama.tanggalLahir);
  cout << "  Masukkan Alamat         :  " << endl; getline(cin, dataPertama.alamat);


  cout << endl << endl;

  dataFile << "Nama           :  " << dataPertama.nama;
  dataFile << "NIM            :  " << dataPertama.NIM;
  dataFile << "Tempat Lahir   :  " << dataPertama.tempatLahir;
  dataFile << "Tanggal Lahir  :  " << dataPertama.tanggalLahir;
  dataFile << "Alamat         :  " << dataPertama.alamat;

  dataFile.close();

  pilihanPertama:

  cout << "=========================================================" << endl << endl;
  cout << "  Apakah ingin membaca isi file (y/n)  :  "; cin >> pilihan;
  cout << endl << endl;
  cout << "=========================================================" << endl << endl;

  if (pilihan == "y" || pilihan == "Y") {
    dataFile.open(namaFilePertama, ios::in);

    while (!dataFile.eof()) {
      getline(dataFile, biodata);
      output.append("  " + biodata + "\n");
    }
    
    cout << output << endl << endl
    ;     
  } else if (pilihan == "n" || pilihan == "N") {
    goto lanjutkan;
  } else {
    cout << "=========================================================" << endl;
    cout << "-----------  Pilihan Yang Anda Masukkan Salah  ----------" << endl;
    cout << "=========================================================" << endl << endl;

    goto pilihanPertama;
  }

  lanjutkan:

  cout << "          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~        " << endl;
  cout << "         :            Buat File Kedua            :       " << endl;
  cout << "          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~        " << endl << endl;

  cout << "  =>  Masukkan nama file  :  "; cin >> namaFileKedua; 

  strcat(namaFileKedua, extention);
  dataFile.open(namaFileKedua, ios::out);

  cout << "=========================================================" << endl << endl;
  cout << "  Menyalin data sesuai dari file  :  "; cin >> namaFileKetiga;
  cout << endl << endl;

  strcat(namaFileKetiga, extention);

  cout << "=========================================================" << endl << endl;

  ifstream namaFile;
  namaFile.open(namaFileKetiga, ios::in);

  while (!namaFile.eof()) {
    namaFile >> buffer1;

    if (buffer1 == "Nama") {
      getline(namaFile, buffer2);
      output.append("  " + buffer1 + buffer2 + "\n");
      
      kondisi1 = true;
    }
    if (buffer1 == "NIM") {
      getline(namaFile, buffer2);
      output.append("  " + buffer1 + buffer2 + "\n");

      kondisi2 = true;
    }
    if (buffer1 == "Alamat") {
      getline(namaFile, buffer2);
      output.append("  " + buffer1 + buffer2 + "\n");

      kondisi3 = true;
    }
    if (kondisi1 = true && kondisi2 == true && kondisi3 == true) {
      break;
    }
  }

  cout << output;




  







  

  
}
