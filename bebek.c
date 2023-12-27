#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>

#define tokluk 0
#define uyku 1
#define sosyallesme 2
#define saglik 3
#define egitim 4
#define hijyen 5
#define tuvalet 6
#define eglence 7
#define sinirlilik 8
#define sevgi 9
#define su_durumu 10
#define bagisiklik 11
#define karakter_durum_sayisi 12

char karakter_durum_isimleri[][15] = {"Tokluk","Uyku","Sosyallesme","Saglik","Egitim","Hijyen","Tuvalet","Eglence","Sinirlilik","Sevgi","Su","Bagisiklik"};

void karakter_durum_data_sifirla(int* data_dizisi); // dum durumlara 5 atanir
void grafik_yazdir(char isaret, int tur_sayisi);  // verilen isaret ve tur_sayisie gore grafik yazdirir
void karakter_durum_yazdir(int durum_id, int* karakter_durum_data,int rpg_sayac,int pork_cutlet_sayac); // durum idsine gore grafiklestirerek yazdirir -1 değeri tüm durumlari yazdirir
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
void SinirlilikFunction(int* karakter_durum_data,int n,int tur_sayisi);
void SevgiFunction(int* karakter_durum_data,int n,int tur_sayisi);
void SuFunction(int* karakter_durum_data,int n,int tur_sayisi);
void EgitimFunction(int* karakter_durum_data,int n,int tur_sayisi);
void BagisiklikFunction(int* karakter_durum_data,int n,int tur_sayisi);
void harfleri_kucult(char* cumle); // buyuk harfleri kucuk harfe donustur
void oyunBaslat(); // oyunu baslat
char* esya_adi(char* yemek_girdi); // bosluktan sonraki ilk harfin adresini donder
void animasyonlu_yazi(char* ekran_yazisi);
void karakter_olum_ekrani(int* karakter_durum_data);
void dolan_bar_animasyonu(int gecen_ms,char* text);
void karakter_ozellikleri_kontrol(int *karakter_durum_data,int rpg_sayac, int pork_cutlet_sayac);
void printASCIIArt();


int main(){
printASCIIArt();

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
        secim = getchar()-48; // char'i int e ceviriyor

    } while (!(secim >= 1 && secim <= 4));
    system("cls");
    switch (secim)
    {
    case 1:
        oyunBaslat();
        break;
    case 2:
        printf(
            "Yaptigin Secimlere Gore Karakterinin Durumlarini Belirtilen Degerlerde Tutmaya Calis!\n\n"
            ""
            "\t<<< Hayati Durumlar >>>\n\n"
            "0 < Saglik < 10\t\t"
            "0 < Uyku < 10\n\n"
            "0 < Tokluk < 10\t\t"
            "Sinirlilik < 10\n\n"
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
                "3- Sinir Kupu!\n"
                "\n\n4-Ana Menu\n\n"
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
                    "Her 6 eylemde bir 'Pork Cutlet' yemez ise 6 eylemin ardindan\nyemedigi her bir eylem icin sevgi 1 azalir ve sinirlilik 1 artar.\n"
                    "\n\nonceki menuye donmek icin 'enter'a bas >> "
                );
                getc(stdin);

                break;
            case 2:
                printf(
                    "Taiga kucuklugunden beri RPG oyunlarina bagimli onla oynamazsan cok uzulur!\nEger 4 eylemde bir 'RPG' oynamazsan 4 eylemin ardindan oynamadigi her bir eylem icin sinirlilik 1 artar ve sevgi 1 azalir."
                    "\n\n\nonceki menuye donmek icin 'enter'a bas >> "
                );
                getc(stdin);
                break;
            case 3:
                printf(
                    "Taiga Cok Sinirli Birisi eger siniri 10 ve ustune cikarsa ne yapacagi belli olmaz dikkat et!"
                    "\n\n\nonceki menuye donmek icin 'enter'a bas >> "
                );
                getc(stdin);
                break;
            case 4:
                break;
            default:
                printf("<<<< Yanlis Girdi Tekrar Deneyin >>>>\n\n");
                
            }
            system("cls");
            if(secim == 4)
                break;
        }while(1);
        break;
    case 4:
        printf("\n\n\tGorusmek Uzere!\n\n\n");
        
        exit(1);
    }
}while(1);

}
void oyunBaslat(){
    fflush(stdin);
    int karakter_durum_data[karakter_durum_sayisi];
    int rpg_sayac = 0;
    int pork_cutlet_sayac = 0;
    karakter_durum_data_sifirla(karakter_durum_data); // varsayilan olarak tum durumlara 5 atanir
    char girdi;
    do
    {
        system("cls"); // ekran temizleme kodu
        printf("\n");
        karakter_durum_yazdir(-1,karakter_durum_data,rpg_sayac,pork_cutlet_sayac); // grafik_Cizme fonksiyonunu kullanarak ekrana durumlarin grafigini ciziyor -1 degeri tum durumlari yazacagini belirtiyor
        duruma_gore_yazi_yazdir(karakter_durum_data);
        printf("\n");
        printf(
            "1- Temel Ihtiyaclar\n"
            "2- Eglence Vb.\n"
            "3- Kisisel Bakim\n"

            "\n4- Ana Menu\n\n"
            ">>>>> "
            );
        girdi = getchar();
        girdi -= '0'; // int'i scanf ile alinca bug oluyordu bu yuzden getchar ile aldim ve asciiden sayiya cevirdim
        system("cls");
        switch (girdi)
        {
        case 1:
            do
        {
            system("cls");
            int girdi2;
            char text_girdi[30];
            int text_adet = 0;
            char *text_isim = "null_Text"; // bi texti isaret etmezse kullanici yanlis girdi yaparsa bug olup program cokuyor
            karakter_durum_yazdir(-1,karakter_durum_data,rpg_sayac,pork_cutlet_sayac);
            fflush(stdin);
            printf(
            "\n1- Yemek\n"
            "2- Icecek\n"
            "3- Uyku\n"
            "\n4- Geri Don\n"
            ">>>>"
            );
            girdi2 = getchar();
            girdi2 -= '0';
            switch (girdi2)
                {
                    case 1:
                        do{
                            system("cls");
                            karakter_durum_yazdir(-1, karakter_durum_data,rpg_sayac,pork_cutlet_sayac);
                            printf(
                                "\n\n"
                                "|----------------  Yiyecekler  ----------------|\n"
                                "| Ramen +3 Tokluk                              |\n"
                                "|                                              |\n" 
                                "| Sata Andagi +2 Tokluk                        |\n"
                                "|                                              |\n" 
                                "| Onigiri +1 Tokluk                            |\n" 
                                "|                                              |\n" 
                                "| Sukiyaki +4 Tokluk +2 Tuvalet                |\n" 
                                "|                                              |\n" 
                                "| Pork Cutlet +3 Tokluk +2 Sevgi -2 Sinirlilik |\n" 
                                "|                                              |\n" 
                                "| Elma +1 Tokluk +2 Bagisiklik +1 Saglik       |\n" 
                                "|                                              |\n" 
                                "| Portakal +1 tokluk +3 Bagisiklik +1 Saglik   |\n" 
                                "|                                              |\n" 
                                "|----------------------------------------------|\n"
                                "\nYemek istediginiz yiyecegi 'adet isim' olarak yaziniz\n\ngeri donmek icin * tusuna basin\n\n"
                                "\n>>>>>> "
                                );
                            fflush(stdin); // gets scanf enter sorunu icin input sifirlama
                            gets(text_girdi);
                            harfleri_kucult(text_girdi); // kullanicinin tum karakterlerini kucuk harfe donustururek karsilasitrma yapmayi kolaylastirma
                            text_adet = atoi(text_girdi); // input (sayi isim) olacagi icin ilk elamanin adresini gönderip atoi fonksiyonu ile sayiyi cekiyoruz
                            text_isim = esya_adi(text_girdi); // bosluktan sonraki adresi gondererek ismi dondermis oluyor
                            if(text_girdi[0] == '*') break;
                            else if(!strcmp(text_isim,"ramen")){ // strcmp fonksiyonu ile yemek karsilastirmasi yapiliyor esit ise 0 dondurulur
                                animasyonlu_yazi("Ramen Yeniyor");
                                pork_cutlet_sayac++;
                                rpg_sayac++;
                                toklukFunction(karakter_durum_data,3,text_adet);
                                karakter_durumlarindan_bir_eksilt(karakter_durum_data,3,tokluk,sevgi,saglik);
                                karakter_ozellikleri_kontrol(karakter_durum_data,rpg_sayac,pork_cutlet_sayac);
                            }
                            else if(!strcmp(text_isim,"sata andagi")){
                                pork_cutlet_sayac++;
                                rpg_sayac++;
                                animasyonlu_yazi("Sata Andagi Yeniyor");
                                toklukFunction(karakter_durum_data,2,text_adet); 
                                karakter_durumlarindan_bir_eksilt(karakter_durum_data,3,tokluk,sevgi,saglik);
                                karakter_ozellikleri_kontrol(karakter_durum_data,rpg_sayac,pork_cutlet_sayac);
                            }
                            else if(!strcmp(text_isim,"onigiri")){
                                pork_cutlet_sayac++;
                                rpg_sayac++;
                                animasyonlu_yazi("Onigiri Yeniyor");
                                toklukFunction(karakter_durum_data,1,text_adet);
                                karakter_durumlarindan_bir_eksilt(karakter_durum_data,2,tokluk,saglik);
                                karakter_ozellikleri_kontrol(karakter_durum_data,rpg_sayac,pork_cutlet_sayac);
                            }
                            else if(!strcmp(text_isim,"sukiyaki")){
                                animasyonlu_yazi("Sukiyaki Yeniyor");
                                toklukFunction(karakter_durum_data,4,text_adet);
                                TuvaletFunction(karakter_durum_data,2,text_adet);
                                karakter_durumlarindan_bir_eksilt(karakter_durum_data,4,tokluk,sevgi,saglik,tuvalet);
                                pork_cutlet_sayac++;
                                rpg_sayac++;
                                karakter_ozellikleri_kontrol(karakter_durum_data,rpg_sayac,pork_cutlet_sayac);
                            }
                            else if(!strcmp(text_isim,"pork cutlet")){
                                animasyonlu_yazi("Pork Cutlet Yeniyor");
                                SinirlilikFunction(karakter_durum_data,-2,text_adet);
                                toklukFunction(karakter_durum_data,3,text_adet);
                                SevgiFunction(karakter_durum_data,2,text_adet);
                                karakter_durumlarindan_bir_eksilt(karakter_durum_data,3,tokluk,sevgi,saglik,sinirlilik);
                                rpg_sayac++;
                                pork_cutlet_sayac = 0;
                                karakter_ozellikleri_kontrol(karakter_durum_data,rpg_sayac,pork_cutlet_sayac);
                            }
                            else if(!strcmp(text_isim,"elma")){
                                animasyonlu_yazi("Elma Yeniyor");
                                toklukFunction(karakter_durum_data,1,text_adet);
                                BagisiklikFunction(karakter_durum_data,2,text_adet);
                                SaglikFunction(karakter_durum_data,1,text_adet);
                                karakter_durumlarindan_bir_eksilt(karakter_durum_data,3,tokluk,saglik,bagisiklik);
                                rpg_sayac++;
                                pork_cutlet_sayac++;
                                karakter_ozellikleri_kontrol(karakter_durum_data,rpg_sayac,pork_cutlet_sayac);
                            }
                            else if(!strcmp(text_isim,"portakal")){
                                animasyonlu_yazi("Portakal Yeniyor");
                                SaglikFunction(karakter_durum_data,1,text_adet);
                                toklukFunction(karakter_durum_data,1,text_adet);
                                BagisiklikFunction(karakter_durum_data,3,text_adet);
                                karakter_durumlarindan_bir_eksilt(karakter_durum_data,3,tokluk,saglik,bagisiklik);
                                rpg_sayac++;    
                                pork_cutlet_sayac++;
                                karakter_ozellikleri_kontrol(karakter_durum_data,rpg_sayac,pork_cutlet_sayac);
                            }
                            else{
                                printf("Yanlis Girdi Tekrar Deneyin\n");
                            
                            }
                        }while (1);
                        break;
                    case 2:
                        do
                        {
                        system("cls");
                        karakter_durum_yazdir(-1, karakter_durum_data,rpg_sayac,pork_cutlet_sayac);
                        printf(
                            "\n\n"
                            "|----------------- Icecekler -------------------|\n"
                            "|  Su -> +3 Su +1 Tuvalet                       |\n" // +3 su 
                            "|  Kola -> +1 su -1 Bagisiklik -1 Uyku +1 Sevgi |\n" // +1 su -1 bagisiklik -1 can -1 uyku
                            "|  Kahve -> -2 uyku +1 su                       |\n" // -2 uyku +1 su
                            "|  Cay -> +1 su  -2 sinirlilik                  |\n" // +1 su 
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
                            pork_cutlet_sayac++;
                            rpg_sayac++;
                            karakter_ozellikleri_kontrol(karakter_durum_data,rpg_sayac,pork_cutlet_sayac);
                            
                        }
                        else if(!strcmp(text_isim,"kola")){
                            SuFunction(karakter_durum_data,1,text_adet);
                            UykuFunction(karakter_durum_data,-1,text_adet);
                            SevgiFunction(karakter_durum_data,1,text_adet);
                            BagisiklikFunction(karakter_durum_data,-1,text_adet);
                            animasyonlu_yazi("Kola Iciliyor");
                            karakter_durumlarindan_bir_eksilt(karakter_durum_data,4,su_durumu,bagisiklik,saglik,uyku);
                            pork_cutlet_sayac++;
                            rpg_sayac++;
                            karakter_ozellikleri_kontrol(karakter_durum_data,rpg_sayac,pork_cutlet_sayac);
                        }
                        else if(!strcmp(text_isim,"kahve")){
                            SuFunction(karakter_durum_data,1,text_adet);
                            UykuFunction(karakter_durum_data,-2,text_adet);
                            animasyonlu_yazi("Kahve Iciliyor");
                            karakter_durumlarindan_bir_eksilt(karakter_durum_data,3,su_durumu,uyku,saglik);
                            pork_cutlet_sayac++;
                            rpg_sayac++;
                            karakter_ozellikleri_kontrol(karakter_durum_data,rpg_sayac,pork_cutlet_sayac);
                        }
                        else if(!strcmp(text_isim,"cay")){
                            SuFunction(karakter_durum_data,1,text_adet);
                            animasyonlu_yazi("Cay Iciliyor");
                            BagisiklikFunction(karakter_durum_data,-2,text_adet);
                            karakter_durumlarindan_bir_eksilt(karakter_durum_data,2,su_durumu,saglik);
                            pork_cutlet_sayac++;
                            rpg_sayac++;
                            karakter_ozellikleri_kontrol(karakter_durum_data,rpg_sayac,pork_cutlet_sayac);
                        }
                        else if(!strcmp(text_isim,"meyve suyu")){
                            SuFunction(karakter_durum_data,1,text_adet);
                            BagisiklikFunction(karakter_durum_data,2,text_adet);
                            animasyonlu_yazi("Meyve Suyu Iciliyor");
                            karakter_durumlarindan_bir_eksilt(karakter_durum_data,3,su_durumu,saglik,bagisiklik);
                            pork_cutlet_sayac++;
                            rpg_sayac++;
                            karakter_ozellikleri_kontrol(karakter_durum_data,rpg_sayac,pork_cutlet_sayac);
                        }
                        else{
                            printf("Yanlis Girdi Tekrar Deneyin");
                            
                        }
                        
                        } while (1);
                        break;
                    case 3:
                        do{
                            system("cls");
                            karakter_durum_yazdir(-1, karakter_durum_data,rpg_sayac,pork_cutlet_sayac);
                            printf(
                                "\n\n"
                                "|---------------------------------------------------|\n"
                                "|                                                   |\n" 
                                "| 1 - Kanepede Biraz Uzan (-3 Uyku -1 sinirlilik)   |\n"
                                "|                                                   |\n" 
                                "| 2 - Sabaha Kadar Uyu  (-9 Uyku -3 sinirlilik)     |\n"
                                "|                                                   |\n" 
                                "|---------------------------------------------------|\n"
                                "\n  3 - Geri don\n"
                                "\n"
                                "\n>>>>>> "
                                );
                            fflush(stdin); // gets scanf enter sorunu icin input sifirlama
                            girdi = getchar();
                            girdi -= '0';
                            if(girdi == 3) break;
                            else
                            {
                                switch (girdi)
                                {
                                case 1:
                                    UykuFunction(karakter_durum_data,-1,3);
                                    SinirlilikFunction(karakter_durum_data,-1,1);
                                    animasyonlu_yazi("Kanapede Uzaniliyor");
                                    karakter_durumlarindan_bir_eksilt(karakter_durum_data,3,uyku,saglik,sinirlilik);
                                    karakter_ozellikleri_kontrol(karakter_durum_data,rpg_sayac,pork_cutlet_sayac);
                                    pork_cutlet_sayac++;
                                    rpg_sayac++;
                                    break;
                                case 2:
                                    UykuFunction(karakter_durum_data,-3,3);
                                    SinirlilikFunction(karakter_durum_data,-3,1);
                                    animasyonlu_yazi("Uyunuluyor");
                                    karakter_durumlarindan_bir_eksilt(karakter_durum_data,2,uyku,saglik);
                                    karakter_ozellikleri_kontrol(karakter_durum_data,rpg_sayac,pork_cutlet_sayac);
                                    pork_cutlet_sayac++;
                                    rpg_sayac++;
                                    break;
                                }
                            }
                            
                        }while (1);
                    case 4:
                        break;
                    default:
                        system("cls");
                        printf("Bilinmeyen Girdi Tekrar Deneyin");
                       
                }
                if(girdi2 == 4) break;
            } while (1);
            break;
        case 2:
            do{
                system("cls");
                karakter_durum_yazdir(-1, karakter_durum_data,rpg_sayac,pork_cutlet_sayac);
                printf(
                    "\n\n"
                    "|-------------------------------------------------------------------------------------|\n"
                    "|                                                                                     |\n" 
                    "|   Taiga ile...                                                                      |\n" 
                    "|                                                                                     |\n" 
                    "| 1 - RPG oyna  (+2 Sosyallik +3 eglence +1 sevgi -3 sinirlilik)                      |\n"
                    "|                                                                                     |\n" 
                    "| 2 - Disarda vakit gecir  (+3 sosyallik  +2 uyku +2 eglence +1 sevgi -2 sinirlilik)  |\n"
                    "|                                                                                     |\n" 
                    "| 3 - Ders Calis (+3 Egitim +2 sinirlilik +2 uyku)                                    |\n" 
                    "|                                                                                     |\n" 
                    "| 4 - Kitap oku (+2 sosyallik +2 egitim)                                              |\n" 
                    "|                                                                                     |\n" 
                    "| 5 - Okula Git (+3 sosyallik +4 egitim -3 sinirlilik +3 uyku +2 eglence)             |\n" 
                    "|                                                                                     |\n" 
                    "|-------------------------------------------------------------------------------------|\n"
                    "\n  6 - Geri don\n"
                    "\n>>>>>> "
                    );
                fflush(stdin); // gets scanf enter sorunu icin input sifirlama
                girdi = getchar();
                girdi -= '0';
                switch (girdi)
                {
                case 1:
                    karakter_durumlarindan_bir_eksilt(karakter_durum_data,5,sosyallesme,eglence,sevgi,saglik,sinirlilik);
                    SosyallikFunction(karakter_durum_data,2,1);
                    EglenceFunction(karakter_durum_data,3,1);
                    SevgiFunction(karakter_durum_data,1,1);
                    SinirlilikFunction(karakter_durum_data,-3,1);
                    animasyonlu_yazi("Taiga ile RPG oynaniyor");
                    pork_cutlet_sayac++;
                    rpg_sayac = 0;
                    karakter_ozellikleri_kontrol(karakter_durum_data,rpg_sayac,pork_cutlet_sayac);
                    break;
                case 2:
                    SosyallikFunction(karakter_durum_data,3,1);
                    UykuFunction(karakter_durum_data,2,1);
                    EglenceFunction(karakter_durum_data,2,1);
                    SevgiFunction(karakter_durum_data,1,1);
                    SinirlilikFunction(karakter_durum_data,-2,1);
                    karakter_durumlarindan_bir_eksilt(karakter_durum_data,6,sosyallesme,eglence,sevgi,uyku,saglik,sinirlilik);
                    animasyonlu_yazi("Taiga ile vakit geciriliyor");
                    pork_cutlet_sayac++;
                    rpg_sayac++;
                    karakter_ozellikleri_kontrol(karakter_durum_data,rpg_sayac,pork_cutlet_sayac);
                    break;
                case 3:
                    animasyonlu_yazi("Taiga ile ders calisiliyor");
                    EgitimFunction(karakter_durum_data,3,1);
                    SinirlilikFunction(karakter_durum_data,2,1);
                    UykuFunction(karakter_durum_data,2,1);
                    karakter_durumlarindan_bir_eksilt(karakter_durum_data,4,eglence,sinirlilik,saglik,uyku);
                    pork_cutlet_sayac++;
                    rpg_sayac++;
                    karakter_ozellikleri_kontrol(karakter_durum_data,rpg_sayac,pork_cutlet_sayac);
                    break;
                case 4:
                    animasyonlu_yazi("Taiga ile kitap okunuyor");
                    SosyallikFunction(karakter_durum_data,2,1);
                    EgitimFunction(karakter_durum_data,2,1);
                    karakter_durumlarindan_bir_eksilt(karakter_durum_data,3,sosyallesme,egitim,saglik);
                    pork_cutlet_sayac++;
                    rpg_sayac++;
                    karakter_ozellikleri_kontrol(karakter_durum_data,rpg_sayac,pork_cutlet_sayac);
                    break;
                case 5:
                    animasyonlu_yazi("Taiga'yi Okula Gidiyor");
                    SosyallikFunction(karakter_durum_data,3,1);
                    EgitimFunction(karakter_durum_data,4,1);
                    SinirlilikFunction(karakter_durum_data,-3,1);
                    UykuFunction(karakter_durum_data,3,1);
                    EglenceFunction(karakter_durum_data,2,1);
                    karakter_durumlarindan_bir_eksilt(karakter_durum_data,6,sosyallesme,egitim,saglik,sinirlilik,uyku,eglence);
                    pork_cutlet_sayac++;
                    rpg_sayac++;
                    karakter_ozellikleri_kontrol(karakter_durum_data,rpg_sayac,pork_cutlet_sayac);
                    break;
                }
                if(girdi == 6) break;
            }while (1);
            break;
        case 3:
            do{
                system("cls");
                karakter_durum_yazdir(-1, karakter_durum_data,rpg_sayac,pork_cutlet_sayac);
                printf(
                    "\n\n"
                    "|-------------------------------------------------------------|\n"
                    "|                                                             |\n" 
                    "| 1 - Taiga Banyo Yapsin (+5 Hijyen +2 Saglik)                |\n"
                    "|                                                             |\n" 
                    "| 2 - Taigaya Saril  (+3 Sevgi -3 Sinirlilik +2 Sosyallesme)  |\n"
                    "|                                                             |\n" 
                    "| 3 - Taiganin Sacini Tara (+3 Hijyen +2 Sevgi -2 Sinirlilik) |\n" 
                    "|                                                             |\n" 
                    "| 4 - Taiga Tuvaletini Yapsin (-7 Tuvalet -2 Hijyen)          |\n" 
                    "|                                                             |\n" 
                    "| 5 - Taiganin Ellerini Yika (+3 Hijyen +1 Saglik)            |\n" 
                    "|                                                             |\n" 
                    "|-------------------------------------------------------------|\n"
                    "\n  6 - Geri don\n"
                    "\n>>>>>> "
                    );
                fflush(stdin); // gets scanf enter sorunu icin input sifirlama
                girdi = getchar();
                girdi -= '0';
                if(girdi == 6) break;
                switch (girdi)
                {
                case 1:
                    animasyonlu_yazi("Taiga Banyo Yapiyor");
                    SaglikFunction(karakter_durum_data,2,1);
                    HijyenFunction(karakter_durum_data,5,1);
                    karakter_durumlarindan_bir_eksilt(karakter_durum_data,2,saglik,hijyen);
                    pork_cutlet_sayac++;
                    rpg_sayac++;
                    karakter_ozellikleri_kontrol(karakter_durum_data,rpg_sayac,pork_cutlet_sayac);
                    break;
                case 2:
                    SevgiFunction(karakter_durum_data,3,1);
                    SinirlilikFunction(karakter_durum_data,-3,1);
                    SosyallikFunction(karakter_durum_data,2,1);
                    animasyonlu_yazi("Taigaya Sariliniyor");
                    pork_cutlet_sayac++;
                    rpg_sayac++;
                    karakter_ozellikleri_kontrol(karakter_durum_data,rpg_sayac,pork_cutlet_sayac);
                    break;
                case 3:
                    HijyenFunction(karakter_durum_data,3,1);
                    SevgiFunction(karakter_durum_data,2,1);
                    SinirlilikFunction(karakter_durum_data,-2,1);
                    animasyonlu_yazi("Taiganin Saci Taraniyor");
                    karakter_durumlarindan_bir_eksilt(karakter_durum_data,4,hijyen,sinirlilik,saglik,sevgi);
                    pork_cutlet_sayac++;
                    rpg_sayac++;
                    karakter_ozellikleri_kontrol(karakter_durum_data,rpg_sayac,pork_cutlet_sayac);
                    break;
                case 4:
                    animasyonlu_yazi("Taiga Tuvaletini Yapiyor");
                    TuvaletFunction(karakter_durum_data,-7,1);
                    HijyenFunction(karakter_durum_data,-2,1);
                    karakter_durumlarindan_bir_eksilt(karakter_durum_data,3,hijyen,tuvalet,saglik);
                    pork_cutlet_sayac++;
                    rpg_sayac++;
                    karakter_ozellikleri_kontrol(karakter_durum_data,rpg_sayac,pork_cutlet_sayac);
                    break;
                case 5:
                    animasyonlu_yazi("Taiganin Elleri Yikaniyor");
                    HijyenFunction(karakter_durum_data,3,1);
                    SaglikFunction(karakter_durum_data,1,1);
                    karakter_durumlarindan_bir_eksilt(karakter_durum_data,2,saglik,hijyen);
                    pork_cutlet_sayac++;
                    rpg_sayac++;
                    karakter_ozellikleri_kontrol(karakter_durum_data,rpg_sayac,pork_cutlet_sayac);
                    break;
                }
            }while (1);
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
void karakter_durum_yazdir(int durum_id, int* karakter_durum_data,int rpg_sayac,int pork_cutlet_sayac) // -1 ise hepsini yazdir yoksa id'sine gore yazdir
{
    if(karakter_durum_data[hijyen] <= 0) SaglikFunction(karakter_durum_data,-1,1);
    if(karakter_durum_data[tuvalet] >= 10){
        system("cls");
        printf(
        "\n\n\n"
        "\t\tTaiga Altina Yapti!"
        "\n\t -4 hijyen +2 sinirlilik -2 sevgi\n"
        );
        
        system("cls");
        karakter_durum_data[tuvalet] = 0;
        HijyenFunction(karakter_durum_data,-4,1);
        SinirlilikFunction(karakter_durum_data,2,1);
        SevgiFunction(karakter_durum_data,-2,1);
    }
    for (int i = 0; i < karakter_durum_sayisi; i++)
    {
        if(i == tokluk || i == uyku || i == sinirlilik || i == tuvalet) continue; // bu durumlar haric cunku olme durumu bunlarin 10 ve 0 alti oldugu durumlarda gecerli 
        if(karakter_durum_data[i] > 10) karakter_durum_data[i] = 10;

    }
    for (int i = 0; i < karakter_durum_sayisi; i++)
    {
        if(i == saglik || i == tokluk || i == su_durumu ||i == su_durumu) continue; // bu durumlar haric cunku olme durumu bunlarin 10 ve 0 alti oldugu durumlarda gecerli 
        if(karakter_durum_data[i] < 0) karakter_durum_data[i] = 0;

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
    if(karakter_durum_data[tokluk] < 4 || karakter_durum_data[tokluk] > 6 || karakter_durum_data[uyku] > 6 || karakter_durum_data[saglik] < 4 || karakter_durum_data[tuvalet] > 7 || karakter_durum_data[su_durumu] < 4) 
    {
        printf("\n------------------ Kritik Durumlar -----------------\n\n  ");
        if(karakter_durum_data[tokluk] < 4 || karakter_durum_data[tokluk] > 6) printf("- Tokluk -");
        if(karakter_durum_data[uyku] > 6) printf("- Uyku -");
        if(karakter_durum_data[saglik] < 4) printf("- Saglik -");
        if(karakter_durum_data[tuvalet] > 7) printf("- Tuvalet -");
        if(karakter_durum_data[su_durumu] < 4) printf("- Su -");
        printf("\n\n----------------------------------------------------\n");
    }
    printf("\n  Taiga %d/6 Eylemdir Pork Cutlet Yemiyor!\n",pork_cutlet_sayac);
    printf("  Taiga %d/4 Eylemdir RPG Oynamiyor!",rpg_sayac);
    printf("\n\n----------------------------------------------------");
}
void karakter_durumlarindan_bir_eksilt(int* karakter_durum_data,int n,...){ // n adet veriyi es gec ve diger durumlardan 1 eksilt

    int es_gecilecekler[n];
    va_list es_gec;
    va_start(es_gec,n);
    for (int i = 0; i < n; i++) es_gecilecekler[i] = va_arg(es_gec,int);
    va_end(es_gec);
    int es_gec_bayrak = 0;
    int azaltilacaklar[] = {tokluk,sosyallesme,saglik,egitim,hijyen,eglence,sevgi,su_durumu,bagisiklik};
    int artirilacaklar[] = {uyku,tuvalet,sinirlilik};
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
    for (int i = 0; i < 3; i++)
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
void printASCIIArt() {
    FILE *file = fopen("ascii-art.txt", "r");

    if (file == NULL) {
        perror("Dosya acma hatasi");
        return;
    }

    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    fclose(file);
}
int karakter_yasiyor_mu(int* karakter_durum_data){ // karakter yasiyorsa 1 yasamiyorsa 0 dondur
    if(karakter_durum_data[tokluk] <= 0 || karakter_durum_data[uyku] > 10 || karakter_durum_data[saglik] <= 0 || karakter_durum_data[tokluk] > 10 || karakter_durum_data[sinirlilik] >= 10 || karakter_durum_data[su_durumu] < 0) // 0 tokluk // 1 uyku // 3 saglik
        return 0;
    else return 1;
}
void duruma_gore_yazi_yazdir(int* karakter_durum_data){
    printf("\n\n");
    if(karakter_durum_data[saglik] < 3){
        printf("Taiga bitkin bir sekilde sana bakiyor");
    }
    else if(karakter_durum_data[saglik] > 5 && karakter_durum_data[su_durumu] > 6 && karakter_durum_data[tokluk] > 6 && karakter_durum_data[sevgi] > 7){
        system("cls");
        printf(
        "\n\tTaiga ansizin sana sariliyor ve sende dayanamayip sariliyorsun\n"
        "\t\t+2 sevgi"
        );
        SevgiFunction(karakter_durum_data,2,1);
    }
    else if(karakter_durum_data[su_durumu] < 4){
        printf("Taiga susuzluktan kivraniyor!");
    }
    else if(karakter_durum_data[sinirlilik] > 7){
        printf("Taiga cok sinirli dikkatli ol!");

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
    else if(karakter_durum_data[hijyen] < 3){
        printf("Taiga cok kirli gozukuyor belki de bi temizlemeyi dusunebilirsin");
    }
    else if(karakter_durum_data[sevgi] < 3){
        printf("Taiga Mutlu bi sekilde sarki dinliyor...");
    }
    else{
        srand(time(NULL));
        char rand_durumlar[][100] = {"Taiga Oylece Etrafda Dolasiyor","Taiga Senin Muzik Kasetlerini Inceliyor","Taiga bir yere dalmis, ne dusunuyor acaba..."};
        printf("%s",rand_durumlar[rand() % 3]);
    }
    printf("\n");
}
////////////////// bu iki aralik sadece durum degistirme fonksiyonlari //////////////////////////////////////////////////
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
void EgitimFunction(int* karakter_durum_data,int n,int tur_sayisi){
    karakter_durum_data[egitim] += n;
    if(tur_sayisi > 1) EgitimFunction(karakter_durum_data, n, tur_sayisi-1);
}
////////////////// bu iki aralik sadece durum degistirme fonksiyonlari //////////////////////////////////////////////////
void harfleri_kucult(char* cumle){ // harfleri buyukten kucuk yapar
    for(int i=0;cumle[i];i++) if(cumle[i]>='A' && cumle[i]<='Z') cumle[i]+=32;
}
char* esya_adi(char* yemek_girdi){ // bosluktan sonraki ilk elemanin adresini dondurur

    for(int i = 0; yemek_girdi[i]; i++) if(yemek_girdi[i] == ' ') return (yemek_girdi + i + 1);
    return yemek_girdi;
}
void animasyonlu_yazi(char* ekran_yazisi){ // 500'er ms bekleyerek nokta bastirir
    system("cls");
    printf(
        "\n\n\n"
        "\t\t%s"
        ,ekran_yazisi);
    for (int i = 0; i < 3; i++)
    {
        printf(".");
        
    }
}
void dolan_bar_animasyonu(int gecen_ms,char* text){ // girilen ms kadar bekleyerek 1 kare bastirir ve bir bar doldururma animasyonu olusur
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
        
        system("cls");
    }
}
void karakter_olum_ekrani(int* karakter_durum_data){ // karakterin olme sebebine gore olum mesaji bastirilir ve oyun yeniden baslatilir
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
        "\t\tTaiga bi anda bayilip uyku komasina girdi!"
        );
    }
    else if(karakter_durum_data[saglik] <= 0){
        printf(
        "\n\n\n"
        "\t\tTaiganin sagligi 0 oldugu icin oldu!"
        );
    }
    else if(karakter_durum_data[su_durumu] < 0){
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
   
    
    dolan_bar_animasyonu(150,"ANA MENUYE DONULUYOR");
    main();
    exit(1);

}
void karakter_ozellikleri_kontrol(int *karakter_durum_data,int rpg_sayac, int pork_cutlet_sayac){
    if (rpg_sayac >= 4)
    {
        SinirlilikFunction(karakter_durum_data,1,1);
        SevgiFunction(karakter_durum_data,-1,1);
    }
    if (pork_cutlet_sayac >= 6)
    {
        SinirlilikFunction(karakter_durum_data,1,1);
        SevgiFunction(karakter_durum_data,-1,1);
    }
    
}