# coc-project-sudoku-grid-validator
Checks if the 9x9 sudoku grid has a valid solution

function:
1. check_rows() -> checks every row of sudoku to find duplicating values and return 0 or 1 based on result
2. check_cols() -> same as check_rows() but for columns
3. check_Duplicate() -> check for duplicate values in an array of 9 values
4. getSubgrid() -> extracts a 3x3 subgrid from 9x9 2d array and decays it into 1d array of 9 values
5. check_subgrid() -> checks if the 3x3 have all distinct values from 1 to 9

6. main() -> has a solved sudoku solution stored in 2d array of 9x9 and if statement to give the final verdict of Solution


# Concepts Used
1. loops -> iterating over arrays
2. function -> for reusabiltiy of code and seperatic complex logic
3. pointers -> passing array is argumrent to the functions

No specific maths concept were used

# How to compile
gcc sudokuGridValidator.c -o sudokuGridValidator

# How to run
gcc sudokuGridValidator.c -o sudokuGridValidator<br>
./sudokuGridValidator
<img width="620" height="87" alt="image" src="https://github.com/user-attachments/assets/55b9ae10-409d-41b3-8966-f9b35db6ac2d" />








