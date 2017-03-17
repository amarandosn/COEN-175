#!/bin/bash
make clean all

echo ---------calc.c------------
./scc < examples/calc.c > examples/calc.s
gcc -m32 examples/calc.s
./a.out < examples/calc.in

echo ---------fib.c------------
./scc < examples/fib.c > examples/global.s
gcc -m32 examples/fib.s
./a.out < examples/fib.in

echo ---------global.c------------
./scc < examples/global.c > examples/global.s
gcc -m32 examples/global.s
./a.out < examples/global.in

echo ---------hello.c------------
./scc < examples/hello.c > examples/hello.s
gcc -m32 examples/hello.s
./a.out < examples/hello.in

echo ---------int.c------------
./scc < examples/int.c > examples/int.s
gcc -m32 examples/int.s
./a.out < examples/int.in

echo ---------matrix.c------------
./scc < examples/matrix.c > examples/matrix.s
gcc -m32 examples/matrix.s
./a.out < examples/matrix.in

echo ---------qsort.c------------
./scc < examples/qsort.c > examples/qsort.s
gcc -m32 examples/qsort.s
./a.out < examples/qsort.in

echo ---------tree.c------------
./scc < examples/tree.c > examples/tree.s
gcc -m32 examples/tree.s
./a.out < examples/tree.in




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