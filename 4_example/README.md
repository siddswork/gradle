# Example 4: Building C++ application with multiple projects having linear dependency

This is my first experiment with C++ build script. Here I built a small application that reads a file with words and build a trie (also called digital tree, radix tree or prefix tree). This algorithm is good for building a dictionary and is really good for looking up words by their prefix. I used this program so that if someone wants they can even have some fun with the code. 

The code is distributed over 3 projects:
- CharTrieNode: The core data-structure is here. This is a shared library with no dependency.
- WordDictionary: Reads a file with all words and builds the tree, using Trie. This is a shared library and is dependent on CharTrieNode.
- DictionaryApp: This is the main application that instantiate the object of WordsDictionary and work with it. This is an executable and depends on shared libraries, WordDictionary & CharTrieNode.

Additionally, it has a run directory with a shell script called dictionaryApp. This scripts sets up the environment, create and populate lib and bin directories. Lastly it execute the application.

The project is made using Eclipse IDE for C/C++ Developers (Version: 2019-06 (4.12.0)) on MacOS (It should be portable). In Eclipse while creating the project, I used "C++ Managed Build" option, A C++ Project build using the CDT's managed build system. Here CDT stands for, "C/C++ Development Tooling". With this setup, one need to configue how each project will be built. However Eclipse dont provide support for building the complete application.

This is where I want to use gradle, to build the complete project. The build process has dependencies, WordDictionary cannot be built without building CharTrieNode and DictionaryApp cannot be built without building CharTrieNode & WordDictionary. 

In the past I have used other scripting language like shell or python on Linux/Solaris to call the make file one by one. They works fine but cannot inherently connect to artifact repositories hosting 3rd party libraries. Also the code become bulky, hard to debug or understand. A Built tool like gradle can be useful to solve such problems.

Lastly, at the root of the workspace I created a build.gradle script, that can do cleanup and compile the full code. Our gradle code is very simple compared to the convoluted build scripts using shell or python.

## Running Gradle to build the code

### Cleaning the shared libraries and executable
```
 $ cd 4_example
 $ gradle debugClean

 > Task :debugCleanCharTrieNode
 rm -rf  ./src/CharTrieNode.o  ./src/CharTrieNode.d  libCharTrieNode.so
 
 
 > Task :debugCleanWordDictionary
 rm -rf  ./src/WordDictionary.o  ./src/WordDictionary.d  libWordDictionary.so
 
 
 > Task :debugClean
 rm -rf  ./src/DictionaryApp.o  ./src/DictionaryApp.d  DictionaryApp.out
 
 
 BUILD SUCCESSFUL in 1s
 3 actionable tasks: 3 executed
```
### Compiling the application (i.e. compiling all projects)
```
 $ gradle compileDebug
 
 > Task :compileDebugCharTrieNode
 Building file: ../src/CharTrieNode.cpp
 Invoking: GCC C++ Compiler
 g++ -std=c++0x -O0 -g3 -Wall -Werror -c -fmessage-length=0 -fPIC -MMD -MP -MF"src/CharTrieNode.d" -MT"src/CharTrieNode.o" -o "src/CharTrieNode.o" "../src/CharTrieNode.cpp"
 Finished building: ../src/CharTrieNode.cpp
 
 Building target: libCharTrieNode.so
 Invoking: MacOS X C++ Linker
 g++ -dynamiclib -o "libCharTrieNode.so"  ./src/CharTrieNode.o   
 Finished building target: libCharTrieNode.so
 
 
 > Task :compileDebugWordDictionary
 Building file: ../src/WordDictionary.cpp
 Invoking: GCC C++ Compiler
 g++ -std=c++0x -I../../CharTrieNode/src -O0 -g3 -Wall -Werror -c -fmessage-length=0 -fPIC -MMD -MP -MF"src/WordDictionary.d" -MT"src/WordDictionary.o" -o "src/WordDictionary.o" "../src/WordDictionary.cpp"
 Finished building: ../src/WordDictionary.cpp


 Building target: libWordDictionary.so
 Invoking: MacOS X C++ Linker
 g++ -L../../CharTrieNode/Debug -dynamiclib -o "libWordDictionary.so"  ./src/WordDictionary.o   -lCharTrieNode
 Finished building target: libWordDictionary.so
 
 
 > Task :compileDebug
 Building file: ../src/DictionaryApp.cpp
 Invoking: GCC C++ Compiler
 g++ -std=c++0x -I../../CharTrieNode/src -I../../WordDictionary/src -O0 -g3 -Wall -Werror -c -fmessage-length=0 -MMD -MP -MF"src/DictionaryApp.d" -MT"src/DictionaryApp.o" -o "src/DictionaryApp.o" "../src/DictionaryApp.cpp"
 Finished building: ../src/DictionaryApp.cpp


 Building target: DictionaryApp.out
 Invoking: MacOS X C++ Linker
 g++ -L../../CharTrieNode/Debug -L../../WordDictionary/Debug -o "DictionaryApp.out"  ./src/DictionaryApp.o   -lCharTrieNode -lWordDictionary
 Finished building target: DictionaryApp.out
 

 BUILD SUCCESSFUL in 13s
 3 actionable tasks: 3 executed
 ```
 ## Notes:
 ### gradle allows short task names
 Below I used "gradle cD" instead of "gradle compileDebug"
```
 $ gradle cD
 > Task :compileDebugCharTrieNode
 make: Nothing to be done for `all'.
 
 > Task :compileDebugWordDictionary
 make: Nothing to be done for `all'.
 
 > Task :compileDebug
 make: Nothing to be done for `all'.
 
 BUILD SUCCESSFUL in 1s
 3 actionable tasks: 3 executed
 ```
 
 Similarly, we can use "gradle dC" instead of "gradle debugClean"

 ### How to run the code
 To run the code, you need to build the run envoronment. Note that run environment is not in git repository. Follow below steps:
 * Go to folder 4_example
 * execute buildRun.ksh (This will create a new run folder under 4_example)
 * go to run folder 
 * execute start script
