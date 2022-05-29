## Problem 1. Find the sum of all the multiples of 3 or 5 below 1000.

A solution can be implemented quickly and intuitively by using an iterative approach that loops through a range of integers between 1 and 999. Using the mod operator to check for even divisiblity (a zero remainder after division) we sum those integers i, that are divisible by 3 or 5. 

```python
limit = 1000
sum = 0
for i in range(1, limit):
    if i % 3 == 0 or i % 5 == 0:
        sum += i
print(sum)
```

This program runs instantly for upper bounds like 1000, but does not scale well for large ones such as 1,000,000,000 or 10^9. So, we need to find a more efficient way of calculating this sum without looping. 

### Scalable solution

Natural numbers are a part of the number system which includes all the positive integers from 1 till infinity and are also used for counting purpose. 

A formula attributed to Carl Friedrich Gauss will calculte the sum of the first n natural numbers.

For example, when n=10 the sum of all the natural numbers from 1 through 10 is:(1+2+3+4+5+6+7+8+9+10)=10*11 / 2 = 55. This is an example of a closed-form expression describing summation. 

Here's how this formula works for n = 10. Write the numbers in two rows that wrap around as shown below:

1   2   3   4   5
10  9   8   7   6

The sum of each column is 11. As the two row increases, the bottom row decreases, so the column sum always stays the same, and we'll always have two rows and n/2 columns for any number n. If n is odd then we will start with zero to keep the columns paired. 

Which is the same formula as Gauss's. 

### Counting every dth number

We can adapt this formula to count the numbers only divisible by d to a specific upper bound, such as n = 33, d = 3, as shown in the following example. Remember, when there is an odd number of elements we start from zero. Here's how the adaptation works.

0   3   6   9   12  15
33  30  27  24  21  18

Each of the 6 columns sum to 33 and, using our understanding from above, we calculate 6*33=198 to find the sum of numbers from 0 to 33 that are evenly divisible by 3. In Python function, sumn(), this is accomplished by using the floor function on n divided by d to find the number of non-zero terms. Then, calculate the sum using an expanded formula which accouns for the multiplier, d.

By applying the above formula to n=999 and d=3 and d=5 we get the sums for every third and fifth natural number. Adding those together is almost our answet but we must first subtract the sum of every 15th natural number (3*5) as it is counted twice: once in the 3 summation and once again in the 5 summation. 

```python
def sumn(n, d):
    n //= d
    return d*n*(n+1)//2

L = int(input("Enter an upper bound? "))
a, b = 3, 5
s = sumn(L-1, a) + sumn(L-1, b) - sumn(L-1, a*b)
print(f"Sum of multiples of {a} or {b} below {L} = ", s)
