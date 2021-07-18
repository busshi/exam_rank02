#!/bin/bash

echo -e "\nChecking get_next_line..."

clang -Wall -Werror -Wextra get_next_line.c main.c -o get_next_line

./get_next_line < get_next_line.c > yours_.res
cat -e yours_.res > yours.res
cat -e < get_next_line.c > original.res
diff -y --suppress-common-line original.res yours.res
ko=0
[[ $? -ne 0 ]] && ko=$(( $ko + 1 )) || echo "GNL: OK"

rm -rf original.res yours_.res yours.res get_next_line

[[ $ko -eq 0 ]] && exit 0 || exit 1
