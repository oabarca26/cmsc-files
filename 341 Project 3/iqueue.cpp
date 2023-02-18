// CMSC 341 - Fall 2022 - Project 3
#include "iqueue.h"
IQueue::IQueue(prifn_t priFn, HEAPTYPE heapType){
    m_heap = nullptr;
    m_size = 0;
    m_priorFunc = priFn;
    m_heapType = heapType;
}

IQueue::~IQueue(){
    clear();
    m_heap = nullptr;
    m_size = 0;
    m_priorFunc = nullptr;
}

IQueue::IQueue(const IQueue& rhs){
    m_size = rhs.m_size;
    m_priorFunc = rhs.m_priorFunc;
    m_heapType = rhs.m_heapType;
    if (rhs.m_heap != nullptr) {
        m_heap = new Node(rhs.m_heap->m_crop);
        copy(m_heap, rhs.m_heap);
    }
    else
        m_heap = nullptr;
}

IQueue& IQueue::operator=(const IQueue& rhs){
    if (this != &rhs) {
        clear();
        m_heap = nullptr;
        m_size = rhs.m_size;
        m_priorFunc = rhs.m_priorFunc;
        m_heapType = rhs.m_heapType;
        if (rhs.m_heap) {
            m_heap = new Node(rhs.m_heap->m_crop);
            copy(m_heap, rhs.m_heap);
        }
        else
            m_heap = nullptr;

    }return *this;

}

void IQueue::insertCrop(const Crop& crop) {
    if (m_size == 0)
        m_heap = new Node(crop);

    else {
        Node* newCrop = new Node(crop);
        mergeWithQueue(m_heap, newCrop);
    }
    m_size++;
}

Crop IQueue::getNextCrop() {
    if (m_size == 0) {
        throw domain_error("empty");
    }
    else {
        Crop rootCrop = m_heap->m_crop;
        Node* tempCrop = m_heap;
        m_heap = mergeWithQueue(tempCrop->m_left, tempCrop->m_right);
        m_size--;
        delete tempCrop;
        return rootCrop;
    }
}

void IQueue::mergeWithQueue(IQueue& rhs) {
    if (this != &rhs) {
        if (m_priorFunc != rhs.m_priorFunc) {
            throw domain_error("attempted to merge queues with different priority functions");
        }
        mergeWithQueue(m_heap, rhs.m_heap);
        m_size += rhs.m_size;
        rhs.m_heap = nullptr;
        rhs.m_size = 0;
        rhs.m_priorFunc = nullptr;
    }
}

void IQueue::clear() {
    if (m_size != 0) {
        clear(m_heap);
    }
}

int IQueue::numCrops() const {
    return m_size;
}

void IQueue::printCropsQueue() const {
    if (m_size != 0) {
        cout << "Contents of the crops queue:" << endl;
        print(m_heap);
    }
}

prifn_t IQueue::getPriorityFn() const {
    return m_priorFunc;
}

void IQueue::setPriorityFn(prifn_t priFn, HEAPTYPE heapType) {
    m_priorFunc = priFn;
    m_heapType = heapType;
    Node** array = new Node * [m_size];
    int increment = 0;
    setPriorityFn(m_heap, array, increment);
    m_heap = array[0];

    for (int i = 0; i < m_size - 1; i++) {
        mergeWithQueue(m_heap, array[i + 1]);
    }

    delete[] array;
}

void IQueue::dump() const
{
    if (m_size == 0) {
        cout << "Empty skew heap.\n";
    }
    else {
        dump(m_heap);
        cout << endl;
    }
}

void IQueue::dump(Node* pos) const {
    if (pos != nullptr) {
        cout << "(";
        dump(pos->m_left);
        cout << m_priorFunc(pos->m_crop) << ":" << pos->m_crop.getCropID();
        dump(pos->m_right);
        cout << ")";
    }
}

ostream& operator<<(ostream& sout, const Crop& crop) {
    sout << "Crop ID: " << crop.getCropID()
        << ", current temperature: " << crop.getTemperature()
        << ", current soil moisture: " << crop.getMoisture() << "%"
        << ", current time: " << crop.getTimeString()
        << ", plant type: " << crop.getTypeString();
    return sout;
}

ostream& operator<<(ostream& sout, const Node& node) {
    sout << node.getCrop();
    return sout;
}

void IQueue::clear(Node* pos) {
    if (pos != nullptr) {
        clear(pos->m_left);
        clear(pos->m_right);
    }
    delete pos;
    pos = nullptr;
}

void IQueue::print(Node* pos) const {
    if (pos != nullptr) {
        print(pos->m_left);
        cout << "[" << m_priorFunc(pos->m_crop) << "]" << " Crop ID: " << pos->m_crop.getCropID() << ", ";
        cout << "current temperature: " << pos->m_crop.getTemperature() << ", ";
        cout << "current soil moisture: " << pos->m_crop.getMoisture() << "%, ";
        cout << "current time: " << pos->m_crop.getTimeString() << ", ";
        cout << "plant type: " << pos->m_crop.getTypeString() << endl;
        print(pos->m_right);
    }
}

void IQueue::setPriorityFn(Node*& pos, Node* array[], int& increment) {
    if (pos != nullptr) {
        setPriorityFn(pos->m_left, array, increment);
        array[increment] = pos;
        increment++;
        setPriorityFn(pos->m_right, array, increment);

        pos->m_right = nullptr;
        pos->m_left = nullptr;
    }
}

Node* IQueue::mergeWithQueue(Node* crop1, Node* crop2) {
    Node* tempCrop;

    if (crop1 == nullptr)
        return crop2;
    if (crop2 == nullptr)
        return crop1;

    if (m_priorFunc(crop1->m_crop) > m_priorFunc(crop2->m_crop)) {
        Node* tempCrop2 = crop2;

        if (crop1 == m_heap) {
            m_heap = tempCrop2;
        }
        crop2 = crop1;
        crop1 = tempCrop2;
    }
    Node* tempCropRight = crop1->m_right;
    crop1->m_right = crop1->m_left;
    crop1->m_left = tempCropRight;

    tempCrop = mergeWithQueue(crop2, crop1->m_left);
    crop1->m_left = tempCrop;

    return crop1;
}

Node* IQueue::copy(Node* crop, Node* copyCrop) {
    if (copyCrop->m_left) {
        crop->m_left = new Node(copyCrop->m_left->m_crop);
        copy(crop->m_left, copyCrop->m_left);
    }
    if (copyCrop->m_right) {
        crop->m_right = new Node(copyCrop->m_right->m_crop);
        copy(crop->m_right, copyCrop->m_right);
    }
    return crop;
}