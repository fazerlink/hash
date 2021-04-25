#pragma once
#define uint unsigned long long
#include <iostream>
#include <cmath>
#include <set>
template <typename T>
class KEKSorts
{
public:
    static int bubbleSort(T*, uint);
    static uint shakerSort(T*, uint);
    static int combSort(T*, uint);
    static int insertionSort(T*, uint);
    static int shellSort(T*, uint);
	static int treeSort(T*, uint);
    static int mergeSort(T*, uint);
    static int timSort(T*, uint);
    static int selectionSort(T*, uint);
    static int heapSort(T*, uint);
    static int smoothSort(T*,uint);
    static int introSort(T*, uint);
    static int patienceSort(T*, uint);
	static void quickSort(T*,uint);
    static int stoogeSort(T*, uint);
    static void monkeySort(T*, uint);
    static void print(T*,uint);
    static bool isSorted(T*, uint);
    static int probabilisticSort(T*, uint);
};

template <typename T>
bool KEKSorts<T>::isSorted(T* mass, uint size)
{
    bool isCorrect;
    if(size >=1)
    isCorrect = true;
    for(int i = 0; i<size-1;i++)
    {
        if(mass[i]>mass[i+1])
        {
            isCorrect = false;
            return isCorrect;
        }

    }
     if(size >=1)
     isCorrect = true;
  return isCorrect;
}
template <typename T>
void KEKSorts<T>::print(T* mass, uint size)
{
    for(int i=0;i<size;i++)
    {
        std::cout<<mass[i]<<", ";
    }

    std::cout<<std::endl;
    std::cout<<std::endl;
}

template <typename T>
int KEKSorts<T>::bubbleSort(T* mass, uint size)
{
    int counter = 0;
    for(int i = 0;i<size;i++)
    {
        for(int j =0; j<size-i-1;j++)
        {
            if(mass[j]>mass[j+1])
            {
                T buff = mass[j];
                mass[j] = mass[j+1];
                mass[j+1] = buff;
                counter++;
            }
        }
    }

    return counter;
}

template <typename T>
uint KEKSorts<T>::shakerSort(T* mass, uint size)
{
    uint counter = 0;
    uint leftBorder =0;
    uint rightBorder = size-1;
    while(leftBorder<rightBorder)
    {

        for(int i=leftBorder;i<rightBorder;i++)
        {

            if(mass[i]>mass[i+1])
            {
                T buff = mass[i];
                mass[i] = mass[i+1];
                mass[i+1] = buff;
               counter++;
            }
        }
        for(int i=rightBorder;i>leftBorder;i--)
        {
            if(mass[i]<mass[i-1])
            {
                T buff = mass[i];
                mass[i] = mass[i-1];
                mass[i-1] = buff;
                counter++;
            }
        }

        rightBorder--;
        leftBorder++;

    }
  return counter;
}


//Not working
template <typename T>
int KEKSorts<T>::combSort(T* mass, uint size)
{
    uint leftBorder = 0;
    uint rightBorder = size-1;
    uint counter = 0;
    while(!KEKSorts<T>::isSorted(mass, size))
    {

            if(mass[leftBorder]> mass[rightBorder])
            {
                T buff = mass[leftBorder];
                mass[leftBorder] = mass[rightBorder];
                mass[rightBorder] = buff;
                counter++;
                rightBorder--;


            }
            else
            {
                leftBorder++;
                rightBorder = size-1;
                counter++;
            }

    }

    return counter;
}

template <typename T>
int KEKSorts<T>::insertionSort(T* mass, uint size)
{
    int counter = 0;
    T buff;
    int index;

    for(uint i =1; i<size; i++)
    {
        buff = mass[i];
        index = i-1;
        while(index>=0 && mass[index] > buff)
        {
            mass[index+1] = mass[index];
			KEKSorts<T>::print(mass, size);
            mass[index] = buff;
            index--;
            counter++;
        }
    }
	KEKSorts<T>::print(mass, size);
    return counter;
}

template <typename T>
int KEKSorts<T>::shellSort(T* mass, uint size)
{
    int counter = 0;
    uint i = 1;
    uint d =0;
    while(d < size)
    {
        if(i % 2 == 0)
        {
            d = 9*pow(2,i)-9*pow(2,i/2);
        }
        else
        {
            d =8*pow(2,i)-6*pow(2,(i+1)/2);
        }

        i++;
    }
    i--;



    for(; i>0;i--)
    {
        if(i % 2 == 0)
        {
            d = 9*pow(2,i)-9*pow(2,i/2);
        }
        else
        {
            d =8*pow(2,i)-6*pow(2,(i+1)/2);
        }

        for(int j = 0; j < d; j++)
        {
            int index = j;
            while(index+d < size)
            {
                if(mass[index] > mass[index+d])
                {
                    T temp = mass[index];
                    mass[index] = mass[index+d];
                    mass[index+d] = temp;
                    counter++;
                }
                index+=d;
            }
        }

    }
    T buff;
    int index;

    for(int i =1; i<size; i++)
    {
        buff = mass[i];
        index = i-1;
        while(index>=0 && mass[index] > buff)
        {
            mass[index+1] = mass[index];
            mass[index] = buff;
            index--;
            counter++;
        }
    }
  return counter;

}


template<typename T>
int KEKSorts<T>::heapSort(T* mass, uint size)
{

}

template <typename T>
int KEKSorts<T>::smoothSort(T* mass, uint size)
{

}

template <typename T>
int KEKSorts<T>::selectionSort(T* mass, uint size)
{
    int counter = 0;
    for(uint i = 0; i!=size; i++)
    {
        int min = mass[i];
        uint jIndex;
        for(uint j = i; j!=size; j++)
        {
            if(min >= mass[j])
            {

                min = mass[j];
                jIndex = j;

            }
        }

        int buff = mass[i];
        mass[i] = min;
        mass[jIndex] = buff;
        counter++;
    }
    return counter;
}

template <typename T>
int KEKSorts<T>::treeSort(T* mass, uint size)
{
  std::multiset<T> tree;

  for(size_t i =0;i<size; i++)
  {
	tree.insert(mass[i]);
  }

  auto it = tree.begin();
  size_t i = 0;
  for(;it!=tree.end(); it++)
  {

	mass[i]  = *it;
	i++;
  }
  return i;

}

template <typename T>
void KEKSorts<T>::quickSort(T* mass, uint size)
{
  uint i =0;
  uint j = size;
  T mid = mass[size/2];
  do
  {
	while(mass[i]<mid)
	{
	  i++;
	}
	while(mass[j]>mid)
	{
	  j--;
	}

	if(i<=j)
	{
	  T tmp = mass[i];
	  mass[i] = mass[j];
	  mass[j] = tmp;
	  i++;
	  j--;
	}
  }while(i<=j);

  if(j>0)
  {
	quickSort(mass,j+1);
  }
  if(i<size)
  {
	quickSort(&mass[i],size-i);
  }
}
