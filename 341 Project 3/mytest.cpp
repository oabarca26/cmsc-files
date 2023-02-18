#include "iqueue.h"
#include <ctime>
using namespace std;

class Tester {
public:
    bool testPriorityDomainError(IQueue& priority1, IQueue& priority2);
    bool testEmptyDomainError(IQueue& queue);
    bool testCopyConstructor(IQueue& copy1, IQueue& copy2);
    bool testCopyConstructorHelper(Node* left, Node* right);
    bool testAssignmentConstructor(IQueue& left, IQueue& right);
    bool testAssignmentConstructorHelper(Node* left, Node* right);
    void InsertPerformance(int numTrials, int inputSize, IQueue& queue);
    void ExtractPerformance(int numTrials, int inputSize, IQueue& queue);
};

bool Tester::testPriorityDomainError(IQueue& priority1, IQueue& priority2) {
    try {
        priority1.mergeWithQueue(priority2);
    }
    catch (domain_error& error) {
        return true;
    }
    return false;
}

bool Tester::testEmptyDomainError(IQueue& queue) {
    try {
        queue.getNextCrop();
    }
    catch (domain_error& error) {
        return true;
    }
    return false;
}

bool Tester::testCopyConstructor(IQueue& left, IQueue& right) {
    if (!testCopyConstructorHelper(left.m_heap, right.m_heap)) {
        return false;
    }
    return true;
}

bool Tester::testCopyConstructorHelper(Node* left, Node* right) {
    bool testPassed = true;
    if (right != nullptr) {
        if (left == right || left->m_crop.m_cropID != right->m_crop.m_cropID) {
            return false;
        }
        if (right->m_left) {
            testPassed = testCopyConstructorHelper(left->m_left, right->m_left);
        }
        if (right->m_right) {
            testPassed = testCopyConstructorHelper(left->m_right, right->m_right);
        }
    }
    return testPassed;
}

bool Tester::testAssignmentConstructor(IQueue& left, IQueue& right) {
    if (!testAssignmentConstructorHelper(left.m_heap, right.m_heap)) {
        return false;
    }
    return true;
}

bool Tester::testAssignmentConstructorHelper(Node* lhs, Node* right) {
    bool testPassed = true;
    if (right != nullptr) {
        if (lhs == right || lhs->m_crop.m_cropID != right->m_crop.m_cropID) {
            return false;
        }
        if (right->m_left) {
            testPassed = testAssignmentConstructorHelper(lhs->m_left, right->m_left);
        }
        if (right->m_right) {
            testPassed = testAssignmentConstructorHelper(lhs->m_right, right->m_right);
        }
    }
    return testPassed;
}

void Tester::InsertPerformance(int numTrials, int inputSize, IQueue& queue) {
    const int a = 5;
    double T = 0.0;
    clock_t start, stop;
    for (int k = 0; k < numTrials; k++)
    {
        start = clock();
        for (int i = 0; i < inputSize; i++) {
            Crop crop(123456, 80, 50, 1, 2);
            queue.insertCrop(crop);
        }
        stop = clock();
        T = stop - start;
        cout << "Inserting " << inputSize << " members took " << T << " clock ticks (" << T / CLOCKS_PER_SEC << " seconds)!" << endl;
        inputSize = inputSize * a;
    }
}

void Tester::ExtractPerformance(int numTrials, int inputSize, IQueue& queue) {
    const int a = 5;
    double T = 0.0;
    clock_t start, stop;
    for (int k = 0; k < numTrials; k++)
    {
        start = clock();
        for (int i = 0; i < inputSize; i++) {
            queue.getNextCrop();
        }
        stop = clock();
        T = stop - start;
        cout << "Extracting " << inputSize << " members took " << T << " clock ticks (" << T / CLOCKS_PER_SEC << " seconds)!" << endl;
        inputSize = inputSize * a;
    }
}

int priorityFn1(const Crop& crop);
int priorityFn2(const Crop& crop);

int main() {
    Tester tester;

    IQueue queue1(priorityFn1, MAXHEAP);
    IQueue queue2(priorityFn2, MAXHEAP);
    IQueue queue3(priorityFn1, MINHEAP);

    Crop crop1(123456, 80, 50, 1, 2);
    Crop crop2(654321, 39, 45, 2, 1);
    Crop crop3(909090, 69, 99, 1, 4);
    Crop crop4(262155, 100, 87, 2, 3);

    queue1.insertCrop(crop3);
    queue1.insertCrop(crop1);
    queue1.insertCrop(crop2);
    queue1.insertCrop(crop4);
    queue2.insertCrop(crop4);
    queue2.insertCrop(crop2);
    queue2.insertCrop(crop3);
    queue2.insertCrop(crop1);

    if (tester.testPriorityDomainError(queue1, queue2) == true) {
        cout << "Priority domain error test passed!\n";
    }
    else {
        cout << "Priority domain error test failed!\n";
    }

    if (tester.testEmptyDomainError(queue3) == true) {
        cout << "Empty domain error test passed!\n";
    }
    else {
        cout << "Empty domain error test failed!\n";
    }

    if (tester.testCopyConstructor(queue1, queue3) == true) {
        cout << "Copy Constructor test passed!\n";
    }
    else {
        cout << "Copy Constructor test failed!\n";
    }

    IQueue queue4 = queue2;
    if (tester.testAssignmentConstructor(queue1, queue3) == true) {
        cout << "Assignment Constructor test passed!\n";
    }
    else {
        cout << "Assignment Constructor test failed!\n";
    }

    cout << endl;
    cout << "Queue with priorityFn1:\n";
    queue1.dump();

    queue1.setPriorityFn(priorityFn2, MAXHEAP);

    cout << endl;
    cout << "Queue now with priorityFn2:\n";
    queue1.dump();

    queue1.setPriorityFn(priorityFn1, MAXHEAP);

    cout << endl;
    cout << "Queue back with with priorityFn1:\n";
    queue1.dump();

    cout << "\nQueue in priority order:\n";
    while (queue1.numCrops() > 0) {
        Crop crop = queue1.getNextCrop();
        cout << "[" << priorityFn1(crop) << "] " << crop << endl;
    }

    IQueue queue5(priorityFn1, MINHEAP);
    int numTrials = 4;
    int inputSize = 100;
    tester.InsertPerformance(numTrials, inputSize, queue5);
    tester.ExtractPerformance(numTrials, inputSize, queue5);

    return 0;
}

int priorityFn1(const Crop& crop) {
    //needs MAXHEAP
    //priority value is determined based on some criteria
    //priority value falls in the range [30-116]
    //the highest priority would be 110+6 = 116
    //the lowest priority would be 30+0 = 30
    //the larger value means the higher priority
    int priority = crop.getTemperature() + crop.getType();
    return priority;
}

int priorityFn2(const Crop& crop) {
    //needs MINHEAP
    //priority value is determined based on some criteria
    //priority value falls in the range [0-103]
    //the highest priority would be 0+0 = 0
    //the lowest priority would be 100+3 = 103
    //the smaller value means the higher priority
    int priority = crop.getMoisture() + crop.getTime();
    return priority;
}