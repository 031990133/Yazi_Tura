#include<random>
#include<time.h>
#include <iostream>
using namespace std;
int yaziTura(int atimSayisi,int denemeSayisi) {
    //// atim sayisi sorudaki n'dir. Deneme sayisi ise kaç farklı deneme sonucu eşit sayıda yazı ve tura geldiğini verecek.
    int sayi;
    int yaziSayisi= 0, turaSayisi= 0;
    for (int i = 0; i < atimSayisi; i++) { // Atim sayisi kadar döngüyü döndürdüm.
       sayi= rand() % 101; // Sayiyi 1 ile 100 arasinda deger alacak sekilde ayarladım.
       if (sayi > 70) { // Sayi 70 den büyükse 1 e eşitledim böylece 0.3 lük ihtimali oluşturdum
           sayi = 1;
           yaziSayisi++; // yazinin kac tane geldiğini tutmak için bu değişkeni artırıyorum.
       }
       else { // 70 den kucukse 0 a esitledim boylece 0.7 lik olasılığı olusturdum. 
           sayi = 0;
           turaSayisi++;
       }
    }
    if (yaziSayisi == turaSayisi) { // Yansiz bir bit dizisi olustugunda fonksiyondan bilgileri vererek çıktım.
        cout << atimSayisi << " sayida atim yapildiginda " << denemeSayisi << ".denemede yansiz bit olusmustur.\n";
        return denemeSayisi;
    }
    else // Yanli bir bit olusursa fonksiyonu deneme sayisini 1 artırarak rekürsif bir biçimde çağırıyorum.
        yaziTura(atimSayisi, denemeSayisi + 1);
}
int main()
{
    int a1, a2, a3;
    int b1, b2, b3;
    srand(time(0)); // Sayı üretme fonksiyonunu bilgisayarımdaki zaman ile ilişkilendirerek tamamen rastgelelik sağlıyorum.
    //Fonksiyonu farklı atış değerleri için çağırıyorum. 1. parametre atış sayısı 2. parametre ise deneme sayısı başlangıç için 1'dir.
    a1=yaziTura(6, 1);
    a2=yaziTura(6, 1);
    a3=yaziTura(6, 1);//sdssds
    cout << "Ortalama = " << (a1 + a2 + a3) / 3<<"\n";
    b1=yaziTura(30, 1);
    b2=yaziTura(30, 1);
    b3=yaziTura(30, 1);
    cout << "Ortalama = " << (b1 + b2 + b3) / 3<<"\n";
    system("pause");
}


