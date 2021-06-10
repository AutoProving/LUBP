# LUBP - Learning Unitary Branching Programs

LUBP implements an heuristic for the problem of learning unitary branching programs.

# Usage

The program LUBP.exe is a stand-alone executable which should run without problems on Ubuntu 18.04 or greater.
Please note that despite the ".exe" extension, this executable will not run on Windows.

If you prefer to compile the program yourself, please follow the instructions in Section **Compilation**. 

To access the help menu, please run. 

```
./LUBP.exe -help
```

There are three ways in which our program can be used. 

1) To learn branching programs from a given dataset using a random initial 
branching program. With this in mind, execute

```
./LUBP.exe -mode learn -data <dataSetFilename> -d <Dimension> -w <Window Size> -t <Time> -ma <Accuracy> -mi <Max Iterations> -mti <Max Total Iterations>

where 
        -f    Input filename (MANDATORY)(requires formated input file)
        -d    Matrix dimension (positive integer)
        -w    Window size (positive integer)
        -t    Killing time in seconds (positive integer)
        -ma   Minimum accuracy (positive float)
        -mi   Maximum number of iterations for the ROPTLIB solver (positive integer) 
        -mti  Maximum total number of iterations. Each iteration updates one instruction (positive integer)
        -ubp  Starts the iterations with a branching program given in file <ubpFileName>
```

2) To learn a dataset with a branching program given at the input. In this case, a file containing 
the branching pogram should be specified using the -ubp "ubpfilename" option. 

```
./LUBP.exe -mode learn -data <dataSetFilename> -d <Dimension> -w <Window Size> -t <Time> -ma <Accuracy> -mi <Max Iterations> -mti <Max Total Iterations> -ubp <File Name> 

```

3) To evaluate a branching program on a dataset. For instance, one may wish to learn a branching program using a training dataset and test it using a testing dataset. 

```
./LUBP.exe -mode evaluate -data <dataSetFileName> -ubp <ubpFileName>
```

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

## Dependencies

Our program is depends on the following libraries

- We recommend compiling using g++ 9.2 or greater and compile with C++ 14 or greater
- [ROPTLIB](https://github.com/whuang08/ROPTLIB), which is a library for optimization over Riemanian manifolds. This library will be fetched as a git submodule in the directory "/LUBP/ROPTLIB" by executing the following commands: 
```
git submodule init

git submodule update

```
- Boost library (Version 1.71 or greater)
- BLAS, LAPACK and FFTW libraries. To install these libraries, use the following commands. 

```
- sudo apt-get install build-essential
-	sudo apt-get install liblapack*
-	sudo apt-get install libblas*
-	sudo apt-get install libfftw3*
```



## Input/Output Formats


## Bug Reports and User Feedback

Please report bugs or ask questions using the issue tracker a [https://github.com/AutoProving/LUBP/issues](https://github.com/AutoProving/LUBP/issues)

## Citation

To cite our heuristics, please refer to the following paper.

Fidel Ernesto Díaz Andino, Maria Kokkou, Mateus de Oliveira Oliveira, Farhad Vadiee. Unitary Branching Programs: Learnability and Lower Bounds. 
38-th International Conference on Machine Learning (ICML 2021)

## Acknowledgements 

This work received support from the Research Council of Norway in the context of the project Automated Theorem Proving from the Mindset of 
Parameterized Complexity Theory (Grant no. 288761). 

We also acknowledge support from the Sigma2 Network (Proj. no. NN9535K)

