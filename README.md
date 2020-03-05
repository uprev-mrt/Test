# Mrt Unit Test

This module is used for unit testing the MrT modules. It uses the Google Test framework

Performing the test requires make, cmake, and GTest

```bash
sudo apt install make cmake libgtest-dev
```

>Note: if you experience problems with your project trying to build this, you may have to manually exclude this directory from your projects build configuration

## Performing a unit test

To perform a unit test on the modules in your project, buld the cmake project inside this 'Test' module :

```bash
mkdir MrT/Test/build
cd MrT/Test/build
cmake ..
make
./runTests
```

## Adding a unit test for a module

The test module searches through all module directories for unit test files ending with '_UT.cpp'. Just add a unit test to the module following this pattern and it will be collected by the tester. Make sure to wrap the file with with a guard to make sure it is not compiled in your project:

```c 
#ifdef UNIT_TESTING_ENABLED 

<unit test code>
#endif /* UNIT_TESTING_ENABLED */
``` 
