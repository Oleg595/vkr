//
// Created by oleg on 13.04.2022.
//

#include "../headers/odom_interval.h"

interval<double> OdomInterval::operator+(const interval<double> &interval) {
    return {lower() + interval.lower(), upper() + interval.upper()};
}

interval<double> OdomInterval::operator-(const interval<double> &interval) {
    return {lower() - interval.upper(), upper() - interval.lower()};
}

interval<double> OdomInterval::operator*(const interval<double> &interval) {
    return {MIN2(MIN2(lower() * interval.lower(), lower() * interval.upper()),
                MIN2(upper() * interval.lower(), upper() * interval.upper())),
            MAX2(MAX2(lower() * interval.lower(), lower() * interval.upper()),
                MAX2(upper() * interval.lower(), upper() * interval.upper()))};
}

interval<double> OdomInterval::operator/(const interval<double> &interval) {
    return {MIN2(MIN2(lower() / interval.lower(), lower() / interval.upper()),
                MIN2(upper() / interval.lower(), upper() / interval.upper())),
            MAX2(MAX2(lower() / interval.lower(), lower() / interval.upper()),
                MAX2(upper() / interval.lower(), upper() / interval.upper()))};
}

OdomInterval OdomInterval::operator=(const interval<double> &interval){
    return OdomInterval(interval.lower(), interval.upper());
}
