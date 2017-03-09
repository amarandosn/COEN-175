#!/bin/bash
make clean all

echo ---------array.c------------
./scc < examples/array.c > array.s
gcc -m32 array.s examples/array-lib.c
./a.out

echo ---------global.c------------
./scc < examples/global.c > global.s
gcc -m32 global.s examples/global-lib.c
./a.out

echo ---------local.c------------
./scc < examples/local.c > local.s
gcc -m32 local.s examples/local-lib.c
./a.out

echo ---------putchar.c------------
./scc < examples/putchar.c > putchar.s
gcc -m32 putchar.s 
./a.out

echo ---------towers.c------------
./scc < examples/towers.c > towers.s
gcc -m32 towers.s examples/towers-lib.c
./a.out


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

echo ---------------finished-----------------

#./scc < examples/expr.c > expr.err
#./scc < examples/stmt.c > stmt.err
#./scc < examples/void.c > void.err
#./scc < examples/tree.c > tree.err
#./scc < examples/manny.c > manny.err
#./scc < examples/expressionChecker.c > expressionChecker.err