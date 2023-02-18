#include "cache.h"
#include <random>
#include <vector>
using namespace std;

class Tester {
public:
    bool testInsertion(Cache& cache);
    bool testRemove(Cache& cache);
};

const int MINSEARCH = 0;
const int MAXSEARCH = 7;
enum RANDOM { UNIFORMINT, UNIFORMREAL, NORMAL };
class Random {
public:
    Random(int min, int max, RANDOM type = UNIFORMINT, int mean = 50, int stdev = 20) : m_min(min), m_max(max), m_type(type)
    {
        if (type == NORMAL) {
            //the case of NORMAL to generate integer numbers with normal distribution
            m_generator = std::mt19937(m_device());
            //the data set will have the mean of 50 (default) and standard deviation of 20 (default)
            //the mean and standard deviation can change by passing new values to constructor 
            m_normdist = std::normal_distribution<>(mean, stdev);
        }
        else if (type == UNIFORMINT) {
            //the case of UNIFORMINT to generate integer numbers
            // Using a fixed seed value generates always the same sequence
            // of pseudorandom numbers, e.g. reproducing scientific experiments
            // here it helps us with testing since the same sequence repeats
            m_generator = std::mt19937(10);// 10 is the fixed seed value
            m_unidist = std::uniform_int_distribution<>(min, max);
        }
        else { //the case of UNIFORMREAL to generate real numbers
            m_generator = std::mt19937(10);// 10 is the fixed seed value
            m_uniReal = std::uniform_real_distribution<double>((double)min, (double)max);
        }
    }
    void setSeed(int seedNum) {
        // we have set a default value for seed in constructor
        // we can change the seed by calling this function after constructor call
        // this gives us more randomness
        m_generator = std::mt19937(seedNum);
    }

    int getRandNum() {
        // this function returns integer numbers
        // the object must have been initialized to generate integers
        int result = 0;
        if (m_type == NORMAL) {
            //returns a random number in a set with normal distribution
            //we limit random numbers by the min and max values
            result = m_min - 1;
            while (result < m_min || result > m_max)
                result = m_normdist(m_generator);
        }
        else if (m_type == UNIFORMINT) {
            //this will generate a random number between min and max values
            result = m_unidist(m_generator);
        }
        return result;
    }

    double getRealRandNum() {
        // this function returns real numbers
        // the object must have been initialized to generate real numbers
        double result = m_uniReal(m_generator);
        // a trick to return numbers only with two deciaml points
        // for example if result is 15.0378, function returns 15.03
        // to round up we can use ceil function instead of floor
        result = std::floor(result * 100.0) / 100.0;
        return result;
    }

private:
    int m_min;
    int m_max;
    RANDOM m_type;
    std::random_device m_device;
    std::mt19937 m_generator;
    std::normal_distribution<> m_normdist;//normal distribution
    std::uniform_int_distribution<> m_unidist;//integer uniform distribution
    std::uniform_real_distribution<double> m_uniReal;//real uniform distribution

};

unsigned int hashCode(const string str);

bool Tester::testInsertion(Cache& cache) {
    vector<Person> dataList;
    bool result = true;

    Person p1("jack", 1);
    Person p2("bob", 2);
    Person p3("mike", 3);

    cache.insert(p1);
    cache.insert(p2);
    cache.insert(p3);

    dataList.push_back(p1);
    dataList.push_back(p2);
    dataList.push_back(p3);

    if (result)
        return true;
    else
        return false;

    return true;
}

bool Tester::testRemove(Cache& cache) {
    vector<Person> dataList;
    bool result = true;

    Person p1("jack", 1);
    Person p2("bob", 2);
    Person p3("mike", 3);

    cache.insert(p1);
    cache.insert(p2);
    cache.insert(p3);

    dataList.push_back(p1);
    dataList.push_back(p2);
    dataList.push_back(p3);

    for (vector<Person>::iterator it = dataList.begin(); it != dataList.end(); it++) {
        result = result && (*it == cache.getPerson((*it).getKey(), (*it).getID()));
    }

    if (result)
        return false;
    else
        return true;

    return true;
}

int main() {
    Random RndID(MINID, MAXID);
    Random RndStr(MINSEARCH, MAXSEARCH);
    Cache cache(MINPRIME, hashCode);
    Tester test;

    if (test.testInsertion(cache))
        cout << "Pass" << endl;
    else
        cout << "Fail" << endl;

    if (test.testRemove(cache))
        cout << "Pass" << endl;
    else
        cout << "Fail" << endl;

    return 0;
}

unsigned int hashCode(const string str) {
    unsigned int val = 0;
    const unsigned int thirtyThree = 33;  // magic number from textbook
    for (unsigned int i = 0; i < str.length(); i++)
        val = val * thirtyThree + str[i];
    return val;
}