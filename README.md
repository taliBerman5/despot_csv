This brunch uses the value returned from SARSOP to estimate a leaf node instead of running a rollout.
In addition, tag pomdp world doesn't contain location abservation. In order to know if the opponent is in the same grid cell as the robot, the robot must use the tag action.

The Sarsop files is located in 
```
despot_csv/cmake-build-debug/examples/cpp_models/
```
