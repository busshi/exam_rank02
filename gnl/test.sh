#!/bin/bash

echo -e "\nChecking get_next_line..."

clang -Wall -Werror -Wextra get_next_line.c main.c -o get_next_line

./get_next_line < get_next_line.c > gnl
cat -e gnl > gnl_output
cat -e < get_next_line.c > cat_output
check=$(diff -y --suppress-common-line gnl_output cat_output > diff)
res=$(cat diff | wc -l)
ko=0
[[ $res -ne 0 ]] && { ko=$(( $ko + 1 )); echo "GNL:KO"; echo -e "DIFF\tGNL vs cat:\n\n$(cat diff)"; } || { echo "GNL: OK"; rm -rf gnl gnl_output cat_output get_next_line diff; }

[[ $ko -eq 0 ]] && exit 0 || exit 1
