#!/bin/bash
g++ lexer.cpp parser.cpp
./scc < examples1/fib.c > fib.txt
diff examples1/fib.out fib.txt
echo passed fib.c
./scc < examples1/hello.c > hello.txt
diff examples1/hello.out hello.txt
echo passed hello.c
./scc < examples1/array.c > array.txt
diff examples1/array.out array.txt
echo passed array.c
./scc < examples1/malloc.c > malloc.txt
diff examples1/malloc.out malloc.txt
echo passed malloc.c
./scc < examples1/sum.c > sum.txt
diff examples1/sum.out sum.txt
echo passed sum.c
./scc < examples1/params.c > params.txt
diff examples1/params.out params.txt

echo passed params.c
#./scc < tests/test00.c > test00.txt
#diff tests/test00.out test00.txt
#./scc < tests/test01.c > test01.txt
#diff tests/test01.out test01.txt
#./scc < tests/test02.c > test02.txt
#diff tests/test02.out test02.txt
#./scc < tests/test03.c > test03.txt
#diff tests/test03.out test03.txt
#./scc < tests/test04.c > test04.txt
#diff tests/test04.out test04.txt
#./scc < tests/test05.c > test05.txt
#diff tests/test05.out test05.txt
#./scc < tests/test06.c > test06.txt
#diff tests/test06.out test06.txt
#./scc < tests/test07.c > test07.txt
#diff tests/test07.out test07.txt
#./scc < tests/test08.c > test08.txt
#diff tests/test08.out test08.txt
#./scc < tests/test09.c > test09.txt
#diff tests/test09.out test09.txt

echo finished