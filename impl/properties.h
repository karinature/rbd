//
// Created by rbd on 15.2.2020.
//

#ifndef TRY_PROPERTIES_H
#define TRY_PROPERTIES_H


#include <cmath>
#include <vector>
#include <helib/FHE.h>
#include <NTL/BasicThreadPool.h>

NTL_CLIENT

#define DIM 2
#define EPSILON 0.2
#define DECIMAL_DIGITS 2
#define FACTOR pow(10, DECIMAL_DIGITS) // for conversion from double to long (helib compatibility)
#define BIT_SIZE 10
#define N_THreads 1

using DecryptedPoint = std::vector<long>;
using Bit = Ctxt;
using EncNumber = Vec<Ctxt>;
//using Binary = Vec<Ctxt>; //todo remove?

static bool verbose = false;


#endif //TRY_PROPERTIES_H


/*  JUST SOME THOUGHTS
 *
 * point
 *      can encrypt
 *      can add/be added to other points
 *      can also be multuplied
 *
 */