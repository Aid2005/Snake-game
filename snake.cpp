#include <iostream>
#include <cstdlib>//Biblijoteka za rendom broj
#include <ctime>//Biblijoteka za rendom broj
#include <conio.h>//Biblijoteka za kontrole
#include <windows.h>//Biblijoteka za crtanje brisanje
#include <vector>//Biblijoteka za vektore
using namespace std;
int main(){//Main
//VARIJABLE!
	int score=0;//Skor
	int height=12;//Visina zida
	int width=30;//Duzina zida
	int snakey=height/2;//y pozicija glave zmije
	int snakex=width/2;//x pozicija glave zmije
	srand(time(NULL));//Rendom generisanje
	int foody=rand()%height;//y pozicija hrane
	int foodx=rand()%width;//x pozicija hrane
	bool gameover=false;//Za igru
	char strelice= 'd';//Kretanje
	vector <int> repx;//Vektor za rep na x osi
	vector <int> repy;//Vektor za rep na y osi
	int duzina=0;//Duzina repa
	PORAZ://Goto
	while(!gameover){//Pocetak igre
//CRTANJE!
		system("cls");//Komanda za crtanje
		for(int i=0;i<=width;i++) cout<<"#";//Crtanje gornjeg zida
		cout<<endl;//Novi red
		for(int i=0;i<=height;i++){//Visina zida
			for(int j=0;j<=width;j++){//Širina zida
				if(j==0 || j==width) cout<<"#";//Crtanje zidova sa strane
				else if(i==snakey && j==snakex) {//Pozicija glave zmije
				cout<<"O";}//Crtanje glave zmije
				else{//Rep
					bool rep=false;//Varijabla tacnosti za rep
					for(int k=0;k<repx.size();k++){//For za ispis koliko ce dug bit rep
						if(repx[k]==j && repy[k]==i){//Ako su kordinate iz k jednake j i i(tj. x i y)
							rep=true;//Rep povecaj
							break;//Napusti for
						}
					}
					if(rep) cout<<"o";//Crtanje repa
					else if(i==foody && j==foodx) cout<<"@";//Crtanje hrane
					else{//Prazan prostor
						cout<<" ";
					}
				}
			} 
			cout<<endl;//Novi red
		}
		for(int i=0;i<=width;i++)cout<<"#";//Doljnji zid
		cout<<endl;//Novi red
//FUNKCIJA IGRE!
		if(snakey==-1 || snakey==height+1 || snakex==-1 || snakex==width+1){//Dodoir zida i poraz
			gameover=true;//Kraj igre
			goto PORAZ;//Goto
		}
		if(snakey==foody && snakex==foodx){//Jedenje hrane
			foody=rand()%height;//Rendom mjesto hrane na y osi
			foodx=rand()%width;//Rendom mjesto hrane na x osi
			score=score+10;//Skor se povecava za 10
			duzina++;//Duzina repa
		}
		repx.insert(repx.begin(),snakex);//Glava zauzima prvu poziciju na x osi
		repy.insert(repy.begin(),snakey);//Glava zauzima prvu poziciju na y osi
		if(repx.size()>duzina){//Ako je rep predug
			repx.pop_back();//Obrisi zadnji dio repa na x osi
			repy.pop_back();//Obrisi zadnji dio repa na y osi
		}
		for(int i=0;i<duzina;i++){//Dio ako se zmija zabije u rep
			if(snakey==repy[i+1] && snakex==repx[i+1]){	
			    gameover=true;//Kraj igre
				goto PORAZ;//Goto
			}
		}
		cout<<"Vas skor: "<<score<<endl;//Ispis skora
		//KOMANDE
		if(_kbhit()){//Pritisci sa tastature
			char ch=_getch();
			if(ch=='w')strelice='w';//Gore
			if(ch=='s')strelice='s';//Dole
			if(ch=='a')strelice='a';//Lijevo
			if(ch=='d')strelice='d';//Desno
		}
		if(strelice=='w')snakey--;//Ide gore zmija
		if(strelice=='s')snakey++;//Ide dole zmija
		if(strelice=='a')snakex--;//Ide lijevo zmija
		if(strelice=='d')snakex++;//Ide desno zmija
		Sleep(300);//Komanda za brisanje
	}
	cout<<"GAME OVER!"<<endl;//Ispis kraja igre
	cout<<"Vas skor: "<<score<<"!"<<endl;//Ispis konacnog skora
}