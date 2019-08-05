Test scripts for competitive programming contest, which contain:

1. `gen.cpp` is the c++ source code to generate input data into file `input`
2. `gen` is the output file after you compile `gen.cpp`
3. `a.cpp` is where you compose your solution for submission
4. `brute.cpp` is where you compose a naive but correct solution
5. `s.sh` combine the files above, it generates 100 sets of input data and feeds to both solutions, which will abort when the solutions give different output. The input to reproduce the difference can be found in `input`.
6. ``makefile`` used to clean up the generated files by running ``make clean``.



How to use:

1. copy the entire ``test/`` directory
2. modify ``a.cpp`` `` brute.cpp`` ``gen.cpp`` 
3. compile the three ``cpp`` files to get ``a`` ``brute`` ``gen``
4. run ``s.sh`` 

