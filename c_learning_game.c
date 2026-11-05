#include <stdio.h>

static int read_char(char *value) {
    int ch;

    if (scanf(" %c", value) != 1) {
        return 0;
    }

    while ((ch = getchar()) != '\n' && ch != EOF) {
    }

    return 1;
}

int main() {
    int i, j, num, score, mode, level, lv, first, total, next;
    char choice, levelKey, answer;

    int passMark  = 6;
    int unlockAll = 0;

    int unlocked[4] = {1, 1, 1, 1};
    int bestScore[20] = {0, 0, 0, 0, 0,
                         0, 0, 0, 0, 0,
                         0, 0, 0, 0, 0,
                         0, 0, 0, 0, 0};

    char digits[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    char right[200] = {
         '4', '1', '1', '3', '4', '3', '3', '1', '2', '3',
         '2', '3', '1', '4', '4', '1', '1', '4', '3', '2',
         '3', '1', '1', '1', '2', '2', '4', '2', '1', '1',
         '2', '1', '4', '3', '3', '2', '1', '2', '4', '4',
         '3', '1', '3', '2', '2', '3', '3', '2', '2', '4',
         '4', '4', '1', '2', '2', '2', '1', '2', '4', '4',
         '4', '2', '2', '2', '3', '1', '3', '3', '1', '1',
         '3', '2', '3', '3', '1', '2', '4', '2', '4', '1',
         '2', '4', '3', '4', '4', '2', '2', '2', '4', '3',
         '4', '3', '1', '4', '1', '2', '1', '1', '4', '4',
         '3', '1', '2', '2', '2', '3', '2', '4', '4', '2',
         '2', '3', '1', '2', '3', '2', '4', '3', '3', '1',
         '3', '4', '1', '2', '2', '1', '4', '4', '3', '2',
         '1', '2', '3', '3', '2', '3', '4', '3', '3', '4',
         '2', '3', '2', '2', '3', '2', '4', '3', '4', '3',
         '2', '1', '4', '2', '4', '4', '1', '4', '1', '3',
         '3', '4', '3', '4', '1', '3', '2', '1', '4', '2',
         '2', '1', '1', '3', '1', '1', '3', '2', '1', '4',
         '4', '3', '4', '2', '2', '4', '1', '3', '1', '2',
         '3', '1', '2', '2', '3', '4', '2', '2', '3', '3'
    };

    if (unlockAll == 1) {
        for (i = 0; i < 4; i++) {
            unlocked[i] = 5;
        }
    }

    for (choice = '0'; choice != 'x' && choice != 'X'; ) {
        printf("\n==========================================\n");
        printf("       C Quest: Learn & Play\n");
        printf("==========================================\n");
        printf(" LEARN\n");
        printf("  1. Data Types & Variables\n");
        printf("  2. Operators\n");
        printf("  3. if-else\n");
        printf("  4. Loops\n");
        printf("  5. Arrays\n");
        printf(" PLAY  (5 levels in every mode)\n");
        printf("  6. Classic Quiz\n");
        printf("  7. Guess the Output\n");
        printf("  8. Bug Hunter\n");
        printf("  9. Fill in the Blank\n");
        printf(" OTHER\n");
        printf("  p. My Progress\n");
        printf("  x. Exit\n");
        printf("------------------------------------------\n");
        printf("Enter your choice (1-9, p, x): ");

        if (!read_char(&choice)) {
            break;
        }

        num = -1;
        for (j = 0; j < 10; j++) {
            if (choice == digits[j]) {
                num = j;
            }
        }

        if (num == 1) {
            printf("===== LESSON 1: DATA TYPES & VARIABLES =====\n");
            printf("A variable is a named box in memory that stores a value.\n");
            printf("A data type tells C WHAT KIND of value the box can hold.\n");
            printf("\n");
            printf("  Type     Stores             Size     Example      Format\n");
            printf("  int      whole numbers      4 bytes  25, -7       %%d\n");
            printf("  float    decimal numbers    4 bytes  3.14         %%f\n");
            printf("  double   bigger decimals    8 bytes  3.14159265   %%lf\n");
            printf("  char     one character      1 byte   'A', '7'     %%c\n");
            printf("\n");
            printf("Declare a variable and give it a value:\n");
            printf("  int age = 20;           // declare + initialize\n");
            printf("  float price = 99.5;\n");
            printf("  char grade = 'A';       // single quotes for a char\n");
            printf("  const int MAX = 100;    // const = the value can never change\n");
            printf("\n");
            printf("Rules for variable names:\n");
            printf("  - letters, digits and underscore (_) only, no spaces\n");
            printf("  - cannot start with a digit   (2num is wrong, num2 is right)\n");
            printf("  - cannot be a keyword (int, for, if, return ...)\n");
            printf("  - C is case-sensitive: Age and age are different variables\n");
            printf("\n");
            printf("Printing and reading (needs  #include <stdio.h>):\n");
            printf("  printf(\"%%d\", age);     // print an int\n");
            printf("  printf(\"%%f\", price);   // prints 99.500000 (6 decimals)\n");
            printf("  printf(\"Hi\\n\");        // \\n = new line,  \\t = tab\n");
            printf("  scanf(\"%%d\", &age);     // read an int  (do not forget the & !)\n");
            printf("\n");
            printf("Good to know:\n");
            printf("  - A statement ends with ;      A comment starts with //\n");
            printf("  - main() ends with  return 0;  (0 = finished without errors)\n");
            printf("  - A char is really a small number (ASCII): 'A' is 65, 'a' is 97\n");
            printf("  - sizeof(int) gives the size in bytes (usually 4)\n");
            printf("  - int / int gives an int:   7 / 2 is 3,   but 7 / 2.0 is 3.5\n");
            printf("  - Type casting:  (int) 3.9  gives 3  (the decimal part is cut off)\n");

            printf("\nPress Enter to go back to the main menu...");
            getchar();
        }
        else if (num == 2) {
            printf("===== LESSON 2: OPERATORS =====\n");
            printf("Arithmetic operators:   +   -   *   /   %%\n");
            printf("  7 + 2 = 9      7 - 2 = 5      7 * 2 = 14\n");
            printf("  7 / 2 = 3      (int / int drops the decimal part!)\n");
            printf("  7 / 2.0 = 3.5  (one decimal number makes the answer decimal)\n");
            printf("  7 %% 2 = 1      (%% = remainder, works with whole numbers)\n");
            printf("\n");
            printf("Relational operators (the answer is 1 = true or 0 = false):\n");
            printf("  ==  equal      !=  not equal\n");
            printf("  >   greater    <   less      >=  greater or equal     <=  less or equal\n");
            printf("  They are checked from left to right:\n");
            printf("  10 > 5 > 2  means  (10 > 5) > 2  =  1 > 2  =  0\n");
            printf("\n");
            printf("Logical operators:\n");
            printf("  &&  AND   both sides must be true     if (age > 18 && age < 60)\n");
            printf("  ||  OR    at least one side is true   if (x == 1 || x == 2)\n");
            printf("  !   NOT   reverses true and false     if (!(x > 5))\n");
            printf("\n");
            printf("Assignment operators:\n");
            printf("  =   stores a value:          x = 5;\n");
            printf("  +=  x += 5;  means  x = x + 5;       (also -=  *=  /=  %%=)\n");
            printf("\n");
            printf("Increment and decrement:\n");
            printf("  i++  or  ++i   adds 1          i--  or  --i   subtracts 1\n");
            printf("  a = 5;  b = a++;   ->  b = 5, a = 6   (use the OLD value, then add)\n");
            printf("  a = 5;  b = ++a;   ->  b = 6, a = 6   (add FIRST, then use)\n");
            printf("\n");
            printf("Order of work (precedence):\n");
            printf("  1) ( )     2) * / %%  (left to right)     3) + -\n");
            printf("  2 + 3 * 4 = 14        (2 + 3) * 4 = 20        7 / 2 * 2 = 6\n");
            printf("\n");
            printf("Truth in C:  0 is FALSE, every other value is TRUE.\n");
            printf("Common bug:  =  assigns a value,   ==  compares two values.\n");

            printf("\nPress Enter to go back to the main menu...");
            getchar();
        }
        else if (num == 3) {
            printf("===== LESSON 3: if-else =====\n");
            printf("if-else lets your program make decisions.\n");
            printf("\n");
            printf("Syntax:\n");
            printf("  if (condition) {\n");
            printf("      // runs when the condition is true\n");
            printf("  } else if (another condition) {\n");
            printf("      // runs when the first is false and this one is true\n");
            printf("  } else {\n");
            printf("      // runs when all the conditions above are false\n");
            printf("  }\n");
            printf("\n");
            printf("How it works:\n");
            printf("  - conditions are checked from top to bottom, only ONE block runs\n");
            printf("  - else if and else are optional\n");
            printf("  - 0 is false, anything else is true, so  if (x)  means  if (x != 0)\n");
            printf("\n");
            printf("Example 1 - even or odd:\n");
            printf("  if (n %% 2 == 0) printf(\"Even\");\n");
            printf("  else            printf(\"Odd\");\n");
            printf("\n");
            printf("Example 2 - grade ladder (marks = 75):\n");
            printf("  if (marks >= 80)      printf(\"A+\");\n");
            printf("  else if (marks >= 70) printf(\"A\");\n");
            printf("  else if (marks >= 60) printf(\"B\");\n");
            printf("  else                  printf(\"Fail\");       -> prints A\n");
            printf("\n");
            printf("Example 3 - nested if (an if inside an if):\n");
            printf("  if (x > 10) {\n");
            printf("      if (x > 15) printf(\"Very big\");\n");
            printf("      else        printf(\"Big\");\n");
            printf("  }\n");
            printf("\n");
            printf("Example 4 - largest of three numbers:\n");
            printf("  if (a > b && a > c)      printf(\"%%d\", a);\n");
            printf("  else if (b > a && b > c) printf(\"%%d\", b);\n");
            printf("  else                     printf(\"%%d\", c);\n");
            printf("\n");
            printf("Common mistakes:\n");
            printf("  if (x = 5)     -> assigns 5! Use == to compare\n");
            printf("  if (x > 5);    -> the ; ends the if, the next line ALWAYS runs\n");
            printf("  if x > 5       -> the condition must be inside brackets ( )\n");
            printf("  else (x > 3)   -> else has no condition, write  else if (x > 3)\n");
            printf("  two statements without { }  -> only the first one belongs to the if\n");

            printf("\nPress Enter to go back to the main menu...");
            getchar();
        }
        else if (num == 4) {
            printf("===== LESSON 4: LOOPS =====\n");
            printf("Loops repeat code, so you do not write it again and again.\n");
            printf("\n");
            printf("1) for loop - best when you know how many times\n");
            printf("     for (initialization; condition; update) { body }\n");
            printf("     for (i = 1; i <= 3; i++) printf(\"%%d \", i);      -> 1 2 3\n");
            printf("   Order: initialization (once), check condition, body, update, check ...\n");
            printf("\n");
            printf("2) while loop - checks the condition FIRST (good when repeats are unknown)\n");
            printf("     i = 1;\n");
            printf("     while (i <= 3) { printf(\"%%d \", i); i++; }       -> 1 2 3\n");
            printf("\n");
            printf("3) do-while loop - runs the body at least ONCE, checks afterwards\n");
            printf("     i = 1;\n");
            printf("     do { printf(\"%%d \", i); i++; } while (i <= 3);   <- note the ; at the end\n");
            printf("\n");
            printf("break     -> leaves the loop immediately\n");
            printf("continue  -> skips the rest of this round and goes to the next round\n");
            printf("\n");
            printf("Nested loops (a loop inside a loop):\n");
            printf("  The inner loop runs completely for EVERY round of the outer loop.\n");
            printf("  for (i = 1; i <= 3; i++) {          // 3 outer rounds\n");
            printf("      for (j = 1; j <= i; j++)        // inner: 1, then 2, then 3 times\n");
            printf("          printf(\"*\");\n");
            printf("      printf(\"\\n\");                   // prints a triangle:  *  **  ***\n");
            printf("  }\n");
            printf("  break inside the inner loop stops ONLY the inner loop.\n");
            printf("\n");
            printf("Useful patterns:\n");
            printf("  sum of 1 to n:    sum = 0;   then  sum = sum + i;   in a loop\n");
            printf("  factorial:        fact = 1;  then  fact = fact * i; in a loop\n");
            printf("  last digit:       n %% 10          remove last digit:  n / 10\n");
            printf("  count digits:     while (n != 0) { n = n / 10; count++; }\n");
            printf("  even number:      i %% 2 == 0\n");
            printf("  prime check:      if n %% i == 0 for any i from 2 to n-1, n is NOT prime\n");
            printf("  counting down:    for (i = 5; i >= 1; i--)\n");
            printf("\n");
            printf("Common mistakes:\n");
            printf("  - forgetting i++ makes an infinite loop\n");
            printf("  - a ; right after for(...) or while(...) makes an empty loop\n");
            printf("  - off by one:  i < 5 starting from 0 runs 5 times, i <= 5 runs 6 times\n");

            printf("\nPress Enter to go back to the main menu...");
            getchar();
        }
        else if (num == 5) {
            printf("===== LESSON 5: ARRAYS =====\n");
            printf("An array stores many values of the SAME type under one name.\n");
            printf("  datatype name[size];          example:  int marks[5];\n");
            printf("\n");
            printf("Initialize:\n");
            printf("  int a[5] = {10, 20, 30, 40, 50};\n");
            printf("  int b[5] = {1, 2};            -> the rest become 0:  1 2 0 0 0\n");
            printf("\n");
            printf("The index is the position, and it starts at 0!\n");
            printf("  size 5 -> indexes 0, 1, 2, 3, 4\n");
            printf("  a[0] is 10 (first)    a[4] is 50 (last)\n");
            printf("  a[5] is OUT OF BOUNDS (a bug!)\n");
            printf("  a[1] = 99;            changes the second element\n");
            printf("\n");
            printf("Visit every element with a loop:\n");
            printf("  for (i = 0; i < 5; i++) printf(\"%%d \", a[i]);\n");
            printf("\n");
            printf("Classic array patterns:\n");
            printf("  sum:       sum = sum + a[i];             average:  sum / 5.0\n");
            printf("  largest:   max = a[0];  if (a[i] > max) max = a[i];\n");
            printf("  smallest:  min = a[0];  if (a[i] < min) min = a[i];\n");
            printf("  search:    if (a[i] == key) { found = 1; break; }\n");
            printf("  count:     if (a[i] > 5) count++;\n");
            printf("  swap:      t = a; a = b; b = t;          (needs a temporary variable)\n");
            printf("  reverse:   swap a[i] and a[n - 1 - i] for only HALF of the array\n");
            printf("  bubble sort: if (a[j] > a[j + 1]) swap them, repeat the passes\n");
            printf("\n");
            printf("You cannot copy an array with  b = a;   copy it with a loop:\n");
            printf("  for (i = 0; i < 3; i++) b[i] = a[i];\n");

            printf("\nPress Enter to go back to the main menu...");
            getchar();
        }

        else if (num >= 6 && num <= 9) {
            mode = num - 6;

            for (levelKey = '9'; levelKey != '0'; ) {

                printf("\n===== ");
                if (mode == 0) printf("CLASSIC QUIZ");
                else if (mode == 1) printf("GUESS THE OUTPUT");
                else if (mode == 2) printf("BUG HUNTER");
                else if (mode == 3) printf("FILL IN THE BLANK");
                printf(" =====\n");
                if (mode == 0) printf("Answer questions about C concepts.\n");
                else if (mode == 1) printf("Read the code carefully and find what it will print.\n");
                else if (mode == 2) printf("Each code has ONE bug. Find the line that has the mistake.\n");
                else if (mode == 3) printf("Choose the option that completes the code correctly.\n");
                printf("\n");

                for (lv = 0; lv < 5; lv++) {
                    printf("  %d. ", lv + 1);
                    if (lv == 0) printf("EASY        ");
                    else if (lv == 1) printf("PRO         ");
                    else if (lv == 2) printf("ULTRA-PRO   ");
                    else if (lv == 3) printf("LEGENDARY   ");
                    else if (lv == 4) printf("GRANDMASTER ");
                    if (lv < unlocked[mode]) {
                        printf("  best: %d/10\n", bestScore[mode * 5 + lv]);
                    } else {
                        printf("  [LOCKED]\n");
                    }
                }
                printf("  0. Back to main menu\n");
                printf("Choose a level (0-5): ");

                if (!read_char(&levelKey)) {
                    return 0;
                }

                level = -1;
                for (j = 0; j < 10; j++) {
                    if (levelKey == digits[j]) {
                        level = j;
                    }
                }

                if (level >= 1 && level <= 5) {

                    if (level > unlocked[mode]) {
                        printf("\nThis level is LOCKED. Score at least %d/10 in the level before it.\n", passMark);
                    }
                    else {

                        lv = level - 1;
                        first = mode * 50 + lv * 10;
                        score = 0;

                        printf("\n===== ");
                        if (mode == 0) printf("CLASSIC QUIZ");
                        else if (mode == 1) printf("GUESS THE OUTPUT");
                        else if (mode == 2) printf("BUG HUNTER");
                        else if (mode == 3) printf("FILL IN THE BLANK");
                        printf(" - LEVEL %d: ", level);
                        if (lv == 0) printf("EASY");
                        else if (lv == 1) printf("PRO");
                        else if (lv == 2) printf("ULTRA-PRO");
                        else if (lv == 3) printf("LEGENDARY");
                        else if (lv == 4) printf("GRANDMASTER");
                        printf(" =====\n");

                        for (i = first; i < first + 10; i++) {
                            printf("\nQuestion %d of 10\n", i - first + 1);

                            if (i == 0) {
                                printf("--------------------------------\n");
                                printf("Which symbol ends most C statements?\n");
                                printf("--------------------------------\n");
                                printf("Choose the correct answer:\n");
                                printf("  1. .\n");
                                printf("  2. ,\n");
                                printf("  3. :\n");
                                printf("  4. ;\n");
                            }
                            else if (i == 1) {
                                printf("--------------------------------\n");
                                printf("Which data type stores whole numbers like 25?\n");
                                printf("--------------------------------\n");
                                printf("Choose the correct answer:\n");
                                printf("  1. int\n");
                                printf("  2. double\n");
                                printf("  3. char\n");
                                printf("  4. float\n");
                            }
                            else if (i == 2) {
                                printf("--------------------------------\n");
                                printf("Which format specifier is used to print a float?\n");
                                printf("--------------------------------\n");
                                printf("Choose the correct answer:\n");
                                printf("  1. %%f\n");
                                printf("  2. %%d\n");
                                printf("  3. %%c\n");
                                printf("  4. %%s\n");
                            }
                            else if (i == 3) {
                                printf("--------------------------------\n");
                                printf("Which data type stores a single character like 'A'?\n");
                                printf("--------------------------------\n");
                                printf("Choose the correct answer:\n");
                                printf("  1. double\n");
                                printf("  2. float\n");
                                printf("  3. char\n");
                                printf("  4. int\n");
                            }
                            else if (i == 4) {
                                printf("--------------------------------\n");
                                printf("Which one is a valid variable name?\n");
                                printf("--------------------------------\n");
                                printf("Choose the correct answer:\n");
                                printf("  1. my marks\n");
                                printf("  2. int\n");
                                printf("  3. 2marks\n");
                                printf("  4. marks_2\n");
                            }
                            else if (i == 5) {
                                printf("--------------------------------\n");
                                printf("Which function prints output on the screen?\n");
                                printf("--------------------------------\n");
                                printf("Choose the correct answer:\n");
                                printf("  1. print()\n");
                                printf("  2. scanf()\n");
                                printf("  3. printf()\n");
                                printf("  4. show()\n");
                            }
                            else if (i == 6) {
                                printf("--------------------------------\n");
                                printf("Which function reads input from the keyboard?\n");
                                printf("--------------------------------\n");
                                printf("Choose the correct answer:\n");
                                printf("  1. input()\n");
                                printf("  2. printf()\n");
                                printf("  3. scanf()\n");
                                printf("  4. read()\n");
                            }
                            else if (i == 7) {
                                printf("--------------------------------\n");
                                printf("Which header file is needed for printf() and scanf()?\n");
                                printf("--------------------------------\n");
                                printf("Choose the correct answer:\n");
                                printf("  1. <stdio.h>\n");
                                printf("  2. <string.h>\n");
                                printf("  3. <stdlib.h>\n");
                                printf("  4. <math.h>\n");
                            }
                            else if (i == 8) {
                                printf("--------------------------------\n");
                                printf("How do you write a single-line comment in C?\n");
                                printf("--------------------------------\n");
                                printf("Choose the correct answer:\n");
                                printf("  1. # comment\n");
                                printf("  2. // comment\n");
                                printf("  3. <!-- comment -->\n");
                                printf("  4. ** comment\n");
                            }
                            else if (i == 9) {
                                printf("--------------------------------\n");
                                printf("Which symbol is used for multiplication?\n");
                                printf("--------------------------------\n");
                                printf("Choose the correct answer:\n");
                                printf("  1. &\n");
                                printf("  2. x\n");
                                printf("  3. *\n");
                                printf("  4. %%\n");
                            }

                            else if (i == 10) {
                                printf("--------------------------------\n");
                                printf("What value is stored in x?\n");
                                printf("\n");
                                printf("int x = 7 / 2;\n");
                                printf("--------------------------------\n");
                                printf("Choose the correct answer:\n");
                                printf("  1. 2\n");
                                printf("  2. 3\n");
                                printf("  3. 3.5\n");
                                printf("  4. 4\n");
                            }
                            else if (i == 11) {
                                printf("--------------------------------\n");
                                printf("What is the value of  17 %% 5 ?\n");
                                printf("--------------------------------\n");
                                printf("Choose the correct answer:\n");
                                printf("  1. 3.4\n");
                                printf("  2. 3\n");
                                printf("  3. 2\n");
                                printf("  4. 12\n");
                            }
                            else if (i == 12) {
                                printf("--------------------------------\n");
                                printf("Which is the correct condition to check if x equals 5?\n");
                                printf("--------------------------------\n");
                                printf("Choose the correct answer:\n");
                                printf("  1. if (x == 5)\n");
                                printf("  2. if (x = 5)\n");
                                printf("  3. if (x := 5)\n");
                                printf("  4. if x == 5\n");
                            }
                            else if (i == 13) {
                                printf("--------------------------------\n");
                                printf("Which operator means 'not equal to'?\n");
                                printf("--------------------------------\n");
                                printf("Choose the correct answer:\n");
                                printf("  1. =/=\n");
                                printf("  2. =!\n");
                                printf("  3. <>\n");
                                printf("  4. !=\n");
                            }
                            else if (i == 14) {
                                printf("--------------------------------\n");
                                printf("What does the symbol = do in C?\n");
                                printf("--------------------------------\n");
                                printf("Choose the correct answer:\n");
                                printf("  1. Checks not equal\n");
                                printf("  2. Adds two values\n");
                                printf("  3. Compares two values\n");
                                printf("  4. Assigns a value\n");
                            }
                            else if (i == 15) {
                                printf("--------------------------------\n");
                                printf("How many bytes does a char usually take?\n");
                                printf("--------------------------------\n");
                                printf("Choose the correct answer:\n");
                                printf("  1. 1\n");
                                printf("  2. 2\n");
                                printf("  3. 4\n");
                                printf("  4. 8\n");
                            }
                            else if (i == 16) {
                                printf("--------------------------------\n");
                                printf("Which line stores the decimal value 2.5 correctly?\n");
                                printf("--------------------------------\n");
                                printf("Choose the correct answer:\n");
                                printf("  1. float x = 2.5;\n");
                                printf("  2. int x = 2.5;\n");
                                printf("  3. char x = 2.5;\n");
                                printf("  4. x float = 2.5;\n");
                            }
                            else if (i == 17) {
                                printf("--------------------------------\n");
                                printf("What does  x += 5;  mean?\n");
                                printf("--------------------------------\n");
                                printf("Choose the correct answer:\n");
                                printf("  1. x = 5\n");
                                printf("  2. x == 5\n");
                                printf("  3. x = x - 5\n");
                                printf("  4. x = x + 5\n");
                            }
                            else if (i == 18) {
                                printf("--------------------------------\n");
                                printf("Which logical operator means AND?\n");
                                printf("--------------------------------\n");
                                printf("Choose the correct answer:\n");
                                printf("  1. ==\n");
                                printf("  2. !\n");
                                printf("  3. &&\n");
                                printf("  4. ||\n");
                            }
                            else if (i == 19) {
                                printf("--------------------------------\n");
                                printf("What is the value of  2 + 3 * 4 ?\n");
                                printf("--------------------------------\n");
                                printf("Choose the correct answer:\n");
                                printf("  1. 24\n");
                                printf("  2. 14\n");
                                printf("  3. 20\n");
                                printf("  4. 9\n");
                            }

                            else if (i == 20) {
                                printf("--------------------------------\n");
                                printf("Which loop always runs its body at least once?\n");
                                printf("--------------------------------\n");
                                printf("Choose the correct answer:\n");
                                printf("  1. for loop\n");
                                printf("  2. while loop\n");
                                printf("  3. do-while loop\n");
                                printf("  4. None of them\n");
                            }
                            else if (i == 21) {
                                printf("--------------------------------\n");
                                printf("For the array  int a[5];  what are the valid indexes?\n");
                                printf("--------------------------------\n");
                                printf("Choose the correct answer:\n");
                                printf("  1. 0 to 4\n");
                                printf("  2. 1 to 5\n");
                                printf("  3. 0 to 5\n");
                                printf("  4. 1 to 4\n");
                            }
                            else if (i == 22) {
                                printf("--------------------------------\n");
                                printf("int a = 5;\n");
                                printf("int b = ++a;\n");
                                printf("\n");
                                printf("What are the values of a and b now?\n");
                                printf("--------------------------------\n");
                                printf("Choose the correct answer:\n");
                                printf("  1. a=6, b=6\n");
                                printf("  2. a=5, b=5\n");
                                printf("  3. a=5, b=6\n");
                                printf("  4. a=6, b=5\n");
                            }
                            else if (i == 23) {
                                printf("--------------------------------\n");
                                printf("Which keyword skips the rest of the current loop round and goes to the next round?\n");
                                printf("--------------------------------\n");
                                printf("Choose the correct answer:\n");
                                printf("  1. continue\n");
                                printf("  2. break\n");
                                printf("  3. next\n");
                                printf("  4. skip\n");
                            }
                            else if (i == 24) {
                                printf("--------------------------------\n");
                                printf("What does this condition check?\n");
                                printf("\n");
                                printf("if (x > 0 && x < 10)\n");
                                printf("--------------------------------\n");
                                printf("Choose the correct answer:\n");
                                printf("  1. x is bigger than 10\n");
                                printf("  2. x is between 0 and 10 (not 0 or 10)\n");
                                printf("  3. x is negative\n");
                                printf("  4. x is 0 or 10\n");
                            }
                            else if (i == 25) {
                                printf("--------------------------------\n");
                                printf("When does the else part of an if-else run?\n");
                                printf("--------------------------------\n");
                                printf("Choose the correct answer:\n");
                                printf("  1. Never\n");
                                printf("  2. When the if condition is false\n");
                                printf("  3. When the if condition is true\n");
                                printf("  4. Always\n");
                            }
                            else if (i == 26) {
                                printf("--------------------------------\n");
                                printf("What happens if you forget i++ inside  while (i <= 5)  ?\n");
                                printf("--------------------------------\n");
                                printf("Choose the correct answer:\n");
                                printf("  1. It runs 5 times\n");
                                printf("  2. It runs once\n");
                                printf("  3. The compiler gives an error\n");
                                printf("  4. It becomes an infinite loop\n");
                            }
                            else if (i == 27) {
                                printf("--------------------------------\n");
                                printf("In C, which value counts as FALSE?\n");
                                printf("--------------------------------\n");
                                printf("Choose the correct answer:\n");
                                printf("  1. Any negative number\n");
                                printf("  2. 0\n");
                                printf("  3. 1\n");
                                printf("  4. Any positive number\n");
                            }
                            else if (i == 28) {
                                printf("--------------------------------\n");
                                printf("In  for (i = 0; i < 5; i++)  which part runs before the first round?\n");
                                printf("--------------------------------\n");
                                printf("Choose the correct answer:\n");
                                printf("  1. i = 0 (initialization)\n");
                                printf("  2. i < 5 (condition)\n");
                                printf("  3. The loop body\n");
                                printf("  4. i++ (update)\n");
                            }
                            else if (i == 29) {
                                printf("--------------------------------\n");
                                printf("Which statement declares an array of 10 integers?\n");
                                printf("--------------------------------\n");
                                printf("Choose the correct answer:\n");
                                printf("  1. int a[10];\n");
                                printf("  2. int a(10);\n");
                                printf("  3. array a[10];\n");
                                printf("  4. int a{10};\n");
                            }

                            else if (i == 30) {
                                printf("--------------------------------\n");
                                printf("int a = 5;\n");
                                printf("int b = a++;\n");
                                printf("\n");
                                printf("What are the values of a and b now?\n");
                                printf("--------------------------------\n");
                                printf("Choose the correct answer:\n");
                                printf("  1. a=5, b=5\n");
                                printf("  2. a=6, b=5\n");
                                printf("  3. a=6, b=6\n");
                                printf("  4. a=5, b=6\n");
                            }
                            else if (i == 31) {
                                printf("--------------------------------\n");
                                printf("int a[5] = {1, 2};\n");
                                printf("\n");
                                printf("What is the value of a[4]?\n");
                                printf("--------------------------------\n");
                                printf("Choose the correct answer:\n");
                                printf("  1. 0\n");
                                printf("  2. Error\n");
                                printf("  3. Garbage value\n");
                                printf("  4. 2\n");
                            }
                            else if (i == 32) {
                                printf("--------------------------------\n");
                                printf("int a[3] = {1, 2, 3};\n");
                                printf("printf(\"%%d\", a[3]);\n");
                                printf("\n");
                                printf("What is wrong here?\n");
                                printf("--------------------------------\n");
                                printf("Choose the correct answer:\n");
                                printf("  1. a must be a float\n");
                                printf("  2. A semicolon is missing\n");
                                printf("  3. Nothing, it prints 3\n");
                                printf("  4. a[3] is out of bounds\n");
                            }
                            else if (i == 33) {
                                printf("--------------------------------\n");
                                printf("Which loop visits every element of  int a[6];  ?\n");
                                printf("--------------------------------\n");
                                printf("Choose the correct answer:\n");
                                printf("  1. for (i = 0; i <= 6; i++)\n");
                                printf("  2. for (i = 1; i <= 6; i++)\n");
                                printf("  3. for (i = 0; i < 6; i++)\n");
                                printf("  4. for (i = 6; i > 6; i--)\n");
                            }
                            else if (i == 34) {
                                printf("--------------------------------\n");
                                printf("How many times does the inner body run?\n");
                                printf("\n");
                                printf("for (i = 0; i < 3; i++)\n");
                                printf("  for (j = 0; j < 4; j++)\n");
                                printf("--------------------------------\n");
                                printf("Choose the correct answer:\n");
                                printf("  1. 3\n");
                                printf("  2. 7\n");
                                printf("  3. 12\n");
                                printf("  4. 4\n");
                            }
                            else if (i == 35) {
                                printf("--------------------------------\n");
                                printf("Which expression checks if a number n is even?\n");
                                printf("--------------------------------\n");
                                printf("Choose the correct answer:\n");
                                printf("  1. n * 2 == 0\n");
                                printf("  2. n %% 2 == 0\n");
                                printf("  3. n / 2 == 0\n");
                                printf("  4. n %% 2 == 1\n");
                            }
                            else if (i == 36) {
                                printf("--------------------------------\n");
                                printf("Inside nested loops, which statement stops ONLY the innermost loop?\n");
                                printf("--------------------------------\n");
                                printf("Choose the correct answer:\n");
                                printf("  1. break\n");
                                printf("  2. exit\n");
                                printf("  3. stop\n");
                                printf("  4. continue\n");
                            }
                            else if (i == 37) {
                                printf("--------------------------------\n");
                                printf("What does  scanf(\"%%d\", &age);  do?\n");
                                printf("--------------------------------\n");
                                printf("Choose the correct answer:\n");
                                printf("  1. Declares age\n");
                                printf("  2. Reads an int from the keyboard into age\n");
                                printf("  3. Adds age\n");
                                printf("  4. Prints age\n");
                            }
                            else if (i == 38) {
                                printf("--------------------------------\n");
                                printf("Why do we write & before the variable in scanf?\n");
                                printf("--------------------------------\n");
                                printf("Choose the correct answer:\n");
                                printf("  1. It makes the value bigger\n");
                                printf("  2. It means AND\n");
                                printf("  3. It is optional\n");
                                printf("  4. It tells scanf where to store the value\n");
                            }
                            else if (i == 39) {
                                printf("--------------------------------\n");
                                printf("Which loop is usually best when you do NOT know how many times to repeat?\n");
                                printf("--------------------------------\n");
                                printf("Choose the correct answer:\n");
                                printf("  1. for loop with a fixed count\n");
                                printf("  2. if-else\n");
                                printf("  3. an array\n");
                                printf("  4. while loop\n");
                            }

                            else if (i == 40) {
                                printf("--------------------------------\n");
                                printf("What does sizeof(int) usually return on a modern computer?\n");
                                printf("--------------------------------\n");
                                printf("Choose the correct answer:\n");
                                printf("  1. 8\n");
                                printf("  2. 2\n");
                                printf("  3. 4\n");
                                printf("  4. 1\n");
                            }
                            else if (i == 41) {
                                printf("--------------------------------\n");
                                printf("What is the value of  5 / 2.0 ?\n");
                                printf("--------------------------------\n");
                                printf("Choose the correct answer:\n");
                                printf("  1. 2.5\n");
                                printf("  2. 2\n");
                                printf("  3. Error\n");
                                printf("  4. 3\n");
                            }
                            else if (i == 42) {
                                printf("--------------------------------\n");
                                printf("What is the result of  10 > 5 > 2 ?\n");
                                printf("--------------------------------\n");
                                printf("Choose the correct answer:\n");
                                printf("  1. Error\n");
                                printf("  2. 5\n");
                                printf("  3. 0 (false)\n");
                                printf("  4. 1 (true)\n");
                            }
                            else if (i == 43) {
                                printf("--------------------------------\n");
                                printf("What does  (int) 3.9  give?\n");
                                printf("--------------------------------\n");
                                printf("Choose the correct answer:\n");
                                printf("  1. 4\n");
                                printf("  2. 3\n");
                                printf("  3. 3.9\n");
                                printf("  4. Error\n");
                            }
                            else if (i == 44) {
                                printf("--------------------------------\n");
                                printf("What is the value of  a[a[0] - 4]  ?\n");
                                printf("\n");
                                printf("int a[3] = {5, 2, 7};\n");
                                printf("--------------------------------\n");
                                printf("Choose the correct answer:\n");
                                printf("  1. 7\n");
                                printf("  2. 2\n");
                                printf("  3. 1\n");
                                printf("  4. 5\n");
                            }
                            else if (i == 45) {
                                printf("--------------------------------\n");
                                printf("What is the value of  5 + 3 %% 2 * 4 ?\n");
                                printf("--------------------------------\n");
                                printf("Choose the correct answer:\n");
                                printf("  1. 12\n");
                                printf("  2. 16\n");
                                printf("  3. 9\n");
                                printf("  4. 4\n");
                            }
                            else if (i == 46) {
                                printf("--------------------------------\n");
                                printf("What is the value of  7 / 2 * 2 ?\n");
                                printf("--------------------------------\n");
                                printf("Choose the correct answer:\n");
                                printf("  1. 8\n");
                                printf("  2. 3.5\n");
                                printf("  3. 6\n");
                                printf("  4. 7\n");
                            }
                            else if (i == 47) {
                                printf("--------------------------------\n");
                                printf("Which statement about arrays is TRUE?\n");
                                printf("--------------------------------\n");
                                printf("Choose the correct answer:\n");
                                printf("  1. An array can store different types\n");
                                printf("  2. All elements have the same type\n");
                                printf("  3. Array indexes start at 1\n");
                                printf("  4. The size can change while running\n");
                            }
                            else if (i == 48) {
                                printf("--------------------------------\n");
                                printf("What does  a[i] = a[i] + 1;  do?\n");
                                printf("--------------------------------\n");
                                printf("Choose the correct answer:\n");
                                printf("  1. Creates a new array\n");
                                printf("  2. Adds 1 to element number i\n");
                                printf("  3. Prints a[i]\n");
                                printf("  4. Adds 1 to the index\n");
                            }
                            else if (i == 49) {
                                printf("--------------------------------\n");
                                printf("What is the BEST reason to use a loop with an array?\n");
                                printf("--------------------------------\n");
                                printf("Choose the correct answer:\n");
                                printf("  1. To change the data type\n");
                                printf("  2. To avoid declaring the array\n");
                                printf("  3. To make the array bigger\n");
                                printf("  4. To visit every element without repeating code\n");
                            }

                            else if (i == 50) {
                                printf("--------------------------------\n");
                                printf("int a = 3, b = 4;\n");
                                printf("printf(\"%%d\", a + b);\n");
                                printf("--------------------------------\n");
                                printf("What will this code print?\n");
                                printf("  1. Error\n");
                                printf("  2. 12\n");
                                printf("  3. 34\n");
                                printf("  4. 7\n");
                            }
                            else if (i == 51) {
                                printf("--------------------------------\n");
                                printf("int x = 10;\n");
                                printf("if (x > 5)\n");
                                printf("    printf(\"Big\");\n");
                                printf("else\n");
                                printf("    printf(\"Small\");\n");
                                printf("--------------------------------\n");
                                printf("What will this code print?\n");
                                printf("  1. BigSmall\n");
                                printf("  2. Small\n");
                                printf("  3. Nothing\n");
                                printf("  4. Big\n");
                            }
                            else if (i == 52) {
                                printf("--------------------------------\n");
                                printf("int i;\n");
                                printf("for (i = 1; i <= 3; i++)\n");
                                printf("    printf(\"%%d \", i);\n");
                                printf("--------------------------------\n");
                                printf("What will this code print?\n");
                                printf("  1. 1 2 3\n");
                                printf("  2. 0 1 2\n");
                                printf("  3. 1 2 3 4\n");
                                printf("  4. 1 2\n");
                            }
                            else if (i == 53) {
                                printf("--------------------------------\n");
                                printf("char c = 'A';\n");
                                printf("printf(\"%%c\", c);\n");
                                printf("--------------------------------\n");
                                printf("What will this code print?\n");
                                printf("  1. 65\n");
                                printf("  2. A\n");
                                printf("  3. a\n");
                                printf("  4. 'A'\n");
                            }
                            else if (i == 54) {
                                printf("--------------------------------\n");
                                printf("int a = 6, b = 4;\n");
                                printf("printf(\"%%d\", a * b);\n");
                                printf("--------------------------------\n");
                                printf("What will this code print?\n");
                                printf("  1. 64\n");
                                printf("  2. 24\n");
                                printf("  3. 10\n");
                                printf("  4. 2\n");
                            }
                            else if (i == 55) {
                                printf("--------------------------------\n");
                                printf("float f = 2.5;\n");
                                printf("printf(\"%%f\", f);\n");
                                printf("--------------------------------\n");
                                printf("What will this code print?\n");
                                printf("  1. 2.50\n");
                                printf("  2. 2.500000\n");
                                printf("  3. 2\n");
                                printf("  4. 2.5\n");
                            }
                            else if (i == 56) {
                                printf("--------------------------------\n");
                                printf("printf(\"Hello\");\n");
                                printf("printf(\"World\");\n");
                                printf("--------------------------------\n");
                                printf("What will this code print?\n");
                                printf("  1. HelloWorld\n");
                                printf("  2. Hello World\n");
                                printf("  3. World Hello\n");
                                printf("  4. Hello\n");
                            }
                            else if (i == 57) {
                                printf("--------------------------------\n");
                                printf("int x = 7;\n");
                                printf("printf(\"x = %%d\", x);\n");
                                printf("--------------------------------\n");
                                printf("What will this code print?\n");
                                printf("  1. x = x\n");
                                printf("  2. x = 7\n");
                                printf("  3. 7\n");
                                printf("  4. %%d = 7\n");
                            }
                            else if (i == 58) {
                                printf("--------------------------------\n");
                                printf("int x = 5;\n");
                                printf("if (x == 5)\n");
                                printf("    printf(\"Yes\");\n");
                                printf("else\n");
                                printf("    printf(\"No\");\n");
                                printf("--------------------------------\n");
                                printf("What will this code print?\n");
                                printf("  1. 5\n");
                                printf("  2. No\n");
                                printf("  3. YesNo\n");
                                printf("  4. Yes\n");
                            }
                            else if (i == 59) {
                                printf("--------------------------------\n");
                                printf("int i;\n");
                                printf("for (i = 0; i < 3; i++)\n");
                                printf("    printf(\"*\");\n");
                                printf("--------------------------------\n");
                                printf("What will this code print?\n");
                                printf("  1. ****\n");
                                printf("  2. **\n");
                                printf("  3. *\n");
                                printf("  4. ***\n");
                            }

                            else if (i == 60) {
                                printf("--------------------------------\n");
                                printf("int x = 5;\n");
                                printf("if (x > 5)\n");
                                printf("    printf(\"A\");\n");
                                printf("else if (x == 5)\n");
                                printf("    printf(\"B\");\n");
                                printf("else\n");
                                printf("    printf(\"C\");\n");
                                printf("--------------------------------\n");
                                printf("What will this code print?\n");
                                printf("  1. A\n");
                                printf("  2. BC\n");
                                printf("  3. C\n");
                                printf("  4. B\n");
                            }
                            else if (i == 61) {
                                printf("--------------------------------\n");
                                printf("int a[4] = {2, 4, 6, 8};\n");
                                printf("printf(\"%%d\", a[1] + a[3]);\n");
                                printf("--------------------------------\n");
                                printf("What will this code print?\n");
                                printf("  1. 10\n");
                                printf("  2. 12\n");
                                printf("  3. 14\n");
                                printf("  4. 16\n");
                            }
                            else if (i == 62) {
                                printf("--------------------------------\n");
                                printf("int i;\n");
                                printf("for (i = 1; i <= 5; i++) {\n");
                                printf("    if (i == 3)\n");
                                printf("        break;\n");
                                printf("    printf(\"%%d \", i);\n");
                                printf("}\n");
                                printf("--------------------------------\n");
                                printf("What will this code print?\n");
                                printf("  1. 1 2 3\n");
                                printf("  2. 1 2\n");
                                printf("  3. 1 2 4 5\n");
                                printf("  4. 1 2 3 4 5\n");
                            }
                            else if (i == 63) {
                                printf("--------------------------------\n");
                                printf("int x = 7 / 2;\n");
                                printf("printf(\"%%d\", x);\n");
                                printf("--------------------------------\n");
                                printf("What will this code print?\n");
                                printf("  1. 2\n");
                                printf("  2. 3\n");
                                printf("  3. 4\n");
                                printf("  4. 3.5\n");
                            }
                            else if (i == 64) {
                                printf("--------------------------------\n");
                                printf("int a = 17, b = 5;\n");
                                printf("printf(\"%%d\", a %% b);\n");
                                printf("--------------------------------\n");
                                printf("What will this code print?\n");
                                printf("  1. 3.4\n");
                                printf("  2. 12\n");
                                printf("  3. 2\n");
                                printf("  4. 3\n");
                            }
                            else if (i == 65) {
                                printf("--------------------------------\n");
                                printf("int i;\n");
                                printf("for (i = 5; i >= 1; i--)\n");
                                printf("    printf(\"%%d \", i);\n");
                                printf("--------------------------------\n");
                                printf("What will this code print?\n");
                                printf("  1. 5 4 3 2 1\n");
                                printf("  2. 5 4 3 2\n");
                                printf("  3. 1 2 3 4 5\n");
                                printf("  4. 4 3 2 1 0\n");
                            }
                            else if (i == 66) {
                                printf("--------------------------------\n");
                                printf("int x = 10;\n");
                                printf("x += 5;\n");
                                printf("x -= 3;\n");
                                printf("printf(\"%%d\", x);\n");
                                printf("--------------------------------\n");
                                printf("What will this code print?\n");
                                printf("  1. 13\n");
                                printf("  2. 15\n");
                                printf("  3. 12\n");
                                printf("  4. 8\n");
                            }
                            else if (i == 67) {
                                printf("--------------------------------\n");
                                printf("int age = 20;\n");
                                printf("if (age >= 18 && age <= 25)\n");
                                printf("    printf(\"Young\");\n");
                                printf("else\n");
                                printf("    printf(\"Other\");\n");
                                printf("--------------------------------\n");
                                printf("What will this code print?\n");
                                printf("  1. Nothing\n");
                                printf("  2. Other\n");
                                printf("  3. Young\n");
                                printf("  4. YoungOther\n");
                            }
                            else if (i == 68) {
                                printf("--------------------------------\n");
                                printf("int i;\n");
                                printf("for (i = 1; i <= 5; i++) {\n");
                                printf("    if (i == 3)\n");
                                printf("        continue;\n");
                                printf("    printf(\"%%d \", i);\n");
                                printf("}\n");
                                printf("--------------------------------\n");
                                printf("What will this code print?\n");
                                printf("  1. 1 2 4 5\n");
                                printf("  2. 1 2\n");
                                printf("  3. 1 2 3\n");
                                printf("  4. 1 2 3 4 5\n");
                            }
                            else if (i == 69) {
                                printf("--------------------------------\n");
                                printf("int a = 2, b = 3;\n");
                                printf("printf(\"%%d\", a + b * 2);\n");
                                printf("--------------------------------\n");
                                printf("What will this code print?\n");
                                printf("  1. 8\n");
                                printf("  2. 7\n");
                                printf("  3. 10\n");
                                printf("  4. 12\n");
                            }

                            else if (i == 70) {
                                printf("--------------------------------\n");
                                printf("int sum = 0, i;\n");
                                printf("for (i = 1; i <= 5; i++) {\n");
                                printf("    if (i %% 2 == 0)\n");
                                printf("        sum = sum + i;\n");
                                printf("}\n");
                                printf("printf(\"%%d\", sum);\n");
                                printf("--------------------------------\n");
                                printf("What will this code print?\n");
                                printf("  1. 9\n");
                                printf("  2. 15\n");
                                printf("  3. 6\n");
                                printf("  4. 12\n");
                            }
                            else if (i == 71) {
                                printf("--------------------------------\n");
                                printf("int i = 0;\n");
                                printf("while (i < 10) {\n");
                                printf("    i = i + 3;\n");
                                printf("}\n");
                                printf("printf(\"%%d\", i);\n");
                                printf("--------------------------------\n");
                                printf("What will this code print?\n");
                                printf("  1. 10\n");
                                printf("  2. 12\n");
                                printf("  3. 9\n");
                                printf("  4. 15\n");
                            }
                            else if (i == 72) {
                                printf("--------------------------------\n");
                                printf("int a[5] = {3, 9, 4, 7, 2};\n");
                                printf("int max = a[0], i;\n");
                                printf("for (i = 1; i < 5; i++) {\n");
                                printf("    if (a[i] > max)\n");
                                printf("        max = a[i];\n");
                                printf("}\n");
                                printf("printf(\"%%d\", max);\n");
                                printf("--------------------------------\n");
                                printf("What will this code print?\n");
                                printf("  1. 3\n");
                                printf("  2. 2\n");
                                printf("  3. 9\n");
                                printf("  4. 7\n");
                            }
                            else if (i == 73) {
                                printf("--------------------------------\n");
                                printf("int n = 5, sum = 0, i;\n");
                                printf("for (i = 1; i <= n; i++)\n");
                                printf("    sum = sum + i;\n");
                                printf("printf(\"%%d\", sum);\n");
                                printf("--------------------------------\n");
                                printf("What will this code print?\n");
                                printf("  1. 20\n");
                                printf("  2. 5\n");
                                printf("  3. 15\n");
                                printf("  4. 10\n");
                            }
                            else if (i == 74) {
                                printf("--------------------------------\n");
                                printf("int i = 1;\n");
                                printf("do {\n");
                                printf("    printf(\"%%d \", i);\n");
                                printf("    i++;\n");
                                printf("} while (i < 1);\n");
                                printf("--------------------------------\n");
                                printf("What will this code print?\n");
                                printf("  1. 1\n");
                                printf("  2. Nothing\n");
                                printf("  3. 1 2\n");
                                printf("  4. 0\n");
                            }
                            else if (i == 75) {
                                printf("--------------------------------\n");
                                printf("int a[5] = {1, 2, 3, 4, 5};\n");
                                printf("int i;\n");
                                printf("for (i = 0; i < 5; i++)\n");
                                printf("    a[i] = a[i] * 2;\n");
                                printf("printf(\"%%d\", a[4]);\n");
                                printf("--------------------------------\n");
                                printf("What will this code print?\n");
                                printf("  1. 5\n");
                                printf("  2. 10\n");
                                printf("  3. 8\n");
                                printf("  4. 12\n");
                            }
                            else if (i == 76) {
                                printf("--------------------------------\n");
                                printf("int x = 15;\n");
                                printf("if (x %% 2 == 0)\n");
                                printf("    printf(\"Even\");\n");
                                printf("else\n");
                                printf("    printf(\"Odd\");\n");
                                printf("--------------------------------\n");
                                printf("What will this code print?\n");
                                printf("  1. Zero\n");
                                printf("  2. Nothing\n");
                                printf("  3. Even\n");
                                printf("  4. Odd\n");
                            }
                            else if (i == 77) {
                                printf("--------------------------------\n");
                                printf("int count = 0, i;\n");
                                printf("for (i = 1; i <= 10; i++) {\n");
                                printf("    if (i %% 3 == 0)\n");
                                printf("        count++;\n");
                                printf("}\n");
                                printf("printf(\"%%d\", count);\n");
                                printf("--------------------------------\n");
                                printf("What will this code print?\n");
                                printf("  1. 2\n");
                                printf("  2. 3\n");
                                printf("  3. 10\n");
                                printf("  4. 4\n");
                            }
                            else if (i == 78) {
                                printf("--------------------------------\n");
                                printf("int a = 4, b = 9;\n");
                                printf("if (a > b)\n");
                                printf("    printf(\"%%d\", a);\n");
                                printf("else\n");
                                printf("    printf(\"%%d\", b);\n");
                                printf("--------------------------------\n");
                                printf("What will this code print?\n");
                                printf("  1. 5\n");
                                printf("  2. 4\n");
                                printf("  3. 13\n");
                                printf("  4. 9\n");
                            }
                            else if (i == 79) {
                                printf("--------------------------------\n");
                                printf("int i, j;\n");
                                printf("for (i = 1; i <= 2; i++) {\n");
                                printf("    for (j = 1; j <= 3; j++) {\n");
                                printf("        printf(\"*\");\n");
                                printf("    }\n");
                                printf("    printf(\"-\");\n");
                                printf("}\n");
                                printf("--------------------------------\n");
                                printf("What will this code print?\n");
                                printf("  1. ***-***-\n");
                                printf("  2. *-*-*-\n");
                                printf("  3. ***-\n");
                                printf("  4. ******-\n");
                            }

                            else if (i == 80) {
                                printf("--------------------------------\n");
                                printf("int a[5] = {1, 2, 3, 4, 5};\n");
                                printf("int i, s = 0;\n");
                                printf("for (i = 0; i < 5; i += 2) {\n");
                                printf("    s = s + a[i];\n");
                                printf("}\n");
                                printf("printf(\"%%d\", s);\n");
                                printf("--------------------------------\n");
                                printf("What will this code print?\n");
                                printf("  1. 15\n");
                                printf("  2. 9\n");
                                printf("  3. 8\n");
                                printf("  4. 6\n");
                            }
                            else if (i == 81) {
                                printf("--------------------------------\n");
                                printf("int a = 17, b = 5;\n");
                                printf("printf(\"%%d %%d\", a / b, a %% b);\n");
                                printf("--------------------------------\n");
                                printf("What will this code print?\n");
                                printf("  1. 2 3\n");
                                printf("  2. 3 3\n");
                                printf("  3. 3.4 2\n");
                                printf("  4. 3 2\n");
                            }
                            else if (i == 82) {
                                printf("--------------------------------\n");
                                printf("int a = 5;\n");
                                printf("int b = a++;\n");
                                printf("printf(\"%%d %%d\", a, b);\n");
                                printf("--------------------------------\n");
                                printf("What will this code print?\n");
                                printf("  1. 5 5\n");
                                printf("  2. 6 6\n");
                                printf("  3. 6 5\n");
                                printf("  4. 5 6\n");
                            }
                            else if (i == 83) {
                                printf("--------------------------------\n");
                                printf("int a[3] = {5, 10, 15};\n");
                                printf("int i, s = 0;\n");
                                printf("for (i = 0; i < 3; i++)\n");
                                printf("    s = s + a[i];\n");
                                printf("printf(\"%%d\", s / 3);\n");
                                printf("--------------------------------\n");
                                printf("What will this code print?\n");
                                printf("  1. 5\n");
                                printf("  2. 15\n");
                                printf("  3. 30\n");
                                printf("  4. 10\n");
                            }
                            else if (i == 84) {
                                printf("--------------------------------\n");
                                printf("int n = 1234, sum = 0;\n");
                                printf("while (n > 0) {\n");
                                printf("    sum = sum + n %% 10;\n");
                                printf("    n = n / 10;\n");
                                printf("}\n");
                                printf("printf(\"%%d\", sum);\n");
                                printf("--------------------------------\n");
                                printf("What will this code print?\n");
                                printf("  1. 24\n");
                                printf("  2. 1234\n");
                                printf("  3. 4\n");
                                printf("  4. 10\n");
                            }
                            else if (i == 85) {
                                printf("--------------------------------\n");
                                printf("int i, j, count = 0;\n");
                                printf("for (i = 1; i <= 3; i++) {\n");
                                printf("    for (j = 1; j <= i; j++)\n");
                                printf("        count++;\n");
                                printf("}\n");
                                printf("printf(\"%%d\", count);\n");
                                printf("--------------------------------\n");
                                printf("What will this code print?\n");
                                printf("  1. 3\n");
                                printf("  2. 6\n");
                                printf("  3. 4\n");
                                printf("  4. 9\n");
                            }
                            else if (i == 86) {
                                printf("--------------------------------\n");
                                printf("int a[4] = {1, 2, 3, 4};\n");
                                printf("int t = a[0];\n");
                                printf("a[0] = a[3];\n");
                                printf("a[3] = t;\n");
                                printf("printf(\"%%d %%d\", a[0], a[3]);\n");
                                printf("--------------------------------\n");
                                printf("What will this code print?\n");
                                printf("  1. 1 1\n");
                                printf("  2. 4 1\n");
                                printf("  3. 1 4\n");
                                printf("  4. 4 4\n");
                            }
                            else if (i == 87) {
                                printf("--------------------------------\n");
                                printf("int x = 20;\n");
                                printf("if (x > 10) {\n");
                                printf("    if (x > 15)\n");
                                printf("        printf(\"A\");\n");
                                printf("    else\n");
                                printf("        printf(\"B\");\n");
                                printf("} else\n");
                                printf("    printf(\"C\");\n");
                                printf("--------------------------------\n");
                                printf("What will this code print?\n");
                                printf("  1. AB\n");
                                printf("  2. A\n");
                                printf("  3. B\n");
                                printf("  4. C\n");
                            }
                            else if (i == 88) {
                                printf("--------------------------------\n");
                                printf("int i;\n");
                                printf("for (i = 10; i > 0; i = i - 4)\n");
                                printf("    printf(\"%%d \", i);\n");
                                printf("--------------------------------\n");
                                printf("What will this code print?\n");
                                printf("  1. 6 2\n");
                                printf("  2. 10 6\n");
                                printf("  3. 10 6 2 -2\n");
                                printf("  4. 10 6 2\n");
                            }
                            else if (i == 89) {
                                printf("--------------------------------\n");
                                printf("int a[5] = {4, 8, 1, 9, 3};\n");
                                printf("int min = a[0], i;\n");
                                printf("for (i = 1; i < 5; i++) {\n");
                                printf("    if (a[i] < min)\n");
                                printf("        min = a[i];\n");
                                printf("}\n");
                                printf("printf(\"%%d\", min);\n");
                                printf("--------------------------------\n");
                                printf("What will this code print?\n");
                                printf("  1. 3\n");
                                printf("  2. 4\n");
                                printf("  3. 1\n");
                                printf("  4. 9\n");
                            }

                            else if (i == 90) {
                                printf("--------------------------------\n");
                                printf("char c = 'A';\n");
                                printf("c = c + 2;\n");
                                printf("printf(\"%%c %%d\", c, c);\n");
                                printf("--------------------------------\n");
                                printf("What will this code print?\n");
                                printf("  1. C 99\n");
                                printf("  2. A 65\n");
                                printf("  3. D 68\n");
                                printf("  4. C 67\n");
                            }
                            else if (i == 91) {
                                printf("--------------------------------\n");
                                printf("int i = 5;\n");
                                printf("printf(\"%%d \", i++);\n");
                                printf("printf(\"%%d \", ++i);\n");
                                printf("printf(\"%%d\", i);\n");
                                printf("--------------------------------\n");
                                printf("What will this code print?\n");
                                printf("  1. 5 6 7\n");
                                printf("  2. 5 7 8\n");
                                printf("  3. 5 7 7\n");
                                printf("  4. 6 7 7\n");
                            }
                            else if (i == 92) {
                                printf("--------------------------------\n");
                                printf("int i, j, count = 0;\n");
                                printf("for (i = 1; i <= 3; i++) {\n");
                                printf("    for (j = 1; j <= 3; j++) {\n");
                                printf("        if (j == 2)\n");
                                printf("            break;\n");
                                printf("        count++;\n");
                                printf("    }\n");
                                printf("}\n");
                                printf("printf(\"%%d\", count);\n");
                                printf("--------------------------------\n");
                                printf("What will this code print?\n");
                                printf("  1. 3\n");
                                printf("  2. 2\n");
                                printf("  3. 9\n");
                                printf("  4. 6\n");
                            }
                            else if (i == 93) {
                                printf("--------------------------------\n");
                                printf("int a[4] = {4, 3, 2, 1};\n");
                                printf("int i, t;\n");
                                printf("for (i = 0; i < 3; i++) {\n");
                                printf("    if (a[i] > a[i + 1]) {\n");
                                printf("        t = a[i];\n");
                                printf("        a[i] = a[i + 1];\n");
                                printf("        a[i + 1] = t;\n");
                                printf("    }\n");
                                printf("}\n");
                                printf("printf(\"%%d %%d %%d %%d\", a[0], a[1], a[2], a[3]);\n");
                                printf("--------------------------------\n");
                                printf("What will this code print?\n");
                                printf("  1. 3 4 2 1\n");
                                printf("  2. 4 3 2 1\n");
                                printf("  3. 1 2 3 4\n");
                                printf("  4. 3 2 1 4\n");
                            }
                            else if (i == 94) {
                                printf("--------------------------------\n");
                                printf("int a[5] = {1, 2, 3, 4, 5};\n");
                                printf("int i, t;\n");
                                printf("for (i = 0; i < 5; i++) {\n");
                                printf("    t = a[i];\n");
                                printf("    a[i] = a[4 - i];\n");
                                printf("    a[4 - i] = t;\n");
                                printf("}\n");
                                printf("printf(\"%%d %%d %%d\", a[0], a[1], a[2]);\n");
                                printf("--------------------------------\n");
                                printf("What will this code print?\n");
                                printf("  1. 1 2 3\n");
                                printf("  2. 3 2 1\n");
                                printf("  3. 5 2 3\n");
                                printf("  4. 5 4 3\n");
                            }
                            else if (i == 95) {
                                printf("--------------------------------\n");
                                printf("int x = 10;\n");
                                printf("int y = x-- - 3;\n");
                                printf("printf(\"%%d %%d\", x, y);\n");
                                printf("--------------------------------\n");
                                printf("What will this code print?\n");
                                printf("  1. 10 7\n");
                                printf("  2. 9 7\n");
                                printf("  3. 9 6\n");
                                printf("  4. 10 6\n");
                            }
                            else if (i == 96) {
                                printf("--------------------------------\n");
                                printf("int a[5] = {2, 4, 6, 8, 10};\n");
                                printf("int i, s = 0;\n");
                                printf("for (i = 4; i >= 0; i -= 2)\n");
                                printf("    s = s + a[i];\n");
                                printf("printf(\"%%d\", s);\n");
                                printf("--------------------------------\n");
                                printf("What will this code print?\n");
                                printf("  1. 18\n");
                                printf("  2. 30\n");
                                printf("  3. 20\n");
                                printf("  4. 12\n");
                            }
                            else if (i == 97) {
                                printf("--------------------------------\n");
                                printf("int a[3] = {1, 2, 3};\n");
                                printf("int i = 0;\n");
                                printf("while (i < 3) {\n");
                                printf("    printf(\"%%d\", a[i] * a[i]);\n");
                                printf("    i++;\n");
                                printf("}\n");
                                printf("--------------------------------\n");
                                printf("What will this code print?\n");
                                printf("  1. 149\n");
                                printf("  2. 14\n");
                                printf("  3. 123\n");
                                printf("  4. 1 4 9\n");
                            }
                            else if (i == 98) {
                                printf("--------------------------------\n");
                                printf("int i, s = 0;\n");
                                printf("for (i = 1; i <= 10; i++) {\n");
                                printf("    if (i %% 2 == 0)\n");
                                printf("        continue;\n");
                                printf("    if (i > 7)\n");
                                printf("        break;\n");
                                printf("    s = s + i;\n");
                                printf("}\n");
                                printf("printf(\"%%d\", s);\n");
                                printf("--------------------------------\n");
                                printf("What will this code print?\n");
                                printf("  1. 21\n");
                                printf("  2. 25\n");
                                printf("  3. 9\n");
                                printf("  4. 16\n");
                            }
                            else if (i == 99) {
                                printf("--------------------------------\n");
                                printf("int i, j;\n");
                                printf("for (i = 1; i <= 3; i++)\n");
                                printf("    for (j = i; j <= 3; j++)\n");
                                printf("        printf(\"%%d\", j);\n");
                                printf("--------------------------------\n");
                                printf("What will this code print?\n");
                                printf("  1. 112233\n");
                                printf("  2. 123\n");
                                printf("  3. 123123\n");
                                printf("  4. 123233\n");
                            }

                            else if (i == 100) {
                                printf("--------------------------------\n");
                                printf("1: int a = 5;\n");
                                printf("2: int b = 10;\n");
                                printf("3: int c = a + b\n");
                                printf("4: printf(\"%%d\", c);\n");
                                printf("--------------------------------\n");
                                printf("Which line has the bug?\n");
                                printf("  1. Line 1\n");
                                printf("  2. Line 2\n");
                                printf("  3. Line 3\n");
                                printf("  4. Line 4\n");
                            }
                            else if (i == 101) {
                                printf("--------------------------------\n");
                                printf("1: printf(\"Welcome);\n");
                                printf("2: int x = 5;\n");
                                printf("3: printf(\"%%d\", x);\n");
                                printf("4: return 0;\n");
                                printf("--------------------------------\n");
                                printf("Which line has the bug?\n");
                                printf("  1. Line 1\n");
                                printf("  2. Line 2\n");
                                printf("  3. Line 3\n");
                                printf("  4. Line 4\n");
                            }
                            else if (i == 102) {
                                printf("--------------------------------\n");
                                printf("1: int a = 10;\n");
                                printf("2: sum = a * 2;\n");
                                printf("3: printf(\"%%d\", sum);\n");
                                printf("4: return 0;\n");
                                printf("--------------------------------\n");
                                printf("Which line has the bug?\n");
                                printf("  1. Line 1\n");
                                printf("  2. Line 2\n");
                                printf("  3. Line 3\n");
                                printf("  4. Line 4\n");
                            }
                            else if (i == 103) {
                                printf("--------------------------------\n");
                                printf("1: int marks = 90;\n");
                                printf("2: int 1st = 5;\n");
                                printf("3: printf(\"%%d\", marks);\n");
                                printf("4: return 0;\n");
                                printf("--------------------------------\n");
                                printf("Which line has the bug?\n");
                                printf("  1. Line 1\n");
                                printf("  2. Line 2\n");
                                printf("  3. Line 3\n");
                                printf("  4. Line 4\n");
                            }
                            else if (i == 104) {
                                printf("--------------------------------\n");
                                printf("1: int x = 5;\n");
                                printf("2: printf(\"x is %%d\", x)\n");
                                printf("3: printf(\" done\");\n");
                                printf("4: return 0;\n");
                                printf("--------------------------------\n");
                                printf("Which line has the bug?\n");
                                printf("  1. Line 1\n");
                                printf("  2. Line 2\n");
                                printf("  3. Line 3\n");
                                printf("  4. Line 4\n");
                            }
                            else if (i == 105) {
                                printf("--------------------------------\n");
                                printf("1: int a = 4;\n");
                                printf("2: int b = 6;\n");
                                printf("3: printf(\"%%d\", a + b;\n");
                                printf("4: return 0;\n");
                                printf("--------------------------------\n");
                                printf("Which line has the bug?\n");
                                printf("  1. Line 1\n");
                                printf("  2. Line 2\n");
                                printf("  3. Line 3\n");
                                printf("  4. Line 4\n");
                            }
                            else if (i == 106) {
                                printf("--------------------------------\n");
                                printf("1: int x = 5;\n");
                                printf("2: Printf(\"%%d\", x);\n");
                                printf("3: printf(\" done\");\n");
                                printf("4: return 0;\n");
                                printf("--------------------------------\n");
                                printf("Which line has the bug?\n");
                                printf("  1. Line 1\n");
                                printf("  2. Line 2\n");
                                printf("  3. Line 3\n");
                                printf("  4. Line 4\n");
                            }
                            else if (i == 107) {
                                printf("--------------------------------\n");
                                printf("1: int a = 5;\n");
                                printf("2: int b = 0;\n");
                                printf("3: a = b + 1;\n");
                                printf("4: printf(\"%%d\", c);\n");
                                printf("--------------------------------\n");
                                printf("Which line has the bug?\n");
                                printf("  1. Line 1\n");
                                printf("  2. Line 2\n");
                                printf("  3. Line 3\n");
                                printf("  4. Line 4\n");
                            }
                            else if (i == 108) {
                                printf("--------------------------------\n");
                                printf("1: int a = 5;\n");
                                printf("2: int b = 3;\n");
                                printf("3: printf(\"%%d\", a + b);\n");
                                printf("4: printf(\"%%d\" b);\n");
                                printf("--------------------------------\n");
                                printf("Which line has the bug?\n");
                                printf("  1. Line 1\n");
                                printf("  2. Line 2\n");
                                printf("  3. Line 3\n");
                                printf("  4. Line 4\n");
                            }
                            else if (i == 109) {
                                printf("--------------------------------\n");
                                printf("1: int x = 5;\n");
                                printf("2: int y = x + ;\n");
                                printf("3: printf(\"%%d\", y);\n");
                                printf("4: return 0;\n");
                                printf("--------------------------------\n");
                                printf("Which line has the bug?\n");
                                printf("  1. Line 1\n");
                                printf("  2. Line 2\n");
                                printf("  3. Line 3\n");
                                printf("  4. Line 4\n");
                            }

                            else if (i == 110) {
                                printf("--------------------------------\n");
                                printf("1: int age = 18;\n");
                                printf("2: if (age = 18)\n");
                                printf("3:     printf(\"Adult\");\n");
                                printf("4: return 0;\n");
                                printf("--------------------------------\n");
                                printf("Which line has the bug?\n");
                                printf("  1. Line 1\n");
                                printf("  2. Line 2\n");
                                printf("  3. Line 3\n");
                                printf("  4. Line 4\n");
                            }
                            else if (i == 111) {
                                printf("--------------------------------\n");
                                printf("1: int a[3] = {1, 2, 3};\n");
                                printf("2: int i;\n");
                                printf("3: for (i = 0; i <= 3; i++)\n");
                                printf("4:     printf(\"%%d \", a[i]);\n");
                                printf("--------------------------------\n");
                                printf("Which line has the bug?\n");
                                printf("  1. Line 1\n");
                                printf("  2. Line 2\n");
                                printf("  3. Line 3\n");
                                printf("  4. Line 4\n");
                            }
                            else if (i == 112) {
                                printf("--------------------------------\n");
                                printf("1: char grade = \"A\";\n");
                                printf("2: printf(\"Grade: \");\n");
                                printf("3: printf(\"%%c\", grade);\n");
                                printf("4: return 0;\n");
                                printf("--------------------------------\n");
                                printf("Which line has the bug?\n");
                                printf("  1. Line 1\n");
                                printf("  2. Line 2\n");
                                printf("  3. Line 3\n");
                                printf("  4. Line 4\n");
                            }
                            else if (i == 113) {
                                printf("--------------------------------\n");
                                printf("1: int x = 7;\n");
                                printf("2: if x > 5\n");
                                printf("3:     printf(\"Big\");\n");
                                printf("4: return 0;\n");
                                printf("--------------------------------\n");
                                printf("Which line has the bug?\n");
                                printf("  1. Line 1\n");
                                printf("  2. Line 2\n");
                                printf("  3. Line 3\n");
                                printf("  4. Line 4\n");
                            }
                            else if (i == 114) {
                                printf("--------------------------------\n");
                                printf("1: float price = 99.5;\n");
                                printf("2: printf(\"Price: \");\n");
                                printf("3: printf(\"%%d\", price);\n");
                                printf("4: return 0;\n");
                                printf("--------------------------------\n");
                                printf("Which line has the bug?\n");
                                printf("  1. Line 1\n");
                                printf("  2. Line 2\n");
                                printf("  3. Line 3\n");
                                printf("  4. Line 4\n");
                            }
                            else if (i == 115) {
                                printf("--------------------------------\n");
                                printf("1: int i;\n");
                                printf("2: for (i = 0; i < 3; i++);\n");
                                printf("3:     printf(\"Hi \");\n");
                                printf("4: return 0;\n");
                                printf("--------------------------------\n");
                                printf("Which line has the bug?\n");
                                printf("  1. Line 1\n");
                                printf("  2. Line 2\n");
                                printf("  3. Line 3\n");
                                printf("  4. Line 4\n");
                            }
                            else if (i == 116) {
                                printf("--------------------------------\n");
                                printf("1: int marks = 85;\n");
                                printf("2: if (marks >= 80)\n");
                                printf("3:     printf(\"A+\");\n");
                                printf("4: else (marks >= 70) printf(\"A\");\n");
                                printf("--------------------------------\n");
                                printf("Which line has the bug?\n");
                                printf("  1. Line 1\n");
                                printf("  2. Line 2\n");
                                printf("  3. Line 3\n");
                                printf("  4. Line 4\n");
                            }
                            else if (i == 117) {
                                printf("--------------------------------\n");
                                printf("1: int a = 10, b = 0;\n");
                                printf("2: int result;\n");
                                printf("3: result = a / b;\n");
                                printf("4: printf(\"%%d\", result);\n");
                                printf("--------------------------------\n");
                                printf("Which line has the bug?\n");
                                printf("  1. Line 1\n");
                                printf("  2. Line 2\n");
                                printf("  3. Line 3\n");
                                printf("  4. Line 4\n");
                            }
                            else if (i == 118) {
                                printf("--------------------------------\n");
                                printf("1: // goal: print 2.5\n");
                                printf("2: int a = 5, b = 2;\n");
                                printf("3: float r = a / b;\n");
                                printf("4: printf(\"%%f\", r);\n");
                                printf("--------------------------------\n");
                                printf("Which line has the bug?\n");
                                printf("  1. Line 1\n");
                                printf("  2. Line 2\n");
                                printf("  3. Line 3\n");
                                printf("  4. Line 4\n");
                            }
                            else if (i == 119) {
                                printf("--------------------------------\n");
                                printf("1: int a[3] = {1, 2, 3, 4};\n");
                                printf("2: printf(\"%%d\", a[0]);\n");
                                printf("3: printf(\"%%d\", a[1]);\n");
                                printf("4: return 0;\n");
                                printf("--------------------------------\n");
                                printf("Which line has the bug?\n");
                                printf("  1. Line 1\n");
                                printf("  2. Line 2\n");
                                printf("  3. Line 3\n");
                                printf("  4. Line 4\n");
                            }

                            else if (i == 120) {
                                printf("--------------------------------\n");
                                printf("1: float price = 99.5;\n");
                                printf("2: float tax = 5.5;\n");
                                printf("3: printf(\"%%d\", price + tax);\n");
                                printf("4: return 0;\n");
                                printf("--------------------------------\n");
                                printf("Which line has the bug?\n");
                                printf("  1. Line 1\n");
                                printf("  2. Line 2\n");
                                printf("  3. Line 3\n");
                                printf("  4. Line 4\n");
                            }
                            else if (i == 121) {
                                printf("--------------------------------\n");
                                printf("1: int a[5] = {1, 2, 3, 4, 5};\n");
                                printf("2: int i;\n");
                                printf("3: for (i = 0; i < 5; i++)\n");
                                printf("4:     printf(\"%%d \", a[i]);\n");
                                printf("5: printf(\"%%d\", a[5]);\n");
                                printf("--------------------------------\n");
                                printf("Which line has the bug?\n");
                                printf("  1. Line 1\n");
                                printf("  2. Line 3\n");
                                printf("  3. Line 4\n");
                                printf("  4. Line 5\n");
                            }
                            else if (i == 122) {
                                printf("--------------------------------\n");
                                printf("1: int i = 1;\n");
                                printf("2: while (i <= 3);\n");
                                printf("3: {\n");
                                printf("4:     printf(\"%%d \", i);\n");
                                printf("5:     i++;\n");
                                printf("6: }\n");
                                printf("--------------------------------\n");
                                printf("Which line has the bug?\n");
                                printf("  1. Line 2\n");
                                printf("  2. Line 3\n");
                                printf("  3. Line 5\n");
                                printf("  4. Line 6\n");
                            }
                            else if (i == 123) {
                                printf("--------------------------------\n");
                                printf("1: int i;\n");
                                printf("2: for (i = 1; i <= 5; i++)\n");
                                printf("3: {\n");
                                printf("4:     if (i %% 2 = 0)\n");
                                printf("5:         printf(\"%%d \", i);\n");
                                printf("6: }\n");
                                printf("--------------------------------\n");
                                printf("Which line has the bug?\n");
                                printf("  1. Line 2\n");
                                printf("  2. Line 4\n");
                                printf("  3. Line 5\n");
                                printf("  4. Line 6\n");
                            }
                            else if (i == 124) {
                                printf("--------------------------------\n");
                                printf("1: int x = 10;\n");
                                printf("2: if (x > 5 && < 20)\n");
                                printf("3:     printf(\"In range\");\n");
                                printf("4: return 0;\n");
                                printf("--------------------------------\n");
                                printf("Which line has the bug?\n");
                                printf("  1. Line 1\n");
                                printf("  2. Line 2\n");
                                printf("  3. Line 3\n");
                                printf("  4. Line 4\n");
                            }
                            else if (i == 125) {
                                printf("--------------------------------\n");
                                printf("1: // goal: sum of 1 to 5\n");
                                printf("2: int sum, i;\n");
                                printf("3: for (i = 1; i <= 5; i++)\n");
                                printf("4:     sum = sum + i;\n");
                                printf("5: printf(\"%%d\", sum);\n");
                                printf("--------------------------------\n");
                                printf("Which line has the bug?\n");
                                printf("  1. Line 2\n");
                                printf("  2. Line 3\n");
                                printf("  3. Line 4\n");
                                printf("  4. Line 5\n");
                            }
                            else if (i == 126) {
                                printf("--------------------------------\n");
                                printf("1: int x = 5;\n");
                                printf("2: if (x > 3)\n");
                                printf("3:     printf(\"A\");\n");
                                printf("4: else\n");
                                printf("5:     printf(\"B\");\n");
                                printf("6: else printf(\"C\");\n");
                                printf("--------------------------------\n");
                                printf("Which line has the bug?\n");
                                printf("  1. Line 2\n");
                                printf("  2. Line 4\n");
                                printf("  3. Line 5\n");
                                printf("  4. Line 6\n");
                            }
                            else if (i == 127) {
                                printf("--------------------------------\n");
                                printf("1: // goal: count down 10 to 1\n");
                                printf("2: int i = 10;\n");
                                printf("3: while (i > 0) {\n");
                                printf("4:     printf(\"%%d \", i);\n");
                                printf("5:     i++;\n");
                                printf("6: }\n");
                                printf("--------------------------------\n");
                                printf("Which line has the bug?\n");
                                printf("  1. Line 2\n");
                                printf("  2. Line 3\n");
                                printf("  3. Line 4\n");
                                printf("  4. Line 5\n");
                            }
                            else if (i == 128) {
                                printf("--------------------------------\n");
                                printf("1: // goal: copy b into a\n");
                                printf("2: int a = 5;\n");
                                printf("3: int b = 10;\n");
                                printf("4: a == b;\n");
                                printf("5: printf(\"%%d\", a);\n");
                                printf("--------------------------------\n");
                                printf("Which line has the bug?\n");
                                printf("  1. Line 2\n");
                                printf("  2. Line 3\n");
                                printf("  3. Line 4\n");
                                printf("  4. Line 5\n");
                            }
                            else if (i == 129) {
                                printf("--------------------------------\n");
                                printf("1: int a[4] = {1, 2, 3, 4};\n");
                                printf("2: int i, s = 0;\n");
                                printf("3: for (i = 0; i < 4; i++);\n");
                                printf("4:     s = s + a[i];\n");
                                printf("5: printf(\"%%d\", s);\n");
                                printf("--------------------------------\n");
                                printf("Which line has the bug?\n");
                                printf("  1. Line 2\n");
                                printf("  2. Line 3\n");
                                printf("  3. Line 4\n");
                                printf("  4. Line 5\n");
                            }

                            else if (i == 130) {
                                printf("--------------------------------\n");
                                printf("1: int marks = 40;\n");
                                printf("2: if (marks >= 80);\n");
                                printf("3:     printf(\"Excellent\");\n");
                                printf("4: else\n");
                                printf("5:     printf(\"Try again\");\n");
                                printf("--------------------------------\n");
                                printf("Which line has the bug?\n");
                                printf("  1. Line 2\n");
                                printf("  2. Line 3\n");
                                printf("  3. Line 4\n");
                                printf("  4. Line 5\n");
                            }
                            else if (i == 131) {
                                printf("--------------------------------\n");
                                printf("1: int i;\n");
                                printf("2: int a[3] = {1, 2, 3};\n");
                                printf("3: for (i = 0, i < 3, i++)\n");
                                printf("4:     printf(\"%%d \", a[i]);\n");
                                printf("5: return 0;\n");
                                printf("--------------------------------\n");
                                printf("Which line has the bug?\n");
                                printf("  1. Line 2\n");
                                printf("  2. Line 3\n");
                                printf("  3. Line 4\n");
                                printf("  4. Line 5\n");
                            }
                            else if (i == 132) {
                                printf("--------------------------------\n");
                                printf("1: // goal: percentage of 45 out of 60\n");
                                printf("2: int got = 45, total = 60;\n");
                                printf("3: float pct;\n");
                                printf("4: pct = got / total * 100;\n");
                                printf("5: printf(\"%%f\", pct);\n");
                                printf("--------------------------------\n");
                                printf("Which line has the bug?\n");
                                printf("  1. Line 2\n");
                                printf("  2. Line 3\n");
                                printf("  3. Line 4\n");
                                printf("  4. Line 5\n");
                            }
                            else if (i == 133) {
                                printf("--------------------------------\n");
                                printf("1: // goal: find 7 in the array\n");
                                printf("2: int a[5] = {3, 7, 1, 9, 4};\n");
                                printf("3: int i, found = 0;\n");
                                printf("4: for (i = 0; i < 5; i++) {\n");
                                printf("5:     if (a[i] = 7)\n");
                                printf("6:         found = 1;\n");
                                printf("7: }\n");
                                printf("--------------------------------\n");
                                printf("Which line has the bug?\n");
                                printf("  1. Line 2\n");
                                printf("  2. Line 3\n");
                                printf("  3. Line 5\n");
                                printf("  4. Line 6\n");
                            }
                            else if (i == 134) {
                                printf("--------------------------------\n");
                                printf("1: // goal: print 3 rows of 4 stars\n");
                                printf("2: int i, j;\n");
                                printf("3: for (i = 1; i <= 3; i++) {\n");
                                printf("4:     for (j = 1; j <= 4; i++)\n");
                                printf("5:         printf(\"*\");\n");
                                printf("6:     printf(\"\\n\");\n");
                                printf("7: }\n");
                                printf("--------------------------------\n");
                                printf("Which line has the bug?\n");
                                printf("  1. Line 3\n");
                                printf("  2. Line 4\n");
                                printf("  3. Line 5\n");
                                printf("  4. Line 6\n");
                            }
                            else if (i == 135) {
                                printf("--------------------------------\n");
                                printf("1: // goal: print numbers 1 to 5\n");
                                printf("2: int i;\n");
                                printf("3: for (i = 1; i < 5; i++)\n");
                                printf("4:     printf(\"%%d \", i);\n");
                                printf("5: return 0;\n");
                                printf("--------------------------------\n");
                                printf("Which line has the bug?\n");
                                printf("  1. Line 1\n");
                                printf("  2. Line 2\n");
                                printf("  3. Line 3\n");
                                printf("  4. Line 5\n");
                            }
                            else if (i == 136) {
                                printf("--------------------------------\n");
                                printf("1: // goal: add 10 to every element\n");
                                printf("2: int a[3] = {1, 2, 3};\n");
                                printf("3: int i;\n");
                                printf("4: for (i = 0; i < 3; i++)\n");
                                printf("5:     a = a[i] + 10;\n");
                                printf("--------------------------------\n");
                                printf("Which line has the bug?\n");
                                printf("  1. Line 2\n");
                                printf("  2. Line 3\n");
                                printf("  3. Line 4\n");
                                printf("  4. Line 5\n");
                            }
                            else if (i == 137) {
                                printf("--------------------------------\n");
                                printf("1: // goal: count even numbers\n");
                                printf("2: int a[5] = {2, 3, 4, 5, 6};\n");
                                printf("3: int i, count = 0;\n");
                                printf("4: for (i = 0; i < 5; i++) {\n");
                                printf("5:     if (a[i] %% 2 == 1)\n");
                                printf("6:         count++;\n");
                                printf("7: }\n");
                                printf("--------------------------------\n");
                                printf("Which line has the bug?\n");
                                printf("  1. Line 2\n");
                                printf("  2. Line 4\n");
                                printf("  3. Line 5\n");
                                printf("  4. Line 6\n");
                            }
                            else if (i == 138) {
                                printf("--------------------------------\n");
                                printf("1: // goal: sum of all elements\n");
                                printf("2: int a[4] = {1, 2, 3, 4};\n");
                                printf("3: int i, sum = 0;\n");
                                printf("4: for (i = 0; i < 4; i++)\n");
                                printf("5:     sum = a[i];\n");
                                printf("6: printf(\"%%d\", sum);\n");
                                printf("--------------------------------\n");
                                printf("Which line has the bug?\n");
                                printf("  1. Line 2\n");
                                printf("  2. Line 3\n");
                                printf("  3. Line 5\n");
                                printf("  4. Line 6\n");
                            }
                            else if (i == 139) {
                                printf("--------------------------------\n");
                                printf("1: // goal: swap a and b\n");
                                printf("2: int a = 5, b = 10, t;\n");
                                printf("3: t = a;\n");
                                printf("4: a = b;\n");
                                printf("5: b = a;\n");
                                printf("6: printf(\"%%d %%d\", a, b);\n");
                                printf("--------------------------------\n");
                                printf("Which line has the bug?\n");
                                printf("  1. Line 2\n");
                                printf("  2. Line 3\n");
                                printf("  3. Line 4\n");
                                printf("  4. Line 5\n");
                            }

                            else if (i == 140) {
                                printf("--------------------------------\n");
                                printf("1: // goal: factorial of 5\n");
                                printf("2: int n = 5, i;\n");
                                printf("3: int fact = 0;\n");
                                printf("4: for (i = 1; i <= n; i++)\n");
                                printf("5:     fact = fact * i;\n");
                                printf("6: printf(\"%%d\", fact);\n");
                                printf("--------------------------------\n");
                                printf("Which line has the bug?\n");
                                printf("  1. Line 2\n");
                                printf("  2. Line 3\n");
                                printf("  3. Line 5\n");
                                printf("  4. Line 6\n");
                            }
                            else if (i == 141) {
                                printf("--------------------------------\n");
                                printf("1: // goal: check if n is prime\n");
                                printf("2: int n = 7, i, isPrime = 1;\n");
                                printf("3: for (i = 2; i < n; i++) {\n");
                                printf("4:     if (n %% i == 0)\n");
                                printf("5:         isPrime = 1;\n");
                                printf("6: }\n");
                                printf("7: printf(\"%%d\", isPrime);\n");
                                printf("--------------------------------\n");
                                printf("Which line has the bug?\n");
                                printf("  1. Line 2\n");
                                printf("  2. Line 3\n");
                                printf("  3. Line 5\n");
                                printf("  4. Line 7\n");
                            }
                            else if (i == 142) {
                                printf("--------------------------------\n");
                                printf("1: // goal: reverse the array\n");
                                printf("2: int a[5] = {1, 2, 3, 4, 5};\n");
                                printf("3: int i, t;\n");
                                printf("4: for (i = 0; i < 5; i++) {\n");
                                printf("5:     t = a[i];\n");
                                printf("6:     a[i] = a[4 - i];\n");
                                printf("7:     a[4 - i] = t;\n");
                                printf("8: }\n");
                                printf("--------------------------------\n");
                                printf("Which line has the bug?\n");
                                printf("  1. Line 3\n");
                                printf("  2. Line 4\n");
                                printf("  3. Line 6\n");
                                printf("  4. Line 7\n");
                            }
                            else if (i == 143) {
                                printf("--------------------------------\n");
                                printf("1: // goal: bubble sort, smallest first\n");
                                printf("2: int a[4] = {4, 3, 2, 1};\n");
                                printf("3: int i, j, t;\n");
                                printf("4: for (i = 0; i < 3; i++) {\n");
                                printf("5:     for (j = 0; j < 4; j++) {\n");
                                printf("6:         if (a[j] > a[j + 1]) {\n");
                                printf("7:             t = a[j]; a[j] = a[j + 1]; a[j + 1] = t;\n");
                                printf("8:         }\n");
                                printf("9:     }\n");
                                printf("10: }\n");
                                printf("--------------------------------\n");
                                printf("Which line has the bug?\n");
                                printf("  1. Line 2\n");
                                printf("  2. Line 5\n");
                                printf("  3. Line 6\n");
                                printf("  4. Line 7\n");
                            }
                            else if (i == 144) {
                                printf("--------------------------------\n");
                                printf("1: // goal: sum of the digits of n\n");
                                printf("2: int n = 123, sum = 0;\n");
                                printf("3: while (n > 0) {\n");
                                printf("4:     sum = sum + n / 10;\n");
                                printf("5:     n = n / 10;\n");
                                printf("6: }\n");
                                printf("7: printf(\"%%d\", sum);\n");
                                printf("--------------------------------\n");
                                printf("Which line has the bug?\n");
                                printf("  1. Line 2\n");
                                printf("  2. Line 3\n");
                                printf("  3. Line 4\n");
                                printf("  4. Line 5\n");
                            }
                            else if (i == 145) {
                                printf("--------------------------------\n");
                                printf("1: // goal: find the smallest number\n");
                                printf("2: int a[4] = {5, 9, 2, 7};\n");
                                printf("3: int min = 0, i;\n");
                                printf("4: for (i = 0; i < 4; i++) {\n");
                                printf("5:     if (a[i] < min)\n");
                                printf("6:         min = a[i];\n");
                                printf("7: }\n");
                                printf("--------------------------------\n");
                                printf("Which line has the bug?\n");
                                printf("  1. Line 2\n");
                                printf("  2. Line 3\n");
                                printf("  3. Line 5\n");
                                printf("  4. Line 6\n");
                            }
                            else if (i == 146) {
                                printf("--------------------------------\n");
                                printf("1: // goal: print 1 to 5 using do-while\n");
                                printf("2: int i = 1;\n");
                                printf("3: do {\n");
                                printf("4:     printf(\"%%d \", i);\n");
                                printf("5:     i++;\n");
                                printf("6: } while (i <= 5)\n");
                                printf("--------------------------------\n");
                                printf("Which line has the bug?\n");
                                printf("  1. Line 2\n");
                                printf("  2. Line 3\n");
                                printf("  3. Line 5\n");
                                printf("  4. Line 6\n");
                            }
                            else if (i == 147) {
                                printf("--------------------------------\n");
                                printf("1: // goal: copy array a into b\n");
                                printf("2: int a[3] = {1, 2, 3};\n");
                                printf("3: int b[3], i;\n");
                                printf("4: b = a;\n");
                                printf("5: printf(\"%%d\", b[0]);\n");
                                printf("--------------------------------\n");
                                printf("Which line has the bug?\n");
                                printf("  1. Line 2\n");
                                printf("  2. Line 3\n");
                                printf("  3. Line 4\n");
                                printf("  4. Line 5\n");
                            }
                            else if (i == 148) {
                                printf("--------------------------------\n");
                                printf("1: // goal: multiplication table of 3\n");
                                printf("2: int i;\n");
                                printf("3: for (i = 1; i <= 10; i++)\n");
                                printf("4:     printf(\"%%d \", 3 + i);\n");
                                printf("--------------------------------\n");
                                printf("Which line has the bug?\n");
                                printf("  1. Line 1\n");
                                printf("  2. Line 2\n");
                                printf("  3. Line 3\n");
                                printf("  4. Line 4\n");
                            }
                            else if (i == 149) {
                                printf("--------------------------------\n");
                                printf("1: // goal: count the digits of n\n");
                                printf("2: int n = 4567, count = 0;\n");
                                printf("3: while (n != 0) {\n");
                                printf("4:     n = n / 10;\n");
                                printf("5:     count = count + 2;\n");
                                printf("6: }\n");
                                printf("7: printf(\"%%d\", count);\n");
                                printf("--------------------------------\n");
                                printf("Which line has the bug?\n");
                                printf("  1. Line 2\n");
                                printf("  2. Line 3\n");
                                printf("  3. Line 5\n");
                                printf("  4. Line 7\n");
                            }

                            else if (i == 150) {
                                printf("--------------------------------\n");
                                printf("// declare a whole number\n");
                                printf("___ age = 20;\n");
                                printf("--------------------------------\n");
                                printf("What goes in the blank (___)?\n");
                                printf("  1. float\n");
                                printf("  2. int\n");
                                printf("  3. double\n");
                                printf("  4. char\n");
                            }
                            else if (i == 151) {
                                printf("--------------------------------\n");
                                printf("// print a float value\n");
                                printf("float pi = 3.14;\n");
                                printf("printf(\"___\", pi);\n");
                                printf("--------------------------------\n");
                                printf("What goes in the blank (___)?\n");
                                printf("  1. %%f\n");
                                printf("  2. %%s\n");
                                printf("  3. %%d\n");
                                printf("  4. %%c\n");
                            }
                            else if (i == 152) {
                                printf("--------------------------------\n");
                                printf("int x = 10;\n");
                                printf("___ (x > 5) {\n");
                                printf("    printf(\"Big\");\n");
                                printf("}\n");
                                printf("--------------------------------\n");
                                printf("What goes in the blank (___)?\n");
                                printf("  1. do\n");
                                printf("  2. for\n");
                                printf("  3. else\n");
                                printf("  4. if\n");
                            }
                            else if (i == 153) {
                                printf("--------------------------------\n");
                                printf("// declare one character\n");
                                printf("___ grade = 'A';\n");
                                printf("--------------------------------\n");
                                printf("What goes in the blank (___)?\n");
                                printf("  1. double\n");
                                printf("  2. char\n");
                                printf("  3. float\n");
                                printf("  4. int\n");
                            }
                            else if (i == 154) {
                                printf("--------------------------------\n");
                                printf("// print an int value\n");
                                printf("int n = 25;\n");
                                printf("printf(\"___\", n);\n");
                                printf("--------------------------------\n");
                                printf("What goes in the blank (___)?\n");
                                printf("  1. %%f\n");
                                printf("  2. %%c\n");
                                printf("  3. %%s\n");
                                printf("  4. %%d\n");
                            }
                            else if (i == 155) {
                                printf("--------------------------------\n");
                                printf("// read an integer from the keyboard\n");
                                printf("int age;\n");
                                printf("scanf(\"%%d\", ___age);\n");
                                printf("--------------------------------\n");
                                printf("What goes in the blank (___)?\n");
                                printf("  1. *\n");
                                printf("  2. #\n");
                                printf("  3. @\n");
                                printf("  4. &\n");
                            }
                            else if (i == 156) {
                                printf("--------------------------------\n");
                                printf("// print a new line after Hello\n");
                                printf("printf(\"Hello___\");\n");
                                printf("--------------------------------\n");
                                printf("What goes in the blank (___)?\n");
                                printf("  1. \\n\n");
                                printf("  2. /n\n");
                                printf("  3. #n\n");
                                printf("  4. %%n\n");
                            }
                            else if (i == 157) {
                                printf("--------------------------------\n");
                                printf("// end main() successfully\n");
                                printf("int main() {\n");
                                printf("    printf(\"Hi\");\n");
                                printf("    return ___;\n");
                                printf("}\n");
                                printf("--------------------------------\n");
                                printf("What goes in the blank (___)?\n");
                                printf("  1. -1\n");
                                printf("  2. 10\n");
                                printf("  3. 1\n");
                                printf("  4. 0\n");
                            }
                            else if (i == 158) {
                                printf("--------------------------------\n");
                                printf("// add two numbers\n");
                                printf("int a = 5, b = 3;\n");
                                printf("int sum = a ___ b;\n");
                                printf("--------------------------------\n");
                                printf("What goes in the blank (___)?\n");
                                printf("  1. +\n");
                                printf("  2. /\n");
                                printf("  3. -\n");
                                printf("  4. *\n");
                            }
                            else if (i == 159) {
                                printf("--------------------------------\n");
                                printf("// a variable that can never change\n");
                                printf("___ int MAX = 100;\n");
                                printf("--------------------------------\n");
                                printf("What goes in the blank (___)?\n");
                                printf("  1. final\n");
                                printf("  2. static\n");
                                printf("  3. const\n");
                                printf("  4. fixed\n");
                            }

                            else if (i == 160) {
                                printf("--------------------------------\n");
                                printf("// fill the array with even numbers\n");
                                printf("int a[5], i;\n");
                                printf("___ (i = 0; i < 5; i++) {\n");
                                printf("    a[i] = i * 2;\n");
                                printf("}\n");
                                printf("--------------------------------\n");
                                printf("What goes in the blank (___)?\n");
                                printf("  1. return\n");
                                printf("  2. else\n");
                                printf("  3. for\n");
                                printf("  4. if\n");
                            }
                            else if (i == 161) {
                                printf("--------------------------------\n");
                                printf("// array of 5 integers\n");
                                printf("int marks___;\n");
                                printf("--------------------------------\n");
                                printf("What goes in the blank (___)?\n");
                                printf("  1. <5>\n");
                                printf("  2. (5)\n");
                                printf("  3. {5}\n");
                                printf("  4. [5]\n");
                            }
                            else if (i == 162) {
                                printf("--------------------------------\n");
                                printf("// run only when x is NOT 5\n");
                                printf("int x = 3;\n");
                                printf("if (x ___ 5)\n");
                                printf("    printf(\"Not five\");\n");
                                printf("--------------------------------\n");
                                printf("What goes in the blank (___)?\n");
                                printf("  1. ==\n");
                                printf("  2. >=\n");
                                printf("  3. !=\n");
                                printf("  4. =\n");
                            }
                            else if (i == 163) {
                                printf("--------------------------------\n");
                                printf("// remainder of 17 divided by 5\n");
                                printf("int r = 17 ___ 5;\n");
                                printf("--------------------------------\n");
                                printf("What goes in the blank (___)?\n");
                                printf("  1. *\n");
                                printf("  2. /\n");
                                printf("  3. -\n");
                                printf("  4. %%\n");
                            }
                            else if (i == 164) {
                                printf("--------------------------------\n");
                                printf("// both conditions must be true\n");
                                printf("int age = 30;\n");
                                printf("if (age > 18 ___ age < 60)\n");
                                printf("    printf(\"Working age\");\n");
                                printf("--------------------------------\n");
                                printf("What goes in the blank (___)?\n");
                                printf("  1. &&\n");
                                printf("  2. !\n");
                                printf("  3. ||\n");
                                printf("  4. ==\n");
                            }
                            else if (i == 165) {
                                printf("--------------------------------\n");
                                printf("// add 5 to x\n");
                                printf("int x = 10;\n");
                                printf("x ___ 5;\n");
                                printf("--------------------------------\n");
                                printf("What goes in the blank (___)?\n");
                                printf("  1. =+\n");
                                printf("  2. ++\n");
                                printf("  3. +=\n");
                                printf("  4. ==\n");
                            }
                            else if (i == 166) {
                                printf("--------------------------------\n");
                                printf("// print numbers 5 down to 1\n");
                                printf("int i;\n");
                                printf("for (i = 5; i >= 1; i___)\n");
                                printf("    printf(\"%%d \", i);\n");
                                printf("--------------------------------\n");
                                printf("What goes in the blank (___)?\n");
                                printf("  1. ==\n");
                                printf("  2. --\n");
                                printf("  3. +=\n");
                                printf("  4. ++\n");
                            }
                            else if (i == 167) {
                                printf("--------------------------------\n");
                                printf("// check that x is positive AND even\n");
                                printf("int x = 8;\n");
                                printf("if (x > 0 && x %% 2 ___ 0)\n");
                                printf("    printf(\"Positive even\");\n");
                                printf("--------------------------------\n");
                                printf("What goes in the blank (___)?\n");
                                printf("  1. ==\n");
                                printf("  2. =\n");
                                printf("  3. !=\n");
                                printf("  4. >\n");
                            }
                            else if (i == 168) {
                                printf("--------------------------------\n");
                                printf("// run this when the if condition is false\n");
                                printf("int x = 3;\n");
                                printf("if (x > 10)\n");
                                printf("    printf(\"Big\");\n");
                                printf("___\n");
                                printf("    printf(\"Small\");\n");
                                printf("--------------------------------\n");
                                printf("What goes in the blank (___)?\n");
                                printf("  1. elif\n");
                                printf("  2. then\n");
                                printf("  3. otherwise\n");
                                printf("  4. else\n");
                            }
                            else if (i == 169) {
                                printf("--------------------------------\n");
                                printf("// print the FIRST element of the array\n");
                                printf("int a[3] = {10, 20, 30};\n");
                                printf("printf(\"%%d\", a[___]);\n");
                                printf("--------------------------------\n");
                                printf("What goes in the blank (___)?\n");
                                printf("  1. 3\n");
                                printf("  2. 0\n");
                                printf("  3. 10\n");
                                printf("  4. 1\n");
                            }

                            else if (i == 170) {
                                printf("--------------------------------\n");
                                printf("// run the body at least once\n");
                                printf("int i = 1;\n");
                                printf("___ {\n");
                                printf("    printf(\"%%d \", i);\n");
                                printf("    i++;\n");
                                printf("} while (i <= 3);\n");
                                printf("--------------------------------\n");
                                printf("What goes in the blank (___)?\n");
                                printf("  1. if\n");
                                printf("  2. do\n");
                                printf("  3. for\n");
                                printf("  4. while\n");
                            }
                            else if (i == 171) {
                                printf("--------------------------------\n");
                                printf("// stop the loop when i is 5\n");
                                printf("int i;\n");
                                printf("for (i = 1; i <= 10; i++) {\n");
                                printf("    if (i == 5)\n");
                                printf("        ___;\n");
                                printf("}\n");
                                printf("--------------------------------\n");
                                printf("What goes in the blank (___)?\n");
                                printf("  1. break\n");
                                printf("  2. stop\n");
                                printf("  3. exit\n");
                                printf("  4. end\n");
                            }
                            else if (i == 172) {
                                printf("--------------------------------\n");
                                printf("// print only even numbers from 1 to 10\n");
                                printf("int i;\n");
                                printf("for (i = 1; i <= 10; i++) {\n");
                                printf("    if (i ___ 2 == 0)\n");
                                printf("        printf(\"%%d \", i);\n");
                                printf("}\n");
                                printf("--------------------------------\n");
                                printf("What goes in the blank (___)?\n");
                                printf("  1. %%\n");
                                printf("  2. +\n");
                                printf("  3. *\n");
                                printf("  4. /\n");
                            }
                            else if (i == 173) {
                                printf("--------------------------------\n");
                                printf("// sum of 1 to 10\n");
                                printf("int sum = ___, i;\n");
                                printf("for (i = 1; i <= 10; i++)\n");
                                printf("    sum = sum + i;\n");
                                printf("--------------------------------\n");
                                printf("What goes in the blank (___)?\n");
                                printf("  1. i\n");
                                printf("  2. 1\n");
                                printf("  3. 0\n");
                                printf("  4. 10\n");
                            }
                            else if (i == 174) {
                                printf("--------------------------------\n");
                                printf("// skip number 3 and print the rest\n");
                                printf("int i;\n");
                                printf("for (i = 1; i <= 5; i++) {\n");
                                printf("    if (i == 3)\n");
                                printf("        ___;\n");
                                printf("    printf(\"%%d \", i);\n");
                                printf("}\n");
                                printf("--------------------------------\n");
                                printf("What goes in the blank (___)?\n");
                                printf("  1. continue\n");
                                printf("  2. skip\n");
                                printf("  3. break\n");
                                printf("  4. exit\n");
                            }
                            else if (i == 175) {
                                printf("--------------------------------\n");
                                printf("// keep asking while the password is wrong\n");
                                printf("int pass = 0;\n");
                                printf("while (pass ___ 1234) {\n");
                                printf("    scanf(\"%%d\", &pass);\n");
                                printf("}\n");
                                printf("--------------------------------\n");
                                printf("What goes in the blank (___)?\n");
                                printf("  1. !=\n");
                                printf("  2. ==\n");
                                printf("  3. =\n");
                                printf("  4. >=\n");
                            }
                            else if (i == 176) {
                                printf("--------------------------------\n");
                                printf("// print Pass if marks are 40 or more\n");
                                printf("int marks = 55;\n");
                                printf("if (marks ___ 40)\n");
                                printf("    printf(\"Pass\");\n");
                                printf("--------------------------------\n");
                                printf("What goes in the blank (___)?\n");
                                printf("  1. ==\n");
                                printf("  2. <\n");
                                printf("  3. >=\n");
                                printf("  4. <=\n");
                            }
                            else if (i == 177) {
                                printf("--------------------------------\n");
                                printf("// print all elements of the array\n");
                                printf("int a[3] = {5, 6, 7};\n");
                                printf("int i;\n");
                                printf("for (i = 0; i < ___; i++)\n");
                                printf("    printf(\"%%d \", a[i]);\n");
                                printf("--------------------------------\n");
                                printf("What goes in the blank (___)?\n");
                                printf("  1. 4\n");
                                printf("  2. 3\n");
                                printf("  3. a\n");
                                printf("  4. 2\n");
                            }
                            else if (i == 178) {
                                printf("--------------------------------\n");
                                printf("// run exactly 10 times\n");
                                printf("int count = 0;\n");
                                printf("while (count ___ 10) {\n");
                                printf("    count++;\n");
                                printf("}\n");
                                printf("--------------------------------\n");
                                printf("What goes in the blank (___)?\n");
                                printf("  1. <\n");
                                printf("  2. <=\n");
                                printf("  3. >=\n");
                                printf("  4. >\n");
                            }
                            else if (i == 179) {
                                printf("--------------------------------\n");
                                printf("// check that x is between 1 and 9\n");
                                printf("int x = 4;\n");
                                printf("if (x >= 1 ___ x <= 9)\n");
                                printf("    printf(\"Yes\");\n");
                                printf("--------------------------------\n");
                                printf("What goes in the blank (___)?\n");
                                printf("  1. ||\n");
                                printf("  2. =\n");
                                printf("  3. !\n");
                                printf("  4. &&\n");
                            }

                            else if (i == 180) {
                                printf("--------------------------------\n");
                                printf("// sum of all elements\n");
                                printf("int a[4] = {3, 5, 7, 9};\n");
                                printf("int i, sum = 0;\n");
                                printf("for (i = 0; i < 4; i++) {\n");
                                printf("    sum = sum + ___;\n");
                                printf("}\n");
                                printf("--------------------------------\n");
                                printf("What goes in the blank (___)?\n");
                                printf("  1. i\n");
                                printf("  2. a[4]\n");
                                printf("  3. a\n");
                                printf("  4. a[i]\n");
                            }
                            else if (i == 181) {
                                printf("--------------------------------\n");
                                printf("// find the largest number\n");
                                printf("int a[4] = {4, 9, 2, 7};\n");
                                printf("int max = a[0], i;\n");
                                printf("for (i = 1; i < 4; i++) {\n");
                                printf("    if (a[i] ___ max)\n");
                                printf("        max = a[i];\n");
                                printf("}\n");
                                printf("--------------------------------\n");
                                printf("What goes in the blank (___)?\n");
                                printf("  1. <\n");
                                printf("  2. !=\n");
                                printf("  3. >\n");
                                printf("  4. ==\n");
                            }
                            else if (i == 182) {
                                printf("--------------------------------\n");
                                printf("// count numbers greater than 5\n");
                                printf("int a[5] = {2, 8, 6, 1, 9};\n");
                                printf("int i, count = 0;\n");
                                printf("for (i = 0; i < 5; i++) {\n");
                                printf("    if (a[i] > 5)\n");
                                printf("        ___;\n");
                                printf("}\n");
                                printf("--------------------------------\n");
                                printf("What goes in the blank (___)?\n");
                                printf("  1. count--\n");
                                printf("  2. count = 1\n");
                                printf("  3. a[i]++\n");
                                printf("  4. count++\n");
                            }
                            else if (i == 183) {
                                printf("--------------------------------\n");
                                printf("// copy array a into array b\n");
                                printf("int a[3] = {1, 2, 3};\n");
                                printf("int b[3], i;\n");
                                printf("for (i = 0; i < 3; i++)\n");
                                printf("    b[___] = a[i];\n");
                                printf("--------------------------------\n");
                                printf("What goes in the blank (___)?\n");
                                printf("  1. 0\n");
                                printf("  2. i\n");
                                printf("  3. a\n");
                                printf("  4. 3\n");
                            }
                            else if (i == 184) {
                                printf("--------------------------------\n");
                                printf("// print the array in reverse order\n");
                                printf("int a[4] = {1, 2, 3, 4};\n");
                                printf("int i;\n");
                                printf("for (i = ___; i >= 0; i--)\n");
                                printf("    printf(\"%%d \", a[i]);\n");
                                printf("--------------------------------\n");
                                printf("What goes in the blank (___)?\n");
                                printf("  1. 2\n");
                                printf("  2. 3\n");
                                printf("  3. 4\n");
                                printf("  4. 1\n");
                            }
                            else if (i == 185) {
                                printf("--------------------------------\n");
                                printf("// count the digits of n\n");
                                printf("int n = 4567, count = 0;\n");
                                printf("while (n != 0) {\n");
                                printf("    n = n ___ 10;\n");
                                printf("    count++;\n");
                                printf("}\n");
                                printf("--------------------------------\n");
                                printf("What goes in the blank (___)?\n");
                                printf("  1. %%\n");
                                printf("  2. *\n");
                                printf("  3. +\n");
                                printf("  4. /\n");
                            }
                            else if (i == 186) {
                                printf("--------------------------------\n");
                                printf("// get the last digit of n\n");
                                printf("int n = 1234;\n");
                                printf("int last = n ___ 10;\n");
                                printf("--------------------------------\n");
                                printf("What goes in the blank (___)?\n");
                                printf("  1. %%\n");
                                printf("  2. *\n");
                                printf("  3. /\n");
                                printf("  4. -\n");
                            }
                            else if (i == 187) {
                                printf("--------------------------------\n");
                                printf("// linear search: stop when 9 is found\n");
                                printf("int a[5] = {4, 8, 1, 9, 3};\n");
                                printf("int i, found = 0;\n");
                                printf("for (i = 0; i < 5; i++) {\n");
                                printf("    if (a[i] == 9) {\n");
                                printf("        found = 1;\n");
                                printf("        ___;\n");
                                printf("    }\n");
                                printf("}\n");
                                printf("--------------------------------\n");
                                printf("What goes in the blank (___)?\n");
                                printf("  1. continue\n");
                                printf("  2. i++\n");
                                printf("  3. break\n");
                                printf("  4. found\n");
                            }
                            else if (i == 188) {
                                printf("--------------------------------\n");
                                printf("// swap a[0] and a[1] using a temporary variable\n");
                                printf("int a[2] = {5, 9};\n");
                                printf("int t;\n");
                                printf("t = a[0];\n");
                                printf("a[0] = a[1];\n");
                                printf("a[1] = ___;\n");
                                printf("--------------------------------\n");
                                printf("What goes in the blank (___)?\n");
                                printf("  1. t\n");
                                printf("  2. a[1]\n");
                                printf("  3. 5\n");
                                printf("  4. a[0]\n");
                            }
                            else if (i == 189) {
                                printf("--------------------------------\n");
                                printf("// check if n is odd\n");
                                printf("int n = 7;\n");
                                printf("if (n %% 2 ___ 1)\n");
                                printf("    printf(\"Odd\");\n");
                                printf("--------------------------------\n");
                                printf("What goes in the blank (___)?\n");
                                printf("  1. >\n");
                                printf("  2. ==\n");
                                printf("  3. !=\n");
                                printf("  4. <\n");
                            }

                            else if (i == 190) {
                                printf("--------------------------------\n");
                                printf("// factorial of 5\n");
                                printf("int n = 5, i, fact = 1;\n");
                                printf("for (i = 1; i <= n; i++) {\n");
                                printf("    fact = fact ___ i;\n");
                                printf("}\n");
                                printf("--------------------------------\n");
                                printf("What goes in the blank (___)?\n");
                                printf("  1. +\n");
                                printf("  2. /\n");
                                printf("  3. *\n");
                                printf("  4. %%\n");
                            }
                            else if (i == 191) {
                                printf("--------------------------------\n");
                                printf("// print a triangle of stars\n");
                                printf("// row 1: *   row 2: **   row 3: ***\n");
                                printf("int i, j;\n");
                                printf("for (i = 1; i <= 3; i++) {\n");
                                printf("    for (j = 1; j <= ___; j++) {\n");
                                printf("        printf(\"*\");\n");
                                printf("    }\n");
                                printf("    printf(\"\\n\");\n");
                                printf("}\n");
                                printf("--------------------------------\n");
                                printf("What goes in the blank (___)?\n");
                                printf("  1. i\n");
                                printf("  2. j\n");
                                printf("  3. 3\n");
                                printf("  4. i + 1\n");
                            }
                            else if (i == 192) {
                                printf("--------------------------------\n");
                                printf("// bubble sort (smallest first)\n");
                                printf("int a[4] = {4, 3, 2, 1};\n");
                                printf("int i, j, t;\n");
                                printf("for (i = 0; i < 3; i++) {\n");
                                printf("    for (j = 0; j < 3 - i; j++) {\n");
                                printf("        if (a[j] ___ a[j + 1]) {\n");
                                printf("            t = a[j];\n");
                                printf("            a[j] = a[j + 1];\n");
                                printf("            a[j + 1] = t;\n");
                                printf("        }\n");
                                printf("    }\n");
                                printf("}\n");
                                printf("--------------------------------\n");
                                printf("What goes in the blank (___)?\n");
                                printf("  1. !=\n");
                                printf("  2. >\n");
                                printf("  3. ==\n");
                                printf("  4. <\n");
                            }
                            else if (i == 193) {
                                printf("--------------------------------\n");
                                printf("// prime check: n is NOT prime if i divides it\n");
                                printf("int n = 7, i, isPrime = 1;\n");
                                printf("for (i = 2; i < n; i++) {\n");
                                printf("    if (n %% i == 0)\n");
                                printf("        isPrime = ___;\n");
                                printf("}\n");
                                printf("--------------------------------\n");
                                printf("What goes in the blank (___)?\n");
                                printf("  1. n\n");
                                printf("  2. 0\n");
                                printf("  3. i\n");
                                printf("  4. 1\n");
                            }
                            else if (i == 194) {
                                printf("--------------------------------\n");
                                printf("// reverse a number\n");
                                printf("int n = 123, rev = 0;\n");
                                printf("while (n > 0) {\n");
                                printf("    rev = rev * 10 + n ___ 10;\n");
                                printf("    n = n / 10;\n");
                                printf("}\n");
                                printf("--------------------------------\n");
                                printf("What goes in the blank (___)?\n");
                                printf("  1. +\n");
                                printf("  2. *\n");
                                printf("  3. %%\n");
                                printf("  4. /\n");
                            }
                            else if (i == 195) {
                                printf("--------------------------------\n");
                                printf("// Fibonacci: print the first 6 numbers\n");
                                printf("int a = 0, b = 1, next, i;\n");
                                printf("for (i = 0; i < 6; i++) {\n");
                                printf("    printf(\"%%d \", a);\n");
                                printf("    next = a + b;\n");
                                printf("    a = b;\n");
                                printf("    b = ___;\n");
                                printf("}\n");
                                printf("--------------------------------\n");
                                printf("What goes in the blank (___)?\n");
                                printf("  1. b\n");
                                printf("  2. 1\n");
                                printf("  3. a\n");
                                printf("  4. next\n");
                            }
                            else if (i == 196) {
                                printf("--------------------------------\n");
                                printf("// print the largest of 3 numbers\n");
                                printf("int a = 4, b = 9, c = 6;\n");
                                printf("if (a > b && a > c)\n");
                                printf("    printf(\"%%d\", a);\n");
                                printf("else if (b > a ___ b > c)\n");
                                printf("    printf(\"%%d\", b);\n");
                                printf("else\n");
                                printf("    printf(\"%%d\", c);\n");
                                printf("--------------------------------\n");
                                printf("What goes in the blank (___)?\n");
                                printf("  1. ==\n");
                                printf("  2. &&\n");
                                printf("  3. ||\n");
                                printf("  4. !\n");
                            }
                            else if (i == 197) {
                                printf("--------------------------------\n");
                                printf("// add the elements at index 0, 2 and 4\n");
                                printf("int a[6] = {1, 2, 3, 4, 5, 6};\n");
                                printf("int i, sum = 0;\n");
                                printf("for (i = 0; i < 6; i += ___)\n");
                                printf("    sum = sum + a[i];\n");
                                printf("--------------------------------\n");
                                printf("What goes in the blank (___)?\n");
                                printf("  1. 0\n");
                                printf("  2. 2\n");
                                printf("  3. 3\n");
                                printf("  4. 1\n");
                            }
                            else if (i == 198) {
                                printf("--------------------------------\n");
                                printf("// swap the first and last element\n");
                                printf("int a[5] = {1, 2, 3, 4, 5};\n");
                                printf("int t;\n");
                                printf("t = a[0];\n");
                                printf("a[0] = a[___];\n");
                                printf("a[4] = t;\n");
                                printf("--------------------------------\n");
                                printf("What goes in the blank (___)?\n");
                                printf("  1. 0\n");
                                printf("  2. 1\n");
                                printf("  3. 4\n");
                                printf("  4. 5\n");
                            }
                            else if (i == 199) {
                                printf("--------------------------------\n");
                                printf("// print this pattern:  1   12   123\n");
                                printf("int i, j;\n");
                                printf("for (i = 1; i <= 3; i++) {\n");
                                printf("    for (j = 1; j <= i; j++) {\n");
                                printf("        printf(\"%%d\", ___);\n");
                                printf("    }\n");
                                printf("    printf(\"\\n\");\n");
                                printf("}\n");
                                printf("--------------------------------\n");
                                printf("What goes in the blank (___)?\n");
                                printf("  1. i\n");
                                printf("  2. i + j\n");
                                printf("  3. j\n");
                                printf("  4. 3\n");
                            }

                            for (answer = 'z'; answer != '1' && answer != '2' && answer != '3' && answer != '4'; ) {
                                printf("Your answer (1-4): ");
                                if (!read_char(&answer)) {
                                    return 0;
                                }
                            }

                            if (answer == right[i]) {
                                printf("Correct! +1 point\n");
                                score++;
                            }

                            if (i == 0) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. ;\n", right[i]);
                                }
                                printf("Explanation: Most C statements end with a semicolon (;).\n");
                            }
                            else if (i == 1) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. int\n", right[i]);
                                }
                                printf("Explanation: int stores whole numbers. float and double store decimals.\n");
                            }
                            else if (i == 2) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. %%f\n", right[i]);
                                }
                                printf("Explanation: %%f prints a float. %%d is for int, %%c is for char, %%s is for text.\n");
                            }
                            else if (i == 3) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. char\n", right[i]);
                                }
                                printf("Explanation: char stores one character, written inside single quotes 'A'.\n");
                            }
                            else if (i == 4) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. marks_2\n", right[i]);
                                }
                                printf("Explanation: Names use letters, digits and _, cannot start with a digit, cannot have spaces and cannot be a keyword.\n");
                            }
                            else if (i == 5) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. printf()\n", right[i]);
                                }
                                printf("Explanation: printf() prints. scanf() reads input from the keyboard.\n");
                            }
                            else if (i == 6) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. scanf()\n", right[i]);
                                }
                                printf("Explanation: scanf() reads input, for example scanf(\"%%d\", &age);\n");
                            }
                            else if (i == 7) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. <stdio.h>\n", right[i]);
                                }
                                printf("Explanation: stdio.h means standard input/output. It holds printf and scanf.\n");
                            }
                            else if (i == 8) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. // comment\n", right[i]);
                                }
                                printf("Explanation: // starts a single-line comment. The compiler ignores it.\n");
                            }
                            else if (i == 9) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. *\n", right[i]);
                                }
                                printf("Explanation: * multiplies. %% gives the remainder and & is used with scanf.\n");
                            }

                            else if (i == 10) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 3\n", right[i]);
                                }
                                printf("Explanation: Both numbers are int, so the decimal part is dropped: 7/2 = 3.\n");
                            }
                            else if (i == 11) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 2\n", right[i]);
                                }
                                printf("Explanation: %% gives the remainder. 17 divided by 5 is 3 with remainder 2.\n");
                            }
                            else if (i == 12) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. if (x == 5)\n", right[i]);
                                }
                                printf("Explanation: == compares values. A single = assigns a value (a common bug!).\n");
                            }
                            else if (i == 13) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. !=\n", right[i]);
                                }
                                printf("Explanation: != is the 'not equal to' operator in C.\n");
                            }
                            else if (i == 14) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. Assigns a value\n", right[i]);
                                }
                                printf("Explanation: = stores the right side value in the variable on the left. Use == to compare.\n");
                            }
                            else if (i == 15) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 1\n", right[i]);
                                }
                                printf("Explanation: char takes 1 byte. int and float usually take 4, double takes 8.\n");
                            }
                            else if (i == 16) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. float x = 2.5;\n", right[i]);
                                }
                                printf("Explanation: A decimal needs float or double. An int would drop the .5 part.\n");
                            }
                            else if (i == 17) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. x = x + 5\n", right[i]);
                                }
                                printf("Explanation: += adds the right side to the variable. It is a shortcut for x = x + 5.\n");
                            }
                            else if (i == 18) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. &&\n", right[i]);
                                }
                                printf("Explanation: && is AND (both true), || is OR (one true), ! is NOT.\n");
                            }
                            else if (i == 19) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 14\n", right[i]);
                                }
                                printf("Explanation: Multiplication comes first: 3 * 4 = 12, then 2 + 12 = 14.\n");
                            }

                            else if (i == 20) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. do-while loop\n", right[i]);
                                }
                                printf("Explanation: do-while checks the condition AFTER running the body once.\n");
                            }
                            else if (i == 21) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 0 to 4\n", right[i]);
                                }
                                printf("Explanation: Array indexes start from 0, so size 5 means indexes 0 to 4.\n");
                            }
                            else if (i == 22) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. a=6, b=6\n", right[i]);
                                }
                                printf("Explanation: ++a adds 1 FIRST, then gives the new value. So both are 6.\n");
                            }
                            else if (i == 23) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. continue\n", right[i]);
                                }
                                printf("Explanation: continue jumps to the next round. break leaves the loop completely.\n");
                            }
                            else if (i == 24) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. x is between 0 and 10 (not 0 or 10)\n", right[i]);
                                }
                                printf("Explanation: && means BOTH conditions must be true: x > 0 and x < 10.\n");
                            }
                            else if (i == 25) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. When the if condition is false\n", right[i]);
                                }
                                printf("Explanation: else runs only when the if condition is false.\n");
                            }
                            else if (i == 26) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. It becomes an infinite loop\n", right[i]);
                                }
                                printf("Explanation: i never changes, so the condition stays true forever.\n");
                            }
                            else if (i == 27) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 0\n", right[i]);
                                }
                                printf("Explanation: 0 is false. Every other value is true.\n");
                            }
                            else if (i == 28) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. i = 0 (initialization)\n", right[i]);
                                }
                                printf("Explanation: Order: initialization once, then condition, body, update, condition, body, update...\n");
                            }
                            else if (i == 29) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. int a[10];\n", right[i]);
                                }
                                printf("Explanation: Arrays use square brackets: datatype name[size];\n");
                            }

                            else if (i == 30) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. a=6, b=5\n", right[i]);
                                }
                                printf("Explanation: b = a++ gives b the OLD value (5) first, then a becomes 6.\n");
                            }
                            else if (i == 31) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 0\n", right[i]);
                                }
                                printf("Explanation: When you give fewer values, the remaining elements become 0.\n");
                            }
                            else if (i == 32) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. a[3] is out of bounds\n", right[i]);
                                }
                                printf("Explanation: The valid indexes are 0, 1, 2. a[3] reads memory outside the array.\n");
                            }
                            else if (i == 33) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. for (i = 0; i < 6; i++)\n", right[i]);
                                }
                                printf("Explanation: Indexes are 0 to 5, so i starts at 0 and must stay below 6.\n");
                            }
                            else if (i == 34) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 12\n", right[i]);
                                }
                                printf("Explanation: The inner loop runs 4 times for each of the 3 outer rounds: 3 x 4 = 12.\n");
                            }
                            else if (i == 35) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. n %% 2 == 0\n", right[i]);
                                }
                                printf("Explanation: An even number leaves remainder 0 when divided by 2.\n");
                            }
                            else if (i == 36) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. break\n", right[i]);
                                }
                                printf("Explanation: break leaves the loop it is written in. The outer loop keeps going.\n");
                            }
                            else if (i == 37) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. Reads an int from the keyboard into age\n", right[i]);
                                }
                                printf("Explanation: scanf reads input and stores it in the variable.\n");
                            }
                            else if (i == 38) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. It tells scanf where to store the value\n", right[i]);
                                }
                                printf("Explanation: scanf needs to know WHERE the variable lives in memory to change it.\n");
                            }
                            else if (i == 39) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. while loop\n", right[i]);
                                }
                                printf("Explanation: A while loop repeats until a condition changes, for example until the user enters 0.\n");
                            }

                            else if (i == 40) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 4\n", right[i]);
                                }
                                printf("Explanation: int usually takes 4 bytes on modern computers.\n");
                            }
                            else if (i == 41) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 2.5\n", right[i]);
                                }
                                printf("Explanation: 5 / 2.0 uses a decimal number, so C gives 2.5 (no integer division).\n");
                            }
                            else if (i == 42) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 0 (false)\n", right[i]);
                                }
                                printf("Explanation: 10 > 5 is 1 (true), then 1 > 2 is 0 (false). C checks left to right.\n");
                            }
                            else if (i == 43) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 3\n", right[i]);
                                }
                                printf("Explanation: Type casting to int cuts off the decimal part. It does not round.\n");
                            }
                            else if (i == 44) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 2\n", right[i]);
                                }
                                printf("Explanation: a[0] is 5, so the index is 5 - 4 = 1, and a[1] is 2.\n");
                            }
                            else if (i == 45) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 9\n", right[i]);
                                }
                                printf("Explanation: %% and * go first (left to right): 3 %% 2 = 1, then 1 * 4 = 4, then 5 + 4 = 9.\n");
                            }
                            else if (i == 46) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 6\n", right[i]);
                                }
                                printf("Explanation: Left to right: 7 / 2 = 3 (integer division), then 3 * 2 = 6.\n");
                            }
                            else if (i == 47) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. All elements have the same type\n", right[i]);
                                }
                                printf("Explanation: An array holds many values of ONE type, and its size is fixed. Indexes start at 0.\n");
                            }
                            else if (i == 48) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. Adds 1 to element number i\n", right[i]);
                                }
                                printf("Explanation: It reads element i, adds 1 and stores it back in the same place.\n");
                            }
                            else if (i == 49) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. To visit every element without repeating code\n", right[i]);
                                }
                                printf("Explanation: A loop with the index i lets one line of code work on every element.\n");
                            }

                            else if (i == 50) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 7\n", right[i]);
                                }
                                printf("Explanation: 3 + 4 = 7. The + operator adds numbers.\n");
                            }
                            else if (i == 51) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. Big\n", right[i]);
                                }
                                printf("Explanation: x is 10, so x > 5 is true and the if part runs: Big.\n");
                            }
                            else if (i == 52) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 1 2 3\n", right[i]);
                                }
                                printf("Explanation: i goes 1, 2, 3 and prints each value.\n");
                            }
                            else if (i == 53) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. A\n", right[i]);
                                }
                                printf("Explanation: %%c prints the character itself: A.\n");
                            }
                            else if (i == 54) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 24\n", right[i]);
                                }
                                printf("Explanation: 6 * 4 = 24.\n");
                            }
                            else if (i == 55) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 2.500000\n", right[i]);
                                }
                                printf("Explanation: %%f prints 6 digits after the point: 2.500000.\n");
                            }
                            else if (i == 56) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. HelloWorld\n", right[i]);
                                }
                                printf("Explanation: printf does not add a space or a new line by itself, so the words join.\n");
                            }
                            else if (i == 57) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. x = 7\n", right[i]);
                                }
                                printf("Explanation: Normal text is printed as it is, and %%d is replaced by the value of x.\n");
                            }
                            else if (i == 58) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. Yes\n", right[i]);
                                }
                                printf("Explanation: x == 5 is true, so only the if part runs.\n");
                            }
                            else if (i == 59) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. ***\n", right[i]);
                                }
                                printf("Explanation: i is 0, 1, 2 so the loop runs 3 times and prints 3 stars.\n");
                            }

                            else if (i == 60) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. B\n", right[i]);
                                }
                                printf("Explanation: x is 5. x > 5 is false, but x == 5 is true. Only B prints.\n");
                            }
                            else if (i == 61) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 12\n", right[i]);
                                }
                                printf("Explanation: a[1] is 4 and a[3] is 8 (indexes start at 0). 4 + 8 = 12.\n");
                            }
                            else if (i == 62) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 1 2\n", right[i]);
                                }
                                printf("Explanation: When i becomes 3, break ends the loop. Only 1 and 2 were printed.\n");
                            }
                            else if (i == 63) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 3\n", right[i]);
                                }
                                printf("Explanation: int divided by int drops the decimal part: 7 / 2 = 3.\n");
                            }
                            else if (i == 64) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 2\n", right[i]);
                                }
                                printf("Explanation: %% gives the remainder: 17 = 3 x 5 + 2.\n");
                            }
                            else if (i == 65) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 5 4 3 2 1\n", right[i]);
                                }
                                printf("Explanation: i starts at 5 and goes down by 1 until it is 1.\n");
                            }
                            else if (i == 66) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 12\n", right[i]);
                                }
                                printf("Explanation: 10 + 5 = 15, then 15 - 3 = 12.\n");
                            }
                            else if (i == 67) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. Young\n", right[i]);
                                }
                                printf("Explanation: Both conditions are true (20 >= 18 and 20 <= 25), so Young prints.\n");
                            }
                            else if (i == 68) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 1 2 4 5\n", right[i]);
                                }
                                printf("Explanation: continue skips only the round where i is 3. The loop goes on.\n");
                            }
                            else if (i == 69) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 8\n", right[i]);
                                }
                                printf("Explanation: Multiplication goes first: 3 * 2 = 6, then 2 + 6 = 8.\n");
                            }

                            else if (i == 70) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 6\n", right[i]);
                                }
                                printf("Explanation: Only even numbers are added: 2 + 4 = 6.\n");
                            }
                            else if (i == 71) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 12\n", right[i]);
                                }
                                printf("Explanation: i goes 0, 3, 6, 9, 12. At 12 the condition fails, so it prints 12.\n");
                            }
                            else if (i == 72) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 9\n", right[i]);
                                }
                                printf("Explanation: The loop keeps the biggest value it has seen. The largest is 9.\n");
                            }
                            else if (i == 73) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 15\n", right[i]);
                                }
                                printf("Explanation: 1 + 2 + 3 + 4 + 5 = 15.\n");
                            }
                            else if (i == 74) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 1\n", right[i]);
                                }
                                printf("Explanation: do-while runs the body once BEFORE checking the condition, so 1 prints.\n");
                            }
                            else if (i == 75) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 10\n", right[i]);
                                }
                                printf("Explanation: Every element is doubled, so a[4] becomes 5 * 2 = 10.\n");
                            }
                            else if (i == 76) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. Odd\n", right[i]);
                                }
                                printf("Explanation: 15 %% 2 is 1, not 0, so the number is odd.\n");
                            }
                            else if (i == 77) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 3\n", right[i]);
                                }
                                printf("Explanation: Multiples of 3 up to 10 are 3, 6, 9. So count is 3.\n");
                            }
                            else if (i == 78) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 9\n", right[i]);
                                }
                                printf("Explanation: a > b is false, so the else part prints b, which is 9.\n");
                            }
                            else if (i == 79) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. ***-***-\n", right[i]);
                                }
                                printf("Explanation: Each outer round prints 3 stars then a dash. Two rounds: ***-***-\n");
                            }

                            else if (i == 80) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 9\n", right[i]);
                                }
                                printf("Explanation: i = 0, 2, 4 so it adds a[0] + a[2] + a[4] = 1 + 3 + 5 = 9.\n");
                            }
                            else if (i == 81) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 3 2\n", right[i]);
                                }
                                printf("Explanation: 17 / 5 = 3 (integer division) and 17 %% 5 = 2 (the remainder).\n");
                            }
                            else if (i == 82) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 6 5\n", right[i]);
                                }
                                printf("Explanation: b gets the OLD value of a (5), then a becomes 6.\n");
                            }
                            else if (i == 83) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 10\n", right[i]);
                                }
                                printf("Explanation: The sum is 30 and 30 / 3 = 10. This is the average.\n");
                            }
                            else if (i == 84) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 10\n", right[i]);
                                }
                                printf("Explanation: It adds the digits one by one: 4 + 3 + 2 + 1 = 10.\n");
                            }
                            else if (i == 85) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 6\n", right[i]);
                                }
                                printf("Explanation: The inner loop runs 1, then 2, then 3 times: 1 + 2 + 3 = 6.\n");
                            }
                            else if (i == 86) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 4 1\n", right[i]);
                                }
                                printf("Explanation: The temporary variable t helps swap the two elements: a[0] becomes 4 and a[3] becomes 1.\n");
                            }
                            else if (i == 87) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. A\n", right[i]);
                                }
                                printf("Explanation: x > 10 is true, then x > 15 is also true, so A prints.\n");
                            }
                            else if (i == 88) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 10 6 2\n", right[i]);
                                }
                                printf("Explanation: i goes 10, 6, 2. Next it would be -2, and the condition i > 0 fails.\n");
                            }
                            else if (i == 89) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 1\n", right[i]);
                                }
                                printf("Explanation: The loop keeps the smallest value it has seen. The smallest is 1.\n");
                            }

                            else if (i == 90) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. C 67\n", right[i]);
                                }
                                printf("Explanation: 'A' is 65. 65 + 2 = 67, which is the letter C.\n");
                            }
                            else if (i == 91) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 5 7 7\n", right[i]);
                                }
                                printf("Explanation: i++ prints 5 then makes i 6. ++i makes i 7 then prints 7. Last print: 7.\n");
                            }
                            else if (i == 92) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 3\n", right[i]);
                                }
                                printf("Explanation: break only exits the INNER loop. Each outer round counts once, so 3.\n");
                            }
                            else if (i == 93) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 3 2 1 4\n", right[i]);
                                }
                                printf("Explanation: One bubble-sort pass pushes the biggest number (4) to the end.\n");
                            }
                            else if (i == 94) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 1 2 3\n", right[i]);
                                }
                                printf("Explanation: The loop swaps every pair twice, so the array ends up unchanged.\n");
                            }
                            else if (i == 95) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 9 7\n", right[i]);
                                }
                                printf("Explanation: x-- gives 10 first, so y = 10 - 3 = 7. Then x becomes 9.\n");
                            }
                            else if (i == 96) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 18\n", right[i]);
                                }
                                printf("Explanation: i goes 4, 2, 0 so it adds a[4] + a[2] + a[0] = 10 + 6 + 2 = 18.\n");
                            }
                            else if (i == 97) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 149\n", right[i]);
                                }
                                printf("Explanation: It prints the squares 1, 4, 9 next to each other with no spaces.\n");
                            }
                            else if (i == 98) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 16\n", right[i]);
                                }
                                printf("Explanation: Even numbers are skipped. It adds 1 + 3 + 5 + 7 = 16, then i = 9 triggers break.\n");
                            }
                            else if (i == 99) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 123233\n", right[i]);
                                }
                                printf("Explanation: i = 1 prints 123, i = 2 prints 23, i = 3 prints 3. Together: 123233.\n");
                            }

                            else if (i == 100) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. Line 3\n", right[i]);
                                }
                                printf("Explanation: Line 3 is missing a semicolon (;) at the end.\n");
                            }
                            else if (i == 101) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. Line 1\n", right[i]);
                                }
                                printf("Explanation: Line 1 has no closing double quote. A string must start and end with a quote.\n");
                            }
                            else if (i == 102) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. Line 2\n", right[i]);
                                }
                                printf("Explanation: Line 2 uses sum but it was never declared. Write: int sum = a * 2;\n");
                            }
                            else if (i == 103) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. Line 2\n", right[i]);
                                }
                                printf("Explanation: A variable name cannot start with a digit. 1st is not allowed.\n");
                            }
                            else if (i == 104) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. Line 2\n", right[i]);
                                }
                                printf("Explanation: Line 2 is missing a semicolon (;) at the end.\n");
                            }
                            else if (i == 105) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. Line 3\n", right[i]);
                                }
                                printf("Explanation: Line 3 is missing the closing bracket ) of printf.\n");
                            }
                            else if (i == 106) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. Line 2\n", right[i]);
                                }
                                printf("Explanation: C is case-sensitive. Printf is not the same as printf.\n");
                            }
                            else if (i == 107) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. Line 4\n", right[i]);
                                }
                                printf("Explanation: Line 4 uses c, but no variable named c was declared.\n");
                            }
                            else if (i == 108) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. Line 4\n", right[i]);
                                }
                                printf("Explanation: Line 4 is missing a comma between \"%%d\" and b.\n");
                            }
                            else if (i == 109) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. Line 2\n", right[i]);
                                }
                                printf("Explanation: Line 2 has + with nothing after it. An operator needs a value on both sides.\n");
                            }

                            else if (i == 110) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. Line 2\n", right[i]);
                                }
                                printf("Explanation: Line 2 uses = (assign) instead of == (compare).\n");
                            }
                            else if (i == 111) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. Line 3\n", right[i]);
                                }
                                printf("Explanation: i <= 3 makes the loop read a[3]. Valid indexes are 0 to 2, so use i < 3.\n");
                            }
                            else if (i == 112) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. Line 1\n", right[i]);
                                }
                                printf("Explanation: A char uses single quotes: 'A'. Double quotes make a string.\n");
                            }
                            else if (i == 113) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. Line 2\n", right[i]);
                                }
                                printf("Explanation: The condition of an if must be inside brackets: if (x > 5)\n");
                            }
                            else if (i == 114) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. Line 3\n", right[i]);
                                }
                                printf("Explanation: A float needs %%f. %%d is only for int.\n");
                            }
                            else if (i == 115) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. Line 2\n", right[i]);
                                }
                                printf("Explanation: The ; after the for ends the loop, so printf runs only once, after the loop.\n");
                            }
                            else if (i == 116) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. Line 4\n", right[i]);
                                }
                                printf("Explanation: else has no condition. Use else if (marks >= 70) to test another condition.\n");
                            }
                            else if (i == 117) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. Line 3\n", right[i]);
                                }
                                printf("Explanation: Line 3 divides by zero because b is 0. The program will crash.\n");
                            }
                            else if (i == 118) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. Line 3\n", right[i]);
                                }
                                printf("Explanation: a / b is integer division (5 / 2 = 2). Use a / 2.0 or (float) a / b.\n");
                            }
                            else if (i == 119) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. Line 1\n", right[i]);
                                }
                                printf("Explanation: The array has size 3 but 4 values were given. One value is too many.\n");
                            }

                            else if (i == 120) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. Line 3\n", right[i]);
                                }
                                printf("Explanation: price + tax is a float, so use %%f. %%d is only for int.\n");
                            }
                            else if (i == 121) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. Line 5\n", right[i]);
                                }
                                printf("Explanation: The array has indexes 0 to 4. Line 5 reads a[5], which is out of bounds.\n");
                            }
                            else if (i == 122) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. Line 2\n", right[i]);
                                }
                                printf("Explanation: The ; after while makes an empty loop that never ends. Remove it.\n");
                            }
                            else if (i == 123) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. Line 4\n", right[i]);
                                }
                                printf("Explanation: Line 4 uses = (assign) instead of == (compare). You cannot assign to i %% 2.\n");
                            }
                            else if (i == 124) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. Line 2\n", right[i]);
                                }
                                printf("Explanation: Each side of && needs a full condition: x > 5 && x < 20\n");
                            }
                            else if (i == 125) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. Line 2\n", right[i]);
                                }
                                printf("Explanation: sum was never given a starting value, so it holds garbage. Use: int sum = 0, i;\n");
                            }
                            else if (i == 126) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. Line 6\n", right[i]);
                                }
                                printf("Explanation: An if can have only one plain else. Line 6 is a second else with no if.\n");
                            }
                            else if (i == 127) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. Line 5\n", right[i]);
                                }
                                printf("Explanation: i++ makes i bigger forever. To count down use i--.\n");
                            }
                            else if (i == 128) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. Line 4\n", right[i]);
                                }
                                printf("Explanation: a == b only compares. To copy the value use a = b;\n");
                            }
                            else if (i == 129) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. Line 3\n", right[i]);
                                }
                                printf("Explanation: The ; after the for makes an empty loop, so line 4 runs once with i = 4 (out of bounds).\n");
                            }

                            else if (i == 130) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. Line 2\n", right[i]);
                                }
                                printf("Explanation: The ; after if (...) ends the if, so else has no if. The compiler complains at else, but the bug is on Line 2.\n");
                            }
                            else if (i == 131) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. Line 3\n", right[i]);
                                }
                                printf("Explanation: A for loop needs semicolons, not commas: for (i = 0; i < 3; i++)\n");
                            }
                            else if (i == 132) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. Line 4\n", right[i]);
                                }
                                printf("Explanation: got / total is integer division (45 / 60 = 0). Use got * 100.0 / total.\n");
                            }
                            else if (i == 133) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. Line 5\n", right[i]);
                                }
                                printf("Explanation: Line 5 uses = (assign) instead of == (compare). It also overwrites the array!\n");
                            }
                            else if (i == 134) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. Line 4\n", right[i]);
                                }
                                printf("Explanation: The inner loop changes i instead of j, so j never grows and the loop never ends.\n");
                            }
                            else if (i == 135) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. Line 3\n", right[i]);
                                }
                                printf("Explanation: i < 5 stops before 5, so only 1 to 4 print. Use i <= 5.\n");
                            }
                            else if (i == 136) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. Line 5\n", right[i]);
                                }
                                printf("Explanation: a is the whole array. To change one element write a[i] = a[i] + 10;\n");
                            }
                            else if (i == 137) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. Line 5\n", right[i]);
                                }
                                printf("Explanation: %% 2 == 1 counts ODD numbers. Even numbers leave remainder 0.\n");
                            }
                            else if (i == 138) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. Line 5\n", right[i]);
                                }
                                printf("Explanation: sum = a[i] replaces the total every round. It must add: sum = sum + a[i];\n");
                            }
                            else if (i == 139) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. Line 5\n", right[i]);
                                }
                                printf("Explanation: After a = b, the old a is lost. The last step must be b = t;\n");
                            }

                            else if (i == 140) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. Line 3\n", right[i]);
                                }
                                printf("Explanation: fact starts at 0, so 0 * anything stays 0. It must start at 1.\n");
                            }
                            else if (i == 141) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. Line 5\n", right[i]);
                                }
                                printf("Explanation: When n %% i == 0 the number is NOT prime, so isPrime must become 0, not 1.\n");
                            }
                            else if (i == 142) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. Line 4\n", right[i]);
                                }
                                printf("Explanation: The loop runs 5 times, so every pair is swapped twice (back to the start). Loop only half: i < 2.\n");
                            }
                            else if (i == 143) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. Line 5\n", right[i]);
                                }
                                printf("Explanation: When j is 3, a[j + 1] is a[4], which is out of bounds. The inner loop must stop at j < 3.\n");
                            }
                            else if (i == 144) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. Line 4\n", right[i]);
                                }
                                printf("Explanation: To get the LAST digit use n %% 10, not n / 10.\n");
                            }
                            else if (i == 145) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. Line 3\n", right[i]);
                                }
                                printf("Explanation: min starts at 0, which is smaller than every number, so it never changes. Start with min = a[0].\n");
                            }
                            else if (i == 146) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. Line 6\n", right[i]);
                                }
                                printf("Explanation: A do-while must end with a semicolon after the condition: while (i <= 5);\n");
                            }
                            else if (i == 147) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. Line 4\n", right[i]);
                                }
                                printf("Explanation: You cannot copy an array with =. Copy it element by element with a loop.\n");
                            }
                            else if (i == 148) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. Line 4\n", right[i]);
                                }
                                printf("Explanation: A multiplication table needs * not +. Use 3 * i.\n");
                            }
                            else if (i == 149) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. Line 5\n", right[i]);
                                }
                                printf("Explanation: Each digit should add 1, not 2. Use count++ or count = count + 1.\n");
                            }

                            else if (i == 150) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. int\n", right[i]);
                                }
                                printf("Explanation: int is the data type for whole numbers.\n");
                            }
                            else if (i == 151) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. %%f\n", right[i]);
                                }
                                printf("Explanation: %%f is the format specifier for float.\n");
                            }
                            else if (i == 152) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. if\n", right[i]);
                                }
                                printf("Explanation: if checks a condition and runs the code when it is true.\n");
                            }
                            else if (i == 153) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. char\n", right[i]);
                                }
                                printf("Explanation: char stores a single character written in single quotes.\n");
                            }
                            else if (i == 154) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. %%d\n", right[i]);
                                }
                                printf("Explanation: %%d is the format specifier for int.\n");
                            }
                            else if (i == 155) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. &\n", right[i]);
                                }
                                printf("Explanation: scanf needs the address of the variable, written with &.\n");
                            }
                            else if (i == 156) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. \\n\n", right[i]);
                                }
                                printf("Explanation: \\n is the new-line character. It moves the cursor to the next line.\n");
                            }
                            else if (i == 157) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 0\n", right[i]);
                                }
                                printf("Explanation: return 0; tells the system that the program ended without errors.\n");
                            }
                            else if (i == 158) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. +\n", right[i]);
                                }
                                printf("Explanation: + adds two numbers.\n");
                            }
                            else if (i == 159) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. const\n", right[i]);
                                }
                                printf("Explanation: The const keyword makes a value read-only.\n");
                            }

                            else if (i == 160) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. for\n", right[i]);
                                }
                                printf("Explanation: A for loop repeats code a fixed number of times.\n");
                            }
                            else if (i == 161) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. [5]\n", right[i]);
                                }
                                printf("Explanation: Arrays use square brackets, like this: int marks[5];\n");
                            }
                            else if (i == 162) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. !=\n", right[i]);
                                }
                                printf("Explanation: != means 'not equal to'. == means equal, and = assigns.\n");
                            }
                            else if (i == 163) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. %%\n", right[i]);
                                }
                                printf("Explanation: %% gives the remainder of a division.\n");
                            }
                            else if (i == 164) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. &&\n", right[i]);
                                }
                                printf("Explanation: && means AND. Both sides must be true.\n");
                            }
                            else if (i == 165) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. +=\n", right[i]);
                                }
                                printf("Explanation: += adds the value to the variable. x += 5 means x = x + 5.\n");
                            }
                            else if (i == 166) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. --\n", right[i]);
                                }
                                printf("Explanation: i-- reduces i by 1 each round, so the loop counts down.\n");
                            }
                            else if (i == 167) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. ==\n", right[i]);
                                }
                                printf("Explanation: An even number has remainder 0 when divided by 2, so use ==.\n");
                            }
                            else if (i == 168) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. else\n", right[i]);
                                }
                                printf("Explanation: else runs when the if condition is false.\n");
                            }
                            else if (i == 169) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 0\n", right[i]);
                                }
                                printf("Explanation: Array indexes start at 0, so the first element is a[0].\n");
                            }

                            else if (i == 170) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. do\n", right[i]);
                                }
                                printf("Explanation: do { ... } while (condition); runs the body once before checking.\n");
                            }
                            else if (i == 171) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. break\n", right[i]);
                                }
                                printf("Explanation: break leaves the loop immediately.\n");
                            }
                            else if (i == 172) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. %%\n", right[i]);
                                }
                                printf("Explanation: %% gives the remainder. i %% 2 == 0 means i is even.\n");
                            }
                            else if (i == 173) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 0\n", right[i]);
                                }
                                printf("Explanation: A sum must start at 0 so the first addition is correct.\n");
                            }
                            else if (i == 174) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. continue\n", right[i]);
                                }
                                printf("Explanation: continue skips the rest of this round and goes to the next round.\n");
                            }
                            else if (i == 175) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. !=\n", right[i]);
                                }
                                printf("Explanation: The loop must continue while pass is NOT equal to the right password.\n");
                            }
                            else if (i == 176) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. >=\n", right[i]);
                                }
                                printf("Explanation: >= means greater than or equal to.\n");
                            }
                            else if (i == 177) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 3\n", right[i]);
                                }
                                printf("Explanation: The array has 3 elements, so the loop runs while i < 3 (indexes 0, 1, 2).\n");
                            }
                            else if (i == 178) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. <\n", right[i]);
                                }
                                printf("Explanation: count goes 0 to 9 while count < 10, which is exactly 10 rounds.\n");
                            }
                            else if (i == 179) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. &&\n", right[i]);
                                }
                                printf("Explanation: Both conditions must be true, so use && (AND).\n");
                            }

                            else if (i == 180) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. a[i]\n", right[i]);
                                }
                                printf("Explanation: a[i] is the current element. Adding each one gives the total.\n");
                            }
                            else if (i == 181) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. >\n", right[i]);
                                }
                                printf("Explanation: If a[i] is greater than max, it becomes the new max.\n");
                            }
                            else if (i == 182) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. count++\n", right[i]);
                                }
                                printf("Explanation: count++ adds 1 each time the condition is true.\n");
                            }
                            else if (i == 183) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. i\n", right[i]);
                                }
                                printf("Explanation: Each element a[i] must go to the same position b[i].\n");
                            }
                            else if (i == 184) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 3\n", right[i]);
                                }
                                printf("Explanation: The last index of an array of size 4 is 3.\n");
                            }
                            else if (i == 185) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. /\n", right[i]);
                                }
                                printf("Explanation: Dividing by 10 removes the last digit, so the loop counts each digit.\n");
                            }
                            else if (i == 186) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. %%\n", right[i]);
                                }
                                printf("Explanation: n %% 10 is the remainder when dividing by 10, which is the last digit.\n");
                            }
                            else if (i == 187) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. break\n", right[i]);
                                }
                                printf("Explanation: break stops the search as soon as the value is found.\n");
                            }
                            else if (i == 188) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. t\n", right[i]);
                                }
                                printf("Explanation: t holds the old a[0]. Putting it into a[1] completes the swap.\n");
                            }
                            else if (i == 189) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. ==\n", right[i]);
                                }
                                printf("Explanation: An odd number leaves remainder 1 when divided by 2.\n");
                            }

                            else if (i == 190) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. *\n", right[i]);
                                }
                                printf("Explanation: Factorial multiplies 1 * 2 * 3 * 4 * 5, so use *.\n");
                            }
                            else if (i == 191) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. i\n", right[i]);
                                }
                                printf("Explanation: Row i needs i stars, so the inner loop runs until j <= i.\n");
                            }
                            else if (i == 192) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. >\n", right[i]);
                                }
                                printf("Explanation: Swap when the left number is bigger (>), so smaller numbers move left.\n");
                            }
                            else if (i == 193) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 0\n", right[i]);
                                }
                                printf("Explanation: isPrime becomes 0 (false) when a divisor is found.\n");
                            }
                            else if (i == 194) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. %%\n", right[i]);
                                }
                                printf("Explanation: n %% 10 takes the last digit, and rev * 10 shifts the digits already collected.\n");
                            }
                            else if (i == 195) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. next\n", right[i]);
                                }
                                printf("Explanation: The new b is the sum we just stored in next.\n");
                            }
                            else if (i == 196) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. &&\n", right[i]);
                                }
                                printf("Explanation: b is the largest only if it beats BOTH a and c, so use &&.\n");
                            }
                            else if (i == 197) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 2\n", right[i]);
                                }
                                printf("Explanation: i += 2 jumps over one element each round, so i is 0, 2, 4.\n");
                            }
                            else if (i == 198) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. 4\n", right[i]);
                                }
                                printf("Explanation: The last element of an array of size 5 is a[4].\n");
                            }
                            else if (i == 199) {
                                if (answer != right[i]) {
                                    printf("Wrong! The correct answer is %c. j\n", right[i]);
                                }
                                printf("Explanation: Each row prints the numbers 1 up to i, which is the value of j.\n");
                            }
                        }

                        printf("\n==========================================\n");
                        printf("Your score: %d / 10\n", score);

                        if (score == 10) {
                            printf("PERFECT! Level cleared!\n");
                        } else if (score >= passMark) {
                            printf("Level passed!\n");
                        } else {
                            printf("Not passed. You need %d/10. Read the lessons and try again.\n", passMark);
                        }

                        if (score > bestScore[mode * 5 + lv]) {
                            bestScore[mode * 5 + lv] = score;
                        }

                        if (score >= passMark && level == unlocked[mode] && unlocked[mode] < 5) {
                            unlocked[mode]++;
                            next = unlocked[mode] - 1;
                            printf("NEW LEVEL UNLOCKED: ");
                            if (next == 0) printf("EASY");
                            else if (next == 1) printf("PRO");
                            else if (next == 2) printf("ULTRA-PRO");
                            else if (next == 3) printf("LEGENDARY");
                            else if (next == 4) printf("GRANDMASTER");
                            printf("\n");
                        }

                        if (score >= passMark && level == 5) {
                            printf("*** You beat GRANDMASTER in ");
                            if (mode == 0) printf("CLASSIC QUIZ");
                            else if (mode == 1) printf("GUESS THE OUTPUT");
                            else if (mode == 2) printf("BUG HUNTER");
                            else if (mode == 3) printf("FILL IN THE BLANK");
                            printf("! ***\n");
                        }
                        printf("==========================================\n");

                        printf("\nPress Enter to continue...");
                        getchar();
                    }
                }
                else if (level != 0) {
                    printf("\nInvalid level! Enter a number from 0 to 5.\n");
                }
            }
        }

        else if (choice == 'p' || choice == 'P') {
            total = 0;
            printf("\n==========================================\n");
            printf("             MY PROGRESS\n");
            printf("==========================================\n");

            for (i = 0; i < 4; i++) {
                printf("\n");
                if (i == 0) printf("CLASSIC QUIZ");
                else if (i == 1) printf("GUESS THE OUTPUT");
                else if (i == 2) printf("BUG HUNTER");
                else if (i == 3) printf("FILL IN THE BLANK");
                printf("\n");
                for (j = 0; j < 5; j++) {
                    printf("  ");
                    if (j == 0) printf("EASY        ");
                    else if (j == 1) printf("PRO         ");
                    else if (j == 2) printf("ULTRA-PRO   ");
                    else if (j == 3) printf("LEGENDARY   ");
                    else if (j == 4) printf("GRANDMASTER ");
                    if (j < unlocked[i]) {
                        printf("  %d/10\n", bestScore[i * 5 + j]);
                        total = total + bestScore[i * 5 + j];
                    } else {
                        printf("  LOCKED\n");
                    }
                }
            }

            printf("\nTotal points: %d / 200\n", total);

            if (total >= 180) {
                printf("Title: C GRANDMASTER\n");
            } else if (total >= 140) {
                printf("Title: C LEGEND\n");
            } else if (total >= 100) {
                printf("Title: C PRO\n");
            } else if (total >= 50) {
                printf("Title: C LEARNER\n");
            } else {
                printf("Title: NEW LEARNER - keep playing!\n");
            }
            printf("==========================================\n");

            printf("\nPress Enter to go back to the main menu...");
            getchar();
        }

        else if (choice == 'x' || choice == 'X') {
            printf("\nThanks for playing. Keep learning C!\n");
        }
        else {
            printf("\nInvalid choice! Please type 1-9, p or x.\n");
        }
    }

    return 0;
}