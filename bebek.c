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
void duruma_gore_yazi_yazdir(int* karakter_durum_data);
void toklukFunction(int* karakter_durum_data,int n,int tur_sayisi);
void UykuFunction(int* karakter_durum_data,int n,int tur_sayisi);
void SosyallikFunction(int* karakter_durum_data,int n,int tur_sayisi);
void SaglikFunction(int* karakter_durum_data,int n,int tur_sayisi);
void HijyenFunction(int* karakter_durum_data,int n,int tur_sayisi);
void TuvaletYap(int* karakter_durum_data,int n,int tur_sayisi);
void EglenceFunction(int* karakter_durum_data,int n,int tur_sayisi);
void YalnizlikFunction(int* karakter_durum_data,int n,int tur_sayisi);
void SinirlilikFunction(int* karakter_durum_data,int n,int tur_sayisi);
void SevgiFunction(int* karakter_durum_data,int n,int tur_sayisi);
void SuFunction(int* karakter_durum_data,int n,int tur_sayisi);
void harfleri_kucult(char* cumle);
void oyunBaslat();

int main(){

    ///////////////////////////////////////////////////////////////////////////////////////////////
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
            "Eger Karakterin Hayati Degerleri 0 ve altina duserse karakterin olur! (belkide sen olursun...))\n\n"
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
                    "Taiga 'Pork Cutlet' yemeden duramiyor! \n"
                    "Her uc gunde bir 'Pork Cutlet' yemez ise yemedigi her bir gun icin mutluluk 1 azalir ve sinirlilik 1 artar.\n"
                    "\n\nonceki menuye donmek icin 'enter'a bas >> "
                );
                getc(stdin);

                break;
            case 2:
                printf(
                    "Taiga oyle bir kisilige sahip ki nerdeyse her seye sinirleniyor dikkatli ol!\n"
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
            );
        scanf("%d",&girdi);
        system("cls");
        switch (girdi)
        {
        case 1:
        do
        {
            int girdi_ic = -1;
            printf(
            "1- Yemek\n"
            "2- Icecek\n"
            "3- Uyku\n"
            );
            scanf("%d",&girdi_ic);
            system("cls");
            switch (girdi_ic)
            {
            case 1:
                char yemek_ismi_girdi[30];
            do{
                karakter_durum_yazdir(-1, karakter_durum_data);
                printf(
                    "\nYiyebilecegin Yemekler\n"
                    "-----------------------\n"
                    " Ramen +3 Tokluk\n"
                    " Sata Andagi +2 Tokluk\n"
                    " Onigiri +1 Tokluk\n" 
                    " Sukiyaki +4 Tokluk\n" 
                    "-----------------------\n"
                    
                    "Yemek istediginiz yiyecegi 'adet isim' olarak yaziniz geri donmek icin * tusuna basin\n\n"
                    "\n>>>>>> "
                    );
                gets(yemek_ismi_girdi);
                system("cls");
                harfleri_kucult(yemek_ismi_girdi);
                if(yemek_ismi_girdi == '*') break;
                else if(!strcmp(yemek_ismi_girdi,"ramen"))
                    toklukFunction(karakter_durum_data,3,1);
                else if(!strcmp(yemek_ismi_girdi,"sata andagi"))
                    toklukFunction(karakter_durum_data,2,1);
                else if(!strcmp(yemek_ismi_girdi,"onigiri"))
                    toklukFunction(karakter_durum_data,1,1);
                else if(!strcmp(yemek_ismi_girdi,"sukiyaki"))
                    toklukFunction(karakter_durum_data,4,1);
                else{
                    printf("Yanlis Girdi Tekrar Deneyin");
                    Sleep(1000);
                }
                karakter_durumlarindan_bir_eksilt(karakter_durum_data,2,tokluk,saglik); // istisna tokluk
            }while (1);
                break;
            case 2:
                do
                {
                karakter_durum_yazdir(-1, karakter_durum_data);
                printf(
                    "\n--- Icecekler ---\n"
                    "|----------------------|\n"
                    "|         Su           |\n" // +3 su 
                    "|         Kola         |\n"  // +1 su -1 bagisiklik -1 can -1 uyku
                    "|         Kahve        |\n" // -2 uyku +1 su
                    "|         Cay          |\n" // +1 su 
                    "|----------------------|\n"
                    
                    "5- Geri Git\n\n"
                    "\n>>>>>> "
                    );
                scanf("%d",&girdi);
                system("cls");
                switch (girdi)
                {
                case 1:
                    SuFunction(karakter_durum_data,3,1); // TODO bagisiklik eklenecek
                    break;
                case 2:
                    SuFunction(karakter_durum_data,2,1);
                    break;
                case 3:
                    SuFunction(karakter_durum_data,1,1); 
                    SaglikFunction(karakter_durum_data,-1,1); 
                    break;
                case 4:
                    break;
                case 5:
                    break;
                default:
                    printf("Yanlis Girdi Tekrar Deneyin");
                    Sleep(1000);
                }
                if(girdi == 5) break;
                karakter_durumlarindan_bir_eksilt(karakter_durum_data,1,tokluk);
                } while (1);
            }
        } while (1);
            break;
        case 2:
            
            break;
        case 3:
            
            break;
        
        default:
            break;
        }
    } while (1);
    
}
void karakter_durum_data_sifirla(int* karakter_durum_data){ // default deger = 5 olarak ata
    for (int i = 0; i < karakter_durum_sayisi; i++) karakter_durum_data[i] = 5;
    
}
void grafik_yazdir(char isaret, int tur_sayisi){ // oranti yaparak grafik olusturma
    int yatay_blok_sayisi = 30;
    int yazdiralacak_blok = (float)tur_sayisi/10*yatay_blok_sayisi; 
    for (int i = 0; i < yazdiralacak_blok; i++)
    {
        printf("%c",isaret);
    }
    for (int i = 0; i < yatay_blok_sayisi-yazdiralacak_blok; i++) // kullaniciya eksik olani gosterebilmek icin - yazdirilir
    {
        printf("-");
    }
    printf("  %d/10",tur_sayisi);
    printf("\n");
    
}
void karakter_durum_yazdir(int durum_id, int* karakter_durum_data) // -1 ise hepsini yazdir yoksa id'sine gore yazdir
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
void karakter_durumlarindan_bir_eksilt(int* karakter_durum_data,int n,...){ // n adet veriyi es gec ve durumlardna 1 eksilt

    int es_gecilecekler[n];
    va_list es_gec;
    va_start(es_gec,n);
    for (int i = 0; i < n; i++) es_gecilecekler[i] = va_arg(es_gec,int);
    va_end(es_gec);
    int es_gec_bayrak = 0;
    for (int i = 0; i < karakter_durum_sayisi; i++)
    {
        for(int j = 0; j < n ; j++){
            if(es_gecilecekler[j] == i){
                es_gec_bayrak = 1;
                break;
            }
        }
        if(es_gec_bayrak){
            es_gec_bayrak = 0;
            continue;
        }
        karakter_durum_data[i]--;
    }
}
int karakter_yasiyor_mu(int* karakter_durum_data){ // karakter yasiyorsa 1 yasamiyorsa 0 dondur
    if(karakter_durum_data[tokluk] <= 0 || karakter_durum_data[uyku] <= 0 || karakter_durum_data[saglik] <= 0) // 0 tokluk // 1 uyku // 3 saglik
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
void TuvaletYap(int* karakter_durum_data,int n,int tur_sayisi){
    karakter_durum_data[tuvalet] += n;
    if(tur_sayisi > 1) TuvaletYap(karakter_durum_data,n,tur_sayisi-1);
    
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
    karakter_durum_data[sevgi] += n;
    if(tur_sayisi > 1) SuFunction(karakter_durum_data, n, tur_sayisi-1);
}
void BagisiklikFunction(int* karakter_durum_data,int n,int tur_sayisi){
    
}
void harfleri_kucult(char* cumle){
    for(int i=0;cumle[i];i++) if(cumle[i]>=65 && cumle[i]<=90) cumle[i]+=32;
}