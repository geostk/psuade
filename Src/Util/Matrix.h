// ************************************************************************
// Copyright (c) 2007   Lawrence Livermore National Security, LLC.
// Produced at the Lawrence Livermore National Laboratory.
// Written by the PSUADE team.
// All rights reserved.
//
// Please see the COPYRIGHT_and_LICENSE file for the copyright notice,
// disclaimer, contact information and the GNU Lesser General Public License.
//
// PSUADE is free software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License (as published by the Free Software
// Foundation) version 2.1 dated February 1999.
//
// PSUADE is distributed in the hope that it will be useful, but WITHOUT ANY
// WARRANTY; without even the IMPLIED WARRANTY OF MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE.  See the terms and conditions of the GNU General
// Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program; if not, write to the Free Software Foundation,
// Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
// ************************************************************************
// psMatrix functions
// AUTHOR : CHARLES TONG
// DATE   : 2008
// ************************************************************************
#ifndef __MATRIXH__
#define __MATRIXH__

/**
 * @name psMatrix class
 *
 **/
/*@{*/

#include "Vector.h"

// ************************************************************************
// class definition
// ************************************************************************

class psMatrix
{
   int    nRows_, nCols_, status_;
   double **Mat_, determinant_;

public:
   int *pivots_;

public:

   psMatrix();
   // Copy constructor by Bill Oliver
   psMatrix(const psMatrix & ma);
   // overload = operator
   psMatrix & operator=(const psMatrix & ma);
   ~psMatrix();
   int    nrows();
   int    ncols();
   int    load(psMatrix &);
   int    load(int, int, double **);
   int    load(int, int, double *);
   int    setDim(int, int);
   void   setEntry(const int, const int, const double);
   double getEntry(const int, const int);
   double getDeterminant();
   void   getMatrix1D(psVector &);
   double **getMatrix2D();
   int    submatrix(psMatrix &, const int, const int *);
   int    CholDecompose();
   int    CholLMatvec(psVector &, psVector &);
   int    CholSolve(psVector &, psVector &);
   int    CholLSolve(psVector &, psVector &);
   int    CholLTSolve(psVector &, psVector &);
   int    LUDecompose();
   int    LUSolve(psVector &, psVector &);
   void   print();
   int    computeInverse(psMatrix &);
   double computeDeterminant();
   int    matvec(psVector &, psVector &, int);
   void   matmult(psMatrix &, psMatrix &);
   void   transpose();
   void   eigenSolve(psMatrix &, psVector &, int);
   void   matSolve(psVector &, psVector &);

private:
   double computeDeterminant(int, double **);
};

/*@}*/

#endif /* __MATRIXH__ */

