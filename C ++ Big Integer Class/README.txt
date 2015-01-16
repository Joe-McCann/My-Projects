My favorite piece of code I have ever written, and certainly the most useful, is my "big" class. Created for the C++ object oriented programming final project, this class was designed to fix a flaw within the C++ language. 

In C++, one major issue that always bugged me was how numbers were limited to 64 bits, an unsigned long long int (around 20 digits). I always thought that it would be great to have a class that was unlimited in the amount of digits it could store, so I created that with the big class.

Using a vector of chars to represent digits, my program can calculate absurdly large numbers, and use a large amount of operations, ranging from basic (addition, subtraction), to complex (exponential, square root, prime factorization). 

My favorite thing about this is how every operation had to be built from scratch on a digit by digit scale, and how I came up with clever work-arounds to cut down on time (for example, prime factoring exponents to reduce loop numbers).

Since this was a group project, my other group members worked on a string class improvement, but that was not written by me, so I cannot take any credit for it. The only minor thing I added to that was the functions in the big class that are able to accept sstrings as parameters.

Finally, as a little bonus, I created a StopWatch class which can measure time between two points. I primarily used this to check how long my code would run for, but this could have several other applications. 