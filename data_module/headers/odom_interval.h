//
// Created by oleg on 13.04.2022.
//

#ifndef VKR_ODOM_INTERVAL_H
#define VKR_ODOM_INTERVAL_H

#define MAX2(x, y) x > y ? x : y
#define MIN2(x, y) x < y ? x : y

#include <boost/numeric/interval.hpp>

using namespace boost::numeric;

class OdomInterval: public interval<double>{
public:
    explicit OdomInterval(const double& val): interval<double>(val, val){}
    OdomInterval(const double& low, const double& up): interval<double>(low, up){}
    explicit OdomInterval(const interval<double>& interval): boost::numeric::interval<double>(interval){}

    interval<double> operator+(const interval<double>& interval);
    interval<double> operator-(const interval<double>& interval);
    interval<double> operator*(const interval<double>& interval);
    interval<double> operator/(const interval<double>& interval);
    OdomInterval operator=(const interval<double>& interval);
};


#endif //VKR_ODOM_INTERVAL_H
