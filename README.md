# Approximate POMDP Planning Online (APPL Online) Toolkit

[Copyright &copy; 2014-2018 by National University of Singapore](http://motion.comp.nus.edu.sg/).

APPL Online is a C++ implementation of the DESPOT algorithm for online POMDP planning [1]. It takes as input a POMDP model in the POMDPX file format. It also provides an API for interfacing directly with a blackbox simulator. 

## Download

Clone the repository from Github (**Recommended**):
```bash
$ git clone https://github.com/taliBerman5/despot_csv.git
```

## Installation

It is prefered you use `CMake` so you could change all parameters.
There is a cmakelists, open the code in IDE (for example Clion).


under examples/cpp_models you can find pomdp worlds.
You can choose the solver in the main file of each world in ChooseSolver function.

To change more parameters (like search depth) go to include/config.h

Pomcp Solver implemention is under src/solver/pomcp.cpp 



## Brunches
```
value_instead_rollout
value_instead_rollout_no_obs
sarsop_instead_rollout
sarsop_instead_rollout_no_obs
heuristic_rollout
heuristic_rollout_no_same_location_observestion
heuristic_rollout_no_same_location_observestion_geomtric
check_default_policy1_heuristic_rollout
heuristic_rollout_no_same_location_observestion_check_defualt_policy1
check_default_policy2_heuristic_rollout
success_in_rollout_to_goal
```
The readme in each brunch explains the porpose of the brunch




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












