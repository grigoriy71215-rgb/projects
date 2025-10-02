#include <iostream>                            // для работ состандартным потоком соut

int main() {                                   // функция с которой начинается выполнение программы
  float potatoAmount = 0;                     // переменная для количества картошки
  float carrotAmount = 0;                     // переменная для количества морковки
  float potatoPrice = 0;                       // переменная для цены картошки
  float carrotPrice = 0;                       // переменная для цены морковки
  std::cout << "Сколько стоит картошка? ";     // спрашивем и заносим данные в соотвествующие переменные
  std::cin >> potatoPrice;
  std::cout << "Сколько стоит морковка? ";
  std::cin >> carrotPrice;
  std::cout << "Сколько кг картошки Вы хотите купить? ";
  std::cin >> potatoAmount;
  std::cout << "Cколько кг морковки Вы хотите купить? ";
  std::cin >> carrotAmount;
  float purchaseSum = potatoPrice * potatoAmount + carrotPrice * carrotAmount;  // расчитываем сумму покупки
  std::cout << "Сумма покупки составила " << purchaseSum << '\n';               // выводим результат на экран
  return 0;                                    // возврат из функции, значение можно посмотреть, нобрав echo $? после выполнения программы
}
  
