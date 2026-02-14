# C-project-1
C++ project

User inputs Z, ni and nf to calculate the energy of a transition in a Bohr atom
The code validates these inputs asks for the units wanted and asks if the operation should be repeated

Change log:
1st commit: working calculation however flawed validation and too many significant figures

2nd commit: 
limited output to 3dp. Introduced getPositiveInt function called for all 3 numerical inputs to make code more compact.

3rd commit: 
added comments
Improved validation (before inputs beginning with y and n were taken to be y and n and now solely the characters 'y' and 'n' are accepted)
Fixed error in calculations
