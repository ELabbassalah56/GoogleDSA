# dynamic-array system 

#mkdir build folder

mkdir build && cd build

#run cmake file 
cmake ..

#after finish run make file

make 

read -p "Remove Build folder(Y/N)" args 

if   [ "$args" == "Y" ];  
then
#run executable file 

  cp DynamicArray  ~/

  ./DynamicArray
  cd ../ 
  rm -fr build
else 
  echo "notRemoved"  
fi




