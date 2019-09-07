# Power of Gradle

This example introduces us to slightly more complex gradle script. It shows how we can define dependency and create tasks dynamically.

To run the script use:
```
 $ gradle groupTherapy

 > Task :startSession
 [ant:echo] Repeat after me...

 > Task :yayGradle0
 Gradle rocks

 > Task :yayGradle1
 Gradle rocks

 > Task :yayGradle2
 Gradle rocks

 BUILD SUCCESSFUL in 2s
 4 actionable tasks: 4 executed
 $
```

## Command to view all tasks in build.gradle file
```
$ gradle -q tasks --all

------------------------------------------------------------
Tasks runnable from root project
------------------------------------------------------------

Build Setup tasks
-----------------
init - Initializes a new Gradle build.
wrapper - Generates Gradle wrapper files.

Help tasks
----------
buildEnvironment - Displays all buildscript dependencies declared in root project '3_example'.
components - Displays the components produced by root project '3_example'. [incubating]
dependencies - Displays all dependencies declared in root project '3_example'.
dependencyInsight - Displays the insight into a specific dependency in root project '3_example'.
dependentComponents - Displays the dependent components of components in root project '3_example'. [incubating]
help - Displays a help message.
model - Displays the configuration model of root project '3_example'. [incubating]
projects - Displays the sub-projects of root project '3_example'.
properties - Displays the properties of root project '3_example'.
tasks - Displays the tasks runnable from root project '3_example'.

Other tasks
-----------
groupTherapy
prepareKotlinBuildScriptModel
startSession
yayGradle0
yayGradle1
yayGradle2
```
