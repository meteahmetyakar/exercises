 #include <stdio.h>
 #include <stdlib.h>
<<<<<<< HEAD
=======
 #include <conio.h>
>>>>>>> 091ee0628d8bc91fcc4e7825e4fc267dc9ffa505
 #include <string.h>
  
struct n{
  	char Ad[10];
  	int fatura;
  	struct n * next;
  	
  };
  typedef struct n node;
  
  
  
<<<<<<< HEAD
node* listeOlustur(node*r, int fatura, char isim[10])	//Girilen deï¿½erlere gï¿½re listeye yeni bir eleman ekleniyor.
  {
  	if(r==NULL)										//Eï¿½er r null ise yani liste boï¿½sa burada ilk deï¿½er oluï¿½turuluyor.
  	{
  		r=(node*)malloc(sizeof(node));				//malloc ile hafï¿½zada r iï¿½in yer aï¿½ï¿½yoruz.
  		r->next=NULL;								//r'nin nexti Null yapï¿½lï¿½yor
  		r->fatura = fatura;							//r'nin fatura verisi, parametre olarak gelen fatura deï¿½eri yapï¿½lï¿½yor
  		strcpy(r->Ad, isim);					//Burada isim deï¿½eri, r nin Ad kï¿½smï¿½na konuluyor
  		return r;
	}
  	node*iter = r;									//Eï¿½er r Null deï¿½ilse bu satï¿½ra geliyoruz.
  	while(iter -> next != NULL) iter = iter->next;	//Burada listenin en sonuna gidiyoruz, r den sonraki eleman null olana kadar kontrol ediyoruz ve null u gï¿½rdï¿½ï¿½ï¿½mï¿½zde duruyoruz.
  	
	iter -> next = (node*)malloc(sizeof(node));		//hafï¿½zada yer aï¿½ï¿½lï¿½yor.
	iter = iter-> next;								//iter artï¿½k hafï¿½zada aï¿½tï¿½ï¿½ï¿½ yere geï¿½iyor.
	iter->fatura = fatura;							//aï¿½ï¿½lan bu yere fatura konuluyor.
	strncpy(iter->Ad, isim, 10);					//isim konuluyor
	iter->next = NULL;								//iter den sonraki yer NULL olarak belirtiliyor ki sonradan geldiï¿½imizde nerede duracaï¿½ï¿½mï¿½zï¿½ bilelim.
=======
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
>>>>>>> 091ee0628d8bc91fcc4e7825e4fc267dc9ffa505
	return r;
	
	
  }
  
  node* faturayaGoreEkle(node*r, int fatura2, char isim[10])
  {
	  if(r-> fatura < fatura2){
<<<<<<< HEAD
	  	node*temp = (node*)malloc(sizeof(node));	//Burada | temp_isim = p1->Ad | ï¿½eklinde kullanmamamï¿½zï¿½n sebebi p1->Ad bir iï¿½aretï¿½i olduï¿½undan kaynaklanï¿½yor,
	  	temp -> fatura = fatura2;					//Bir iï¿½aretï¿½iyi, bir diziye atamayacaï¿½ï¿½mï¿½zdan hata verir, bundan dolayï¿½ strncpy fonksiyonunu kullanï¿½yoruz.
	  	strcpy(temp -> Ad, isim);				//strncpy(hedef, kaynak, karakter uzunluï¿½u) ï¿½eklinde kullanï¿½lï¿½r. Bu fonksiyonda n kadar karakteri (10 olarak belirttik) kaynaktan hedefe gï¿½nderir.		
	  	temp -> next = r;							//int atamalarda bï¿½yle bir hata almayï¿½z, bu yï¿½zden | temp -> fatura = gelenFatura | ï¿½eklinde bir kullanï¿½m yapabiliyoruz.
=======
	  	node*temp = (node*)malloc(sizeof(node));	//Burada | temp_isim = p1->Ad | þeklinde kullanmamamýzýn sebebi p1->Ad bir iþaretçi olduðundan kaynaklanýyor,
	  	temp -> fatura = fatura2;					//Bir iþaretçiyi, bir diziye atamayacaðýmýzdan hata verir, bundan dolayý strncpy fonksiyonunu kullanýyoruz.
	  	strncpy(temp -> Ad, isim, 10);				//strncpy(hedef, kaynak, karakter uzunluðu) þeklinde kullanýlýr. Bu fonksiyonda n kadar karakteri (10 olarak belirttik) kaynaktan hedefe gönderir.		
	  	temp -> next = r;							//int atamalarda böyle bir hata almayýz, bu yüzden | temp -> fatura = gelenFatura | þeklinde bir kullaným yapabiliyoruz.
>>>>>>> 091ee0628d8bc91fcc4e7825e4fc267dc9ffa505
	  	return temp;									
	  }													
	  node*iter =r;
	  while(iter->next !=NULL && iter -> next -> fatura > fatura2){
	  	iter = iter -> next;
	  }
<<<<<<< HEAD
	  node* temp = (node*)malloc(sizeof(node));		//temp iï¿½in hafï¿½zada yer aï¿½ï¿½lï¿½yor.
	  temp->next = iter -> next;					//temp'in nexti olarak iterin ï¿½nï¿½ndeki baï¿½lï¿½ olduï¿½u yer belirtiliyor.
	  iter -> next = temp;							//daha sonra iterin nexti olarak temp belirtiliyor. Bu ï¿½ekilde iki elemanï¿½n arasï¿½na baï¿½ka bir eleman ekleyebiliyoruz.
	  temp -> fatura = fatura2;						//fonksiyonda parametre olarak gelen deï¿½erler iki elemanï¿½n arasï¿½na soktuï¿½umuz tempe koyuluyor.
=======
	  node* temp = (node*)malloc(sizeof(node));		//temp için hafýzada yer açýlýyor.
	  temp->next = iter -> next;					//temp'in nexti olarak iterin önündeki baðlý olduðu yer belirtiliyor.
	  iter -> next = temp;							//daha sonra iterin nexti olarak temp belirtiliyor. Bu þekilde iki elemanýn arasýna baþka bir eleman ekleyebiliyoruz.
	  temp -> fatura = fatura2;						//fonksiyonda parametre olarak gelen deðerler iki elemanýn arasýna soktuðumuz tempe koyuluyor.
>>>>>>> 091ee0628d8bc91fcc4e7825e4fc267dc9ffa505
	  strncpy(temp -> Ad, isim, 10);
	  return r;
  }
  

  
  
<<<<<<< HEAD
  void ismeGoreSirala(node *root)					//Sï¿½ralama algoritmasï¿½ olarak 'Selection Sort' algoritmasï¿½ kullandï¿½k.
{													//Bu algoritmada en kï¿½ï¿½ï¿½k veya en bï¿½yï¿½k deï¿½er seï¿½ilerek teker teker dizinin baï¿½ï¿½na konulur ve sï¿½ralanï¿½r.
=======
  void ismeGoreSirala(node *root)					//Sýralama algoritmasý olarak 'Selection Sort' algoritmasý kullandýk.
{													//Bu algoritmada en küçük veya en büyük deðer seçilerek teker teker dizinin baþýna konulur ve sýralanýr.
>>>>>>> 091ee0628d8bc91fcc4e7825e4fc267dc9ffa505
	node *start = root;
	node *traverse;
	node *min;
	
	while(start->next != NULL)
	{
<<<<<<< HEAD
		min = start;								//min deï¿½er root yapï¿½lï¿½yor
		traverse = start->next;						//roottan bir sonraki dï¿½ï¿½ï¿½m traverse yapï¿½lï¿½yor
		
		while(traverse != NULL)						//traverse NULL olmadï¿½ï¿½ï¿½ sï¿½rece devam ediliyor
		{
			/*min ve traverse'ï¿½n Ad verilerinin ilk harflerinin ASCII kodlarï¿½ alï¿½nï¿½p deï¿½iï¿½kenlere atanï¿½yor*/
			int ASCII = *(traverse->Ad);	
			int harfRoot = *(min->Ad);
			/* Dizideki en kï¿½ï¿½ï¿½k eleman bulunuyor */ 
=======
		min = start;								//min deðer root yapýlýyor
		traverse = start->next;						//roottan bir sonraki düðüm traverse yapýlýyor
		
		while(traverse != NULL)						//traverse NULL olmadýðý sürece devam ediliyor
		{
			/*min ve traverse'ýn Ad verilerinin ilk harflerinin ASCII kodlarý alýnýp deðiþkenlere atanýyor*/
			int ASCII = *(traverse->Ad);	
			int harfRoot = *(min->Ad);
			/* Dizideki en küçük eleman bulunuyor */ 
>>>>>>> 091ee0628d8bc91fcc4e7825e4fc267dc9ffa505
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
			
<<<<<<< HEAD
			traverse = traverse->next;				//traverse bir sonraki dï¿½ï¿½ï¿½m yapï¿½lï¿½yor.
		}
		swap(start,min);							// swap fonksiyonuyla dizideki en kï¿½ï¿½ï¿½k eleman en baï¿½a konuluyor, bir sonraki dï¿½ngï¿½de taramaya 0. indeksten deï¿½il 1. indeksten baï¿½lanacak ve 2. en kï¿½ï¿½ï¿½k eleman bulunup 1.indekse yerleï¿½tirilecek.
		start = start->next;						//ve bu ï¿½ekilde seï¿½e seï¿½e sï¿½ralama tamamlanacak
=======
			traverse = traverse->next;				//traverse bir sonraki düðüm yapýlýyor.
		}
		swap(start,min);							// swap fonksiyonuyla dizideki en küçük eleman en baþa konuluyor, bir sonraki döngüde taramaya 0. indeksten deðil 1. indeksten baþlanacak ve 2. en küçük eleman bulunup 1.indekse yerleþtirilecek.
		start = start->next;						//ve bu þekilde seçe seçe sýralama tamamlanacak
>>>>>>> 091ee0628d8bc91fcc4e7825e4fc267dc9ffa505
	}
} 


<<<<<<< HEAD
/* ï¿½stteki iï¿½lemle aynï¿½ iï¿½lemler yapï¿½lï¿½yor fakat burada isim deï¿½il fatura tutarï¿½ karï¿½ï¿½laï¿½tï¿½rï¿½lï¿½yor. */
=======
/* üstteki iþlemle ayný iþlemler yapýlýyor fakat burada isim deðil fatura tutarý karþýlaþtýrýlýyor. */
>>>>>>> 091ee0628d8bc91fcc4e7825e4fc267dc9ffa505
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
<<<<<<< HEAD
	/*Burada bir temp oluï¿½turuluyor, fonksiyona gelen start noktasï¿½nï¿½n verileri ve min'in verileri yer deï¿½iï¿½tirecek. ï¿½nce start noktasï¿½ tempe atï¿½lacak, sonra min noktasï¿½ start noktasï¿½na konulacak, en son tempdeki veriler min'in alï¿½ndï¿½ï¿½ï¿½ yere konulacak*/
=======
	/*Burada bir temp oluþturuluyor, fonksiyona gelen start noktasýnýn verileri ve min'in verileri yer deðiþtirecek. önce start noktasý tempe atýlacak, sonra min noktasý start noktasýna konulacak, en son tempdeki veriler min'in alýndýðý yere konulacak*/
>>>>>>> 091ee0628d8bc91fcc4e7825e4fc267dc9ffa505
	int temp_fatura = p1->fatura;	
	p1->fatura = p2->fatura;
	p2->fatura = temp_fatura;
	
	char temp_isim[10];
	strncpy(temp_isim, p1->Ad, 10);	
	strncpy(p1->Ad, p2->Ad, 10);	
	strncpy(p2->Ad, temp_isim, 10);	
										
}
 

  void faturayaGoreYazdir(node*r, int fatura){
  	
<<<<<<< HEAD
  		while(r != NULL){							//r Null olmadï¿½ï¿½ï¿½ sï¿½rece dï¿½ngï¿½ devam eder.
  			if(r->fatura >= fatura)					//r nin fatura deï¿½eri, fonksiyona parametre olarak verilen fatura deï¿½erinden (deï¿½erlerin isimleri aynï¿½ sadece, aynï¿½ ï¿½ey deï¿½iller) bï¿½yï¿½kse, true dï¿½ner.
  			{							
  			printf("%s\t------\t%d\n", r->Ad,r->fatura);;	// r'nin Ad ve fatura deï¿½erleri ekrana yazdï¿½rï¿½lï¿½r.
			}
  			r = r->next;							//r, baï¿½lï¿½ olduï¿½u bir sonraki dï¿½ï¿½ï¿½me geï¿½er. 
		}											//Bu ï¿½ekilde root dan baï¿½layï¿½p Null a kadar tï¿½m linked list yazdï¿½rï¿½lï¿½r.
=======
  		while(r != NULL){							//r Null olmadýðý sürece döngü devam eder.
  			if(r->fatura >= fatura)					//r nin fatura deðeri, fonksiyona parametre olarak verilen fatura deðerinden (deðerlerin isimleri ayný sadece, ayný þey deðiller) büyükse, true döner.
  			{							
  			printf("%s\t------\t%d\n", r->Ad,r->fatura);;	// r'nin Ad ve fatura deðerleri ekrana yazdýrýlýr.
			}
  			r = r->next;							//r, baðlý olduðu bir sonraki düðüme geçer. 
		}											//Bu þekilde root dan baþlayýp Null a kadar tüm linked list yazdýrýlýr.
>>>>>>> 091ee0628d8bc91fcc4e7825e4fc267dc9ffa505
	}
  
  void ismeGoreYazdir(node*r, char *harf)
  {
<<<<<<< HEAD
  		int ASCII = *harf;							//Burada fonksiyona parametre olarak gelen harf deï¿½eri ASCII isimli int deï¿½iï¿½kenine atanï¿½yor.
  													//karakteri int bir deï¿½iï¿½kene atadï¿½ï¿½ï¿½mï¿½z iï¿½in o karakterin ASCII deï¿½eri deï¿½iï¿½kene atanï¿½r. ï¿½rneï¿½in 'A' harfinin ASCII deï¿½eri 65 dir.
  													//yani her harfin bir sayï¿½sal deï¿½eri vardï¿½r, biz de bu deï¿½ere gï¿½re sï¿½ralama yapacaï¿½ï¿½z.
  		while(r != NULL)							//r null olmadï¿½ï¿½ï¿½ sï¿½rece devam.							
  		{
			if(ASCII == *(r->Ad))					//burada *(r->Ad) yaparak Ad deï¿½erinin ilk harfini almï¿½ï¿½ oluyoruz. ve ASCII deï¿½eriyle karï¿½ï¿½laï¿½tï¿½rï¿½lï¿½yor, Eï¿½er eï¿½itlerse	  
		  	{
  				printf("%s\t------\t%d\n", r->Ad,r->fatura);//Ekrana bu deï¿½erler yazdï¿½rï¿½lï¿½yor.
  			}
  			r = r->next;							//r bir sonraki dï¿½ï¿½ï¿½me geï¿½iyor
=======
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
>>>>>>> 091ee0628d8bc91fcc4e7825e4fc267dc9ffa505
		}
  }
  
  node* ismeGoreEkle(node*r, int fatura, char isim[10])
  {
<<<<<<< HEAD
  	//Yukarï¿½da yaptï¿½ï¿½ï¿½mï¿½z gibi harfler karï¿½ï¿½laï¿½tï¿½rï¿½lmak iï¿½in ASCII deï¿½erlere dï¿½nï¿½ï¿½tï¿½rï¿½lï¿½yor.
=======
  	//Yukarýda yaptýðýmýz gibi harfler karþýlaþtýrýlmak için ASCII deðerlere dönüþtürülüyor.
>>>>>>> 091ee0628d8bc91fcc4e7825e4fc267dc9ffa505
  	char harf = isim[0];
  	int ASCII = harf;
  	int ASCII2 = *(r->Ad);
  	
  	
<<<<<<< HEAD
  	if(ASCII < ASCII2){								//Eï¿½er parametre olarak gelen ismin baï¿½ harfinin ascï¿½ï¿½ deï¿½eri, iterin bulunduï¿½u dï¿½ï¿½ï¿½mdeki ismin Ascï¿½ï¿½ deï¿½erinden kï¿½ï¿½ï¿½kse bu bloï¿½a giriyor.
	  	node*temp = (node*)malloc(sizeof(node));	//Hafï¿½zada yer aï¿½ï¿½lï¿½yor
	  	temp -> fatura = fatura;					//Deï¿½erler aï¿½ï¿½lan yere konuluyor.
	  	strncpy(temp -> Ad, isim, 10);
	  	temp -> next = r;							//oluï¿½turulan yeni yer r nin arkasï¿½na yerleï¿½tiï¿½i iï¿½in root olarak tempi dï¿½ndï¿½rï¿½yoruz.
	  	return temp;
	  }
	  node*iter =r;									//ï¿½stteki bloktan false dï¿½nerse buraya geliniyor ve r nin olduï¿½u noktada bir iter oluï¿½turuyoruz
	  ASCII2 = iter->Ad[0];							//iterin Ad verisinin ASCII deï¿½eri alï¿½nï¿½yor
	  while(iter->next !=NULL && ASCII2 < ASCII){	//eï¿½er iterin nexti null deï¿½ilse ve iterin Ad verisinin ASCII deï¿½eri parametre olarak gelen ismin ASCII deï¿½erinden kï¿½ï¿½ï¿½kse buraya giriliyor.
	  	iter = iter -> next;						//sonraki dï¿½ï¿½ï¿½me geï¿½iliyor.
	  	ASCII2 = iter->Ad[0];						//iterin Ad verisinin ASCII deï¿½eri alï¿½nï¿½yor
	  	if(ASCII < iter -> next -> Ad[0])			//Eï¿½er parametre olarak gelen ismin ASCII deï¿½eri iterin nextinin Ad verisinin ASCII deï¿½erinden bï¿½yï¿½kse bu bloï¿½a giriliyor.
	  	{
	  	node* temp = (node*)malloc(sizeof(node));   //Bir temp oluï¿½turulup araya yerleï¿½tirme iï¿½lemi yapï¿½lï¿½yor.
=======
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
>>>>>>> 091ee0628d8bc91fcc4e7825e4fc267dc9ffa505
	  	temp->next = iter -> next;
	 	iter -> next = temp;
	 	temp -> fatura = fatura;
	 	strncpy(temp -> Ad, isim, 10);
	  	return r;
		}
	  }
<<<<<<< HEAD
	  if(ASCII2 = ASCII)							//Eï¿½er parametre olarak gelen ismin ASCII deï¿½eriyle iterin Ad verisinin ASCII deï¿½eri eï¿½itse, yani aynï¿½ harf ile baï¿½lï¿½yorlarsa
	  {												//Yine araya yerleï¿½tirme iï¿½lemi yapï¿½yoruz.
=======
	  if(ASCII2 = ASCII)							//Eðer parametre olarak gelen ismin ASCII deðeriyle iterin Ad verisinin ASCII deðeri eþitse, yani ayný harf ile baþlýyorlarsa
	  {												//Yine araya yerleþtirme iþlemi yapýyoruz.
>>>>>>> 091ee0628d8bc91fcc4e7825e4fc267dc9ffa505
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
