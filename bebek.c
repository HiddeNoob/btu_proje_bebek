#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdarg.h>

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
#define sevgi 10
#define su_durumu 11
#define bagisiklik 12
#define karakter_durum_sayisi 13

char karakter_durum_isimleri[][15] = {"Tokluk","Uyku","Sosyallesme","Saglik","Egitim","Hijyen","Tuvalet","Eglence","Yalnizlik","Sinirlilik","Sevgi","Su","Bagisiklik"};

void karakter_durum_data_sifirla(int* data_dizisi); // dum durumlara 5 atanir
void grafik_yazdir(char isaret, int tur_sayisi);  // verilen isaret ve tur_sayisie gore grafik yazdirir
void karakter_durum_yazdir(int durum_id, int* karakter_durum_data); // durum idsine gore grafiklestirerek yazdirir -1 değeri tüm durumlari yazdirir
void karakter_durumlarindan_bir_eksilt(int* karakter_durum_data,int n, ...); // gonderilen idleri es gecip digerlerinden 1 eksiltir
int  karakter_yasiyor_mu(int* karakter_durum_data); // yasiyorsa 1 yasamiyorsa 0
void duruma_gore_yazi_yazdir(int* karakter_durum_data); // ?
void toklukFunction(int* karakter_durum_data,int n,int tur_sayisi);
void UykuFunction(int* karakter_durum_data,int n,int tur_sayisi);
void SosyallikFunction(int* karakter_durum_data,int n,int tur_sayisi);
void SaglikFunction(int* karakter_durum_data,int n,int tur_sayisi);
void HijyenFunction(int* karakter_durum_data,int n,int tur_sayisi);
void TuvaletFunction(int* karakter_durum_data,int n,int tur_sayisi);
void EglenceFunction(int* karakter_durum_data,int n,int tur_sayisi);
void YalnizlikFunction(int* karakter_durum_data,int n,int tur_sayisi);
void SinirlilikFunction(int* karakter_durum_data,int n,int tur_sayisi);
void SevgiFunction(int* karakter_durum_data,int n,int tur_sayisi);
void SuFunction(int* karakter_durum_data,int n,int tur_sayisi);
void BagisiklikFunction(int* karakter_durum_data,int n,int tur_sayisi);
void harfleri_kucult(char* cumle); // buyuk harfleri kucuk harfe donustur
void oyunBaslat(); // oyunu baslat
char* esya_adi(char* yemek_girdi); // bosluktan sonraki ilk harfin adresini donder
void animasyonlu_yazi(char* ekran_yazisi);
void karakter_olum_ekrani(int* karakter_durum_data);
void dolan_bar_animasyonu(int gecen_ms,char* text);

int main(){

    int secim = -1;
    
do{
    do
    {
        system("cls");
        printf(
        "Taiga Aisaka ile basa cikabilecek misin?\n\n"
        "1- Oyunu Baslat\n"
        "2- Oyunun Kurallari\n"
        "3- Karakter Ozellikleri\n"
        "4- Cikis\n"
        ">>>>> "
        );
        fflush(stdin);
        secim = getchar()-48;

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
            "Eger Karakterin Hayati Degerleri 0 ve altina duserse karakterin olur!\n\n"
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
                "2- RPG Delisi!\n"
                "\n\n3-Ana Menu\n\n"
                ">>>>> "
                );
                scanf("%d",&secim);
                fflush(stdin);
            system("cls");
            switch (secim)
            {
            case 1:
                printf(
                    "Taiga 'Pork Cutlet' yemeden duramiyor! \n"
                    "Her uc gunde bir 'Pork Cutlet' yemez ise yemedigi her bir gun icin mutluluk 1 azalir ve sinirlilik 1 artar.\n"
                    "\n\nonceki menuye donmek icin 'enter'a bas >> "
                );
                getc(stdin);

                break;
            case 2:
                printf(
                    "Taiga kucuklugunden beri rpg oyunlarina bagimli onla oynamazsan cok uzulur!\nEger iki gunde bir 'RPG' oynamazsan sinirlilik 1 artar ve mutluluk 1 azalir."
                    "\n\n\nonceki menuye donmek icin 'enter'a bas >> "
                );
                getc(stdin);
                break;
            case 3:
                break;
            default:
                printf("<<<< Yanlis Girdi Tekrar Deneyin >>>>\n\n");
                Sleep(1000);
            }
            system("cls");
            if(secim == 3)
                break;
        }while(1);
        break;
    case 4:
        printf("\n\n\tGorusmek Uzere!\n\n\n");
        Sleep(1000);
        exit(1);
    }
}while(1);
     

    

}
void oyunBaslat(){
    fflush(stdin);
    int karakter_durum_data[karakter_durum_sayisi];
    karakter_durum_data_sifirla(karakter_durum_data);
    int girdi;
    do
    {
        system("cls");
        printf("\n");
        duruma_gore_yazi_yazdir(karakter_durum_data);
        karakter_durum_yazdir(-1,karakter_durum_data);
        printf("\n\n");
        printf(
            "1- Temel Ihtiyaclar\n"
            "2- Eglence!\n"
            "3- Kisisel Ihtiyac\n"

            "\n4- Ana Menu\n\n"
            ">>>>>"
            );
        scanf("%d",&girdi);
        system("cls");
        switch (girdi)
        {
        case 1:
            do
        {
            system("cls");
            char text_girdi[30];
            int text_adet = 0;
            char *text_isim = "null_Text";
            int girdi_ic = -1;
            karakter_durum_yazdir(-1,karakter_durum_data);
            printf(
            "\n1- Yemek\n"
            "2- Icecek\n"
            "3- Uyku\n"
            "\n4- Ana Menu\n"
            ">>>>"
            );
            scanf("%d",&girdi_ic);
            switch (girdi_ic)
                {
                    case 1:
                        do{
                            system("cls");
                            karakter_durum_yazdir(-1, karakter_durum_data);
                            printf(
                                "\n\n"
                                "|----------------  Yiyecekler  ----------------|\n"
                                "| Ramen +3 Tokluk                              |\n"
                                "|                                              |\n" 
                                "| Sata Andagi +2 Tokluk                        |\n"
                                "|                                              |\n" 
                                "| Onigiri +1 Tokluk                            |\n" 
                                "|                                              |\n" 
                                "| Sukiyaki +4 Tokluk                           |\n" 
                                "|                                              |\n" 
                                "| Pork Cutlet +3 Tokluk +2 Sevgi -2 Sinirlilik |\n" 
                                "|----------------------------------------------|\n"
                                
                                "Yemek istediginiz yiyecegi 'adet isim' olarak yaziniz\n\ngeri donmek icin * tusuna basin\n\n"
                                "\n>>>>>> "
                                );
                            fflush(stdin);
                            gets(text_girdi);
                            harfleri_kucult(text_girdi);
                            text_adet = atoi(text_girdi);
                            text_isim = esya_adi(text_girdi);
                            if(text_girdi[0] == '*') break;
                            else if(!strcmp(text_isim,"ramen")){
                                animasyonlu_yazi("Ramen Yeniyor");
                                toklukFunction(karakter_durum_data,3,text_adet);
                                karakter_durumlarindan_bir_eksilt(karakter_durum_data,3,tokluk,sevgi,saglik);
                            }
                            else if(!strcmp(text_isim,"sata andagi")){
                                animasyonlu_yazi("Sata Andagi Yeniyor");
                                toklukFunction(karakter_durum_data,2,text_adet);
                                karakter_durumlarindan_bir_eksilt(karakter_durum_data,3,tokluk,sevgi,saglik);
                            }
                            else if(!strcmp(text_isim,"onigiri")){
                                animasyonlu_yazi("Onigiri Yeniyor");
                                toklukFunction(karakter_durum_data,1,text_adet);
                                karakter_durumlarindan_bir_eksilt(karakter_durum_data,2,tokluk,saglik);
                            }
                            else if(!strcmp(text_isim,"sukiyaki")){
                                animasyonlu_yazi("Sukiyaki Yeniyor");
                                toklukFunction(karakter_durum_data,4,text_adet);
                                karakter_durumlarindan_bir_eksilt(karakter_durum_data,3,tokluk,sevgi,saglik);
                            }
                            else if(!strcmp(text_isim,"pork cutlet")){
                                animasyonlu_yazi("Pork Cutlet Yeniyor");
                                toklukFunction(karakter_durum_data,3,text_adet);
                                SevgiFunction(karakter_durum_data,2,text_adet);
                                karakter_durumlarindan_bir_eksilt(karakter_durum_data,3,tokluk,sevgi,saglik);
                            }
                            else{
                                printf("Yanlis Girdi Tekrar Deneyin\n");
                                Sleep(1000);
                            }
                        }while (1);
                        break;
                    case 2:
                        do
                        {
                        system("cls");
                        karakter_durum_yazdir(-1, karakter_durum_data);
                        printf(
                            "\n\n"
                            "|----------------- Icecekler -------------------|\n"
                            "|  Su -> +3 Su +1 Tuvalet                       |\n" // +3 su 
                            "|  Kola -> +1 su -1 Bagisiklik -1 Uyku +1 Sevgi |\n" // +1 su -1 bagisiklik -1 can -1 uyku
                            "|  Kahve -> -2 uyku +1 su                       |\n" // -2 uyku +1 su
                            "|  Cay -> +1 su                                 |\n" // +1 su 
                            "|  Meyve Suyu -> +1 su +2 bagisiklik            |\n" // +1 su 
                            "|-----------------------------------------------|\n"
                            "\nYemek istediginiz yiyecegi 'adet isim' olarak yaziniz\n\ngeri donmek icin * tusuna basin\n\n"
                            "\n>>>>>> "
                            );
                        fflush(stdin);
                        gets(text_girdi);
                        system("cls");
                        harfleri_kucult(text_girdi);
                        text_adet = atoi(text_girdi);
                        text_isim = esya_adi(text_girdi);
                        if(text_girdi[0] == '*') break;
                        else if(!strcmp(text_isim,"su")){
                            SuFunction(karakter_durum_data,3,text_adet);
                            TuvaletFunction(karakter_durum_data,1,text_adet);
                            animasyonlu_yazi("Su iciliyor");
                            karakter_durumlarindan_bir_eksilt(karakter_durum_data,2,su_durumu,saglik);

                        }
                        else if(!strcmp(text_isim,"kola")){
                            SuFunction(karakter_durum_data,1,text_adet);
                            UykuFunction(karakter_durum_data,-1,text_adet);
                            SevgiFunction(karakter_durum_data,1,text_adet);
                            BagisiklikFunction(karakter_durum_data,-1,text_adet);
                            animasyonlu_yazi("Kola Iciliyor");
                            karakter_durumlarindan_bir_eksilt(karakter_durum_data,4,su_durumu,bagisiklik,saglik,uyku);
                        }
                        else if(!strcmp(text_isim,"kahve")){
                            SuFunction(karakter_durum_data,1,text_adet);
                            UykuFunction(karakter_durum_data,-2,text_adet);
                            animasyonlu_yazi("Kahve Iciliyor");
                            karakter_durumlarindan_bir_eksilt(karakter_durum_data,3,su_durumu,uyku,saglik);
                        }
                        else if(!strcmp(text_isim,"cay")){
                            SuFunction(karakter_durum_data,1,text_adet);
                            animasyonlu_yazi("Cay Iciliyor");
                            karakter_durumlarindan_bir_eksilt(karakter_durum_data,2,su_durumu,saglik);
                        }
                        else if(!strcmp(text_isim,"meyve suyu")){
                            SuFunction(karakter_durum_data,1,text_adet);
                            animasyonlu_yazi("Meyve Suyu Iciliyor");
                            karakter_durumlarindan_bir_eksilt(karakter_durum_data,2,su_durumu,saglik);
                        }
                        else{
                            printf("Yanlis Girdi Tekrar Deneyin");
                            Sleep(1000);
                        }
                        
                        } while (1);
                        break;
                    case 3:
                        if(karakter_durum_data[uyku] < 7) system("cls"), printf("\n\n\n\t\tTaiga Uyumak Istemiyor!"), Sleep(2000);
                        else{
                            UykuFunction(karakter_durum_data,-3,3);
                            animasyonlu_yazi("Uyunuluyor");
                        }
                    case 4:
                        break;
                    default:
                        printf("Bilinmeyen Girdi Tekrar Deneyin");
                }
                if(girdi_ic == 4) break;
            } while (1);
            break;
        case 2:
            
            break;
        case 3:
            
            break;
        case 4:
            break;
        default:
            break;
        }
        if(girdi == 4)
            break;
    } while (1);
    
}
void karakter_durum_data_sifirla(int* karakter_durum_data){ // default deger = 5 olarak ata
    for (int i = 0; i < karakter_durum_sayisi; i++) karakter_durum_data[i] = 5;
    
}
void grafik_yazdir(char isaret, int tur_sayisi){ // oranti yaparak grafik olusturma
    int yatay_blok_sayisi = 30;
    if(tur_sayisi > 10) tur_sayisi = 10;
    else if(tur_sayisi < 0) tur_sayisi = 0;
    int yazdiralacak_blok = (float)tur_sayisi/10*yatay_blok_sayisi; 
    for (int i = 0; i < yazdiralacak_blok; i++)
    {
        printf("%c",isaret);
    }
    for (int i = 0; i < yatay_blok_sayisi-yazdiralacak_blok; i++) // kullaniciya eksik olani gosterebilmek icin - yazdirilir
    {
        printf("-");
    }
}
void karakter_durum_yazdir(int durum_id, int* karakter_durum_data) // -1 ise hepsini yazdir yoksa id'sine gore yazdir
{
    for (int i = 0; i < karakter_durum_sayisi; i++)
    {
        if(karakter_durum_data[i] > 12) karakter_durum_data[i] = 12; // durumlar 12 ustune cikamasin
        else if(karakter_durum_data[i] < -2) karakter_durum_data[i] = -2;
    }

    if(karakter_durum_data[tuvalet] >= 10){
        system("cls");
        printf(
        "\n\n\n"
        "\t\tTaiga Altina Yapti!"
        );
        Sleep(3000);
        karakter_durum_data[tuvalet] = 0;
        SinirlilikFunction(karakter_durum_data,2,1);
        SevgiFunction(karakter_durum_data,-2,1);
    }
    
    if(!karakter_yasiyor_mu(karakter_durum_data)) karakter_olum_ekrani(karakter_durum_data); // Ekrana yazdirmadan once karakter yasiyor mu kontrol
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
        for(int i = 0; i < karakter_durum_sayisi;i++ ){ // tum karakter durumlarini yazdir
            printf("%13s --> ",karakter_durum_isimleri[i]);
            grafik_yazdir('#',karakter_durum_data[i]);
            printf("  %d/10\n",karakter_durum_data[i]);
            } 
    }
}
void karakter_durumlarindan_bir_eksilt(int* karakter_durum_data,int n,...){ // n adet veriyi es gec ve durumlardan 1 eksilt

    int es_gecilecekler[n];
    va_list es_gec;
    va_start(es_gec,n);
    for (int i = 0; i < n; i++) es_gecilecekler[i] = va_arg(es_gec,int);
    va_end(es_gec);
    int es_gec_bayrak = 0;
    int azaltilacaklar[] = {tokluk,sosyallesme,saglik,egitim,hijyen,eglence,sevgi,su_durumu,bagisiklik};
    int artirilacaklar[] = {uyku,tuvalet,yalnizlik,sinirlilik};
    for (int i = 0; i < 9; i++)
    {
        for(int j = 0; j < n ; j++){
            if(es_gecilecekler[j] == azaltilacaklar[i]){
                es_gec_bayrak = 1;
                break;
            }
        }
        if(es_gec_bayrak){
            es_gec_bayrak = 0;
            continue;
        }
        karakter_durum_data[azaltilacaklar[i]]--;
    }
    for (int i = 0; i < 4; i++)
    {
        for(int j = 0; j < n ; j++){
            if(es_gecilecekler[j] == artirilacaklar[i]){
                es_gec_bayrak = 1;
                break;
            }
        }
        if(es_gec_bayrak){
            es_gec_bayrak = 0;
            continue;
        }
        karakter_durum_data[artirilacaklar[i]]++;
    }
}
int karakter_yasiyor_mu(int* karakter_durum_data){ // karakter yasiyorsa 1 yasamiyorsa 0 dondur
    if(karakter_durum_data[tokluk] <= 0 || karakter_durum_data[uyku] > 10 || karakter_durum_data[saglik] <= 0 || karakter_durum_data[tokluk] > 10 || karakter_durum_data[sinirlilik] >= 10) // 0 tokluk // 1 uyku // 3 saglik
        return 0;
    else return 1;
}
void duruma_gore_yazi_yazdir(int* karakter_durum_data){
    if(karakter_durum_data[saglik] < 3){
        printf("Taiga Aisaka bitkin bir sekilde sana bakiyor");
    }
    else if(karakter_durum_data[su_durumu] < 4){
        printf("Taiga Aisaka susuzluktan kivraniyor!");
    }
    else if(karakter_durum_data[tokluk] < 4){
        if(karakter_durum_data[sinirlilik] > 7)
            printf("Taiga cok sinirli gozukuyor belki 'Pork Cutlet' yedirirsen mutlu olabilir");
        else
            printf("(Mide Gurultusu)");
    }
    else if(karakter_durum_data[uyku] < 3){
        printf("Taigayi uyutsan iyi olucak gibi!");
    }
    else if(karakter_durum_data[sinirlilik] > 7){
        printf("Taiga sana oyle bir sinirle bakiyor ki...");

    }
    else if(karakter_durum_data[saglik] > 5 && karakter_durum_data[su_durumu] > 6 && karakter_durum_data[tokluk] > 6 && karakter_durum_data[sevgi] > 7){

        printf("Taiga ansizin sana sariliyor ve sende dayanamayip sende sariliyorsun");

    }
    printf("\n");
}
void toklukFunction(int* karakter_durum_data,int n,int tur_sayisi){
    karakter_durum_data[tokluk] += n;
    if(tur_sayisi > 1){
        toklukFunction(karakter_durum_data, n,tur_sayisi-1);
    }
}
void UykuFunction(int* karakter_durum_data,int n,int tur_sayisi){

    karakter_durum_data[uyku] += n;
    if(tur_sayisi > 1){
        UykuFunction(karakter_durum_data, n,tur_sayisi-1);
    }
}
void SosyallikFunction(int* karakter_durum_data,int n,int tur_sayisi){
    karakter_durum_data[sosyallesme] += n;
    if(tur_sayisi > 1) SosyallikFunction(karakter_durum_data,n,tur_sayisi-1);   
}
void SaglikFunction(int* karakter_durum_data,int n,int tur_sayisi){
    karakter_durum_data[saglik] += n;
    if(tur_sayisi > 1) SaglikFunction(karakter_durum_data,n,tur_sayisi-1);  
}
void HijyenFunction(int* karakter_durum_data,int n,int tur_sayisi){
    karakter_durum_data[hijyen] += n;
    if(tur_sayisi > 1) HijyenFunction(karakter_durum_data,n,tur_sayisi-1);  
}
void TuvaletFunction(int* karakter_durum_data,int n,int tur_sayisi){
    karakter_durum_data[tuvalet] += n;
    if(tur_sayisi > 1) TuvaletFunction(karakter_durum_data,n,tur_sayisi-1);
    
}
void EglenceFunction(int* karakter_durum_data,int n,int tur_sayisi){
    karakter_durum_data[eglence] += n;
    if(tur_sayisi > 1) EglenceFunction(karakter_durum_data, n, tur_sayisi-1);  
}
void YalnizlikFunction(int* karakter_durum_data,int n,int tur_sayisi){
    karakter_durum_data[yalnizlik] += n;
    if(tur_sayisi > 1) YalnizlikFunction(karakter_durum_data, n, tur_sayisi-1);   
}
void SinirlilikFunction(int* karakter_durum_data,int n,int tur_sayisi){
    karakter_durum_data[sinirlilik] += n;
    if(tur_sayisi > 1) SinirlilikFunction(karakter_durum_data, n, tur_sayisi-1);
    
}
void SevgiFunction(int* karakter_durum_data,int n,int tur_sayisi){
    karakter_durum_data[sevgi] += n;
    if(tur_sayisi > 1) SevgiFunction(karakter_durum_data, n, tur_sayisi-1);   
}
void SuFunction(int* karakter_durum_data,int n,int tur_sayisi){
    karakter_durum_data[su_durumu] += n;
    if(tur_sayisi > 1) SuFunction(karakter_durum_data, n, tur_sayisi-1);
}
void BagisiklikFunction(int* karakter_durum_data,int n,int tur_sayisi){
    karakter_durum_data[bagisiklik] += n;
    if(tur_sayisi > 1) BagisiklikFunction(karakter_durum_data, n, tur_sayisi-1);
}
void harfleri_kucult(char* cumle){ // harfleri buyukten kucuk yapar
    for(int i=0;cumle[i];i++) if(cumle[i]>='A' && cumle[i]<='Z') cumle[i]+=32;
}
char* esya_adi(char* yemek_girdi){ // bosluktan sonraki ilk elemanin adresini dondurur

    for(int i = 0; yemek_girdi[i]; i++) if(yemek_girdi[i] == ' ') return (yemek_girdi + i + 1);
    return yemek_girdi;
}
void animasyonlu_yazi(char* ekran_yazisi){
    system("cls");
    printf(
        "\n\n\n"
        "\t\t%s"
        ,ekran_yazisi);
    for (int i = 0; i < 3; i++)
    {
        printf(".");
        Sleep(500);
    }
}
void dolan_bar_animasyonu(int gecen_ms,char* text){
    system("cls");
    for (int i = 1; i <= 10; i++)
    {
        printf(
        "\n\t\t%s"
        "\n\n\t|--------------------------------|\n"
        "\t|                                |\n"
        "\t| "
        ,text);
        grafik_yazdir('#',i);
        printf(
        " |"
        "\n\t|                                |"
        "\n\t|--------------------------------|\n"
        );
        Sleep(gecen_ms);
        system("cls");
    }
}
void karakter_olum_ekrani(int* karakter_durum_data){
    system("cls");
    printf(
        "\n\n"
        "\t\t\tKAYBETTINIZ");
    /* // debugging icin
    for(int i = 0; i < karakter_durum_sayisi ; i++){
        printf("%s %d\n",karakter_durum_isimleri[i],karakter_durum_data[i]);
    }
    */
    if(karakter_durum_data[tokluk] > 10){
        printf(
        "\n\n\n"
        "\t\tTaiga o kadar yemek yedi ki patlayip oldu!"
        );
    }
    else if(karakter_durum_data[uyku] >= 10){
        printf(
        "\n\n\n"
        "\t\tTaiga o kadar yemek yedi ki patlayip oldu!"
        );
    }
    else if(karakter_durum_data[saglik] <= 0){
        printf(
        "\n\n\n"
        "\t\tTaiganin sagligi 0 oldugu icin oldu!"
        );
    }
    else if(karakter_durum_data[su_durumu] <= 0){
        printf(
        "\n\n\n"
        "\t\tTaiga susuzluktan oldu!"
        );
    }
    else if(karakter_durum_data[sinirlilik] >= 10){
        printf(
        "\n\n\n"
        "\t\tTaiga sinirlenip tahta kiliciyla seni doverek evden kovdu\n"
        );
    }
    Sleep(3000);
    
    dolan_bar_animasyonu(150,"ANA MENUYE DONULUYOR");
    return main();

}