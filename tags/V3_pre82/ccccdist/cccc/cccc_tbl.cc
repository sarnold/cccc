// cccc_tbl.cc

#include "cccc_itm.h"
#include "cccc_tbl.h"
#include <cassert>

#define LINE_BUFFER_SIZE 1000


template <class T> CCCC_Table<T>::CCCC_Table() 
: iter_(end()), sorted(true)
{
}

template <class T> CCCC_Table<T>::~CCCC_Table() 
{
  // the container should manage the destruction of its own
  // nodes correctly, we just need to get rid of the 
  // objects to which we hold pointers.
  // NB Although CCCC_Table holds pointers, it owns the 
  // objects they point to and is responsible for their disposal.
  T* itemptr=first_item();
  while(itemptr!=NULL)
    {
      delete itemptr;
      itemptr=next_item();
    }
}

template<class T> 
int CCCC_Table<T>::get_count(const char* count_tag) 
{
  int retval=0;
  T* itemptr=first_item();
  while(itemptr!=NULL)
    {
      retval+=itemptr->get_count(count_tag);
      itemptr=next_item();
    }
  
  return retval;
}

template<class T> 
T* CCCC_Table<T>::find(string name)
{
  T *retval=NULL;
  typename map_t::iterator value_iterator=map_t::find(name);
  if(value_iterator!=end())
    {
      retval=(*value_iterator).second;
    }
  return retval;
}

template<class T> 
T* CCCC_Table<T>::find_or_insert(T* new_item_ptr)
{
  string new_key=new_item_ptr->key();
  T *retval=find(new_key);
  if(retval==NULL)
    {
      typename map_t::value_type new_pair(new_key,new_item_ptr);
      insert(new_pair);
      sorted=false;
      retval=new_item_ptr;
    }
  return retval;
}

template<class T>
bool CCCC_Table<T>::remove(T* old_item_ptr)
{
  bool retval=false; 
  typename map_t::iterator value_iterator=map_t::find(old_item_ptr->key());
  if(value_iterator!=map_t::end())
    {
      erase(value_iterator);
      retval=true;
    }
  return retval;
}
   
template <class T> void CCCC_Table<T>::sort() 
{
  if(sorted==false)
    {
      sorted=true;
    }
}

template <class T> void CCCC_Table<T>::reset_iterator()
{
  iter_=begin();
}

template <class T> T* CCCC_Table<T>::first_item()
{
  reset_iterator();
  return next_item();
}

template <class T> T* CCCC_Table<T>::next_item()
{
  T* retval=NULL;
  if(iter_!=end())
    {
      retval=(*iter_).second;
      iter_++;
    }
  return retval;
}

template <class T> int CCCC_Table<T>::records()
{ 
  return size(); 
}

#include "cccc_db.h"

// The lines below are, I believe, the standard way of
// performing explicit template instantiation under ANSI C++.
// On some compilers, these lines may cause problems, either
// because they do not support the standard syntax for this
// purpose, or because they are performing implicit 
// instantiation.
// If their are problems, first try commenting this section 
// out, then try the specific #pragma documented for your 
// compiler.
template class CCCC_Table<CCCC_Extent>;
template class CCCC_Table<CCCC_Module>;
template class CCCC_Table<CCCC_Member>;
template class CCCC_Table<CCCC_UseRelationship>;











