# Модульна контрольна робота з ООП

## НД “Об'єктно орієнтоване програмування”

### МКР Рівень 1

У репозиторії розміщено практичні C++ приклади до контрольних завдань першого рівня модульної контрольної роботи.

Для кожного завдання підготовлено:

- `.cpp` файл з програмним кодом;
- скріншот результату виконання програми в терміналі;
- приклад компіляції та запуску через Microsoft C++ Compiler.

---

## Структура файлів

| № | Тема завдання | Код | Результат виконання |
|---|---|---|---|
| 1 | Загальні форми операторів `try`, `catch`, `throw` | [`01_try_catch_throw.cpp`](01_try_catch_throw.cpp) | [`01_terminal_try_catch_throw.png`](01_terminal_try_catch_throw.png) |
| 2 | Сумісна робота операторів `try`, `catch`, `throw` | [`02_exception_handling_example.cpp`](02_exception_handling_example.cpp) | [`02_result_exception_handling.png`](02_result_exception_handling.png) |
| 3 | Використання `throw` без блоку `try` | [`03_throw_without_try.cpp`](03_throw_without_try.cpp) | [`03_result_throw_without_try.png`](03_result_throw_without_try.png) |
| 4 | Переваги введення-виведення C++ порівняно з мовою C | [`04_cpp_io_advantages.cpp`](04_cpp_io_advantages.cpp) | [`04_result_cpp_io_advantages.png`](04_result_cpp_io_advantages.png) |
| 5 | Функції та маніпулятори форматування | [`05_format_parameters.cpp`](05_format_parameters.cpp) | [`05_result_format_parameters.png`](05_result_format_parameters.png) |
| 6 | Зручність використання фабрики для створення об’єктів | [`06_factory_method.cpp`](06_factory_method.cpp) | [`06_result_factory_method.png`](06_result_factory_method.png) |
| 7 | Dependency Injection | [`07_dependency_injection.cpp`](07_dependency_injection.cpp) | [`07_result_dependency_injection.png`](07_result_dependency_injection.png) |
| 8 | Поява нового похідного класу в патерні Visitor | [`08_visitor_pattern.cpp`](08_visitor_pattern.cpp) | [`08_result_visitor_pattern.png`](08_result_visitor_pattern.png) |

---

## Середовище виконання

Для виконання практичних прикладів використовувалось середовище:

- **Visual Studio Developer PowerShell**
- **Microsoft C++ Compiler**
- мова програмування **C++**

Компіляція виконувалась командою:

```powershell
cl /EHsc filename.cpp
```

Запуск програми виконувався командою:

```powershell
.\filename.exe
```

---

## Короткий опис виконаних завдань

### Завдання 1. Оператори `try`, `catch`, `throw`

У першому прикладі показано загальну форму роботи механізму оброблення винятків у C++.  
Блок `try` містить код, у якому може виникнути помилка. Оператор `throw` створює виняток, а блок `catch` перехоплює його та виконує оброблення.

Файл з кодом: [`01_try_catch_throw.cpp`](01_try_catch_throw.cpp)  
Результат виконання: [`01_terminal_try_catch_throw.png`](01_terminal_try_catch_throw.png)

---

### Завдання 2. Сумісна робота `try`, `catch` і `throw`

У другому прикладі показано оброблення ситуації ділення на нуль.  
Програма перевіряє значення дільника, генерує виняток за допомогою `throw`, а потім перехоплює його в блоці `catch`. Завдяки цьому програма не завершується аварійно.

Файл з кодом: [`02_exception_handling_example.cpp`](02_exception_handling_example.cpp)  
Результат виконання: [`02_result_exception_handling.png`](02_result_exception_handling.png)

---

### Завдання 3. Використання `throw` без блоку `try`

У третьому прикладі показано, що оператор `throw` можна використати без блоку `try`, але якщо виняток не буде перехоплений, програма викличе механізм аварійного завершення.  
Для наочності використано власний обробник `std::terminate`.

Файл з кодом: [`03_throw_without_try.cpp`](03_throw_without_try.cpp)  
Результат виконання: [`03_result_throw_without_try.png`](03_result_throw_without_try.png)

---

### Завдання 4. Введення-виведення C++ порівняно з C

У четвертому прикладі порівнюється C-style виведення через `printf()` та C++-style виведення через `cout`.  
Також показано, що в C++ можна зручно виводити об’єкти класів через перевантаження оператора `<<`.

Файл з кодом: [`04_cpp_io_advantages.cpp`](04_cpp_io_advantages.cpp)  
Результат виконання: [`04_result_cpp_io_advantages.png`](04_result_cpp_io_advantages.png)

---

### Завдання 5. Форматування виведення

У п’ятому прикладі показано застосування засобів форматування:

- `setw()`;
- `setprecision()`;
- `fixed`;
- `left`;
- `right`;
- `setfill()`;
- `boolalpha`;
- `showpos`;
- `scientific`.

Ці маніпулятори дозволяють зробити виведення даних більш структурованим і зручним для читання.

Файл з кодом: [`05_format_parameters.cpp`](05_format_parameters.cpp)  
Результат виконання: [`05_result_format_parameters.png`](05_result_format_parameters.png)

---

### Завдання 6. Factory Method

У шостому прикладі показано зручність використання фабрики для створення об’єктів.  
Клієнтський код не створює об’єкти `Admin`, `Client` або `Manager` напряму, а звертається до `UserFactory`, яка сама створює потрібний об’єкт.

Файл з кодом: [`06_factory_method.cpp`](06_factory_method.cpp)  
Результат виконання: [`06_result_factory_method.png`](06_result_factory_method.png)

---

### Завдання 7. Dependency Injection

У сьомому прикладі показано, як залежність від конкретного класу трансформується в залежність від абстракції.  
Клас `BookingServiceWithDI` не створює сервіс повідомлень самостійно, а отримує його ззовні через конструктор. Це дозволяє легко замінити Email-повідомлення на SMS-повідомлення без зміни логіки бронювання.

Файл з кодом: [`07_dependency_injection.cpp`](07_dependency_injection.cpp)  
Результат виконання: [`07_result_dependency_injection.png`](07_result_dependency_injection.png)

---

### Завдання 8. Visitor

У восьмому прикладі показано наслідки появи нового похідного класу `Triangle` у структурі патерну Visitor.  
Після додавання нового класу потрібно змінити інтерфейс `ShapeVisitor` і додати новий метод `visit(const Triangle&)`. Також цей метод потрібно реалізувати в усіх конкретних visitor-класах.

Файл з кодом: [`08_visitor_pattern.cpp`](08_visitor_pattern.cpp)  
Результат виконання: [`08_result_visitor_pattern.png`](08_result_visitor_pattern.png)

---

## Висновок

У межах модульної контрольної роботи було розглянуто основні механізми оброблення винятків у C++, засоби введення-виведення, форматування даних, а також патерни Factory Method, Dependency Injection і Visitor.

Для кожного завдання створено окремий практичний C++ приклад. Усі приклади було скомпільовано та перевірено в терміналі, а результати виконання додано до репозиторію у вигляді скріншотів.
