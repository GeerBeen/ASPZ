TESTS=("0.c" "1.c" "2.c" "3.c" "5.c" "6.c" "8.c" "9.c" "13.c")

mkdir -p reports

for test in "${TESTS[@]}"; do
    echo "Current test: $test"
    
    if [ ! -f "$test" ]; then
        echo "$test not found"
        continue
    fi
    
    gcc -g -o program "$test"
    if [ $? -ne 0 ]; then
        echo "Compilation failed for $test"
        continue
    fi
    
    test_name=$(basename "$test" .c)
    valgrind --leak-check=full --track-origins=yes --read-var-info=yes ./program > "reports/$test_name.txt" 2>&1
    
    echo "Report saved reports/$test_name"
done

echo "End"