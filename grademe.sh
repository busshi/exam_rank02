#!/bin/bash

check()
{
[[ $? -ne 0 ]] && ok=$(( $ok + 1 ))
}


ok=0


cd union && /bin/bash test.sh union.c ; check
cd ../inter && /bin/bash test.sh inter.c ; check
cd ../gnl && /bin/bash test.sh ; check
cd ../printf && /bin/bash test.sh ; check

[[ $ok -eq 0 ]] && exit 0 || exit 1
