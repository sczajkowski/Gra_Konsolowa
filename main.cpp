#include <iostream>
#include <windows.h>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
	bool zapetlaj=true;
	bool strzela=false;
	int rozmiarpl [2]  = {30,22};
	int ile=1;
	int pozgracza=rozmiarpl[0]/2;
	int predkoscfali=15;
	int wysmaleje=rozmiarpl[1]*predkoscfali;
	int poziom=2;
	bool pozwroga[70];
	int zyciewroga[70];
	int punkty=0;
	int zywiwrogowie;
	int taknie;
	int zestrzelenia;
	int dozabicia;
	int tempwys=rozmiarpl[1]*predkoscfali;
	int wybor=1;
	int punktyp;
	string wynikimie[10];
	int wynikpunkty[10];
	int tempwynik;
	string tempimie;
	bool duzapetla=true;
	bool kolejnapetla=true;
	int losowaniestrzalu[70];
	bool czystrzela[70];
	int odliczanie[70];
	bool strzelajteraz[70];
	bool strzalykoniec=false;
	bool strzalysrodek=false;
	int losujkolor;
	bool zapetlajmenu=true;
	int wyborustawienia=1;
	bool kolejnapetla2=true;
	int wyborkoloru=1;
	int kolorstatku=1;
	int kolorstrzalu=6;
	bool kolejnapetla3=true;
	bool kolejnapetla4=true;
	int wybortrudnosci=1;
	int mnoznik=100;
	int licznik=50;
	int loskos;
	int hiscore;
	int rozmiarokna;
	int prawolewo;
	int ktorymoment=1;
	bool grajmuzyke=true;
	bool zapetlajpause=false;
//	int strzelajace=0;
	bool petlaover=true;
void clearscreen(){
    HANDLE hOut;
    COORD Position;

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
  	Position.X = 0;
    Position.Y = 0;
    SetConsoleCursorPosition(hOut, Position);
}
void song(int moment){
		switch(moment){
		    case 1: Beep(100,100);break;
		    case 2: Beep(200,100);break;
		    case 3: Beep(300,100);break;
		    case 4: Beep(400,100);break;
		    case 5: Beep(500,100);break;
		    case 6: Beep(600,100);break;
		    case 7: Beep(700,100);break;
		    case 8: Beep(800,100);break;
		    case 9: Beep(900,100);break;
		    case 10: Beep(800,100);break;
		    case 11: Beep(700,100);break;
		    case 12: Beep(600,100);break;
		    case 13: Beep(500,100);break;
		    case 14: Beep(400,100);break;
		    case 15: Beep(300,100);break;
		    case 16: Beep(200,100);break;
		    case 17: Beep(100,100);break;
		}
		ktorymoment++;
		if(ktorymoment>17){
			ktorymoment=1;
		}
}
void kolorujstrzal(){
	HANDLE hOut;
   	hOut = GetStdHandle( STD_OUTPUT_HANDLE );
	switch(kolorstrzalu){
		case 1:
		SetConsoleTextAttribute( hOut, FOREGROUND_RED);
		break;
		case 2:
		SetConsoleTextAttribute( hOut, FOREGROUND_GREEN);
		break;
		case 3:
		SetConsoleTextAttribute( hOut, FOREGROUND_BLUE);
		break;
		case 4:
		SetConsoleTextAttribute( hOut, FOREGROUND_BLUE|FOREGROUND_GREEN);
		break;
		case 5:
		SetConsoleTextAttribute( hOut, FOREGROUND_BLUE|FOREGROUND_RED);
		break;
		case 6:
		SetConsoleTextAttribute( hOut, FOREGROUND_RED|FOREGROUND_GREEN);
		case 7:
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
		break;
	}
}
void wsong(){
	if(grajmuzyke){
		song(ktorymoment);	
	}
	else{
		Sleep(100);
	}
}
void kolorujstatek(){
	HANDLE hOut;
   	hOut = GetStdHandle( STD_OUTPUT_HANDLE );
	switch(kolorstatku){
		case 1:
		SetConsoleTextAttribute( hOut, FOREGROUND_RED);
		break;
		case 2:
		SetConsoleTextAttribute( hOut, FOREGROUND_GREEN);
		break;
		case 3:
		SetConsoleTextAttribute( hOut, FOREGROUND_BLUE);
		break;
		case 4:
		SetConsoleTextAttribute( hOut, FOREGROUND_BLUE|FOREGROUND_GREEN);
		break;
		case 5:
		SetConsoleTextAttribute( hOut, FOREGROUND_BLUE|FOREGROUND_RED);
		break;
		case 6:
		SetConsoleTextAttribute( hOut, FOREGROUND_RED|FOREGROUND_GREEN);
		case 7:
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
		break;
	}
}
void hcore(){
	ifstream czyt;
		czyt.open("wyniki.txt");
		czyt>>tempimie;
		czyt>>hiscore;
	czyt.close();
	if(hiscore>punktyp){
		cout<<hiscore;
	}
	else{
		cout<<punktyp;
	}
}
void czytajwyniki(){
		ifstream czytaj;
		system("cls");
			czytaj.open("wyniki.txt");
		while(ile<10){
				czytaj>>tempimie;
				while(tempimie.length()<10){
					tempimie.append(" ");
				}
				czytaj>>tempwynik;
				cout<<ile<<": "<<tempimie<<tempwynik<<endl;			
				ile++;
			}
		ile=1;
		czytaj.close();
}
void losowykolor(){
	HANDLE hOut;
   	hOut = GetStdHandle( STD_OUTPUT_HANDLE );
	losujkolor=(rand()%12)+0;
		switch(losujkolor){
			case 0:
    		SetConsoleTextAttribute( hOut, FOREGROUND_RED);
			break;
			
			case 1:
    		SetConsoleTextAttribute( hOut, FOREGROUND_GREEN );
			break;
			
			case 2:
    		SetConsoleTextAttribute( hOut, FOREGROUND_BLUE );
			break;
			
			case 3:
			SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_GREEN);
			break;
			
			case 4:
			SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE);
			break;
			
			case 5:
			SetConsoleTextAttribute( hOut, FOREGROUND_GREEN| FOREGROUND_BLUE);
			break;
			
			case 6:
			SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_RED |  FOREGROUND_BLUE);
			break;
			
			case 7:
			SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_RED |  FOREGROUND_GREEN);
			break;
			
			case 8:
			SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_GREEN|  FOREGROUND_GREEN);
			break;
			
			case 9:
			SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_GREEN|  FOREGROUND_GREEN);
			break;
			
			case 10:
			SetConsoleTextAttribute( hOut, FOREGROUND_BLUE| FOREGROUND_BLUE|  FOREGROUND_RED);
			break;
			
			case 11:
			SetConsoleTextAttribute( hOut, FOREGROUND_BLUE| FOREGROUND_BLUE|  FOREGROUND_GREEN);
			break;
		}
}
void gameover(){
	HANDLE hOut;
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );
	cout<<endl;
	losowykolor();cout<<" GGGGGGG     A     M M   M M  EEEEEE";losowykolor();cout<<"     OOO  V     V EEEEEE  RRRR  "<<endl;
	losowykolor();cout<<" G          A A    M  M M  M  E     ";losowykolor();cout<<"    O   O  V   V  E       R _ R "<<endl;
	losowykolor();cout<<" G    GG   A __A   M   M   M  EEEEE ";losowykolor();cout<<"    O   O  V   V  EEEEE   R  R  "<<endl;
	losowykolor();cout<<" G     G  A     A  M       M  E     ";losowykolor();cout<<"    O   O   V V   E       R   R "<<endl;
	losowykolor();cout<<" GGGGGGG A       A M       M  EEEEEE";losowykolor();cout<<"     OOO     V    EEEEEE  R    R"<<endl;
	SetConsoleTextAttribute( hOut, FOREGROUND_RED| FOREGROUND_GREEN|  FOREGROUND_BLUE);
	cout<<endl;
	cout<<endl;
	cout<<endl;
}
void koniecgry(){
		system("mode 70,15");
		ofstream zapisz;
		ifstream odczytaj;
		system("cls");
		wynikimie[0]="0";
		gameover();
		cout<<"                         Twój wynik      :"<<punktyp<<endl;
		Sleep(100);
		cout<<"                         Podaj swój nick :";
		cin>>wynikimie[0];
		cout<<endl;
		wynikpunkty[0]=punktyp;
		odczytaj.open("wyniki.txt");
			while(ile<9){
				odczytaj>>tempimie;
				wynikimie[ile]=tempimie;
				odczytaj>>tempwynik;
				wynikpunkty[ile]=tempwynik;			
				ile++;
			}
		odczytaj.close();
	
		for(int o=0;o<ile;o++){
			for(int i=0;i<ile;i++){				
				if(wynikpunkty[i]>wynikpunkty[i+1]){
					swap(wynikimie[i],wynikimie[i+1]); 
					swap(wynikpunkty[i],wynikpunkty[i+1]);
				}
			}
		}	
			
		zapisz.open("wyniki.txt");	

		while(ile>=0){			
			zapisz<<wynikimie[ile]<<endl;
			zapisz<<wynikpunkty[ile]<<endl;
			ile--;
		}
		zapisz.close();
		ile=1;
}
void czystrzelaja(){
//	while(strzelajace==0){
		for(int i;i<rozmiarpl[0];i++){
			if(zyciewroga[i]==3){
				losowaniestrzalu[i]=(rand()%2)+1;
			/*	if(losowaniestrzalu[i]==1){
					strzelajace++;
				}*/
			}
		}
//	}
//	strzelajace=0;
}
void definiuj(){
	for(int i=0;i<rozmiarpl[0];i++){
		taknie=(rand()%poziom)+0;
			if(taknie==1){
				pozwroga[i]=true;
				zyciewroga[i]=(rand()%3)+1;			//definiuje wrogów
			}
		odliczanie[i]=50;
	}
	czystrzelaja();
}
void strzelaj(){
	if(pozwroga[pozgracza+1]==true&&zyciewroga[pozgracza+1]!=0){
		zyciewroga[pozgracza+1]--;
	}
	if(pozwroga[pozgracza+1]==true&&zyciewroga[pozgracza+1]==0){
		pozwroga[pozgracza+1]=false;
		zestrzelenia++;
		Beep(300,100);
		dozabicia--;
	}
	//	Beep(500,100);
	//	Beep(1000,100);
}
void rysprzerwe(){
	HANDLE hOut;
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );
	for(int c=0;c<(wysmaleje/predkoscfali);c++){
		
		for(int i=0;i<rozmiarpl[0]+1;i++){
			
			if(pozgracza+1==i&&strzela){
				kolorujstrzal();
				cout<<"|";
				strzalysrodek=true;
				strzalykoniec=true;
			}
			else if(strzelajteraz[i]==true){
				SetConsoleTextAttribute( hOut, FOREGROUND_RED);
				cout<<"+";
					if(i==pozgracza||i==pozgracza+1||i==pozgracza+2){
					zapetlaj=false;
					}
			}
			else{
			cout<<" ";
			}
		}
		cout<<endl;
	}
	
	if(strzela){
		strzelaj();
	}
	for(int i=0;i<rozmiarpl[0];i++){
		strzelajteraz[i]=false;				//strza³y wrogów
		czystrzela[i]=false;
	}
	strzela=false;
	wysmaleje--;
	tempwys--;
	
		if((wysmaleje==0)&&(dozabicia!=0)){
			zapetlaj=false;
		}
		
}
void liczpunkty(){
	punkty=zestrzelenia*mnoznik;
	punktyp=punkty;
	cout<<punkty;
	punkty=0;
}
void zmianakierunku(){
	loskos=(rand()%rozmiarpl[0]-1)+1;
	int i=loskos;
		if(pozwroga[i]==true&&pozwroga[i-1]==false|pozwroga[i]==true&&pozwroga[i+1]==false){			
				if(pozwroga[i]==true&&pozwroga[i-1]==false&&pozwroga[i+1]==false&&i-1>0&&i+1<rozmiarpl[0]){
					prawolewo=(rand()%2)+1;
					switch(prawolewo){
						case 1:
						swap(pozwroga[i],pozwroga[i-1]);
						swap(zyciewroga[i],zyciewroga[i-1]);
						swap(losowaniestrzalu[i],losowaniestrzalu[i-1]);
						swap(czystrzela[i],czystrzela[i-1]);
						swap(strzelajteraz[i],strzelajteraz[i-1]);
						swap(odliczanie[i],odliczanie[i-1]);
						break;
						case 2:
						swap(pozwroga[i],pozwroga[i+1]);
						swap(zyciewroga[i],zyciewroga[i+1]);
						swap(losowaniestrzalu[i],losowaniestrzalu[i+1]);
						swap(czystrzela[i],czystrzela[i+1]);
						swap(strzelajteraz[i],strzelajteraz[i+1]);
						swap(odliczanie[i],odliczanie[i+1]);
						break;
					}					
				}
				else if(pozwroga[i-1]==false&&i-1>0){
					swap(pozwroga[i],pozwroga[i-1]);
					swap(zyciewroga[i],zyciewroga[i-1]);
					swap(losowaniestrzalu[i],losowaniestrzalu[i-1]);
					swap(czystrzela[i],czystrzela[i-1]);
					swap(strzelajteraz[i],strzelajteraz[i-1]);
					swap(odliczanie[i],odliczanie[i-1]);
				}
				else if(pozwroga[i+1]==false&&i+1<rozmiarpl[0]){
					swap(pozwroga[i],pozwroga[i+1]);
					swap(zyciewroga[i],zyciewroga[i+1]);
					swap(losowaniestrzalu[i],losowaniestrzalu[i+1]);
					swap(czystrzela[i],czystrzela[i+1]);
					swap(strzelajteraz[i],strzelajteraz[i+1]);
					swap(odliczanie[i],odliczanie[i+1]);
				}	
		}
}
void ryswrog(){
	HANDLE hOut;
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );
	if(dozabicia==0){
			definiuj();
			wysmaleje=rozmiarpl[1]*predkoscfali;
			tempwys=rozmiarpl[1]*predkoscfali;
			predkoscfali-=2;
	}
	cout<<" ";
	zmianakierunku();
	for(int i=1;i<rozmiarpl[0];i++){
			if(pozwroga[i]){
				switch(zyciewroga[i]){
					case 1:
					SetConsoleTextAttribute( hOut, FOREGROUND_GREEN );
					break;
					case 2:
					SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_GREEN);
					break;
					case 3:
					SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_RED );
					if(losowaniestrzalu[i]==1){
						SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
						odliczanie[i]--;
						if(odliczanie[i]==0){
							strzelajteraz[i]=true;
							czystrzelaja();
							odliczanie[i]=50;
						}
					}
					break;
				}
				cout<<"V";
				zywiwrogowie++;
				SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			}
			else if(pozgracza+1==i&&strzalysrodek){
				kolorujstrzal();
				cout<<"|";
				SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			}
			else{
				cout<<" ";
			}			
	}
	strzalysrodek=false;
	cout<<endl;
	dozabicia=zywiwrogowie;	
	zywiwrogowie=0;	

}
void ryskoniec(){
	HANDLE hOut;
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );
	for(int i=0;i<rozmiarpl[1]-tempwys/predkoscfali;i++){
			for(int i=0;i<rozmiarpl[0];i++){
				
			if(strzalykoniec&&pozgracza+1==i&&pozwroga[i]==false){
				kolorujstrzal();
				cout<<"|";
			}
			else{
				cout<<" ";
			}
		}
		cout<<endl;
	}
	strzalykoniec=false;
	SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}
void ryswyniki(){

	cout<<"SCORE   :";
	liczpunkty();
	cout<<"           ";
	cout<<endl;
	cout<<"HISCORE :";
	hcore();
	cout<<"           ";
	cout<<endl;
	
}	
void rysstatku(){
	HANDLE hOut;
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );
	if(pozgracza<=rozmiarpl[0]){
			for(int i=0;i<pozgracza;i++){
				cout<<" ";
			}
			kolorujstatek();
			cout<<"*^*";
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);	
			for(int i=0;i<rozmiarpl[0]-pozgracza;i++){
			cout<<" ";
			}
			cout<<endl;
	}
}
void animacjatla(){	
	HANDLE hOut;
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );
	losowykolor();
	cout<<"   _______                                                     "<<endl;
	losowykolor();
	cout<<"  ||     ||   ________      ____         __________    _______ "<<endl;
	losowykolor();
	cout<<" ||           ||     ||     ||||        ||       ||   | _____| "<<endl;
	losowykolor();
	cout<<" ||           ||      ||   ||  ||       ||            ||       "<<endl;
	losowykolor();
	cout<<"  ||______    ||      ||  ||    ||      ||            ||____   "<<endl;
	losowykolor();
	cout<<"         ||   ||_____||  ||______||     ||            |_____|  "<<endl;
	losowykolor();
	cout<<"          ||  ||        ||        ||    ||            ||       "<<endl;
	losowykolor();
	cout<<"          ||  ||       ||          ||   ||            ||_____  "<<endl;
	losowykolor();
	cout<<"  ||_____||   ||      ||            ||  ||_______||   |______| "<<endl;
	SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
}

void sterowanie(){
	  if (_kbhit()){
        switch (_getch()){
        	case 'a':
        		if(pozgracza>0){
        			pozgracza--;
        		}
        	break;
        	
        	case 'd':
		        if(pozgracza<rozmiarpl[0]-2){
		        	pozgracza++;
		        }
        	break;
        	
        	case 'w':
        		strzela=true;
        	break;
        	case 27:
        		if(zapetlajpause==false){
					zapetlajpause=true;
				}
        		else if(zapetlajpause){
        			zapetlajpause=false;
				}
			break;
        }
    }
}
void pausa(){
	while(zapetlajpause){
		cout<<"PAUZA"<<endl;
		sterowanie();
		Sleep(100);
		clearscreen();
	}
}
void zapiszustawienia(){
		ofstream zapiszu;
		zapiszu.open("ustawienia.txt");	
		zapiszu<<kolorstrzalu<<endl;
		zapiszu<<kolorstatku<<endl;
		zapiszu<<poziom<<endl;
		zapiszu<<predkoscfali<<endl;
		zapiszu<<mnoznik<<endl;
		zapiszu<<rozmiarpl[0]<<endl;
		zapiszu<<rozmiarokna<<endl;
		zapiszu<<grajmuzyke<<endl;
		zapiszu.close();
}
void czytajustawienia(){
		ifstream czytaju;
		czytaju.open("ustawienia.txt");
		czytaju>>kolorstrzalu;
		czytaju>>kolorstatku;
		czytaju>>poziom;
		czytaju>>predkoscfali;
		czytaju>>mnoznik;
		czytaju>>rozmiarpl[0];
		czytaju>>rozmiarokna;
		czytaju>>grajmuzyke;
		czytaju.close();
}
void kolorki(){
	HANDLE hOut;
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );
				switch(wyborkoloru){
						case 1:
							SetConsoleTextAttribute( hOut, FOREGROUND_RED);
							cout<<"--> Czerwony"<<endl;
							SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
							cout<<"    Zielony"<<endl;
							cout<<"    Niebieski"<<endl;
							cout<<"    Turkusowy"<<endl;
							cout<<"    Fioletowy"<<endl;
							cout<<"    ¯ó³ty"<<endl;
							cout<<"    Bia³y"<<endl;
						break;
						case 2:
							cout<<"    Czerwony"<<endl;
							SetConsoleTextAttribute( hOut, FOREGROUND_GREEN);
							cout<<"--> Zielony"<<endl;
							SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);							
							cout<<"    Niebieski"<<endl;
							cout<<"    Turkusowy"<<endl;
							cout<<"    Fioletowy"<<endl;
							cout<<"    ¯ó³ty"<<endl;
							cout<<"    Bia³y"<<endl;
						break;
						case 3:
							cout<<"    Czerwony"<<endl;
							cout<<"    Zielony"<<endl;
							SetConsoleTextAttribute( hOut, FOREGROUND_BLUE);						
							cout<<"--> Niebieski"<<endl;
							SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);	
							cout<<"    Turkusowy"<<endl;
							cout<<"    Fioletowy"<<endl;
							cout<<"    ¯ó³ty"<<endl;
							cout<<"    Bia³y"<<endl;
						break;
						case 4:
							cout<<"    Czerwony"<<endl;
							cout<<"    Zielony"<<endl;						
							cout<<"    Niebieski"<<endl;
							SetConsoleTextAttribute( hOut, FOREGROUND_BLUE|FOREGROUND_GREEN);	
							cout<<"--> Turkusowy"<<endl;
							SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
							cout<<"    Fioletowy"<<endl;
							cout<<"    ¯ó³ty"<<endl;
							cout<<"    Bia³y"<<endl;
						break;
						case 5:
							cout<<"    Czerwony"<<endl;
							cout<<"    Zielony"<<endl;						
							cout<<"    Niebieski"<<endl;
							cout<<"    Turkusowy"<<endl;
							SetConsoleTextAttribute( hOut, FOREGROUND_BLUE|FOREGROUND_RED);	
							cout<<"--> Fioletowy"<<endl;
							SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
							cout<<"    ¯ó³ty"<<endl;
							cout<<"    Bia³y"<<endl;
						break;
						case 6:
							cout<<"    Czerwony"<<endl;
							cout<<"    Zielony"<<endl;						
							cout<<"    Niebieski"<<endl;
							cout<<"    Turkusowy"<<endl;	
							cout<<"    Fioletowy"<<endl;
							SetConsoleTextAttribute( hOut, FOREGROUND_RED|FOREGROUND_GREEN);
							cout<<"--> ¯ó³ty"<<endl;
							SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
							cout<<"    Bia³y"<<endl;
						break;
						case 7:
							cout<<"    Czerwony"<<endl;
							cout<<"    Zielony"<<endl;						
							cout<<"    Niebieski"<<endl;
							cout<<"    Turkusowy"<<endl;	
							cout<<"    Fioletowy"<<endl;
							cout<<"    ¯ó³ty"<<endl;
							SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
							cout<<"--> Bia³y"<<endl;
						break;
					}
					wsong();
}
void menu(){
	HANDLE hOut;
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );
    system("mode 65,15");
	while(zapetlajmenu){
		animacjatla();
		cout<<endl;
		switch(wybor){
			case 1:
			SetConsoleTextAttribute( hOut, FOREGROUND_RED);
			cout<<"                  --> Nowa gra"<<endl;
			SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout<<"                      Najlepsze wyniki"<<endl;
			cout<<"                      Ustawienia"<<endl;
			cout<<"                      Koniec"<<endl;
			break;
			
			case 2:
			cout<<"                      Nowa gra"<<endl;
			SetConsoleTextAttribute( hOut, FOREGROUND_RED);
			cout<<"                  --> Najlepsze wyniki"<<endl;
			SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout<<"                      Ustawienia"<<endl;
			cout<<"                      Koniec"<<endl;
			break;
			
			case 3:
			cout<<"                      Nowa gra"<<endl;
			cout<<"                      Najlepsze wyniki"<<endl;
			SetConsoleTextAttribute( hOut, FOREGROUND_RED);
			cout<<"                  --> Ustawienia"<<endl;
			SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout<<"                      Koniec"<<endl;
			break;
			
			case 4:
			cout<<"                      Nowa gra"<<endl;
			cout<<"                      Najlepsze wyniki"<<endl;
			cout<<"                      Ustawienia"<<endl;
			SetConsoleTextAttribute( hOut, FOREGROUND_RED);
			cout<<"                  --> Koniec"<<endl;
			SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
			break;
		}
		if (_kbhit()){
	        switch (_getch()){
	        	case 'w':
	        	if(wybor>1){
	        		wybor--;
				}
				else{
					wybor=4;
				}
				Beep(5000,100);
	        	break;
	        	
	        	case 's':
			    if(wybor<4){
	        	wybor++;
				}
				else{
					wybor=1;
				}
				Beep(5000,100);
	        	break;
	        	
	        	case 13:
	        	Beep(5000,100);
	        	zapetlajmenu=false;
	        	system("cls");
	        }
	    }
		clearscreen();
		wsong();
	}
}
int main(){
	system("title SPACE");
	HANDLE hOut;
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );
	setlocale (LC_ALL, "");
	srand( time( NULL ) );
	czytajustawienia();
	definiuj();
	while(duzapetla){
		kolejnapetla=true;
		menu();
		switch(wybor){
			case 1:
			switch(rozmiarokna){
				case 1:
				system("mode 26,27");
				break;
				
				case 2:
				system("mode 34,27");
				break;
				
				case 3:
				system("mode 44,27");
	
				break;
			}
			
			while(zapetlaj){
				sterowanie();	
				pausa();		
				ryskoniec();
				ryswrog();
				rysprzerwe();
				rysstatku();
				ryswyniki();	
				clearscreen();
				Sleep(7);	
			}
			Beep(300,300);
			Beep(600,300);
			Beep(300,300);
			Beep(600,300);
			Beep(300,300);
			Beep(600,300);
			Beep(300,300);
			Beep(600,300);
			Beep(300,300);
			Beep(600,300);
			SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
			koniecgry();
			system("cls");
			return 0;
			break;
			
			case 2:
				czytajwyniki();
				SetConsoleTextAttribute( hOut, FOREGROUND_RED);
				cout<<"--> Powrót"<<endl;
				SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout<<endl;
				while(kolejnapetla){
					if (_kbhit()){
				        switch (_getch()){
				        	case 13:
				        	system("cls");
							wybor=2;
							kolejnapetla=false;
							zapetlajmenu=true;
							wybor=1;
							Beep(5000,100);
				        }
				    }
				    clearscreen();
					wsong();
				}
			break;
			
			case 3:
				system("cls");
				kolejnapetla2=true;
				kolejnapetla3=true;
				kolejnapetla4=true;
				while(kolejnapetla){
						switch(wyborustawienia){
							case 1:
								SetConsoleTextAttribute( hOut, FOREGROUND_RED);
								cout<<"--> Kolor strza³u"<<endl;
								SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
								cout<<"    Kolor statku"<<endl;
								cout<<"    Poziom trudnoœci"<<endl;
								if(grajmuzyke){
									cout<<"    Wy³¹cz muzyke"<<endl;
								}
								else{
									cout<<"    W³¹cz muzyke "<<endl;
								}
							break;
							case 2:
								cout<<"    Kolor strza³u"<<endl;
								SetConsoleTextAttribute( hOut, FOREGROUND_RED);
								cout<<"--> Kolor statku"<<endl;
								SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
								cout<<"    Poziom trudnoœci"<<endl;
								if(grajmuzyke){
									cout<<"    Wy³¹cz muzyke"<<endl;
								}
								else{
									cout<<"    W³¹cz muzyke "<<endl;
								}
							break;
							case 3:
								cout<<"    Kolor strza³u"<<endl;
								cout<<"    Kolor statku"<<endl;
								SetConsoleTextAttribute( hOut, FOREGROUND_RED);
								cout<<"--> Poziom trudnoœci"<<endl;
								SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
								if(grajmuzyke){
									cout<<"    Wy³¹cz muzyke"<<endl;
								}
								else{
									cout<<"    W³¹cz muzyke "<<endl;
								}
							break;
							case 4:
								cout<<"    Kolor strza³u"<<endl;
								cout<<"    Kolor statku"<<endl;
								cout<<"    Poziom trudnoœci"<<endl;
								SetConsoleTextAttribute( hOut, FOREGROUND_RED);
								if(grajmuzyke){
									cout<<"--> Wy³¹cz muzyke"<<endl;
								}
								else{
									cout<<"--> W³¹cz muzyke "<<endl;
								}
								SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
								
						}
				if (_kbhit()){
			        switch (_getch()){
			        	case 'w':
			        	if(wyborustawienia>1){
			        		wyborustawienia--;
						}
						else{
							wyborustawienia=4;
						}
						Beep(5000,100);
			        	break;
			        	
			        	case 's':
					    if(wyborustawienia<4){
			        	wyborustawienia++;
						}
						else{
							wyborustawienia=1;
						}
						Beep(5000,100);
			        	break;
			        	
			        	case 13:
			        	if(wyborustawienia==4&&grajmuzyke){
			        		grajmuzyke=false;
			        		zapiszustawienia();
						}
						else if(wyborustawienia==4&&grajmuzyke==false){
			        		grajmuzyke=true;
			        		ktorymoment=1;
			        		zapiszustawienia();
						}
						else{
			        	kolejnapetla=false;
			        	zapetlajmenu=false;
			       		}
			       		Beep(5000,100);
			        	break;
			        	case 27:
			        	kolejnapetla=false;
			        	zapetlajmenu=true;
			        	kolejnapetla2=false;
			        	kolejnapetla3=false;
			        	kolejnapetla4=false;
			        	wybor=1;
			        	wyborustawienia=1;
			        	Beep(5000,100);
			        	break;
			        }
			    }
			clearscreen();
		wsong();
			}
			kolejnapetla=true;
			switch(wyborustawienia){
				case 1:
					system("cls");
					while(kolejnapetla2){
						kolorki();
						if (_kbhit()){
					        switch (_getch()){
					        	case 'w':
					        	if(wyborkoloru>1){
					        		wyborkoloru--;
								}
								else{
									wyborkoloru=7;
								}
								Beep(5000,100);
					        	break;
					        	
					        	case 's':
							    if(wyborkoloru<7){
					        	wyborkoloru++;
								}
								else{
									wyborkoloru=1;
								}
								Beep(5000,100);
					        	break;
					        	case 13:
					        	kolejnapetla2=false;
					        	kolorstrzalu=wyborkoloru;
					        	zapiszustawienia();
					        	wyborkoloru=1;
					        	Beep(5000,100);
					        	break;
					        	case 27:
					        	kolejnapetla2=false;
					        	kolejnapetla=true;
					        	wyborkoloru=1;
					        	Beep(5000,100);
					        	break;
					        }
					    }
					clearscreen();
					wsong();
					}
				break;
				case 2:
					system("cls");
					while(kolejnapetla3){
						kolorki();
						if (_kbhit()){
					        switch (_getch()){
					        	case 'w':
					        	if(wyborkoloru>1){
					        		wyborkoloru--;
								}
								else{
									wyborkoloru=7;
								}
								Beep(5000,100);
					        	break;
					        	
					        	case 's':
							    if(wyborkoloru<7){
					        	wyborkoloru++;
								}
								else{
									wyborkoloru=1;
								}
								Beep(5000,100);
					        	break;
					        	case 13:
					        	kolejnapetla3=false;
					        	kolorstatku=wyborkoloru;
					        	zapiszustawienia();
					        	wyborkoloru=1;
					        	Beep(5000,100);
					        	break;
					        	case 27:
					        	kolejnapetla3=false;
					        	zapetlajmenu=false;
					        	wyborkoloru=1;
					        	Beep(5000,100);
					        	break;
					        }
					    }
					clearscreen();
					wsong();
					}
				break;
				case 3:
					system("cls");
					while(kolejnapetla4){
						switch(wybortrudnosci){
							case 1:
								SetConsoleTextAttribute( hOut, FOREGROUND_RED);
								cout<<"--> Trudny"<<endl;
								SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
								cout<<"    Normalny"<<endl;
								cout<<"    £atwy"<<endl;
							break;
							case 2:
								cout<<"    Trudny"<<endl;
								SetConsoleTextAttribute( hOut, FOREGROUND_RED);
								cout<<"--> Normalny"<<endl;
								SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
								cout<<"    £atwy"<<endl;
							break;
							case 3:
								cout<<"    Trudny"<<endl;
								cout<<"    Normalny"<<endl;
								SetConsoleTextAttribute( hOut, FOREGROUND_RED);
								cout<<"--> £atwy"<<endl;
								SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
							break;
						}
						if (_kbhit()){
					        switch (_getch()){
					        	case 'w':
					        	if(wybortrudnosci>1){
					        		wybortrudnosci--;
								}
								else{
									wybortrudnosci=3;
								}
								Beep(5000,100);
					        	break;
					        	
					        	case 's':
							    if(wybortrudnosci<3){
					        	wybortrudnosci++;
								}
								else{
									wybortrudnosci=1;
								}
								Beep(5000,100);
					        	break;
					        	case 13:
					        	kolejnapetla4=false;
					        	switch(wybortrudnosci){
					        		case 1:
					        			predkoscfali=40;
					        			poziom=3;
					        			mnoznik=150;
					        			rozmiarpl[0]=40;
					        			rozmiarokna=3;
					        		break;
					        		case 2:
					        			predkoscfali=30;
					        			poziom=2;
					        			mnoznik=125;
					        			rozmiarpl[0]=30;
					        			rozmiarokna=2;
					        		break;
					        		case 3:
					        			predkoscfali=30;
					        			poziom=3;
					        			mnoznik=100;
					        			rozmiarpl[0]=20;
					        			rozmiarokna=1;
					        		break;
								}
					        	zapiszustawienia();
					        	wybortrudnosci=1;
					        	Beep(5000,100);
					        	break;
					        	case 27:
					        	kolejnapetla4=false;
					        	kolejnapetla=true;
					        	wybortrudnosci=1;
					        	Beep(5000,100);
					        	break;
					        }
					    }
					clearscreen();
					wsong();
					}		
			}
			break;	
			case 4:
				system("cls");
			return 0;
			break;
		}
	}
}
