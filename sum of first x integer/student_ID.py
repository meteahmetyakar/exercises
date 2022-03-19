#Student ID = 64210067

txtFile = open('studentID.txt', 'r')  # we opened txt file for read (with 'r' mode)
lenght = int(txtFile.readline()) #we reading only one line from file and that is last two digits of ID
txtFile.close() #closing the file

# START First Way

sum = 0

for x in range(lenght): #A loop that assigns numbers from 0 to length one by one to x and runs.
	sum += x #add each x value to the sum variable
	
print(sum)

# END First Way


# START Second Way (with sum of consecutive numbers)

first_number = 0
last_number = lenght-1 #Since the first x numbers (lenght) are requested and our first number is 0, we subtract 1 from lenght

sum = (lenght/2)*(first_number + last_number) #this is the formula of sum of consecutive numbers
print(sum)

# END Second Way


#Hocalar genelde ilk yolu yapmanızı isterler çünkü burada amaçları sonuca ulaşmak değil döngü yapısını anlamanız ve kullanabilmenizdir. Bunu ölçmek isterler.
#Fakat böyle bir durumda ikinci yolu kullanmak daha mantıklıdır, ilk yolda makineye 67 (id nizin son iki basamağı) kere işlem yaptırıyoruz ikinci yolda ise 1 kere.
#Sayı (lenght) büyüdükçe makinenin hesaplama süresi de büyüyecektir bu da kodun stabil olmasını engelliyor. 
#Ama ikinci yolda daima 1 kere işlem yapıyorsunuz bu yüzden ikinci yolu kullanmak daha doğru.
