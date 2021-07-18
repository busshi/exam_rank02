#!/bin/bash

[ -z $1 ] && { echo "Usage: bash test.sh [file.c]"; exit 1; }

clang -Wall -Wextra -Werror "$1" -o inter

good=0

[ $(./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e) = 'padinto$' ] && { echo "OK"; good=$(( $good + 1 )); } || echo "KO"
[ $(./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e) = 'df6ewg4$' ] && { echo "OK"; good=$(( $good + 1 )); } || echo "KO"
[ $(./inter "rien" "cette phrase ne cache rien" | cat -e) = 'rien$' ] && { echo "OK"; good=$(( $good + 1 )); } || echo "KO"
[ $(./inter | cat -e) = '$' ] && { echo "OK"; good=$(( $good + 1 )); } || echo "KO"

echo "${good} / 4 tests passed"

rm -rf inter

[[ $good -eq 4 ]] && exit 0 || exit 1
