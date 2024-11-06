# IITG2406213_sem1project1
A C++ Program to identify 10 similar pairs of text books from a given set of 64 text books in txt format.

Note: The code works of the books are stored in a folder named Book-Txt

Project I: Similarity Checking from Books
Write a C++ Program to identify 10 similar pairs of text books from a given set of 64
text books
in txt format.
A simple (but crude) way to measures similarity is given as following:
Identify top 100 frequent (normalize) occurring words in a text file. Consider only
numeric character and alphabet character (by converting both small and capital
alphabets to capital form) of the text file. Normalize the word count of a file by
dividing total number of words in the file.
◦ remove commonly occurring six specific words “a”, “and”, “an” , “of” “in” and
“the” from the file at the time of counting frequent word, total number of word
and the normalize frequency.
Similarity index of two files can be calculated as sum of normalize value of all the
frequent words occurred in both the files.
Create a 64x64 size similarity matrix.
Report top ten similar pairs of text books using the similarity matrix. You need to
exclude the self similarity.
Data Set:
https://drive.google.com/file/d/1jcm_-q3IzrDD7lCg0yMlH_GJbg8wudir/view?usp=sharing
