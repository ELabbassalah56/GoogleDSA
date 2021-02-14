#include "dynamic-array.hpp"

template <typename T>
T dynamicArray<T>::begin()
{
  return arr[0];
}
template <typename T>
T dynamicArray<T>::end()
{
  return arr[capacity--];
}
template <typename T>
void dynamicArray<T>::iteratorShow()
{
  std::cout<<"[";
  for(auto index:arr)
  {
    std::cout<<index;
  }
  std::cout<<"]";
}
template <typename T>
bool dynamicArray<T>::contains(dynamicArray<T> obj)
{
  return (indexOf(obj)==-1);
}

template <typename T>
int dynamicArray<T>::indexOf(dynamicArray<T> obj)
{
  for(auto index:obj){if(arr[index]==obj){return index;}
  return -1;}
}


template <typename T>
bool dynamicArray<T>::remove(dynamicArray<T> obj)
{
  for(auto index:obj){if(arr[index]==obj){removeAt(index);return true;}
  }
  return false;
}

template <typename T>
T dynamicArray<T>::removeAt(int rm_index)
{
  try{
  if(rm_index >= length && rm_index<0){ throw rm_index;}
  }catch(int rm_index){
    std::cout<<"kOutOfBoundries \t"<<rm_index<<std::endl;
  }
  T Data = arr[rm_index];
  T* newArr = static_cast<T*>(new T[length-1]);
  for(int i=0 ,j=0;i<length;++i,j++)
  {
    if(rm_index == i){j--;//skip over rm_index by fixing j temporary
    }
    else{
         newArr[j] = arr[i];
         arr= newArr;
         capacity = --length;
        }
  }
  return Data;
}

template <typename T>
void dynamicArray<T>::add(T elem)
{
  if(capacity <= (++length))//this time to resize 
  {
    capacity *= 2;
    T *newArr = static_cast<T*>(new T[capacity]);
    try{
      if(newArr == nullptr) {throw newArr;} 
    }catch(T *newArr){
      std::cout<<"kNoSuffecientMemory!"<<std::endl;
    }
    for(int index=0;index<capacity;index++){newArr[index] =arr[index]; }
    arr = newArr;    
  }
  else{
    /*Do nothing*/
  }
  arr[++length] = elem;
}
template <typename T>
int dynamicArray<T>::Size(){ return length;}
template <typename T>
bool dynamicArray<T>::isEmpty(){ return (Size()==0);}
template <typename T>
T dynamicArray<T>::get(int index){return arr[index];}
template <typename T>
void dynamicArray<T>::set(int index, T elem){ arr[index] = elem;}
template <typename T>
void dynamicArray<T>::clear(){ 
  for(T index:arr){index=nullptr;}
  length = 0;
}
template <typename T>
dynamicArray<T>::dynamicArray(/* args */)
{
        return this(16);
}
template <typename T>
dynamicArray<T>::dynamicArray(int capacity)
{
       try{if(capacity < 0){throw capacity;}
       }catch(int capacity){ std::cout<<"IllegalCapacity : "<<capacity<<std::endl;}
       this->capacity=capacity ;
       arr = static_cast<T*>( new T[capacity] );
}
template <typename T>
dynamicArray<T>::~dynamicArray()
{
}


int main(int argc, char const *argv[])
{
    if (argc < 2) {
    // report version
    std::cout << argv[0] << " Version " << DynamicArray_VERSION_MAJOR << "."
              << DynamicArray_VERSION_MINOR << std::endl;
    std::cout << "Usage: " << argv[0] << " number" << std::endl;
    return 1;
  }
  return 0;
}
