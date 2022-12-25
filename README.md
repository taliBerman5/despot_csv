# Approximate POMDP Planning Online 

[Copyright &copy; 2014-2018 by National University of Singapore](http://motion.comp.nus.edu.sg/).


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














