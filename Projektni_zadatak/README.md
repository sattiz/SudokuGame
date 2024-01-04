# Индивидуальный проект 2023/24
## Требования к проекту

### Введение
Поздравляем вас с успешным прохождением в полуфинале квиза "Судокусфера"! Теперь пришло время столкнуться с решающей игрой, которая определит вашу судьбу - "Судоку Испытание". В этом мире вам предстоит принять вызовы числами в формате судоку 3x3.

Вам предоставлена доска с 9 квадратами по 9 ячеек. Правила просты - каждая цифра от 1 до 9 должна встречаться ровно один раз в:

- каждой строке всей таблицы
- каждом столбце всей таблицы
- каждой из подматриц 3x3 всей таблицы

Чтобы упростить решение задачи судоку, вам необходимо написать программу, которая сделает ваше путешествие по математическому лабиринту более легким.

Подготовьтесь к логическим подвигам, потому что успех в игре "Судоку Испытание" приближает вас к финалу "Судокусферы". Удачи!

### Ход игры
#### Запуск программы и игрового меню в консоли
1. Создание меню сначала предоставляет возможность выбора пользователя: хочет ли он загрузить уже заданную головоломку судоку из файла или хочет, чтобы программа сгенерировала новую.
    - Если выбрана генерация установки, программа создает файл, в который записывает установку головоломки судоку для пользователя.
2. Через консольное меню пользователь выбирает, хочет ли он сам ввести решение, загрузив файл с решенной головоломкой, или позволить программе решить ее.
3. После введения решения (сгенерированного программой или загруженного из файла пользователя), на консольном приложении отображаются статистические данные игры (количество правильно установленных ячеек, количество ошибок, счетчик сыгранных игр).
4. После завершения игры пользователь может выбрать повторение игры, что запускает новую итерацию игры.

### Функциональные требования
1. **Загрузка аргументов командной строки**
   - Программа должна обрабатывать файлы, имена которых предоставлены через аргументы командной строки.

2. **Загрузка головоломки судоку**
   - Программа должна иметь функциональность загрузки головоломки судоку размером 9x9 из файла в текстовом формате.
   - Для функциональности загрузки головоломки из файла не важно, является ли загадка в файле установленной или ее решением, т.е. важно, чтобы загадка, которую загружает программа, была или не была заполнена.

3. **Сохранение головоломки судоку**
   - Программа должна выводить головоломку судоку в файл.
   - Вывод должен быть ясным и легко читаемым.
   - Для функциональности сохранения головоломки в файле не важно, решена ли головоломка или нет; важно, чтобы матрица была представлена ясно.

4. **Проверка правильности решения игрока**
   - Программа должна проверить правильность решения, введенного игроком через файл, обеспечивая, что каждое число вводится только один раз в каждой строке, столбце и подматрице 3x3.

5. **Автоматическое решение головоломки**
   - Программа должна иметь функциональность для автоматического решения головоломки судоку.
   - Решение, предложенное программой, должно быть правильным, что означает, что все три правила игры судоку должны быть соблюдены.

6. **Генерация установки головоломки судоку**
   - Программа должна создавать действительную установку головоломки судоку 3x3.
   - Среднее количество установленных чисел, т.е. заполненных ячеек в подматрице, не должно превышать 6.

7. **Вывод статистической информации**
   - Программа должна после каждой игры генерировать следующую информацию:
     - Количество правильно введенных чисел на своем месте.
     - Количество правильно введенных чисел, но не на своем месте.
     - Порядковый номер игры.

## Реализационные шаги
Класс "Sudoku9" представляет собой ядро программы для работы с головоломкой Судоку размером 9x9.
Он содержит матрицу 9x9 для представления поля головоломки и основные функциональности.
Помимо этого класса, необходимо создать классы, определяющие определенные логические компоненты и осмысленно разделяющие функциональности. При разработке проекта рассмотрите использование концепций, упомянутых на занятиях, таких как полиморфизм, наследование, композиция, инкапсуляция и т.д. В тексте ниже определены шаги реализации.

1. **Определение класса для представления головоломки Судоку:**
   - Определите класс "Sudoku", который будет содержать матрицу 9x9 для представления головоломки.
   - Рассмотрите добавление дополнительных членов класса, таких как счетчик правильных вводов, счетчик сыгранных игр и т.д.
   - Рассмотрите создание модулей для дополнительных членов класса и классов, с которыми класс "Sudoku" взаимодействует, чтобы программа была модульной.

2. **Реализация функциональности загрузки и вывода головоломки:**
   - Имена файлов для загрузки или вывода головоломки Судоку должны быть заданы через аргументы командной строки.
   - Формат файла должен быть таким, что каждая строка представляет собой строку головоломки Судоку, и каждый символ в строке соответствует значению в этом месте.
   - При загрузке, если головоломка Судоку не заполнена, то есть, если загружается ее установка, для отсутствующих полей можно определить идентификатор, описывающий их (например, число 0, число -1 и т.д.).
   - При выводе необходимо удалить идентификаторы, которые обозначали пустые поля, чтобы вывод был аккуратным и ясным.
   - Предполагается, что входной файл определен без ошибок.

3. **Реализация проверки корректности ввода игрока:**
   - Функции должны проверить корректность матрицы, представляющей решение головоломки Судоку, независимо от того, является ли эта матрица введенным пользователем решением или решением, сгенерированным программой.
   - Программа внимательно анализирует ввод пользователя и определяет, содержит ли он ошибки или все правила игры успешно выполняются.

4. **Реализация алгоритмов решения головоломки:**
   - На основе матрицы, представляющей установку, необходимо реализовать функции, которые позволят заполнить ее, соблюдая правила игры Судоку.
   - Рассмотрите добавление оптимизаций для уменьшения времени выполнения алгоритма.

5. **Реализация функциональности генерации установки головоломки Судоку:**
   - Необходимо сгенерировать таблицу головоломки Судоку так, чтобы числа и их позиции были псевдослучайными, но гарантировали возможность правильного решения головоломки.
   - Для генерации установки и решения головоломки рассмотрите различные подходы: рекурсивный алгоритм, метод исключения, комбинаторику и обработку перестановок и т.д.

6. **Модульность функциональности:**
   - Все перечисленные функциональности можно реализовать модульно и независимо друг от друга. Это следует использовать при разработке и тестировании решения, чтобы каждый этап был правильно проверен и верифицирован.
   - Учтите связи между функциональностями (например, способ передачи матрицы) и эффективность кода (не создавайте ненужные копии и т.д.).

## Тестирование

Для проверки функциональности программы необходимо написать дополнительные модули в рамках того же программного обеспечения (или в отдельной программе), предназначенные для тестирования. Модули для тестирования должны использовать соответствующие функции из модулей решения, которые тестируются. Для каждой тестируемой функции модуль тестирования проверяет, соответствует ли ее поведение ожидаемому, и таким образом сигнализирует, прошел ли тестовый случай или нет.

Для тестирования не достаточно использовать только тестовые случаи, которые, вероятно, будут успешными. Необходимо также тестировать работу программы с граничными случаями, в которых функциональность программы под вопросом, чтобы тесты имели больший смысл.

1. **Модуль тестирования загрузки и вывода**
    - Тест случаев удачной загрузки и сохранения головоломки.
    - Тестирование на граничных случаях и пустых головоломках.
    - Проверка правильности обработки идентификаторов для незаполненных полей.

2. **Модуль тестирования проверки корректности ввода игрока**
    - Тестирование правильного решения головоломки.
    - Тестирование наличия ошибок в решении.
    - Тестирование на граничных случаях и случаях, где правила игры нарушены.

3. **Модуль тестирования алгоритмов решения головоломки**
    - Тестирование правильного решения головоломки.
    - Тестирование на граничных случаях и случаях, когда головоломка не имеет решения.

4. **Модуль тестирования генерации установки головоломки**
    - Тестирование правильной генерации установки головоломки.
    - Тестирование на граничных случаях и случаях, когда генерация не удается.

5. **Примечания**
    - С целью более качественной проверки работы программы используйте больше тестовых файлов с разными числами.

## Стиль написания кода

- В каждом заголовке и модуле с исходным кодом (разделять заголовки и файлы с исходным кодом) добавьте краткое описание функциональности, информацию об авторах и дату и автора последнего изменения.
- Прокомментируйте наиболее важные свободные функции, члены функций и атрибуты классов. Для функций предоставьте краткое описание функциональности, список входных аргументов и возвращаемое значение.
- Обратите внимание на отступы строк и форматирование кода, на стиль и формат именования переменных и функций, а также на длины строк.
- Код должен быть чистым, читаемым и содержать полезные комментарии.

# Извещение

Требуется предоставить следующее:
- Титульную страницу с информацией об авторе.
- Описание и/или анализ:
  - Работы ввода/вывода (загрузка и сохранение/чтение).
  - Список всех классов, исключений и свободных функций.
  - Объяснение наиболее важных атрибутов, классов и функций-членов, свободных функций и исключений.
  - Структуры аргументов командной строки и пример использования.
  - Структуры входных и выходных файлов.
  - Описание алгоритма решения головоломки.
  - Описание метода тестирования.
  - Выявленные проблемы и ограничения.
- Пример структуры хорошей документации предоставлен в проекте (имейте в виду, что необходимо адаптировать названия глав и их содержание).

# Инструкция по предоставлению проекта

Проект должен быть заархивирован и назван следующим образом:
Index_Name_LastName.zip
(например: SW123_Peter_Petrov.zip)
- Архив поместите на CANVAS в предусмотренный срок, указанный в уведомлении на платформе CANVAS.
- Архив должен содержать следующие каталоги:
  - Code – файлы с исходным кодом (.cpp и .h/.hpp) и проектные файлы (.sln, vcxproj и filters).
  - Tests – все тестовые файлы.
  - Documentation – проектную документацию Izvestaj.pdf.

