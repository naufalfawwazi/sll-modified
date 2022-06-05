#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

struct Node {
  char nama[30];
  int umur;
  Node *next;
};

Node *head=NULL;
Node *tail=NULL;

void tambah() {
	char nama[30];
	int umur;
	cout<<"Masukan Nama Teman : "; cin>>nama;
	cout<<"Masukan Umur Teman : "; cin>>umur;
	Node *baru;
	baru = new Node;
	strcpy(baru->nama,nama);
	baru->umur=umur;
	
	Node *bantu;
	bantu = head;
	if(head==NULL) {
		head=baru;
		head->next=NULL;
		tail=head;
	} else if(baru->umur < head->umur) {
		baru->next = head;
		head = baru;
	} else if(baru->umur > tail->umur) {
		baru->next = NULL;
		tail->next = baru;
		tail = baru;
	} else {
		Node *penampung = bantu;
		while(bantu!=NULL) {

			if(bantu->umur >= baru->umur) {
				if(bantu->umur > baru->umur) { 
					baru->next = bantu;
					penampung->next = baru; 
				} else {
					while(bantu!=NULL) {
						if(strcmp(bantu->nama,baru->nama)>=0 && bantu->umur==baru->umur) {
							baru->next = bantu;
							if(bantu==head) head = baru; 
							else if(bantu==tail) penampung->next = baru; 
							else penampung->next = baru;
							break;
						}
						if(bantu->umur!=baru->umur) break;
						if(bantu->next==NULL) break;
						penampung = bantu;
						bantu = bantu->next;
					}
					
					if(bantu->next==NULL && strcmp(baru->nama,bantu->nama)>=0 && bantu->umur==baru->umur) { 
						baru->next = NULL;
						bantu->next = baru;
						tail = baru;  
					}

					if(bantu->umur != baru->umur) {
						if(penampung==head) { 
							baru->next = penampung->next;
							head = baru; 
						} else if(penampung==tail) { 
							baru->next = tail;
							penampung->next = baru; 
						} else { 
							baru->next = penampung->next;
							penampung->next = baru; 
						} break;
					} 
					
				} break;
			}
			penampung = bantu;
			bantu = bantu->next;
		} 
	} getch();
}

void hapus() {
	if(head==NULL) {
		cout<<"List masih kosong\n";
	} else {
		if(head==tail) {
			cout<<"berhasil menghapus "<<head->nama<<" dari List\n";
			delete head;
			head=NULL; tail=NULL;
		} else {
			char x[30];
			bool found=false;
			cout<<"Menghapus nama siapa : "; cin>>x;
			Node *bantu;
			bantu=head;
			if(strcmp(x, head->nama)==0) {
				head=head->next;
				delete bantu;
				found=true;
			} else if(strcmp(x, tail->nama)==0) {
				while(bantu->next!=tail) {
					bantu = bantu->next;
				} bantu->next = NULL;
				delete tail;
				tail = bantu; found=true;
			} else {
				while(bantu->next!=NULL) {
					if(strcmp(x,(bantu->next)->nama)==0 ) {
						Node *hapus;
						hapus=bantu->next;
						if((bantu->next)->next==NULL) {
							bantu->next=NULL;
							tail=bantu;	
						} else
							bantu->next = (bantu->next)->next;
						delete hapus;
						found=true; break;
					} bantu = bantu->next;
				}
			}
			if(!found) cout<<x<<" tidak ada di List\n";
			else cout<<"berhasil menghapus "<<x<<" dari List\n";
		} 
	} getch();
}

void tampil() {
  Node *bantu;
  bantu=head;
  if(head!=NULL) {
    while(bantu!=NULL) {
      cout<<bantu->nama<<" "<<bantu->umur<<" -> ";
      bantu=bantu->next;
    } cout<<"NULL\n";
  } else cout <<"List masih kosong\n";
	getch();
}

int main() {
	int pilih;
	do {
		system("cls");
		cout<<"1. Menambah Data"<<endl;
		cout<<"2. Menghapus Data"<<endl;
		cout<<"3. Menampilkan Data"<<endl;
		cout<<"4. Keluar Program"<<endl;
		cout<<"Pilihan Anda [1-4] : "; cin>>pilih;
	
		if(pilih==1) tambah();
		if(pilih==2) hapus();
		if(pilih==3) tampil();
	} while(pilih!=4);
	
	return 0;
}
