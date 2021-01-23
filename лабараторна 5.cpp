
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n, m;

    setlocale(LC_ALL, "Ukr");
    printf("Трачук Юлiя IС-01\n");

    cout << "Ввести число n = ";  cin >> n; //Введення n
    if (n > 0 && n < 27)// Умова виконная програми
    {
       int sum = 0; // Присвоїти початковій суммі значення 0
       int m = 0;
        while (sum == !n)
        {
            sum += m % 10;  // Обчислюємо суму 
            m /= 10;
         cout << "Сума m останнiх цифер числа n" << " = " << m << endl;
        }
 
    }
    else cout << "Неможливо визначити\n";

    return 0;
    system("pause");
}


