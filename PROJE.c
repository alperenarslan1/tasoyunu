#include <stdio.h>
#include <stdlib.h>
#include <time.h>
	
int oyuncu1[2][20]={{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
int oyuncu2[2][20]={{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
	
void durum(); // durum fonksiyonu dizilerin durumunu yans�t�r.
int rastgele(int); // rastgele fonksiyonu ihtiya� halinde �a�r�larak rastgele de�er elde edilir.
int sira(int,int,int); // sira fonksiyonu girilen arg�manlara g�re sonraki oyuncuyu , sonraki rengi ve sonraki ta�� belirler.
void oyun(); // oyun fonksiyonu sira fonksiyonundan ��kan sonuca g�re bir diziden ��karma di�erine ekleme yapar.

int sonraki_oyuncu,sonraki_renk,sonraki_tas,oyun_bitti,hamle_sayisi=0;

int main()
{
	srand(time(NULL));
	durum();
	
	sonraki_oyuncu=rastgele(2);
	sonraki_renk=rastgele(2);
	sonraki_tas=1+rastgele(10);

	printf("Kura Cekiliyor.\n");
	printf("\n%d.oyuncu ",sonraki_oyuncu+1);
		if(sonraki_renk==0)
 			printf("mavi renk ile ");
		else 
			printf("kirmizi renk ile ");
	printf("%d.tasiyla oyuna baslayacaktir.\n\n\n",sonraki_tas);

	oyun();
	
	return 0;
}

void durum()
{
	int i,j;
	
	printf("--------------ILK OYUNCUNUN TASLARI--------------\n");
	for(i=0;i<2;i++)
	{		
		if(i==0)
			printf("MAVI\t");
		else
			printf("KIRMIZI\t");
     	for(j=0;j<20;j++)
			printf("%d ",oyuncu1[i][j]);
  	 printf("\n");	
	}
	printf("\n--------------IKINCI OYUNCUNUN TASLARI--------------\n");
	for(i=0;i<2;i++)
	{
		if(i==0)
			printf("MAVI\t");
		else
			printf("KIRMIZI\t");
		for(j=0;j<20;j++)
			printf("%d ",oyuncu2[i][j]);		
	
	printf("\n");	
	}
	printf("\n\n\n");
}

int rastgele(int x)
{
	return rand()%x;	
}

int sira(int oyuncu_kontrolu,int renk_kontrolu,int tas_kontrolu)
{
	
	int kat2,eksik4;
	
	if(oyuncu_kontrolu == 0)
		sonraki_oyuncu = 1;
	else
		sonraki_oyuncu = 0;	

	if(tas_kontrolu*2>0 && tas_kontrolu*2<=20 && tas_kontrolu-4>0) // ta�lar�n 1-20 aral���na sahip olmas�n� sa�lar.
	{
		kat2 = tas_kontrolu*2;
		eksik4 = tas_kontrolu-4;
		
			if(sonraki_oyuncu==0) // dizi i�eri�inin 0'dan b�y�k olup olmad��� sorgulan�r.Ve hem 2 kat� hem de 4 eksi�i 0 dan b�y�kse rastgele se�im yap�lmas� sa�lan�r.
			{
				if(oyuncu1[renk_kontrolu][kat2-1]>0 && oyuncu1[!renk_kontrolu][eksik4-1]>0) 
				{
					sonraki_renk=rastgele(2);
	
 					if(sonraki_renk==renk_kontrolu)
						sonraki_tas=kat2;
					else 
						sonraki_tas=eksik4;	
				}

				else if(oyuncu1[renk_kontrolu][kat2-1]>0)
				{
					sonraki_renk=renk_kontrolu;
					sonraki_tas=kat2;
				}
				else if(oyuncu1[!renk_kontrolu][eksik4-1]>0)
				{
					sonraki_renk=!renk_kontrolu;
					sonraki_tas=eksik4;	
				}
				else
					oyun_bitti=1;
			}
	
			else // sonraki oyuncunun farkl� olmas� halinde ayn� kontrolleri yapar.
			{
				if(oyuncu2[renk_kontrolu][kat2-1]>0 && oyuncu2[!renk_kontrolu][eksik4-1]>0)
				{
					sonraki_renk=rastgele(2);
	
					if(sonraki_renk==renk_kontrolu)
						sonraki_tas=kat2;
					else 
						sonraki_tas=eksik4;	
				}
				else if(oyuncu2[renk_kontrolu][kat2-1]>0)
				{
					sonraki_renk=renk_kontrolu;
					sonraki_tas=kat2;
				}
				else if(oyuncu2[!renk_kontrolu][eksik4-1]>0)
				{
					sonraki_renk=!renk_kontrolu;
					sonraki_tas=eksik4;	
				}
				else
					oyun_bitti=1;
			}

	}

	else if(tas_kontrolu*2>0 && tas_kontrolu*2<20) // a��k�as� bu ayr�m gereksiz gibi g�z�kse de atad���m de�i�kenleri dizi kontrollerinde kullanmamdan �t�r� bug ihtimalini ortadan kald�r�yor.
	{
		kat2 = tas_kontrolu*2;
	
			if(sonraki_oyuncu==0)
			{			
				if(oyuncu1[renk_kontrolu][kat2-1]>0)
				{
					sonraki_renk=renk_kontrolu;
					sonraki_tas=kat2;
				}
				else
					oyun_bitti=1;
			}

			else
			{
				if(oyuncu2[renk_kontrolu][kat2-1]>0)
				{
					sonraki_renk=renk_kontrolu;
					sonraki_tas=kat2;
				}
				else
					oyun_bitti=1;
				}
	}

	else if(tas_kontrolu-4>0) // a��k�as� bu ayr�m gereksiz gibi g�z�kse de atad���m de�i�kenleri dizi kontrollerinde kullanmamdan �t�r� bug ihtimalini ortadan kald�r�r.
	{
	
		eksik4 = tas_kontrolu-4;

			if(sonraki_oyuncu==0)
			{			
				if(oyuncu1[!renk_kontrolu][eksik4-1]>0)
				{
					sonraki_renk=!renk_kontrolu;
					sonraki_tas=eksik4;
				}
				else
					oyun_bitti=1;
			}
			else
			{
				if(oyuncu2[!renk_kontrolu][eksik4-1]>0)
				{
					sonraki_renk=!renk_kontrolu;
					sonraki_tas=eksik4;
				}
				else
				oyun_bitti=1;
			}	
	}

	if(oyun_bitti!=1) // oyuna devam eden oyuncuyu,rengi ve ta�� bildirir.
	{
		printf("%d.oyuncu ",sonraki_oyuncu+1);

			if(sonraki_renk==0)
				printf("mavi renk ile ");
			else
				printf("kirmizi renk ile ");
			
		printf("%d.tasiyla oyuna devam ediyor.\n\n\n",sonraki_tas);
	}

	else
	{
		printf("%d.oyuncu uygun tas bulamadi.\n\n",sonraki_oyuncu+1);
		printf("\n\t\t    SON DURUM\n\n");
		durum();
	}

}

void oyun()
{
	while(oyun_bitti!=1)	
	{	
		if(sonraki_oyuncu==0)
		{
			oyuncu1[sonraki_renk][sonraki_tas-1]-= 1;
			oyuncu2[sonraki_renk][sonraki_tas-1]+= 1;	
		}	
		else
		{
			oyuncu2[sonraki_renk][sonraki_tas-1]-= 1;
			oyuncu1[sonraki_renk][sonraki_tas-1]+= 1;	
		}
		
	durum();	 		
	
	sira(sonraki_oyuncu,sonraki_renk,sonraki_tas);
	
	hamle_sayisi++;
	}
 	
	printf("Oyun %d hamlede sonlandi.%d.oyuncu uygun tas bulamadigi icin %d.oyuncu oyunu kazandi.\n",hamle_sayisi,sonraki_oyuncu+1,!sonraki_oyuncu+1);

}

