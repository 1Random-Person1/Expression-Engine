**\#\#\# Entry 1**  
**Date:** 2026-03-27  
**Entry Type: Engineering Decision**  
**Task worked on:** Tokenizer in Main.cpp and TO DOs in ArrayStack.h  
**Issue or decision:** Implemented a tokenizer based on [Tokenizing a string in C++ \- GeeksforGeeks](https://www.geeksforgeeks.org/cpp/tokenizing-a-string-cpp/) guide  
**Error message/symptom (if applicable):**  
**What I tried:** Tried to follow the guide to understand what the program is doing and how to implement it into the Main.cpp. I also noticed that \#include \<sstream\> was at the top of the main, so I assumed this was the intended pathway.   
**Fix / resolution (or final decision):** To follow the guide and use stringstream to read the string input from the user  
**Commit(s):** Commit made on the 27th

**\#\#\# Entry 2**  
**Date:** 2026-03-28  
**Entry Type: Bug Fix**   
**Task worked on:** Precedence and Postfix detection   
**Issue or decision:** The first initial design had it so that only the first ever token was checked to see if it was an operator or not, if it was, it would return false. This made it so that nothing else was checked after that, except for the first token.   
**Error message/symptom (if applicable):** N/A  
**What I tried:** I went online to see if there was a better way to check the tokens, resulting in me finding a guide that explained to use isdigit and isOperator methods to check instead.   
**Fix / resolution (or final decision):** I used a loop that included both checks for isdigit and isOperator to check every token if it's one or the other. I also included a counter to check how many tokens have been read so far, and that if the token was an operator, if the counter was less than 2, it would return a false. Also fixed a bug where the counter wouldn’t change, and \[3 4\] was considered a valid input.   
**Commit(s):** Commits made on the 28th

**\#\#\# Entry 3**  
**Date:** 2026-03-29  
**Entry Type:** Edge Case  
**Task worked on:** Infix detection/validation  
**Issue or decision:** Decided to implement a loop, where it checks if a digit is in the odd place and if an operator is in the even place.   
**Error message/symptom (if applicable):** N/A  
**What I tried:** An implementation of a simple system that checks if the digit and operator are alternating without checking for parentheses. This was meant to be a trial run to see if an even/odd check would work for the program.   
**Fix / resolution (or final decision):** System to be changed in the next commit, since I didn’t know how to incorporate parentheses in the system.  
**Commit(s):** Commit made on the 29th

**\#\#\# Entry 4**  
**Date:** 2026-03-30  
**Entry Type: Edge Case / Engineering Decision**  
**Task worked on:** Infix detection and Postfix evaluation   
**Issue or decision:** The initial design of infix was not able to account for parentheses, since the original design checked for odd/even spacing of the tokens. Creation of the postfix evaluation method, the initial design used the precedence of the operator, but was later changed to just check which operator the token was.  
**Error message/symptom (if applicable):** ArrayStack was empty and never updated with input  
**What I tried:** For the infix detection, I initially tried to use an odd/even check for the positioning of the digits and operators. For the postfix evaluation, I initially tried to use precedence for the tokens to decide how the math was going to work. For the ArrayStack, I didn’t include a method to check if the token was a digit, thus making the loop check for only operators.   
**Fix / resolution (or final decision):** For the infix, I went back to the previous design like in the postfix detection that checks for if the token is a digit or an operator. I then included checks for if the tokens were parentheses or not. This resulted in a system that alternates between whether the next token is supposed to be an operator or not, something I imagined with the even/odd check. For the postfix evaluation, it was switched to if statements that checked which operator the token equaled and pushed the results to the ArrayStack. For the bug, I forgot to include an if statement to check if the token was a digit or not.   
**Commit(s):** Commits on the 30th

**\#\#\# Entry 5**  
**Date:** 2026-03-31  
**Entry Type: Bug Fix / Edge Case**  
**Task worked on:** Infix to postfix  
**Issue or decision:** For this, during the testing of this portion, I keep getting bugs over and over, especially over how it kept giving incorrect evaluations of basic infixes and errors whenever parentheses were being used   
**Error message/symptom (if applicable):** invalid postfix/wrong evaluation result/code \-1073740791 (0xC0000409)  
**What I tried:** I tried to follow a guide [Infix to Postfix Expression \- GeeksforGeeks](https://www.geeksforgeeks.org/dsa/convert-infix-expression-to-postfix-expression/) , since I didn’t fully understand how postfixes work and how parentheses would be handled. The diagram really helped me understand how the postfix truly worked and what the general layout/design of the program should look like. Seeing as how the guide didn’t fully explain what it was doing in detail and how it was different from what we were doing, this forced me to break down what they were doing and modify the code to match our system. After the implementation and during testing, I kept getting errors for basic infixes, and this was due to me putting the while loop inside of the for loop, causing it to delete all the operators in the tempStack. I also kept getting errors whenever parentheses were being used, even though I kept rechecking my work compared to the guide.   
**Fix / resolution (or final decision):** In the end, the wrong evaluation bug was solved by moving the while loop outside of the for loop, so it doesn’t immediately delete everything. As for the parentheses bug, it was due to me setting up precedence for the parentheses. In the conversion, the if statement for the operators has a check for if the precedence for the current token is less than the precedence for the token on top of the tempStack. Since it sees that every other operator is less in precedence than the parentheses, it would cause the tempStack to push the parentheses to the output and delete it, and since “)” relies on “(” existing in the tempStack, this would cause an error as the tempStack will be deleted completely.   
**Commit(s):** Commits made on the 31st