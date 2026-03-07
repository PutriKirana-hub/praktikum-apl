#include <iostream>
#include <iomanip>
using namespace std;

/* ===================== STRUCT ===================== */

struct Vote{
    bool sudahVote;
    int idWaifu;
};

struct User{
    string nama;
    string nim;
    Vote vote;
};

struct Waifu{
    int id;
    string nama;
    string elemen;
    int jumlahVote;
};

/* ===================== FUNCTION ===================== */

void tampilWaifu(Waifu w[], int jumlah){

    cout<<"\n========================================\n";
    cout<<left<<setw(5)<<"ID"<<setw(15)<<"Nama"<<setw(15)<<"Elemen"<<setw(10)<<"Vote"<<endl;
    cout<<"========================================\n";

    for(int i=0;i<jumlah;i++){
        cout<<left<<setw(5)<<w[i].id
            <<setw(15)<<w[i].nama
            <<setw(15)<<w[i].elemen
            <<setw(10)<<w[i].jumlahVote<<endl;
    }
}

/* ===================== ADMIN CRUD ===================== */

void tambahWaifu(Waifu w[], int &jumlah){

    cout<<"\n=== Tambah Waifu ===\n";

    cout<<"ID: ";
    cin>>w[jumlah].id;

    cout<<"Nama: ";
    cin>>w[jumlah].nama;

    cout<<"Elemen: ";
    cin>>w[jumlah].elemen;

    w[jumlah].jumlahVote=0;

    jumlah++;

    cout<<"Waifu berhasil ditambahkan\n";
}

void editWaifu(Waifu w[], int jumlah){

    int id;
    cout<<"\nMasukkan ID Waifu yang ingin diedit: ";
    cin>>id;

    for(int i=0;i<jumlah;i++){

        if(w[i].id==id){

            cout<<"Nama baru: ";
            cin>>w[i].nama;

            cout<<"Elemen baru: ";
            cin>>w[i].elemen;

            cout<<"Data berhasil diupdate\n";
            return;
        }
    }

    cout<<"Waifu tidak ditemukan\n";
}

void hapusWaifu(Waifu w[], int &jumlah){

    int id;

    cout<<"\nMasukkan ID Waifu yang ingin dihapus: ";
    cin>>id;

    for(int i=0;i<jumlah;i++){

        if(w[i].id==id){

            for(int j=i;j<jumlah-1;j++){
                w[j]=w[j+1];
            }

            jumlah--;

            cout<<"Waifu berhasil dihapus\n";
            return;
        }
    }

    cout<<"Waifu tidak ditemukan\n";
}

/* ===================== USER ===================== */

void voting(User &u, Waifu w[], int jumlah){

    if(u.vote.sudahVote){
        cout<<"Anda sudah melakukan voting!\n";
        return;
    }

    int pilih;

    tampilWaifu(w,jumlah);

    cout<<"\nPilih ID Waifu: ";
    cin>>pilih;

    for(int i=0;i<jumlah;i++){

        if(w[i].id==pilih){

            w[i].jumlahVote++;

            u.vote.sudahVote=true;
            u.vote.idWaifu=pilih;

            cout<<"Voting berhasil!\n";
            return;
        }
    }

    cout<<"Waifu tidak ditemukan\n";
}

void gantiPassword(User &u){

    string lama,baru;

    cout<<"\nPassword lama: ";
    cin>>lama;

    if(lama==u.nim){

        cout<<"Password baru: ";
        cin>>baru;

        u.nim=baru;

        cout<<"Password berhasil diganti\n";
    }
    else{
        cout<<"Password salah\n";
    }
}

/* ===================== REGISTER ===================== */

void registerUser(User user[], int &jumlahUser){

    cout<<"\n=== REGISTER ===\n";

    cout<<"Nama: ";
    cin>>user[jumlahUser].nama;

    cout<<"NIM: ";
    cin>>user[jumlahUser].nim;

    user[jumlahUser].vote.sudahVote=false;

    jumlahUser++;

    cout<<"Register berhasil!\n";
}

/* ===================== MENU USER ===================== */

void menuUser(User &u, Waifu w[], int jumlahWaifu){

    int menu;

    do{

        cout<<"\n=== MENU USER ===\n";
        cout<<"1. Lihat Waifu\n";
        cout<<"2. Voting Waifu\n";
        cout<<"3. Ganti Password\n";
        cout<<"4. Logout\n";
        cout<<"Pilih: ";
        cin>>menu;

        switch(menu){

        case 1:
            tampilWaifu(w,jumlahWaifu);
        break;

        case 2:
            voting(u,w,jumlahWaifu);
        break;

        case 3:
            gantiPassword(u);
        break;

        }

    }while(menu!=4);
}

/* ===================== MENU ADMIN ===================== */

void menuAdmin(Waifu w[], int &jumlahWaifu){

    int menu;

    do{

        cout<<"\n=== MENU ADMIN ===\n";
        cout<<"1. Tambah Waifu\n";
        cout<<"2. Lihat Waifu\n";
        cout<<"3. Edit Waifu\n";
        cout<<"4. Hapus Waifu\n";
        cout<<"5. Logout\n";
        cout<<"Pilih: ";
        cin>>menu;

        switch(menu){

        case 1:
            tambahWaifu(w,jumlahWaifu);
        break;

        case 2:
            tampilWaifu(w,jumlahWaifu);
        break;

        case 3:
            editWaifu(w,jumlahWaifu);
        break;

        case 4:
            hapusWaifu(w,jumlahWaifu);
        break;

        }

    }while(menu!=5);
}

/* ===================== LOGIN ===================== */

void login(User user[], int jumlahUser, Waifu w[], int &jumlahWaifu){

    int kesempatan=0;

    while(kesempatan<3){

        string nama,nim;

        cout<<"\n=== LOGIN ===\n";
        cout<<"Nama: ";
        cin>>nama;

        cout<<"NIM: ";
        cin>>nim;

        if(nama=="admin" && nim=="admin"){
            menuAdmin(w,jumlahWaifu);
            return;
        }

        for(int i=0;i<jumlahUser;i++){

            if(user[i].nama==nama && user[i].nim==nim){
                menuUser(user[i],w,jumlahWaifu);
                return;
            }
        }

        cout<<"Login gagal\n";

        kesempatan++;
    }

    cout<<"Kesempatan login habis. Program berhenti.\n";
}

/* ===================== MAIN ===================== */

int main(){

    User user[50];
    Waifu waifu[50];

    int jumlahUser=0;
    int jumlahWaifu=3;

    waifu[0]={1,"Changli","Fusion",0};
    waifu[1]={2,"Jinhsi","Spectro",0};
    waifu[2]={3,"Yinlin","Electro",0};

    int menu;

    do{

        cout<<"\n=== SISTEM LIST WAIFU ===\n";
        cout<<"1. Register\n";
        cout<<"2. Login\n";
        cout<<"3. Keluar\n";
        cout<<"Pilih: ";
        cin>>menu;

        switch(menu){

        case 1:
            registerUser(user,jumlahUser);
        break;

        case 2:
            login(user,jumlahUser,waifu,jumlahWaifu);
        break;

        }

    }while(menu!=3);

    cout<<"Program selesai\n";

}