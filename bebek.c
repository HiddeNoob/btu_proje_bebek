#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define max_width_of_box 50
#define karakter_durum_sayisi 8

///////////////////////
#define tokluk 0
#define uyku 1
#define sosyallesme 2
#define saglik 3
#define egitim 4
#define hijyen 5
#define tuvalet 6
#define eglence 7
///////////////////////

int karakter_durum_data[karakter_durum_sayisi];

char karakter_durum_isimleri[karakter_durum_sayisi][100] = {"Tokluk","Uyku","Sosyallesme","Saglik","Egitim","Hijyen","Tuvalet","Eglence"};
void karakter_durum_data_sifirla(){ // default deger = 5 olarak ata
    for (int i = 0; i < karakter_durum_sayisi; i++) karakter_durum_data[i] = 5;
    
}
void grafik_yazdir(char isaret, int adet){

    adet = (float)adet/10*max_width_of_box; // oranti yaparak ciktiyi kolaylastirmak
    for (int i = 0; i < adet; i++)
    {
        printf("%c",isaret);
    }
    printf("\n");
    
}
void karakter_durum_yazdir(int durum_id) // -1 ise hepsini yazdir yoksa id'sine gore yazdir
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
void karakter_durum_tumunden_bir_eksilt(){ // saglik haric

    for (int i = 0; i < karakter_durum_sayisi; i++)
    {
        if (i == saglik) continue;
        else
            karakter_durum_data[i]--;
    }
    

}
void karakter_durumlarin_diger_durumlardan_etkilenmesi(){
    if(karakter_durum_data[hijyen] == 0)
        karakter_durum_data[saglik]--; // hijyen 0 ise ekstra olarak saglik bi kez daha azalsin

}
int karakter_yasiyor_mu(){ // karakter yasiyorsa 1 yasamiyorsa 0 dondur

    if(karakter_durum_data[tokluk] <= 0 || karakter_durum_data[uyku] <= 0 || karakter_durum_data[saglik] <= 0)
        return 0;
    else return 1;

}

void main(){

    karakter_durum_data_sifirla(); // baslangicta tum degerlere 5 atanir
    karakter_durum_yazdir(-1);

    

}