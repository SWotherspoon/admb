/**
 * Author: David Fournier
 * Copyright (c) 2008-2012 Regents of the University of California
 */
#include <admodel.h>
#include <stdlib.h>

#if defined(_WIN32)
  #include <windows.h>
#endif

#ifndef _MSC_VER
  #include <unistd.h>
#endif

/**
 * Description not yet available.
 * \param
 */
void ADSleep(unsigned int t)
{
#if defined(_WIN32)
  Sleep(t);
#else
  sleep(t);
#endif
}
