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

# Experiment wrapper

`runexp` is a shell script that wraps an experiment and adds a line to the CSV-formatted log.
For example, running

	runexp -l tag.log tag/tag --runs 100

Will add line

    N6despot3TagE,90,90,5,-9.22297,1.87514,-11.4,3.34186,110.938

to file `tag.log`. If the log file is empty, the header is added first, so the resulting 
file may look like

	model,depth,steps,runs,drmean,drstd,urmean,urstd,cputime
	N6despot3TagE,90,90,5,-8.46979,2.57059,-12.2,5.79931,114.888
	N6despot3TagE,90,90,5,-3.28042,2.83195,-2.6,2.94754,65.013
	...


More fields can be added if desired.

## Branches
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














