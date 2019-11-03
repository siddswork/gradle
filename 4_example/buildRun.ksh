#!/bin/ksh

if [[ ! -e CharTrieNode/Debug/libCharTrieNode.so ]] 
then
   echo "Before running this program, please execute: gradle compileDebug"
   exit 1;
fi
if [[ ! -e WordDictionary/Debug/libWordDictionary.so ]]
then
   echo "Before running this program, please execute: gradle compileDebug" 
   exit 1;
fi
if [[ ! -e DictionaryApp/Debug/DictionaryApp.out ]]
then
   echo "Before running this program, please execute: gradle compileDebug" 
   exit 1;
fi

[ -d run ] || mkdir run;
[ -d run/lib ] || mkdir run/lib;
[ -d run/bin ] || mkdir run/bin;
[ -d run/resource ] || mkdir run/resource;

cd run/lib
if [[ ! -e libCharTrieNode.so ]]
then
   ln -s ../../CharTrieNode/Debug/libCharTrieNode.so
fi
if [[ ! -e libWordDictionary.so ]]
then
   ln -s ../../WordDictionary/Debug/libWordDictionary.so
fi

cd ../bin
if [[ ! -e DictionaryApp.out ]]
then
   ln -s ../../DictionaryApp/Debug/DictionaryApp.out
fi

cd ../resource
if [[ ! -e words.txt ]]
then
   ln -s ../../resource/words.txt
fi

cd ..
if [[ ! -e start ]]
then
   cat >> start <<EOF
#!/bin/ksh

export DYLD_LIBRARY_PATH=$DYLD_LIBRARY_PATH:./lib/

./bin/DictionaryApp.out

EOF
fi
chmod u+x start;

exit 0;

