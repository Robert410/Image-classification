# Image-classification
+binary tree

  The final extra credit with random classifier and the class KNN classifier. with binary reading for the trainind data and also with the training and evaluation functions.

  The program created an output called out.txt where i saved an predit on a set of images ( with its confusion matrix and accuracy) contains 490 images, everything compiled in 434 seconds.

  The program is using minkowski with p = 1 to reduce the time of the computation. At KNN classifier, after computing all the distances we have to sort them but not all of them.
I used bublle sort 7 times and check the label of the last 7 distances(the closest one) and keep their result into a frequency array and the label with the most "votes" is returned(its position)
An images is predicted between 0.5 and 1.5 seconds.

  Besides the extra credit, we had one more extra "exercise". Ex. 3 from the lab13, more exactly a binary tree implemented with smart pointers (with some more functionality: like a parametrized constructor
and overload for operator<< and a static method and some display functions). The class is called: binaryTreeSmartPointers, i tested it in main. There are some lines commented from the binary tree.

