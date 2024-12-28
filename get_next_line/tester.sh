#!/bin/bash

# Directory for test files
TEST_DIR="./test_files"
mkdir -p $TEST_DIR

# Path to your compiled get_next_line program
GNL_PROGRAM="./get_next_line.h.gch"  # Replace with your actual program name

# Array of test cases
declare -a TEST_CASES=(
    "Hello, World!\nThis is a test file.\nEnd of the file."
    ""
    "Single line without newline at the end"
    "Line 1\n\nLine 3\n\n"
    "$(head -c 10000 < /dev/zero | tr '\0' 'A')"  # Long single line
    "A\nB\nC"                                    # Multiple short lines
    "\n\n\n"                                     # Only newlines
    "Short\nThis is a medium-length line.\nThis is an extremely long line that should also work with the buffer size being properly handled."
    "Last line has no newline"
    "Line with special characters: ~!@#$%^&*()_+{}|:\"<>?`-=[]\\;',./"
)

# Expected outputs for some of the cases (manual verification recommended for complex ones)
declare -a EXPECTED_OUTPUTS=(
    "Hello, World!\nThis is a test file.\nEnd of the file."
    ""
    "Single line without newline at the end"
    "Line 1\n\nLine 3\n\n"
    "$(head -c 10000 < /dev/zero | tr '\0' 'A')"
    "A\nB\nC"
    "\n\n\n"
    "Short\nThis is a medium-length line.\nThis is an extremely long line that should also work with the buffer size being properly handled."
    "Last line has no newline"
    "Line with special characters: ~!@#$%^&*()_+{}|:\"<>?`-=[]\\;',./"
)

# Create test files
echo "Creating test files..."
for i in "${!TEST_CASES[@]}"; do
    echo -e "${TEST_CASES[$i]}" > "${TEST_DIR}/test_${i}.txt"
done
echo "Test files created."

# Run tests
echo "Running tests..."
for i in "${!TEST_CASES[@]}"; do
    INPUT_FILE="${TEST_DIR}/test_${i}.txt"
    EXPECTED="${EXPECTED_OUTPUTS[$i]}"
    echo "Test case $i: ${INPUT_FILE}"

    # Run the program and capture output
    OUTPUT=$($GNL_PROGRAM < $INPUT_FILE)

    # Compare output with expected
    if [ "$OUTPUT" == "$EXPECTED" ]; then
        echo "Test $i PASSED!"
    else
        echo "Test $i FAILED!"
        echo "Expected:"
        echo -e "$EXPECTED"
        echo "Got:"
        echo -e "$OUTPUT"
    fi
done

echo "Testing complete."
