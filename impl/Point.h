// Created by rbd on 15.3.2020.
#ifndef TRY_PointH
#define TRY_PointH

//helib
#include <helib/FHE.h>
#include <helib/EncryptedArray.h>
#include <helib/intraSlot.h>
#include <helib/binaryArith.h>
#include <helib/binaryCompare.h>
#include <helib/ArgMap.h>
#include <NTL/BasicThreadPool.h>
#include <numeric>
#include <cmath>
#include <unistd.h>

NTL_CLIENT
//static std::vector<zzX> unpackSlotEncoding; // a global variable

//mine
#include <vector>
#include "KeysServer.h"

using namespace std;


/**
 * @class Point
 * @brief Representation of user point: d encrypted coordinates and a ptr to the CA
 ********************************************************************/
class Point {
    //! @var KeysServer * keysServer
    //! points to the corresponding CA
    KeysServer * keysServer; //CA - the keys Server
    
    //! @var Ctxt pubEncrKey
    //! "The public encryption key is an encryption of 0,
    //! relative to the first secret key"
    FHEPubKey * pubKey;  // logic - future use
    
    vector<long> deCoor; /** for DBG **/

private:  // other kind of ctor?

public:
    //! @var vector<Vec<Ctxt> > eCoordinates
    //! The encrypted coordinates vector (each coor is Vec<Ctxt>)
    vector<Vec<Ctxt> > eCoordinates;
    
    Point(KeysServer * keysServer, vector<Vec<Ctxt> > eCoordinates);
    
    //! @brief _Encrypted_ addition of coordinates
    Point operator+(const Point &) const;
    //! @brief _Encrypted_ multiplication of coordinates
    Point operator*(const Ctxt & b);
    
    //! @brief The encrypted coordiante
    Vec<Ctxt> operator[](int idx) { return eCoordinates[idx]; }
    Vec<Ctxt> operator[](int idx) const { return eCoordinates[idx]; }
    
    /** for DBG **/
    DecryptedPoint decrypt();
    
    friend std::ostream & operator<<(std::ostream & os, const Point & p);

protected:
    virtual void print(ostream & os) const;
    
};

/**
 * @class PointExtended
 * @brief Extention of class Point - allows init with plaintext (long) coordinates, and saves them
 ********************************************************************/
class PointExtended : public Point {
protected:
    //! @var vector<long> coordinates
    //! The plaintext coordinates vector (double represented as long)
    vector<long> coordinates; //todo check if overriding public/private is allowed
public:
    PointExtended(KeysServer * keysServer, const vector<long> & coordinates);
    //todo make c'tor private. make Skeys (or some class) a friend and create a factory method
    
    /** for DBG **/
    void print(ostream & os) const override;
};


// TODO
//  cmp
//  substruction
//  multi by negative
//  --maybe
//  dummy_Point (with random values)
//  copy c'tor
//  copy c'tor from and/or to  PointExtended
//  assignment


#endif //TRY_PointH
