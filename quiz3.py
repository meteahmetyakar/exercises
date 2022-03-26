def listSearch(myId, element):
    ### THE LIST DOES NOT NEED TO BE SORTED ###  
    for i in range(len(myId)):  #a loop that will repeat for the length of the list, i stars from 0 and ends in list end
        if myId[i] == element:  #if ith element is equal to element variable
            return True         #then return True
    
    return False                #If it comes this far, it means no value was returned from the for loop, which means that the state of myId[i] == element is not found, so the element is not in the list


def binarySearch(myId, element):
    ### THE LIST MUST BE SORTED ###
    first = 0           
    last = len(myId)-1  #The last element of list is one less than the length of the list
    found = False

    while first<=last and not found:  
        mid = (first + last)//2         #We will start from the middle of the list due to binary search, so we find the middle element. It can be find float that's why we used // operand (floor division)
        if myId[mid] == element:        #if middle element is equal to element then return true
            found = True
        else:
            if element < myId[mid]:     #If the searched element is less than the element we are in, we set the value of last variable to mid-1.
                last = mid-1
            else:
                first = mid+1           #else we set the value of last variable to mid+1
	
        #binary searchde listenin ortasından başlanır ve liste sıralı olmalıdır listemiz [0,0,1,2,4,6,6,7] olsun ve 3 sayısını arayalım. Orta elemanı 3.index oluyor burada 3, 2 e eşit olmadığı için
        #20.satıra geliyoruz ve element küçük mü myId[mid] diye soruyoruz yani 3 küçük mü 2? hayır. o zaman firsti mid+1 yapıyoruz . first şuan 4 oldu, last bizim listemizin uzunluğunun bir eksiğiydi yani
        #7 idi. Daha sonra tekrar 16. satıra dönüyor (15.satırdaki koşul sağlanmasa dönmezdi) ve (4 + 7)/2 yapıyor bu da 5 indeksini verir yani 6 elemanı. 6 da 3 e eşit değil ve 3 den büyük bu yüzden firsti yine mid+1 yapıyoruz 
        #böylece first 12 olmuş oluyor, 15. satıra tekrar dönüyoruz first (12) küçük eşit olmadığı için lasta (7) döngü duruyor ve false değeri döndürülüyor.

        #binary tree nin amacı listeyi parçalara bölüp bakmamız gereken yere bakmak burada önemli olan tek şey listenin sıralı olması. Listemiz sıralıydı ve [0,0,1,2,4,6,6,7] idi ilk işlemi yaptığımızda yani orta noktaya bakıp
        #küçük mü büyük mü diye baktığımızda eğer orta elemandan küçükse orta elemandan küçük sayılara bakıyoruz. aslında listeyi iki parçaya bölüyoruz  [0,0,1,2] - [4,6,6,7] olarak. aradığımız eleman 3 idi o zaman üçten büyük sayıların içinde olamaz. yani ikinci listeyi ([4,6,6,7]) at çöpe
        #bu işlemde çok büyük aramalarda işe yarıyor. 1000 tane elemanın olduğu bir liste olsun sadece ilk işlemde 500 tanesini atmış oluyorsunuz ve en kötü ihtimalle 10 kez bakmada var mı yok mu bunu anlıyorsunuz bu da bize hız kazandırmış oluyor

    return found


def bubbleSort(myId):
    for i in range(len(myId)):          #a loop that returns the length of the list
        for j in range(len(myId)-1):    #a loop that returns one less than the list length
            if myId[j]>myId[j+1]:       #if myId[j] greater than myId[j+1]
                temp = myId[j]          #create a temp and put the myId[j] to temp
                myId[j] = myId[j+1]     #put the myId[j+1] to myId[]
                myId[j+1] = temp        #put the temp to myId[j+1]
    
    #burada önce 0.indeksten başlıyoruz ve 0 ile 1 i karşılaştırıyoruz eğer 0 1 den büyükse yerleri değiştiriliyor. Listemiz [6,4,2,1,0,0,6,7] olsun 0.indeks 1.indeksten büyük mü? evet. O zaman yerlerini değiştir
    #yeni liste [4,6,2,1,0,0,6,7] oldu daha sonra 1 ile 2 ye bakılıyor yine büyükse yeri değiştiriliyor bu şekilde 2-3, 3-4, 4-5 bakılarak ve gerekiyorsa değiştirilerek en büyük elemanı listenin en sonuna götürmüş oluyoruz bunu da listenin uzunluğu kez yapıyoruz (yani bir elemanı alıp her elemanla karşılaştırma işlemini liste uzunluğu 10 ise 10 kez yapıyoruz)
    #bu yüzden iç içe döngü kullandık. Yer değiştirme işlemi de şu şekilde oluyor
    #temp   a1  a2  --> (a lar değişken ve onların değerini değiştireceğiz, bu kısmı tablo şeklinde yazacağım isimlerinin altında kalan kısımlar değerler)
    # -     5   7   --> burada yerlerini değiştirmek için a1 = a2 yapsak a1 = 7, a2 = 7 olur böylece 5 değerini kaybederiz bu yüzden 5 değerini kaybetmemek için onu temp değişkenine koyuyoruz
    # 5     5   7   --> temp = a1 yaptık (satır 43), şimdi a1 in değerini bir yerde tuttuğumuz için a1 e değer koyabiliriz
    # 5     7   7   --> a1 = a2 yaptık (satır 44), yerlerini değiştirmek istediğimizden temp değerini de a2 nin içine koyuyoruz a2 = temp (satır 45)
    # 5     7   5   --> son durumda yerlerini değiştirmiş olduk

    return myId #return list

myId = [6,4,2,1,0,0,6,7]

falseValue = 3  #value to use in wrong case
trueValue = 6   #value to use in right case

print("My student id = "+str(myId))
myId = bubbleSort(myId) #sorting list

print("Sorted with bubble sort = " +str(myId))

print("\n#############################################\n")

print("Searched "+str(falseValue)+" with binary search")
print("result: "+str(binarySearch(myId, falseValue)))
print("\n")
print("Searched "+str(trueValue)+" with binary search")
print("result: "+str(binarySearch(myId, trueValue)))

print("\n#############################################\n")

print("Searched "+str(falseValue)+" with list search")
print("result: "+str(listSearch(myId, falseValue)))
print("\n")
print("Searched "+str(trueValue)+" with list search")
print("result: "+str(listSearch(myId, trueValue)))

print("\n#############################################\n")
