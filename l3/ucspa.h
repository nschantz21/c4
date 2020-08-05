/*
 * Nicholas Schantz
 * Assignment 3
 * 2020-07-28
 * ucspa.h
 *
 * Implement UpperCasingSPA class
 */
#ifndef UCSPA_H
#define UCSPA_H

#include <algorithm>
#include <cctype>
#include "spa.h"

class UppercasingSPA: public StreamProcessorAlgorithm
{
public:
    UppercasingSPA(istream &in, ostream &out):
        StreamProcessorAlgorithm(in, out)
    {}
    
private:
    virtual bool filterToken(const string &token) const;
    virtual void processToken(string &token) const;
};

bool
UppercasingSPA::filterToken(const string &token) const
{
    return true;
}

void
UppercasingSPA::processToken(string &token) const
{
    std::transform(token.begin(), token.end(), token.begin(), toupper);
    out_ << token << "\n";
}

#endif
