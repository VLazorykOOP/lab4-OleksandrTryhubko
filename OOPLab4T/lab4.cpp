#include <cmath>
#include <iostream>
#include <string>
#include <map>
using namespace std;

enum STATE { OK, BAD_INIT, BAD_DIV };

/*Створити тип даних - клас вектор Vector3F, який має поля x, y та z типу float і
змінну стану State . У класі визначити:

o конструктор без параметрів(інінціалізує поля в нуль);
o конструктор з одним параметром типу float (інінціалізує поля x, y та z
значенням параметру);
o конструктор з одним параметром вказівник на тип (інінціалізує поля x, y та z
значенням масиву за вказівником, якщо вказівник NULL (nulptr) то
встановити код помилки);
o деструктор із виведенням інформації про стан вектора;
o перевантаження операцій (операції перевантажувати через функції класу або
дружні функції, якщо не вказано яким чином це робити):
• унарних префіксних та постфіксних ++ та --: одночасно збільшує
(зменшує) значення елементів масиву на 1.0;
• унарної логічної ! (заперечення): повертає значення true, якщо
елементи якщо x, y та z не дорівнюють – нулю, інакше false;
• унарної побітової ~ (заперечення): повертає перпендикулярний вектор
для заданого;
• унарний арифметичний - (мінус) : повертає всі елементи масиву
класу вектор з протилежним знаком;
• присвоєння =: копіює вектор(перевантажити через функцію класу);
• присвоєння з
o += - додаванням векторів;
o -= - відніманням векторів;
o *= - множенням на число;
o /= - ділення на число;
• арифметичних бінарні:
o + - додавання векторів;
o - - віднімання векторів;
o * - множення вектора на число;
o / - ділення вектора на число;
o % - остача від ділення для цілої части дійсного числа на число
типу int;
• побітові операції зсувів, як дружні операції введення та виведення
вектора у потік (перевантажувати через дружні функції)
o введення >> (побітовий зсув право) ;
o введення << (побітовий зсув ліво);
• рівності == та нерівності!= , функція-операція виконує певні дії над
кожною парою елементів векторів за індексом;
• операцію індексації [] – функцію, яка звертається до елементу
масиву за індексом до x, y та z, якщо індекс невірний функція вказує
на z та встановлює код помилки у змінну State;
• розподілу пам’яті new та delete;
• виклику функції ();
• порівняння (функція-операція виконує певні дії над кожною парою
елементів векторів за індексом), які повертають true або false:
o > (більше) для двох векторів;
o >= (більше рівне) для двох векторів;
o < (менше) для двох векторів;
o <=(менше рівне) для двох векторів.
*/


class Vector3F {
  float x, y, z;
  int state = OK;

public:
  Vector3F() {
    x = 0;
    y = 0;
    z = 0;
  }
  Vector3F(int value) {
    x = value;
    y = value;
    z = value;
  }

  Vector3F(Vector3F &v) {
    if (&v == nullptr) {
      state = BAD_INIT;
    }
    x = v.x;
    y = v.y;
    z = v.z;
    state = v.state;
  }

  ~Vector3F() {}

  void setValue(int value) {
    x = value;
    y = value;
    z = value;
  }

  double returnX() { return x; }
  double returnY() { return y; }
  double returnZ() { return z; }

  void print() { cout << "X = " << x << " Y = " << y << " Z = " << z << endl; };

  Vector3F(const Vector3F &other) {
    x = other.x;
    y = other.y;
    z = other.z;
    state = other.state;
  }

  Vector3F operator++() {
    x++;
    y++;
    z++;
    return *this;
  };

  Vector3F operator--() {
    x--;
    y--;
    z--;
    return *this;
  };

  bool operator!() {
    if (x != 0 && y != 0 && z != 0) {
      return true;
    }
    return false;
  }

  Vector3F operator-() {
    Vector3F result(*this);
    result.x = -x;
    result.y = -y;
    result.z = -z;
    return result;
  }

  Vector3F &operator=(const Vector3F &v) {
    x = v.x;
    y = v.y;
    z = v.z;
    state = v.state;
    return *this;
  }

  Vector3F &operator+=(const Vector3F &v) {
    x += v.x;
    y += v.y;
    z += v.z;
    state = v.state;
    return *this;
  }

  Vector3F &operator-=(const Vector3F &v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    state = v.state;
    return *this;
  }

  Vector3F &operator*=(int value) {
    x *= value;
    y *= value;
    z *= value;
    return *this;
  }

  Vector3F &operator/=(int value) {
    if (value != 0) {
      x /= value;
      y /= value;
      z /= value;
      return *this;
    } else {
      state = BAD_DIV;
      return *this;
    }
  }

  Vector3F operator+(const Vector3F &v) {
    Vector3F result;
    result.x = x + v.x;
    result.y = y + v.y;
    result.z = z + v.z;
    return result;
  }
  Vector3F operator-(const Vector3F &v) {
    Vector3F result;
    result.x = x - v.x;
    result.y = y - v.y;
    result.z = z - v.z;
    return result;
  }
  Vector3F operator*(int n) {
    Vector3F result;
    result.x = x * n;
    result.y = y * n;
    result.z = z * n;
    return result;
  }
  Vector3F operator/(int n) {
    Vector3F result;
    if (n == 0) {
      result.state = BAD_DIV;
      return result;
    } else {
      result.x = x / n;
      result.y = y / n;
      result.z = z / n;
      return result;
    }
  }

  friend istream &operator>>(istream &input, Vector3F &vector);
  friend ostream &operator<<(ostream &output, const Vector3F &vector);

  bool operator==(const Vector3F &v) {
    if (x != v.x || y != v.y || z != v.z) {
      return false;
    }
    return true;
  }

  bool operator!=(const Vector3F &v) {
    if (x == v.x || y == v.y || z == v.z) {
      return false;
    }
    return true;
  }

  int operator[](int index) {
    if (index < 0 || index > 3) {
      state = BAD_DIV;
      return z;
    } else {
      switch (index) {
      case 1:
        return x;
        break;
      case 2:
        return y;
        break;
      case 3:
        return z;
        break;
      default:
        break;
      }
    }
  }

  void *operator new(size_t size_new) {
    void *v = malloc(size_new);
    return v;
  }

  void operator delete(void *v) { free(v); }

  void operator()() { cout << "Function"; }

  bool operator>(const Vector3F &v) {
    double length1 = 0, length2 = 0;
    length1 = x * x + y * y + z * z;

    length1 = sqrt(length1);

    length2 = v.x * v.x + v.y * v.y + v.z * v.z;

    length2 = sqrt(length2);

    if (length1 > length2) {
      return true;
    }
    return false;
  }

  bool operator>=(const Vector3F &v) {
    double length1 = 0, length2 = 0;
    length1 = x * x + y * y + z * z;

    length1 = sqrt(length1);

    length2 = v.x * v.x + v.y * v.y + v.z * v.z;

    length2 = sqrt(length2);

    if (length1 >= length2) {
      return true;
    }
    return false;
  }

  bool operator<(const Vector3F &v) {
    double length1 = 0, length2 = 0;
    length1 = x * x + y * y + z * z;

    length1 = sqrt(length1);

    length2 = v.x * v.x + v.y * v.y + v.z * v.z;

    length2 = sqrt(length2);

    if (length1 < length2) {
      return true;
    }
    return false;
  }

  bool operator<=(const Vector3F &v) {
    double length1 = 0, length2 = 0;
    length1 = x * x + y * y + z * z;

    length1 = sqrt(length1);

    length2 = v.x * v.x + v.y * v.y + v.z * v.z;

    length2 = sqrt(length2);

    if (length1 <= length2) {
      return true;
    }
    return false;
  };
};

istream &operator>>(istream &input, Vector3F &v) {
  cout << "Enter x, y, z:";
  input >> v.x >> v.y >> v.z;
  return input;
}

ostream &operator<<(ostream &output, const Vector3F &v) {
  output << "X = " << v.x << " Y = " << v.y << " Z = " << v.z;
  output << endl;
  return output;
}

void exersice1() {
 float value;
  cout << "Enter the value of vector:";
  cin >> value;
  Vector3F v1(value);
  cout << "Entered vector" << endl;
  cout << v1;
  cout << "vector++" << endl;
  ++v1;
  cout << v1;
  cout << "vector--" << endl;
  --v1;
  cout << v1;
  cout << "Vector2 value 2" << endl;
  Vector3F v2(2);
  cout << v2;
  cout << "Vector1 + Vector2" << endl;
  cout << (v1 + v2) << endl;
  cout << "Vector1 - Vector2" << endl;
  cout << (v1 - v2) << endl;
  cout << "Entered vector < Vector2" << endl;
  cout << (v1 < v2) << endl;
  cout << "Entered vector > Vector2" << endl;
  cout << (v1 > v2) << endl;
  cout << "Entered vector <= Vector2" << endl;
  cout << (v1 <= v2) << endl;
  cout << "Entered vector >= Vector2" << endl;
  cout << (v1 >= v2) << endl;
}

/*Побудувати асоційований клас збереження
двох сутностей. В завданні створити клас, який представляє собою
асоціативний масив між двома сутностями. Написати функцію створення
набору асоціативних сутностей. Перевантажити операцію індексації [] –
функцію, яка звертається до об’єкта класу, за однією сутністю, якщо індекс,
повертає асоціативну сутність, якщо відповідної сутності немає в встановлює
код помилки у змінну CodeError, альтернативні звернення через
перевантаження операції виклику функції(); перевантажити дружні операції
введення та виведення.

Номер телефону та прізвище, ім’я, по-батькові.
*/

class AssocArray {
private:
    map<string, string> data;
    int codeError;

public:
    AssocArray() {
        codeError = 0;
    }
    
    void set(string key, string value) {
        data[key] = value;
    }
    
    string get(string key) {
        if (data.count(key)) {
            return data[key];
        } else {
            codeError = 1; // Key not found    
        } 
    }
    
    string operator[](string key) {
        return get(key);
    }
    
    friend ostream& operator<<(ostream& os, const AssocArray& aa) {
        for (auto const& pair : aa.data) {
            os << pair.first << ": " << pair.second << endl;
        }
        return os;
    }
    
    friend istream& operator>>(istream& is, AssocArray& aa) {
        string key, value;
        cout << "Enter key and value (separated by space): ";
        is >> key >> value;
        aa.set(key, value);
        return is;
    }
    
    void printCodeError() {
        switch (codeError) {
            case 0:
                cout << "No error" << endl;
                break;
            case 1:
                cout << "Key not found" << endl;
                break;
            default:
                cout << "Unknown error" << endl;
                break;
        }
    }
};

void exersice2() {
    AssocArray list;
    list.set("Truhubko Olexander", "+380638893750");
    list.set("Dmutro Yusko", "+380508202385");
    list.set("Vasyl Kostenuk", "+380685565495");

    cout << "list[\"Truhubko Olexander\"] = " << list["Truhubko Olexander"] << endl;
    cout << "list[\"Dmutro Yusko\"] = " << list["Dmutro Yusko"] << endl;
    list.printCodeError();

    cout << endl << "Associative Array Contents:" << endl;
    cout << list;

    cin >> list;
    cout << endl << "Associative Array Contents After Input:" << endl;
    cout << list;
}


int main() {
  exersice2();
  return 0;
}