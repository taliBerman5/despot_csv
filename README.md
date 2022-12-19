# Approximate POMDP Planning Online (APPL Online) Toolkit

[Copyright &copy; 2014-2018 by National University of Singapore](http://motion.comp.nus.edu.sg/).

APPL Online is a C++ implementation of the DESPOT algorithm for online POMDP planning [1]. It takes as input a POMDP model in the POMDPX file format. It also provides an API for interfacing directly with a blackbox simulator. 

## Download

Clone the repository from Github (**Recommended**):
```bash
$ git clone https://github.com/taliBerman5/despot_csv.git
```

## Installation

Compile using `make`:
```bash
$ cd despot
$ make
```

(Optional): If you prefer using `CMake` see the [CMakeLists](#cmakelists) section.

## Quick Start

DESPOT can be used to solve a POMDP specified in the **POMDPX** format or a POMDP
specified in **C++** according to the API. We illustrate this on the [Tiger](http://people.csail.mit.edu/lpk/papers/aij98-pomdp.pdf) problem.



```
To run Tiger specified in [C++](doc/cpp_model_doc), compile and run: 
```bash
$ cd despot/examples/cpp_models/tiger
$ make
$ ./tiger --runs 2
```

This command computes and simulates DESPOT's policy for `N = 2` runs and reports the
performance for the tiger problem specified in C++. See [doc/Usage.txt](doc/usage.txt) for more options. 

Most of options in [doc/Usage.txt](doc/usage.txt) can also be specified the programmatically, see [include/despot/config.h](include/despot/config.h) for the global parameters to use, and the `InitializeDefaultParameters` function in [this section](doc/cpp_model_doc/Tutorial%20on%20Using%20DESPOT%20with%20cpp%20model.md#4-running-the-planning) for an example.



## CMakeLists

**(Optional)**

If you are interested in integrating DESPOT into an existing CMake project or using an IDE for editing, we provide a [CMakeLists.txt](CMakeLists.txt).

To install DESPOT libraries and header files into your system directory:
```bash
$ cd despot
$ mkdir build; cd build
$ cmake ../
$ make
$ sudo make install
```

To integrate DESPOT into your project, add this to your `CMakeLists.txt` file:

```CMake
find_package(Despot CONFIG REQUIRED)

add_executable("YOUR_PROJECT_NAME"
  <your_src_files>
)

target_link_libraries("YOUR_PROJECT_NAME"
  despot
)
```


