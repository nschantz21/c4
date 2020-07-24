#include <vector>
#include <map>

using std::vector;
using std::map;
using std::string;

class AnyMap<string, T>
{

}

class VecMap
{
    private:
    // the map needs to be able to hold anything as the value
        vector<map<string, int>> vm;
}

int main()
{

    return 0;
}