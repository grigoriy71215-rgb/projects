/* Задача 2: Написать проверку билета у пассажиров:
 * пассажиры допускаются на борт, если
 * достигли 18 лет и имеют билет. То есть: дан возвраст и наличие/отстутствие
 * билета, вернуть возможность прохождения на борт судна.*/

#include <iostream>

bool isAdult(int age) { return age >= 18; }

bool hasTicket(bool ticket) { return ticket; }

void decideTask() {
  int age = 23;
  bool ticket = false;
  if (isAdult(age) && hasTicket(ticket)) {
    std::cout << "пассажир не пропушен по тому что у него нет билета"
              << std::endl;
  }
}

int main(int argc, char *argv[]) {
  decideTask();
  return 0;
}
