 #include <stdio.h>
 #include <stdlib.h>
 #include <conio.h>
 #include <string.h>
  
struct n{
  	char Ad[10];
  	int fatura;
  	struct n * next;
  	
  };
  typedef struct n node;
  
  
  
    node* listeOlustur(node*r, int fatura, char isim[10])	//Girilen deðerlere göre listeye yeni bir eleman ekleniyor.
  {
  	if(r==NULL)										//Eðer r null ise yani liste boþsa burada ilk deðer oluþturuluyor.
  	{
  		r=(node*)malloc(sizeof(node));				//malloc ile hafýzada r için yer açýyoruz.
  		r->next=NULL;								//r'nin nexti Null yapýlýyor
  		r->fatura = fatura;							//r'nin fatura verisi, parametre olarak gelen fatura deðeri yapýlýyor
  		strncpy(r->Ad, isim, 10);					//Burada isim deðeri, r nin Ad kýsmýna konuluyor
  		return r;
	}
  	node*iter = r;									//Eðer r Null deðilse bu satýra geliyoruz.
  	while(iter -> next != NULL) iter = iter->next;	//Burada listenin en sonuna gidiyoruz, r den sonraki eleman null olana kadar kontrol ediyoruz ve null u gördüðümüzde duruyoruz.
  	
	iter -> next = (node*)malloc(sizeof(node));		//hafýzada yer açýlýyor.
	iter = iter-> next;								//iter artýk hafýzada açtýðý yere geçiyor.
	iter->fatura = fatura;							//açýlan bu yere fatura konuluyor.
	strncpy(iter->Ad, isim, 10);					//isim konuluyor
	iter->next = NULL;								//iter den sonraki yer NULL olarak belirtiliyor ki sonradan geldiðimizde nerede duracaðýmýzý bilelim.
	return r;
	
	
  }
  
  node* faturayaGoreEkle(node*r, int fatura2, char isim[10])
  {
	  if(r-> fatura < fatura2){
	  	node*temp = (node*)malloc(sizeof(node));	//Burada | temp_isim = p1->Ad | þeklinde kullanmamamýzýn sebebi p1->Ad bir iþaretçi olduðundan kaynaklanýyor,
	  	temp -> fatura = fatura2;					//Bir iþaretçiyi, bir diziye atamayacaðýmýzdan hata verir, bundan dolayý strncpy fonksiyonunu kullanýyoruz.
	  	strncpy(temp -> Ad, isim, 10);				//strncpy(hedef, kaynak, karakter uzunluðu) þeklinde kullanýlýr. Bu fonksiyonda n kadar karakteri (10 olarak belirttik) kaynaktan hedefe gönderir.		
	  	temp -> next = r;							//int atamalarda böyle bir hata almayýz, bu yüzden | temp -> fatura = gelenFatura | þeklinde bir kullaným yapabiliyoruz.
	  	return temp;									
	  }													
	  node*iter =r;
	  while(iter->next !=NULL && iter -> next -> fatura > fatura2){
	  	iter = iter -> next;
	  }
	  node* temp = (node*)malloc(sizeof(node));		//temp için hafýzada yer açýlýyor.
	  temp->next = iter -> next;					//temp'in nexti olarak iterin önündeki baðlý olduðu yer belirtiliyor.
	  iter -> next = temp;							//daha sonra iterin nexti olarak temp belirtiliyor. Bu þekilde iki elemanýn arasýna baþka bir eleman ekleyebiliyoruz.
	  temp -> fatura = fatura2;						//fonksiyonda parametre olarak gelen deðerler iki elemanýn arasýna soktuðumuz tempe koyuluyor.
	  strncpy(temp -> Ad, isim, 10);
	  return r;
  }
  

  
  
  void ismeGoreSirala(node *root)					//Sýralama algoritmasý olarak 'Selection Sort' algoritmasý kullandýk.
{													//Bu algoritmada en küçük veya en büyük deðer seçilerek teker teker dizinin baþýna konulur ve sýralanýr.
	node *start = root;
	node *traverse;
	node *min;
	
	while(start->next != NULL)
	{
		min = start;								//min deðer root yapýlýyor
		traverse = start->next;						//roottan bir sonraki düðüm traverse yapýlýyor
		
		while(traverse != NULL)						//traverse NULL olmadýðý sürece devam ediliyor
		{
			/*min ve traverse'ýn Ad verilerinin ilk harflerinin ASCII kodlarý alýnýp deðiþkenlere atanýyor*/
			int ASCII = *(traverse->Ad);	
			int harfRoot = *(min->Ad);
			/* Dizideki en küçük eleman bulunuyor */ 
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
			
			traverse = traverse->next;				//traverse bir sonraki düðüm yapýlýyor.
		}
		swap(start,min);							// swap fonksiyonuyla dizideki en küçük eleman en baþa konuluyor, bir sonraki döngüde taramaya 0. indeksten deðil 1. indeksten baþlanacak ve 2. en küçük eleman bulunup 1.indekse yerleþtirilecek.
		start = start->next;						//ve bu þekilde seçe seçe sýralama tamamlanacak
	}
} 


/* üstteki iþlemle ayný iþlemler yapýlýyor fakat burada isim deðil fatura tutarý karþýlaþtýrýlýyor. */
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
	/*Burada bir temp oluþturuluyor, fonksiyona gelen start noktasýnýn verileri ve min'in verileri yer deðiþtirecek. önce start noktasý tempe atýlacak, sonra min noktasý start noktasýna konulacak, en son tempdeki veriler min'in alýndýðý yere konulacak*/
	int temp_fatura = p1->fatura;	
	p1->fatura = p2->fatura;
	p2->fatura = temp_fatura;
	
	char temp_isim[10];
	strncpy(temp_isim, p1->Ad, 10);	
	strncpy(p1->Ad, p2->Ad, 10);	
	strncpy(p2->Ad, temp_isim, 10);	
										
}
 

  void faturayaGoreYazdir(node*r, int fatura){
  	
  		while(r != NULL){							//r Null olmadýðý sürece döngü devam eder.
  			if(r->fatura >= fatura)					//r nin fatura deðeri, fonksiyona parametre olarak verilen fatura deðerinden (deðerlerin isimleri ayný sadece, ayný þey deðiller) büyükse, true döner.
  			{							
  			printf("%s\t------\t%d\n", r->Ad,r->fatura);;	// r'nin Ad ve fatura deðerleri ekrana yazdýrýlýr.
			}
  			r = r->next;							//r, baðlý olduðu bir sonraki düðüme geçer. 
		}											//Bu þekilde root dan baþlayýp Null a kadar tüm linked list yazdýrýlýr.
	}
  
  void ismeGoreYazdir(node*r, char *harf)
  {
  		int ASCII = *harf;							//Burada fonksiyona parametre olarak gelen harf deðeri ASCII isimli int deðiþkenine atanýyor.
  													//karakteri int bir deðiþkene atadýðýmýz için o karakterin ASCII deðeri deðiþkene atanýr. Örneðin 'A' harfinin ASCII deðeri 65 dir.
  													//yani her harfin bir sayýsal deðeri vardýr, biz de bu deðere göre sýralama yapacaðýz.
  		while(r != NULL)							//r null olmadýðý sürece devam.							
  		{
			if(ASCII == *(r->Ad))					//burada *(r->Ad) yaparak Ad deðerinin ilk harfini almýþ oluyoruz. ve ASCII deðeriyle karþýlaþtýrýlýyor, Eðer eþitlerse	  
		  	{
  				printf("%s\t------\t%d\n", r->Ad,r->fatura);//Ekrana bu deðerler yazdýrýlýyor.
  			}
  			r = r->next;							//r bir sonraki düðüme geçiyor
		}
  }
  
  node* ismeGoreEkle(node*r, int fatura, char isim[10])
  {
  	//Yukarýda yaptýðýmýz gibi harfler karþýlaþtýrýlmak için ASCII deðerlere dönüþtürülüyor.
  	char harf = isim[0];
  	int ASCII = harf;
  	int ASCII2 = *(r->Ad);
  	
  	
  	if(ASCII < ASCII2){								//Eðer parametre olarak gelen ismin baþ harfinin ascýý deðeri, iterin bulunduðu düðümdeki ismin Ascýý deðerinden küçükse bu bloða giriyor.
	  	node*temp = (node*)malloc(sizeof(node));	//Hafýzada yer açýlýyor
	  	temp -> fatura = fatura;					//Deðerler açýlan yere konuluyor.
	  	strncpy(temp -> Ad, isim, 10);
	  	temp -> next = r;							//oluþturulan yeni yer r nin arkasýna yerleþtiði için root olarak tempi döndürüyoruz.
	  	return temp;
	  }
	  node*iter =r;									//üstteki bloktan false dönerse buraya geliniyor ve r nin olduðu noktada bir iter oluþturuyoruz
	  ASCII2 = iter->Ad[0];							//iterin Ad verisinin ASCII deðeri alýnýyor
	  while(iter->next !=NULL && ASCII2 < ASCII){	//eðer iterin nexti null deðilse ve iterin Ad verisinin ASCII deðeri parametre olarak gelen ismin ASCII deðerinden küçükse buraya giriliyor.
	  	iter = iter -> next;						//sonraki düðüme geçiliyor.
	  	ASCII2 = iter->Ad[0];						//iterin Ad verisinin ASCII deðeri alýnýyor
	  	if(ASCII < iter -> next -> Ad[0])			//Eðer parametre olarak gelen ismin ASCII deðeri iterin nextinin Ad verisinin ASCII deðerinden büyükse bu bloða giriliyor.
	  	{
	  	node* temp = (node*)malloc(sizeof(node));   //Bir temp oluþturulup araya yerleþtirme iþlemi yapýlýyor.
	  	temp->next = iter -> next;
	 	iter -> next = temp;
	 	temp -> fatura = fatura;
	 	strncpy(temp -> Ad, isim, 10);
	  	return r;
		}
	  }
	  if(ASCII2 = ASCII)							//Eðer parametre olarak gelen ismin ASCII deðeriyle iterin Ad verisinin ASCII deðeri eþitse, yani ayný harf ile baþlýyorlarsa
	  {												//Yine araya yerleþtirme iþlemi yapýyoruz.
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
