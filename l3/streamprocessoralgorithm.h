/*
 * Nicholas Schantz
 * Assignment 3
 * 2020-07-28
 * streamprocessoralgorithm.h
 *
 * Implement StreamProcessorAlgorithm class
 */

#include <string>
using std::string;

class StreamProcessorAlgorithm
{
public:
    StreamProcessorAlgorithm(istream &in, ostream &out)
    virtual ~StreamProcessorAlgorithm()
    void process()
private:
    virtual bool filterToken(const string &token) const = 0;
    virtual void processToken(string &token) const = 0;
    istream &in_;
    ostream &out_;
};

// constructor
StreamProcessorAlgorithm::StreamProcessorAlgorithm
(istream &in, ostream &out): &in_(in), &out_(out)
{}

// destructor
streamprocessoralgorithm::~StreamProcessorAlgorithm()
{
}

// process
void
StreamProcessorAlgorithm::process()
{
    string token;
    // while there's stuff coming in
    while(token << in_)
    {
        if filterToken(token)
        {
            processToken(token);
        }
    }
}

