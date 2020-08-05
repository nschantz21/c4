/*
 * Nicholas Schantz
 * Assignment 3
 * 2020-07-28
 * spa.h
 *
 * Implement StreamProcessorAlgorithm class
 */
#ifndef SPA_H
#define SPA_H

#include <iostream>
#include <string>
using std::string;
using std::istream;
using std::ostream;

class StreamProcessorAlgorithm
{
public:
    StreamProcessorAlgorithm(istream &in, ostream &out);
    virtual ~StreamProcessorAlgorithm();
    void process();
private:
    virtual bool filterToken(const string &token) const = 0;
    virtual void processToken(string &token) const = 0;
protected:
    istream &in_;
    ostream &out_;
};

// constructor
StreamProcessorAlgorithm::StreamProcessorAlgorithm
(istream &in, ostream &out): in_(in), out_(out)
{}

// destructor
StreamProcessorAlgorithm::~StreamProcessorAlgorithm()
{
}

// process
void
StreamProcessorAlgorithm::process()
{
    string token;
    // while there's stuff coming in
    while(in_ >> token)
    {
        if (filterToken(token))
        {
            processToken(token);
        }
    }
}

#endif
