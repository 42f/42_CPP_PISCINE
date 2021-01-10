# 42_CPP_PISCINE

## CPP01 Eval

|Exercice|Command|
|:-------:|-------|
ex00|`clang++ -Werror -Wall -Wextra -std=c++98 *.cpp  && ./a.out`
ex01|`clang++ -Werror -Wall -Wextra -std=c++98 *.cpp  && valgrind ./a.out`
ex02 ~ ex06|`clang++ -Werror -Wall -Wextra -std=c++98 *.cpp  && ./a.out`
ex07|`make f`
ex08|`clang++ -Werror -Wall -Wextra -std=c++98 *.cpp  && ./a.out`
ex09|`clang++ -Werror -Wall -Wextra -std=c++98 *.cpp  && ./a.out && cat ./file.log`
ex10|`clang++ -Werror -Wall -Wextra -std=c++98 *.cpp  && echo -e "From pipe :\n" ; echo "coucou" \| ./a.out && echo -e "\nFrom file :\n" ; ./a.out file && echo -e "\nFrom stdin :\n" ; ./a.out`
