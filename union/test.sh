#!/bin/bash

[ -z $1 ] && { echo "Usage: ./test.sh [file.c]"; exit 1; }

echo "Checking union..."

clang -Wall -Wextra -Werror "$1" -o union

good=0

[ $(./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e) = 'zpadintoqefwjy$' ] && { echo "OK"; good=$(( $good + 1 )); } || echo "KO"
[ $(./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e) = 'df6vewg4thras$' ] && { echo "OK"; good=$(( $good + 1 )); } || echo "KO"
[ "$(./union rien 'cette phrase ne cache rien' | cat -e)" = 'rienct phas$' ] && { echo "OK"; good=$(( $good + 1 )); } || echo "KO"
[ $(./union | cat -e) = '$' ] && { echo "OK"; good=$(( $good + 1 )); } || echo "KO"
[ $(./union "rien" | cat -e) = '$' ] && { echo "OK"; good=$(( $good + 1 )); } || echo "KO"

echo "${good} / 5 tests passed"

rm -f union

[[ $good -eq 5 ]] && exit 0 || exit 1
