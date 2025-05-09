Coin Flip and Dice Roll Simulation
This C++ project simulates two SIMPLE probability-based experiments:

1. Coin Flip Simulation
The program simulates flipping a fair coin multiple times (200, 20,000, and 200,000 flips) using a random number generator. Each flip results in either:
1 → Heads
2 → Tails
It calculates and displays the percentage of heads and tails for each level to demonstrate how the results converge towards theoretical probability (50% each) with more trials.

2. Two Dice Roll Simulation
The program also simulates rolling two six-sided dice (d6) 36,000,000 times. For each roll:
It generates two random integers between 1 and 6.
Sums the two dice.
Records the frequency of each possible result (from 2 to 12).
It then displays a table showing:
Each possible sum (2 to 12),
The number of times it occurred,
Its relative percentage based on the total number of rolls.
This part demonstrates how the distribution of dice sums forms a bell-shaped probability curve, with 7 being the most common outcome.




OUTPUT:
The result of flipping coins by 200 is for heads 49.5 % for coins 50.5 % 
The result of flipping coins by 20000 is for heads 49.575 % for coins 50.425 % 
The result of flipping coins by 200000 is for heads 50.121 % for coins 49.879 % 
Number   Frequency  Percentage
     2     1000128      2.7781%
     3     2000218      5.5562%
     4     2998096      8.3280%
     5     4003084     11.1197%
     6     4997692     13.8825%
     7     6001311     16.6703%
     8     4999263     13.8868%
     9     3998792     11.1078%
    10     3000437      8.3345%
    11     2000742      5.5576%
    12     1000237      2.7784%
