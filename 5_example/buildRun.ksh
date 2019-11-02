#!/bin/ksh

if [[ ! -e cpu/Debug/libcpu.so ]] 
then
   echo "Before running this program, please execute: gradle compileDebug"
   exit 1;
fi
if [[ ! -e memory/Debug/libmemory.so ]]
then
   echo "Before running this program, please execute: gradle compileDebug" 
   exit 1;
fi
if [[ ! -e harddrive/Debug/libharddrive.so ]]
then
   echo "Before running this program, please execute: gradle compileDebug" 
   exit 1;
fi
if [[ ! -e ComputerFacade/Debug/ComputerFacade.out ]]
then
   echo "Before running this program, please execute: gradle compileDebug" 
   exit 1;
fi

[ -d run ] || mkdir run;
[ -d run/lib ] || mkdir run/lib;
[ -d run/bin ] || mkdir run/bin;

cd run/lib
if [[ ! -e libcpu.so ]]
then
   ln -s ../../cpu/Debug/libcpu.so
fi
if [[ ! -e libmemory.so ]]
then
   ln -s ../../memory/Debug/libmemory.so
fi
if [[ ! -e libharddrive.so ]]
then
   ln -s ../../harddrive/Debug/libharddrive.so
fi

cd ../bin
if [[ ! -e ComputerFacade.out ]]
then
   ln -s ../../ComputerFacade/Debug/ComputerFacade.out
fi

cd ..
if [[ ! -e start ]]
then
cat >> start <<EOF
#!/bin/ksh

export DYLD_LIBRARY_PATH=$DYLD_LIBRARY_PATH:./lib/
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./lib/

./bin/ComputerFacade.out

EOF
fi

chmod u+x start;

exit 0;

