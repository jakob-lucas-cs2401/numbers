/**************************************
   CS2401 Spring 2013	Lab Assignment 4
	John Dolan
   A little class that holds a dynamic array of numbers
***************************************/

#include<iostream>

size_t byte_count = 0;
class Numbers{
     public:
             Numbers();
             ~Numbers();
             void insert(unsigned long large);
             void resize();
             void remove_last();
             void display();
             void operator =(const numbers& other);
             unsigned long * reveal_address()const;


      private:
              unsigned long *data;
              std::size_t used;
              std::size_t capacity;
};



Numbers::Numbers()
{
  used=0;
  capacity=5;
  data=new unsigned long[capacity];
}


void Numbers::insert(unsigned long large)
{
  if(used == capacity)
   resize();

   data[used]=large;
   used++;
}

void Numbers::resize()
{
   unsigned long *tmp;
   tmp=new unsigned long[capacity+5];
   copy(data, data+used, tmp);
   delete[]data;
   data=tmp;
   capacity+=5;
}

void Numbers::remove_last()
{
 used--;
}

void Numbers::display()
{
  for(int i=0; i<used; i++)
     {cout << data[i]<<" ";
      }
     cout<<endl;
}

// You will need to write the implementation of this overloaded operator
void Numbers::operator =(const numbers& other)
{ if(this==&other)
     return;
  delete[]data;
  used=other.used;
  capacity=other.capacity;
  data=new unsigned long[capacity];
  copy(other.data, other.data+used, data);
}
