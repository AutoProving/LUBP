# LUBP - Learning Unitary Branching Programs

LUBP implements an heuristic for the problem of learning unitary branching programs.

## Download

Open a windows/linux terminal and execute the following command 
to clone this repository. 

```
git clone https://github.com/AutoProving/LUBP.git

git submodule init

git submodule update
```


## Compilation

Enter the main folder `LUBP` and type `make BUILD-LUBP` to compile the program. 

An executable called `LUBP.exe` will be created in the root folder. 


To compile our program, type "make" in a linux terminal. Please note that the compilation
involves both the files of our programs and the files of the external library ROPTLIB.
The compilation may take some minutes (3 min). 

The following requirements must be satisfied in order for the program to be compiled correctly. 

a) You should use g++ 10.0 or greater and compile with C++ 14 or greater
b) You will need the BLAS, LAPACK and FFTW to be able to compile our program. To install these
libraries, use the following commands. 

- sudo apt-get install build-essential
-	sudo apt-get install liblapack*
-	sudo apt-get install libblas*
-	sudo apt-get install libfftw3*


## Usage


## Input/Output Formats


## Bug Reports and User Feedback

Please report bugs or ask questions using the issue tracker a [https://github.com/AutoProving/LUBP/issues](https://github.com/AutoProving/LUBP/issues)

## Citation

To cite our heuristics, please refer to the following paper.

Fidel Ernesto Díaz Andino, Maria Kokkou, Mateus de Oliveira Oliveira, Farhad Vadiee. Unitary Branching Programs: Learnability and Lower Bounds. 
38 International Conference on Machine Learning (ICML 2021)

## Acknowledgements 

This work received support from the Research Council of Norway in the context of the project Automated Theorem Proving from the Mindset of 
Parameterized Complexity Theory (Grant no. 288761). 

We also acknowledge support from the Sigma2 Network (Proj. no. NN9535K)

