/*
 * $Id$
 *
 * Author: David Fournier
 * Copyright (c) 2009-2012 ADMB Foundation
 */
/**
 * \file
 * This file has routines for the constant type
 * log-factorial, log-binomial, and log-gamma functions
 */

#include <fvar.hpp>

double factln(double n);
double gammln(double xx);
double lgam(double xx);

/**
 * Log of the binomial coefficent
 * i.e log of 'n choose k'
 * \param n a number
 * \param k a number
 * \return log of the binomial coefficent
 */
double log_comb(double n, double k)
{
  return factln(n)-factln(k)-factln(n-k);
}

/**
 * Log-factorial \f$\ln(n!)\f$
 * \param n a number
 * \return log of the factorial
 */
double factln(double n)
{
  return gammln(n+1.0);
}

/**
 * A wrapper for igam
o */
// get rid of cephes
//
//double gammln(double xx)
//{
//  return lgam(xx);
//}

double gammln(double xx)
{
  double x,tmp,ser;
  static double cof[6]={76.18009173,-86.50532033,24.01409822,
    -1.231739516,0.120858003e-2,-0.536382e-5};
  int j;
  x=xx-1.0;
  tmp=x+5.5;
  tmp -= (x+0.5)*log(tmp);
  ser=1.0;
  for (j=0;j<=5;j++)
  {
    x += 1.0;
    ser += cof[j]/x;
  }
  return -tmp+log(2.50662827465*ser);
}

/**
 * Log-binomial of two arrays
 * \param n an array
 * \param r an array
 * \return log of the binomial coefficent
 */
dvector log_comb(const dvector& n, const dvector& r)
{
  int mmin=n.indexmin();
  int mmax=n.indexmax();
  if (mmin != r.indexmin() || mmax != r.indexmax()) 
  {
    cerr << "Incompatible array bounds in function "
      "dvector log_comb(const dvector& n, const dvector& r)" << endl;
    ad_exit(1);
  } 
  dvector tmp(mmin,mmax);
  for (int i=mmin;i<=mmax;i++)
  {
    tmp(i)=log_comb(n(i),r(i));
  }
  return tmp;
} 

/**
 * Log-binomial of a number with an arrays
 * \param n a number
 * \param r an array
 * \return log of the binomial coefficent
 */
dvector log_comb(double n, const dvector& r)
{
  int mmin=r.indexmin();
  int mmax=r.indexmax();
  dvector tmp(mmin,mmax);
  for (int i=mmin;i<=mmax;i++)
  {
    tmp(i)=log_comb(n,r(i));
  }
  return tmp;
} 

/**
 * Log-Gamma of an array
 * \param v an array
 * \return log of the factorial
 */
dvector gammln(const dvector& v)
{
  int mmin=v.indexmin();
  int mmax=v.indexmax();
  dvector tmp(mmin,mmax);
  for (int i=mmin;i<=mmax;i++)
  {
    tmp(i)=gammln(v(i));
  }
  return tmp;
}

/**
 * Log-factorial of an array
 * \param r an array
 * \return log of the factorial
 */
dvector factln(const dvector& r)
{
    int mmin=r.indexmin();
    int mmax=r.indexmax();
    dvector tmp(mmin,mmax);
    for (int i=mmin;i<=mmax;i++)
    {
      tmp(i)=gammln(r(i)+1.0);
    }
    return tmp;
}
