# Example 5: Building C++ application with multiple projects having dependency to support parallel compilation

This is my second experiment with C++ build script. Here I built a small application that makes use of Facade pattern. You can find the base code in Wiki (https://en.wikipedia.org/wiki/Facade_pattern#C++) with some minor change. 

The code is distributed over 4 projects:
cpu - Simulates cpu, has no dependency on any other project 
harddrive - Simulates hard drive, has no dependency on any other project
memory - Simulates memory, has no dependency on any other project
ComputerFacade - This is the main application. It is dependent above 3 projects

Like the previous example, it has shell script called buildRun.ksh, which can create a run directory with lib and bin folders & a start script. Execute the script buildRun.ksh once the code is compiled. Then go to run directory and execute the start script to run the program. 

The project is made using Eclipse IDE for C/C++ Developers (Version: 2019-06 (4.12.0)) on MacOS (It should be portable, however I have not tested it). In Eclipse while creating the projects, I used "C++ Managed Build" option, A C++ Project build using the CDT's managed build system. Here CDT stands for, "C/C++ Development Tooling". With this setup, one need to configue how each project will be built. However Eclipse doesent provide support for building the complete application.

Lastly the main part, at the root of the workspace I created a build.gradle script, that can do cleanup and compile the full code.

## Running Gradle to build the code

### Cleaning the shared libraries and executable
```
 $ cd 5_example
 $ gradle debugClean --parallel
 
 > Task :debugCleanCpu
 rm -rf  ./src/cpu.o  ./src/cpu.d  libcpu.so
  
 
 > Task :debugCleanHardDrive
 rm -rf  ./src/harddrive.o  ./src/harddrive.d  libharddrive.so
  
 
 > Task :debugCleanMemory
 rm -rf  ./src/memory.o  ./src/memory.d  libmemory.so
  
 
 > Task :debugClean
 rm -rf  ./src/ComputerFacade.o  ./src/ComputerFacade.d  ComputerFacade.out
  
 
 BUILD SUCCESSFUL in 2s
 4 actionable tasks: 4 executed
```
### Compiling the application (i.e. compiling all projects)
```
 $ gradle compileDebug --parallel

 > Task :compileDebugCpu
 Building file: ../src/cpu.cpp
 Invoking: GCC C++ Compiler
 g++ -std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -fPIC -MMD -MP -MF"src/cpu.d" -MT"src/cpu.o" -o "src/cpu.o" "../src/cpu.cpp"
 Finished building: ../src/cpu.cpp
 
 Building target: libcpu.so
 Invoking: MacOS X C++ Linker
 g++ -dynamiclib -o "libcpu.so"  ./src/cpu.o   
 Finished building target: libcpu.so
 
 
 > Task :compileDebugHardDrive
 Building file: ../src/harddrive.cpp
 Invoking: GCC C++ Compiler
 g++ -std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -fPIC -MMD -MP -MF"src/harddrive.d" -MT"src/harddrive.o" -o "src/harddrive.o" "../src/harddrive.cpp"
 Finished building: ../src/harddrive.cpp
  
 Building target: libharddrive.so
 Invoking: MacOS X C++ Linker
 g++ -dynamiclib -o "libharddrive.so"  ./src/harddrive.o   
 Finished building target: libharddrive.so
 
 
 > Task :compileDebugMemory
 Building file: ../src/memory.cpp
 Invoking: GCC C++ Compiler
 g++ -std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -fPIC -MMD -MP -MF"src/memory.d" -MT"src/memory.o" -o "src/memory.o" "../src/memory.cpp"
 Finished building: ../src/memory.cpp
 
 Building target: libmemory.so
 Invoking: MacOS X C++ Linker
 g++ -dynamiclib -o "libmemory.so"  ./src/memory.o   
 Finished building target: libmemory.so
 
 
 > Task :compileDebug
 Building file: ../src/ComputerFacade.cpp
 Invoking: GCC C++ Compiler
 g++ -std=c++0x -I../../cpu/src -I../../harddrive/src -I../../memory/src -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/ComputerFacade.d" -MT"src/ComputerFacade.o" -o "src/ComputerFacade.o" "../src/ComputerFacade.cpp"
 Finished building: ../src/ComputerFacade.cpp
 
 Building target: ComputerFacade.out
 Invoking: MacOS X C++ Linker
 g++ -L../../cpu/Debug -L../../harddrive/Debug -L../../memory/Debug -o "ComputerFacade.out"  ./src/ComputerFacade.o   -lcpu -lharddrive -lmemory
 Finished building target: ComputerFacade.out
 
 
 BUILD SUCCESSFUL in 6s
 4 actionable tasks: 4 executed
```
 ## Notes:
 ### Here we are using the --parallel option, this should ideally make the tasks run in paralle based on dependencydefined. Parallel project compilation should reduce the total time taken to build the application. Without this gradle will always execute each task in sequence.

 ### How to run the code
 To run the code, you need to compile the code using above mentioned method and then build the run envoronment. Note that run environment is not in git repository. One can follow below steps:
 * Go to folder 5_example
 * $ gradle compileDebug --parallel
 * $ buildRun.ksh 
 ** This will create a new run folder under 5_example
 * $ cd run
 * $ ./start
