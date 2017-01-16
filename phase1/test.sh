#!/bin/bash
g++ lexer.cpp
./a.out < examples/fib.c > fib.txt
diff examples/fib.out fib.txt
./a.out < examples/hello.c > hello.txt
diff examples/hello.out hello.txt
./a.out < examples/list.c > list.txt
diff examples/list.out list.txt
./a.out < examples/malloc.c > malloc.txt
diff examples/malloc.out malloc.txt
./a.out < examples/sum.c > sum.txt
diff examples/sum.out sum.txt
./a.out < examples/tricky.c > tricky.txt
diff examples/tricky.out tricky.txt

./a.out < tests/test00.c > test00.txt
diff tests/test00.out test00.txt
./a.out < tests/test01.c > test01.txt
diff tests/test01.out test01.txt
./a.out < tests/test02.c > test02.txt
diff tests/test02.out test02.txt
./a.out < tests/test03.c > test03.txt
diff tests/test03.out test03.txt
./a.out < tests/test04.c > test04.txt
diff tests/test04.out test04.txt
./a.out < tests/test05.c > test05.txt
diff tests/test05.out test05.txt
./a.out < tests/test06.c > test06.txt
diff tests/test06.out test06.txt
./a.out < tests/test07.c > test07.txt
diff tests/test07.out test07.txt
./a.out < tests/test08.c > test08.txt
diff tests/test08.out test08.txt
./a.out < tests/test09.c > test09.txt
diff tests/test09.out test09.txt

echo finished