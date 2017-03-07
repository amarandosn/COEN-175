#!/bin/bash
make
./scc < examples/expr.c > expr.out
diff examples/expr.err expr.out
echo finished expr.c
./scc < examples/stmt.c > stmt.out
diff examples/stmt.err stmt.out
echo finished stmt.c
./scc < examples/void.c > void.out
diff examples/void.err void.out
echo finished void.c
./scc < examples/tree.c > tree.out
diff examples/tree.err tree.out
echo finished tree.c
./scc < examples/expressionChecker.c > expressionChecker.out
diff examples/expressionChecker.err expressionChecker.out
echo finished expressionChecker.c
./scc < examples/manny.c > manny.out
diff examples/manny.err manny.out
echo finished manny.c

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

#./scc < examples/expr.c > expr.err
#./scc < examples/stmt.c > stmt.err
#./scc < examples/void.c > void.err
#./scc < examples/tree.c > tree.err
#./scc < examples/manny.c > manny.err
#./scc < examples/expressionChecker.c > expressionChecker.err