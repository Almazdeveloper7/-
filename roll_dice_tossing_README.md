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
