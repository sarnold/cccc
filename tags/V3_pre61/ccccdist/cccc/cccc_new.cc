// cccc_new.cc

// we are having some problems with heap corruption, so I am making sure that
// all class news and deletes are done by the malloc subsystem, and adding 
// logging and deletion suppression

#include "cccc.h"

#include <stdlib.h>
#include <memory.h>
#ifdef CCCC_CONF_W32VC
#include <time.h>
#else
#ifdef CCCC_CONF_W32BC
#include <time.h>
#else
#include <sys/time.h>
#endif
#endif

#define USE_SYSTEM_NEW
#ifndef USE_SYSTEM_NEW
extern int dont_free;

ofstream str("cccc_new.log");

void *
operator new(size_t n) 
{
  void *retval=malloc(n);
  memset(retval,0xFA,n);
  str << hex << retval << "@" << time(NULL) << "+" << n << endl;
  return retval;
}

void *
operator new[](size_t n)
{
  void *retval=malloc(n);
  memset(retval,0xFB,n);
  str << hex << retval << "@" << time(NULL) << "*" << n << endl;
  return retval;
}

void
operator delete(void * cp)
{
  str << hex << cp << "@" << time(NULL) << "-" << endl;
  memset(cp,0xFC,1);
  if(dont_free==0)
    {
      free(cp);
    }
}

void
operator delete[](void * cp)
{
  str << hex << cp << "@" << time(NULL) << "/" << endl;
  memset(cp,0xFD,1);
  if(dont_free==0)
    {
      free(cp);
    }
}


#endif





