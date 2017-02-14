make

for element in conflicting functions nesting previously undeclared void; do 
	./scc < examples/$element.c > stdout/$element.out 2> tests/$element.err
	if [$(diff "examples/$element.err" "tests/$element.err") == ""]
	then
		echo "Success on $element"
	else
		echo "Failure on $element"
	fi 
done
