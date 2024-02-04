#include <map>

// Режим в котором работает контролер
enum Mode {
  Single = 1,   // Одиночный
  Start,        // Стоит на страте
  Finish        //Стоит на финише
};

// LED подсветки текущего режима
std::map<int, int> ModeLED{
  {Single, D5},
  {Start, D6},
  {Finish, D7}
};
