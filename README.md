Small Language Model
Program description:

The small language model program is a c++ written program with the goal to generate text after the model has trained on text data. However, the generated text is not meant to be creating real words or sentences so you could call this program an "artificial idiot".

The program learns "k-grams" from the training text and will then generate the next character due to transition probabilities computed from the training data. A pseudocount can be implemented aswell but if the user dont specify it will automatically be 0. When using this program errors will be handeled automatically, such as input error or calculation errors, and are handeled with exceptions. 

The small language model is built on three main classes, one for extracting the training data/text from the input file and sampling all occuring chars in it. The second class is called SmallLanguageModel and creates maps where each k-gram's frequency from the text is stored. In this class each k-gram also has a map consisting of the chars frequency of coming after the k-gram. The final class generates the new text by using the distributions from the SmallLanguageModel to sample new characters. 

The input will look like this:

"$ sml k training file w"

If you want to set your own pseudocount:

"$ sml -a pseudocount k training file w"

k - is the lenght of the "words" the model will be training on. It needs to be a positive integer. 
training file - a direction to a text file.
w - the length of the new generated text, w has to be a positive integer greater or equal to k. 
pseudocount - a non negative double to smooth out the probabilities. 


How to compile:

make 
to build the slm

make clean 
to remove compiled files


Enjoy! 
Ella<3
