
#ifndef TRY_AUX_H
#define TRY_AUX_H

#include "Point.h"
#include "properties.h"
#include <map>

struct cmpPoints;

void writeToFile(const vector<Point> & vec, const string & filename, KeysServer & keysServer);
void decWriteToFile(const vector<DecryptedPoint> & vec, const string & filename, KeysServer & keysServer);

//! retrieves the list of coordinates and converts to a list of points
vector<DecryptedPoint> getPointsFromFile(const string & filename = "io/points");
vector<PointExtended> getEncryptedPointsFromFile(KeysServer & keysServer);

//! creates a dictionary of helib's compatr results.
//! the result for the query point1 > point2 is located at cmp[point1][point2] and return as Bit (Ctxt)
map<Point, map<Point, vector<Bit>, cmpPoints>, cmpPoints>
createCmpDict(const vector<Point> & randomPoints, const vector<Point> & stripPoints);
//Bit cmp(const Point & a, const Point & b) ;

long encryptDouble(double d);
vector<long> encryptVec(const vector<double> & vector);


/***********  aux  ***********/
DecryptedPoint operator/(DecryptedPoint p, int factor);

struct cmpPoints{
    bool operator()(const Point & a, const Point & b){
        return a.id>b.id;
    }
};

/*
 * Deprecated
 */
/*
using namespace std;
using Binary = long;

vector<long> getDistFromClosestMeanByClient(const vector<DecryptedPoint> &reps, const vector<Point> &pointsForDBG, Skeys &sk);

#define isNullPoint point == vector<double>(DIM, 0)

using DecryptedPoint =  vector<long>;

void tag();

template<typename T>
void tag(T t);

template<typename T>
void tag(vector<T> vector);

template<typename T>
void tag(vector<vector<T> > vector);
*/


#endif //TRY_AUX_H


