Part 1: 
A fun and educational C++ console application that tests your math skills across three difficulty levels. Answer randomly generated arithmetic questions, get feedback in real time, and see if you’re ready to advance to the next level!

| Level | Number Range |
| ----- | ------------ |
| 1     | 1 - 9        |
| 2     | 10 - 99      |
| 3     | 100 - 999    |

Part 2: 
  Random Question Generation
The program generates two random numbers and one random operator (+, -, *, /) using C++’s <random> library.
For division: the program ensures the larger number is divided by the smaller to avoid zero division or decimals.
The operation is selected from a list of 4: { '*', '-', '+', '/' }.

Part 3: 
  User Input & Feedback
The user is prompted to input an answer. The program checks the answer and gives feedback:
If incorrect: a random motivational message from failed_words[] is shown and the number of chances decreases.
If correct: a random praise from pass_words[] is shown, and your score increases.

Part 4:
 Attempts Tracking
You have 10 chances to answer correctly.
Each round reduces your chances by 1 if you answer incorrectly.
After 10 questions (or attempts), the session ends.

Part 5:
  Final Performance Evaluation
After all attempts:
Your performance is calculated as a percentage:
float passed_result = (1.0f * summary / total) * 100;
 If you scored more than 75%, you are congratulated:
  Congratulations, you are ready to go to the next level!
 Otherwise, you are encouraged to seek help:
  Please ask your teacher for extra help.
