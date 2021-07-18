#!/bin/bash

echo -e "\nChecking ft_printf..."

clang -Wall -Wextra -Werror ft_printf.c main_ptys.c ptys.c -o printf

ko=0

./printf
[[ $? -ne 0 ]] && { ko=$(( $ko + 1)); echo "ft_printf: KO"; } || echo "ft_printf: OK"

rm -rf printf logs

[[ $ko -eq 0 ]] && exit 0 || exit 1
