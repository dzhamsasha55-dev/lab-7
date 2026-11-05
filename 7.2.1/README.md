# Завдання 7.2.1

Джамалов Олександр, РІ-11, варіант 7.

C++17.

```sh
clang++ -std=c++17 -Wall -Wextra -Werror main.cpp -o lab
./lab
clang++ -std=c++17 -Wall -Wextra -Werror -fsanitize=address,undefined tests.cpp -o tests
./tests
```

Або CMake: `cmake -S . -B build`, `cmake --build build`, `ctest --test-dir build --output-on-failure`. Не вимикайте assert параметром NDEBUG під час тестування.

Фактичні результати запуску: main_output.txt і tests_output.txt.
