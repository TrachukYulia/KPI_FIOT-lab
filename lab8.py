import math #Введення бібліотеки
#Задані натуральні числа m та n. Обчислити суму m останніх цифер числа n.
n = int(input( "Ввести число n = ")) #Ввести значення n
m = int(input("Ввести к-ть цифр числа n, m = ")) #Ввести значення m
sum=0;
i=0;
if (m > 0) and (m%10<=n%10): #Умова виконання
  for i in range(0, int(m)): #умова циклу
   sum = sum + n % 10;  #Обчислюємо суму 
   n //= 10; #Ділим число на 10, переходимо до наступної цифри 
  print ("Сума m останнiх цифер числа n = " + str(sum)); #Виводимо значення 
else:
   print("Неможливо визначити\n") #Виведення результату за не виконання умови

