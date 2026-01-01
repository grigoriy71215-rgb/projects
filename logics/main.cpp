#include <iostream>

// По && соединяем только разные характеристики
// Между возможными значениями одной характеристики ставится ||

enum PERMISSION { ADMIN, CLIENT_MANAGER, CREDIT_SPEC };

bool permitForClM(PERMISSION user) { return user == CLIENT_MANAGER; }

bool permitForClmExt(PERMISSION user) {
  return user == CLIENT_MANAGER || user == ADMIN;
}

int main(int argc, char *argv[]) {
  auto admin = PERMISSION::ADMIN;
  auto clm = PERMISSION::CLIENT_MANAGER;
  auto crs = PERMISSION::CREDIT_SPEC;
  std::cout << "User: admin. Permit for ClM: " << permitForClM(admin) << '\n';
  std::cout << "User: clm. Permit for ClM: " << permitForClM(clm) << '\n';
  std::cout << "User: crs. Permit for ClM: " << permitForClM(crs) << '\n';
  std::cout << "-----------------------------------------\n";
  std::cout << "User: admin. Permit for ClMEx: " << permitForClmExt(admin)
            << '\n';
  std::cout << "User: clm. Permit for ClMEx: " << permitForClmExt(clm) << '\n';
  std::cout << "User: crs. Permit for ClMEx: " << permitForClmExt(crs) << '\n';

  int value = 3;
  std::cout << "-----------------------------------------\n";
  std::cout << "User: admin. Value is not 0 and for ClM: "
            << (permitForClM(admin) && value != 0) << '\n';
  std::cout << "User: clm. Value is not 0 and for ClM: "
            << (permitForClM(clm) && value != 0) << '\n';
  std::cout << "User: crs. Value is not 0 and for ClM: "
            << (permitForClM(crs) && value != 0) << '\n';
  std::cout << "-----------------------------------------\n";
  // Задание: разрешить доступ только для CREDIT_SPEC при value != 0
  std::cout << "User: admin. Value is not 0 and for CrS: "
            << (!permitForClmExt(admin) && value != 0) << '\n';
  std::cout << "User: clm. Value is not 0 and for CrS: "
            << (!permitForClmExt(clm) && value != 0) << '\n';
  std::cout << "User: crs. Value is not 0 and for CrS: "
            << (!permitForClmExt(crs) && value != 0) << '\n';
  std::cout << "-----------------------------------------\n";
  // Задание: разрешить доступ для CREDIT_SPEC и CLIENT_MANAGER при value != 0
  std::cout << "User: admin. Value is not 0 and for CrS: "
            << ((!permitForClmExt(admin) || permitForClM(admin)) && value != 0)
            << '\n';
  std::cout << "User: clm. Value is not 0 and for CrS: "
            << ((!permitForClmExt(clm) || permitForClM(clm)) && value != 0)
            << '\n';
  std::cout << "User: crs. Value is not 0 and for CrS: "
            << ((!permitForClmExt(crs) || permitForClM(crs)) && value != 0)
            << '\n';
  std::cout << "-----------------------------------------\n";
  // Задание: разрешить доступ для admin при value != 0
  std::cout << "User: admin. Value is not 0 and for Admin: "
            << ((permitForClmExt(admin) && !permitForClM(admin)) && value != 0)
            << '\n';
  std::cout << "User: clm. Value is not 0 and for Admin: "
            << ((permitForClmExt(clm) && !permitForClM(clm)) && value != 0)
            << '\n';
  std::cout << "User: crs. Value is not 0 and for Admin: "
            << ((permitForClmExt(crs) && !permitForClM(crs)) && value != 0)
            << '\n';

  return 0;
}
