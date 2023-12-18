#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#define tokluk 0
#define uyku 1
#define sosyallesme 2
#define saglik 3
#define egitim 4
#define hijyen 5
#define tuvalet 6
#define eglence 7
#define yalnizlik 8
#define sinirlilik 9
#define karakter_durum_sayisi 10

void karakter_durum_data_sifirla(char* data_dizisi); // dum durumlara 5 atanir
void grafik_yazdir(char isaret, int adet);  // verilen isaret ve adete gore grafik yazdirir
void karakter_durum_yazdir(int durum_id, char* karakter_durum_data, char* karakter_durum_isimleri); // durum idsine gore grafiklestirerek yazdirir -1 değeri tüm durumlari yazdirir
void karakter_durum_tumunden_bir_eksilt(char* karakter_durum_data); // tum durumlardan 1 eksiltir
void karakter_durumlarin_diger_durumlardan_etkilenmesi(); // ?
int karakter_yasiyor_mu(); // yasiyorsa 1 yasamiyorsa 0
void oyunBaslat();

int main(){

    ///////////////////////////////////////////////////////////////////////////////////////////////
    int karakter_durum_data[karakter_durum_sayisi];
    char karakter_durum_isimleri[karakter_durum_sayisi][15] = {"Tokluk","Uyku","Sosyallesme","Saglik","Egitim","Hijyen","Tuvalet","Eglence","Yalnizlik"};
    int secim = -1;
    
    ////////////////////////////////////////////////////////////////////////////////////////////////
do{
    system("cls");
    do
    {
        printf(
        "Taiga Aisaka ile basa cikabilecek misin?\n\n"
        "1- Oyunu Baslat\n"
        "2- Oyunun Kurallari\n"
        "3- Karakter Ozellikleri\n"
        "4- Cikis\n"
        ">>>>> "
        );
        scanf("%d",&secim);

    } while (!(secim >= 1 && secim <= 4));
    system("cls");
    switch (secim)
    {
    case 1:
        oyunBaslat();
        break;
    case 2:
        printf(
            "Yaptigin Secimlere Gore Karakterini Hayatta Tutmaya Calis!\n"
            "Eger Karakterin Hayati Degerleri 0 ve altina duserse kaybedersin!\n\n"
            "\t<<< Hayati Durumlar >>>\n\n"
            "1- Saglik\t"
            "2- Uyku\t\t"
            "3- Tokluk\n\n"
        );
        fflush(stdin);
        printf("Menuye donmek icin 'Enter'a bas");
        getc(stdin);
        break;
    case 3:
        do{
            system("cls");
            int secim;
                printf(
                "Ozelliklerin Aciklamasini Okumak Icin Konsola Numarasini gir! \n\n-----------------------\n"
                "1- Pork Cutlet Bagimliligi\n"
                "2- Sinir Kupu\n"
                "3- RPG Delisi!\n"
                "\n\n4-Ana Menuye Don\n\n"
                ">>>>> "
                );
                scanf("%d",&secim);
                fflush(stdin);
            system("cls");
            switch (secim)
            {
            case 1:
                printf(
                    "Her uc gunde bir 'pork cutlet' yemez ise yemedigi her bir gun icin mutluluk 1 azalir ve sinirlilik 1 artar.\n"
                    "\n\nonceki menuye donmek icin 'enter'a bas >> "
                );
                getc(stdin);

                break;
            case 2:
                printf(
                    "Taiga oyle bir kisilige sahip ki nerdeyse her seye sinirleniyor! dikkatli ol!\n"
                    "\n\nonceki menuye donmek icin 'enter'a bas >> "
                );
                getc(stdin);
                
                break;
            case 3:
                printf(
                    "Taiga kucuklugunden beri rpg oyunlarina bagimli onla oynamazsan cok uzulur!\nEger iki gunde bir 'RPG' oynamazsan sinirlilik 1 artar ve mutluluk 1 azalir."
                    "\n\n\nonceki menuye donmek icin 'enter'a bas >> "
                );
                getc(stdin);
                break;
            case 4:
                break;
            default:
                printf("<<<< Yanlis Girdi Tekrar Deneyin >>>>\n\n");
                Sleep(1000);
            }
            system("cls");
            if(secim == 4)
                break;
        }while(1);
        break;
    case 4:
        printf("\n\n\tGorusmek Uzere!\n\n\n");
        Sleep(1000);
        return 1;
    }
}while(1);
     

    

}
void oyunBaslat(){

}
void karakter_durum_data_sifirla(char* karakter_durum_data){ // default deger = 5 olarak ata
    for (int i = 0; i < karakter_durum_sayisi; i++) karakter_durum_data[i] = 5;
    
}
void grafik_yazdir(char isaret, int adet){

    adet = (float)adet/10*30; // oranti yaparak ciktiyi kolaylastirmak
    for (int i = 0; i < adet; i++)
    {
        printf("%c",isaret);
    }
    for (int i = 0; i < adet; i++)
    {
        
    }
    
    printf("\n");
    
}
void karakter_durum_yazdir(int durum_id, char* karakter_durum_data, char* karakter_durum_isimleri) // -1 ise hepsini yazdir yoksa id'sine gore yazdir
{

    switch (durum_id)
    {

    case tokluk:
            printf("%s --> ",karakter_durum_isimleri[tokluk]);
            grafik_yazdir('#',karakter_durum_data[tokluk]);
        break;
    case uyku:
            printf("%s --> ",karakter_durum_isimleri[uyku]);
            grafik_yazdir('#',karakter_durum_data[uyku]);
        break;
    case sosyallesme:
            printf("%s --> ",karakter_durum_isimleri[sosyallesme]);
            grafik_yazdir('#',karakter_durum_data[sosyallesme]);
        break;
    case saglik:
            printf("%s --> ",karakter_durum_isimleri[saglik]);
            grafik_yazdir('#',karakter_durum_data[saglik]);
        break;
    case egitim:
            printf("%s",karakter_durum_isimleri[egitim]);
            grafik_yazdir('#',karakter_durum_data[egitim]);
        break;
    case hijyen:
            printf("%s --> ",karakter_durum_isimleri[hijyen]);
            grafik_yazdir('#',karakter_durum_data[hijyen]);
        break;
    case tuvalet:
            printf("%s --> ",karakter_durum_isimleri[tuvalet]);
            grafik_yazdir('#',karakter_durum_data[tuvalet]);
        break;
    case eglence:
            printf("%s --> ",karakter_durum_isimleri[eglence]);
            grafik_yazdir('#',karakter_durum_data[eglence]);
        break;
    case -1:
        for(int i = 0; i < karakter_durum_sayisi;i++ ) printf("%13s --> ",karakter_durum_isimleri[i]) ,grafik_yazdir('#',karakter_durum_data[i]); // tum karakter durumlarini yazdir
    }
}
void karakter_durum_tumunden_bir_eksilt(char* karakter_durum_data){ // saglik haric

    for (int i = 0; i < karakter_durum_sayisi; i++)
    {
        if (i == saglik) continue;
        else
            karakter_durum_data[i]--;
    }
    

}
int karakter_yasiyor_mu(char* karakter_durum_data){ // karakter yasiyorsa 1 yasamiyorsa 0 dondur

    if(karakter_durum_data[0] <= 0 || karakter_durum_data[1] <= 0 || karakter_durum_data[3] <= 0) // 0 tokluk // 1 uyku // 3 saglik
        return 0;
    else return 1;

}