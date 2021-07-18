#!/bin/bash

echo -e "\nChecking ft_printf..."

clang -Wall -Werror -Wextra ft_printf.c main_checker.c -o ft_printf
[[ $? -ne 0 ]] && exit 1

./ft_printf > ft
cat -e ft > ft_printf_output
clang -Wall -Werror -Wextra -D PRINTF main_checker.c -o printf

./printf | cat -e > printf_output
diff -y --suppress-common-lines ft_printf_output printf_output
[[ $? -eq 0 ]] && { echo "ft_printf: OK"; ok=0; } || { echo "ft_printf: KO"; ok=1; }


rm -rf ft ft_printf_output printf_output ft_printf printf

exit $ok
