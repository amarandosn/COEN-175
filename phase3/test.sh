#!/bin/bash
make
./scc < examples/conflicting.c > conflicting.txt
diff examples/conflicting.err conflicting.txt
echo passed conflicting.c
./scc < examples/functions.c > functions.txt
diff examples/functions.err functions.txt
echo passed functions.c
./scc < examples/nesting.c > nesting.txt
diff examples/nesting.err nesting.txt
echo passed nesting.c
./scc < examples/previously.c > previously.txt
diff examples/previously.err previously.txt
echo passed previously.c
./scc < examples/undeclared.c > undeclared.txt
diff examples/undeclared.err undeclared.txt
echo passed undeclared.c
./scc < examples/void.c > void.txt
diff examples/void.err void.txt
echo passed void.c
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