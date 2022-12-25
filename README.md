This brunch uses the value returned from SARSOP to estimate a leaf node instead of running a rollout.
In addition, tag pomdp world doesn't contain location abservation. In order to know if the opponent is in the same grid cell as the robot, the robot must use the tag action.

The Sarsop files is located in 
```
despot_csv/cmake-build-debug/examples/cpp_models/
```

In Tag world there are more than 1 Sarsop value files. To change the file go to 
```
despot_csv/examples/cpp_models/tag/src/tag/tag.cpp 
```

sarsop.out - has location observation, Tag reward is -10 for unsuccessful tag.
sarsop_noObs.out, sarsop_noObs_minus1.out, sarsop_noObs_minus2.out - don't have location observation, differ in the unsuccessful tag reward. 
