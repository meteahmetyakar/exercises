 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
  
struct n{
  	char Ad[10];
  	int fatura;
  	struct n * next;
  	
  };
  typedef struct n node;
  
  
  
node* listeOlustur(node*r, int fatura, char isim[10])	//Girilen de�erlere g�re listeye yeni bir eleman ekleniyor.
  {
  	if(r==NULL)										//E�er r null ise yani liste bo�sa burada ilk de�er olu�turuluyor.
  	{
  		r=(node*)malloc(sizeof(node));				//malloc ile haf�zada r i�in yer a��yoruz.
  		r->next=NULL;								//r'nin nexti Null yap�l�yor
  		r->fatura = fatura;							//r'nin fatura verisi, parametre olarak gelen fatura de�eri yap�l�yor
  		strcpy(r->Ad, isim);					//Burada isim de�eri, r nin Ad k�sm�na konuluyor
  		return r;
	}
  	node*iter = r;									//E�er r Null de�ilse bu sat�ra geliyoruz.
  	while(iter -> next != NULL) iter = iter->next;	//Burada listenin en sonuna gidiyoruz, r den sonraki eleman null olana kadar kontrol ediyoruz ve null u g�rd���m�zde duruyoruz.
  	
	iter -> next = (node*)malloc(sizeof(node));		//haf�zada yer a��l�yor.
	iter = iter-> next;								//iter art�k haf�zada a�t��� yere ge�iyor.
	iter->fatura = fatura;							//a��lan bu yere fatura konuluyor.
	strncpy(iter->Ad, isim, 10);					//isim konuluyor
	iter->next = NULL;								//iter den sonraki yer NULL olarak belirtiliyor ki sonradan geldi�imizde nerede duraca��m�z� bilelim.
	return r;
	
	
  }
  
  node* faturayaGoreEkle(node*r, int fatura2, char isim[10])
  {
	  if(r-> fatura < fatura2){
	  	node*temp = (node*)malloc(sizeof(node));	//Burada | temp_isim = p1->Ad | �eklinde kullanmamam�z�n sebebi p1->Ad bir i�aret�i oldu�undan kaynaklan�yor,
	  	temp -> fatura = fatura2;					//Bir i�aret�iyi, bir diziye atamayaca��m�zdan hata verir, bundan dolay� strncpy fonksiyonunu kullan�yoruz.
	  	strcpy(temp -> Ad, isim);				//strncpy(hedef, kaynak, karakter uzunlu�u) �eklinde kullan�l�r. Bu fonksiyonda n kadar karakteri (10 olarak belirttik) kaynaktan hedefe g�nderir.		
	  	temp -> next = r;							//int atamalarda b�yle bir hata almay�z, bu y�zden | temp -> fatura = gelenFatura | �eklinde bir kullan�m yapabiliyoruz.
	  	return temp;									
	  }													
	  node*iter =r;
	  while(iter->next !=NULL && iter -> next -> fatura > fatura2){
	  	iter = iter -> next;
	  }
	  node* temp = (node*)malloc(sizeof(node));		//temp i�in haf�zada yer a��l�yor.
	  temp->next = iter -> next;					//temp'in nexti olarak iterin �n�ndeki ba�l� oldu�u yer belirtiliyor.
	  iter -> next = temp;							//daha sonra iterin nexti olarak temp belirtiliyor. Bu �ekilde iki eleman�n aras�na ba�ka bir eleman ekleyebiliyoruz.
	  temp -> fatura = fatura2;						//fonksiyonda parametre olarak gelen de�erler iki eleman�n aras�na soktu�umuz tempe koyuluyor.
	  strncpy(temp -> Ad, isim, 10);
	  return r;
  }
  

  
  
  void ismeGoreSirala(node *root)					//S�ralama algoritmas� olarak 'Selection Sort' algoritmas� kulland�k.
{													//Bu algoritmada en k���k veya en b�y�k de�er se�ilerek teker teker dizinin ba��na konulur ve s�ralan�r.
	node *start = root;
	node *traverse;
	node *min;
	
	while(start->next != NULL)
	{
		min = start;								//min de�er root yap�l�yor
		traverse = start->next;						//roottan bir sonraki d���m traverse yap�l�yor
		
		while(traverse != NULL)						//traverse NULL olmad��� s�rece devam ediliyor
		{
			/*min ve traverse'�n Ad verilerinin ilk harflerinin ASCII kodlar� al�n�p de�i�kenlere atan�yor*/
			int ASCII = *(traverse->Ad);	
			int harfRoot = *(min->Ad);
			/* Dizideki en k���k eleman bulunuyor */ 
			if(harfRoot == ASCII)
			{
				ASCII = traverse -> Ad[1];
				harfRoot = min -> Ad[1];
				if(harfRoot > ASCII)
				{
					min = traverse;
				}
			}
			else if( harfRoot > ASCII )
			{
				min = traverse;
			}
			
			traverse = traverse->next;				//traverse bir sonraki d���m yap�l�yor.
		}
		swap(start,min);							// swap fonksiyonuyla dizideki en k���k eleman en ba�a konuluyor, bir sonraki d�ng�de taramaya 0. indeksten de�il 1. indeksten ba�lanacak ve 2. en k���k eleman bulunup 1.indekse yerle�tirilecek.
		start = start->next;						//ve bu �ekilde se�e se�e s�ralama tamamlanacak
	}
} 


/* �stteki i�lemle ayn� i�lemler yap�l�yor fakat burada isim de�il fatura tutar� kar��la�t�r�l�yor. */
  void faturayaGoreSirala(node *head)	
{
	node *start = head;
	node *traverse;
	node *min;
	
	while(start->next != NULL)
	{
		min = start;
		traverse = start->next;
		
		while(traverse != NULL)
		{
			
			if( min->fatura < traverse->fatura )
			{
				min = traverse;
			}
			
			traverse = traverse->next;
		}
		swap(start,min);			
		start = start->next;
	}
} 

void swap(node *p1, node*p2)
{
	/*Burada bir temp olu�turuluyor, fonksiyona gelen start noktas�n�n verileri ve min'in verileri yer de�i�tirecek. �nce start noktas� tempe at�lacak, sonra min noktas� start noktas�na konulacak, en son tempdeki veriler min'in al�nd��� yere konulacak*/
	int temp_fatura = p1->fatura;	
	p1->fatura = p2->fatura;
	p2->fatura = temp_fatura;
	
	char temp_isim[10];
	strncpy(temp_isim, p1->Ad, 10);	
	strncpy(p1->Ad, p2->Ad, 10);	
	strncpy(p2->Ad, temp_isim, 10);	
										
}
 

  void faturayaGoreYazdir(node*r, int fatura){
  	
  		while(r != NULL){							//r Null olmad��� s�rece d�ng� devam eder.
  			if(r->fatura >= fatura)					//r nin fatura de�eri, fonksiyona parametre olarak verilen fatura de�erinden (de�erlerin isimleri ayn� sadece, ayn� �ey de�iller) b�y�kse, true d�ner.
  			{							
  			printf("%s\t------\t%d\n", r->Ad,r->fatura);;	// r'nin Ad ve fatura de�erleri ekrana yazd�r�l�r.
			}
  			r = r->next;							//r, ba�l� oldu�u bir sonraki d���me ge�er. 
		}											//Bu �ekilde root dan ba�lay�p Null a kadar t�m linked list yazd�r�l�r.
	}
  
  void ismeGoreYazdir(node*r, char *harf)
  {
  		int ASCII = *harf;							//Burada fonksiyona parametre olarak gelen harf de�eri ASCII isimli int de�i�kenine atan�yor.
  													//karakteri int bir de�i�kene atad���m�z i�in o karakterin ASCII de�eri de�i�kene atan�r. �rne�in 'A' harfinin ASCII de�eri 65 dir.
  													//yani her harfin bir say�sal de�eri vard�r, biz de bu de�ere g�re s�ralama yapaca��z.
  		while(r != NULL)							//r null olmad��� s�rece devam.							
  		{
			if(ASCII == *(r->Ad))					//burada *(r->Ad) yaparak Ad de�erinin ilk harfini alm�� oluyoruz. ve ASCII de�eriyle kar��la�t�r�l�yor, E�er e�itlerse	  
		  	{
  				printf("%s\t------\t%d\n", r->Ad,r->fatura);//Ekrana bu de�erler yazd�r�l�yor.
  			}
  			r = r->next;							//r bir sonraki d���me ge�iyor
		}
  }
  
  node* ismeGoreEkle(node*r, int fatura, char isim[10])
  {
  	//Yukar�da yapt���m�z gibi harfler kar��la�t�r�lmak i�in ASCII de�erlere d�n��t�r�l�yor.
  	char harf = isim[0];
  	int ASCII = harf;
  	int ASCII2 = *(r->Ad);
  	
  	
  	if(ASCII < ASCII2){								//E�er parametre olarak gelen ismin ba� harfinin asc�� de�eri, iterin bulundu�u d���mdeki ismin Asc�� de�erinden k���kse bu blo�a giriyor.
	  	node*temp = (node*)malloc(sizeof(node));	//Haf�zada yer a��l�yor
	  	temp -> fatura = fatura;					//De�erler a��lan yere konuluyor.
	  	strncpy(temp -> Ad, isim, 10);
	  	temp -> next = r;							//olu�turulan yeni yer r nin arkas�na yerle�ti�i i�in root olarak tempi d�nd�r�yoruz.
	  	return temp;
	  }
	  node*iter =r;									//�stteki bloktan false d�nerse buraya geliniyor ve r nin oldu�u noktada bir iter olu�turuyoruz
	  ASCII2 = iter->Ad[0];							//iterin Ad verisinin ASCII de�eri al�n�yor
	  while(iter->next !=NULL && ASCII2 < ASCII){	//e�er iterin nexti null de�ilse ve iterin Ad verisinin ASCII de�eri parametre olarak gelen ismin ASCII de�erinden k���kse buraya giriliyor.
	  	iter = iter -> next;						//sonraki d���me ge�iliyor.
	  	ASCII2 = iter->Ad[0];						//iterin Ad verisinin ASCII de�eri al�n�yor
	  	if(ASCII < iter -> next -> Ad[0])			//E�er parametre olarak gelen ismin ASCII de�eri iterin nextinin Ad verisinin ASCII de�erinden b�y�kse bu blo�a giriliyor.
	  	{
	  	node* temp = (node*)malloc(sizeof(node));   //Bir temp olu�turulup araya yerle�tirme i�lemi yap�l�yor.
	  	temp->next = iter -> next;
	 	iter -> next = temp;
	 	temp -> fatura = fatura;
	 	strncpy(temp -> Ad, isim, 10);
	  	return r;
		}
	  }
	  if(ASCII2 = ASCII)							//E�er parametre olarak gelen ismin ASCII de�eriyle iterin Ad verisinin ASCII de�eri e�itse, yani ayn� harf ile ba�l�yorlarsa
	  {												//Yine araya yerle�tirme i�lemi yap�yoruz.
	  	node* temp = (node*)malloc(sizeof(node));
	  	temp->next = iter -> next;
	 	iter -> next = temp;
	 	temp -> fatura = fatura;
	 	strncpy(temp -> Ad, isim, 10);
	  	return r;
	  }
	  
  }
  
  void olduguGibiBastir(node*r)
  {
  	while(r!=NULL)
  	{
  		printf("%s\t------\t%d\n", r->Ad,r->fatura);
  		r = r->next;
	}
  }
  
  int main(){  	
  
  	node * root;
  	root = NULL;
  			
  	root = listeOlustur(root, 100, "Ahmet");
	root = listeOlustur(root, 1000, "Bilal");	
	root = listeOlustur(root, 600, "Cemal");
	root = listeOlustur(root, 650, "Adem");
	root = listeOlustur(root, 350, "Yasin");
	root = listeOlustur(root, 270, "Esin");	
	root = listeOlustur(root, 410, "Emel");
	root = listeOlustur(root, 750, "Mustfa");
	root = listeOlustur(root, 600, "Ayten");
	root = listeOlustur(root, 1000, "Ceylan");
	root = listeOlustur(root, 900, "Nesrin");
  	root = listeOlustur(root, 850, "Bekir");
	root = listeOlustur(root, 790, "Emin");			
  	root = listeOlustur(root, 610, "Hakan");
  	root = listeOlustur(root, 550, "Hatce");
  	
  	
	
  	/*
	
	ismeGoreYazdir(root, "M");*/
  	
  	
  	
  	printf("\n<<SIRASIZ iNDEKS TABLOSU>>\n\n");
  	
  	olduguGibiBastir(root);
  	
  	printf("\n<<iSME GORE SIRALI iNDEKS TABLOSU>>\n");
  	printf("--isim = Cengiz, fatura = 100, eklendi--\n");
  	
  	root = ismeGoreEkle(root, 100, "Cengiz");
  	ismeGoreSirala(root);
  	olduguGibiBastir(root);
  	
  	printf("\n<<FATURAYA GORE SIRALI iNDEKS TABLOSU>>\n");
  	printf("--isim = d20pt, fatura = 605, eklendi--\n");
  	root = faturayaGoreEkle(root, 605, "d20pt");
  	faturayaGoreSirala(root);
  	olduguGibiBastir(root);
  	
  	printf("\n<<FATURADAN DAHA PAHALI OLAN FATURALARA GORE YAZDIRMA>>\n");
  	printf("--Secilen fatura degeri 450--\n");
	faturayaGoreYazdir(root, 450);
  	
  	printf("\n<<AYNI HARF iLE BASLAYAN iSiMLERE GORE YAZDIRMA>>\n");
  	printf("--Secilen harf 'A'--\n");
  	ismeGoreSirala(root);
  	ismeGoreYazdir(root, "A");
  	
  	
  	
  	
  	
  	
  	
  	
  	
  	
  	
  	
  	
  	
  	
  	
  	
  	
  	
  	
  	
  	getchar();
  }
