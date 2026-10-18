Assignment 5- Small Language Model

C++ & Unix program that trains itself with a textfile to infer character patterns, and then generates character patterns using 
conditional probabilities. Generates text using std::discrete_distribution from the <random> library.


You need to have C++ compiler and make to be able to run.

In bash, use command make first. 

Two options for running: 
kgram_length- breaks text into chunks of character length, kgram. (example: textfile: hello, 2, kgram= he, ll, o )
output_length = how many characters the generated output should be. 

#Without pseudocount flag
./slm kgram_length textfile_name.txt output_length

#With pseudocount flag
adds probability to alphabet characters not present in training text. 

./slm -a 0.01 3 moby_dick.txt 40



