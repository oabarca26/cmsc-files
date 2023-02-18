// CMSC 341 - Fall 2022 - Project 4
#include "cache.h"
Cache::Cache(int size, hash_fn hash) {
    if (size < MINPRIME)
        size = MINPRIME;

    else if (size > MAXPRIME)
        size = MAXPRIME;

    if (!isPrime(size))
        size = findNextPrime(size);

    m_currentCap = size;
    m_hash = hash;
    m_currentTable = new Person[m_currentCap];

    for (int i = 0; i < m_currentCap; i++) {
        m_currentTable[i].setID(0);
        m_currentTable[i].setKey("");
    }

    m_currentSize = 0;
    m_currNumDeleted = 0;
}

Cache::~Cache() {
    delete[] m_currentTable;
    m_currentTable = nullptr;

    m_currentSize = 0;
    m_currNumDeleted = 0;
}

bool Cache::insert(Person person) {
    int index = 0;

    index = m_hash(person.getKey()) % m_currentCap;

    if (m_currentTable[index].getKey() == person.getKey() && m_currentTable[index].getID() == person.getID())
        return false;

    if (!m_currentTable[index].getID() && m_currentTable[index].getKey() != DELETEDKEY && m_currentTable[index].getKey() == "") {
        m_currentTable[index] = person;
        m_currentSize++;

        if (lambda() > 0.5)
            rehash();

        return true;
    }

    else {
        for (unsigned int i = 0; i < m_currentCap; i++) {
            index = ((m_hash(person.getKey()) % m_currentCap) + (i * i) % m_currentCap);
            if (m_currentTable[index].getKey() == person.getKey() && m_currentTable[index].getID() == person.getID())
                return false;

            if (!m_currentTable[index].getID() && m_currentTable[index].getKey() != DELETEDKEY && m_currentTable[index].getKey() == "") {
                m_currentTable[index] = person;

                m_currentSize++;

                if (lambda() > 0.5)
                    rehash();

                return true;
                break;
            }
        }
    }
    return false;
}

bool Cache::remove(Person person) {
    int index;

    for (unsigned int i = 0; i < m_currentCap; i++) {
        index = ((m_hash(person.getKey()) % m_currentCap) + (i * i) % m_currentCap);

        if (m_currentTable[index].getKey() == person.getKey() && m_currentTable[index].getID() == person.getID()) {
            m_currentTable[index] = DELETED;
            m_currentTable[index].setKey(DELETEDKEY);

            m_currNumDeleted++;

            if (m_currNumDeleted > (.25 * m_currentSize))
                rehash();

            return true;
        }

        else if(m_oldTable[index].getKey() == person.getKey() && m_oldTable[index].getID() == person.getID()) {
            m_oldTable[index] = DELETED;
            m_oldTable[index].setKey(DELETEDKEY);

            m_oldNumDeleted++;

            if (m_oldNumDeleted > (.25 * m_oldSize))
                rehash();

            return true;
        }
    }
    return false;
}

Person Cache::getPerson(string key, int id) const {
    Person* person = new Person("", 0);
    int index;

    for (unsigned int i = 0; i < m_currentCap; i++) {
        index = ((m_hash(person->getKey()) % m_currentCap) + (i * i) % m_currentCap);

        if (m_currentTable[index].getKey() == person->getKey() && m_currentTable[index].getID() == person->getID()) {
            return *person;
        }
    }

    for (unsigned int i = 0; i < m_oldCap; i++) {
        index = ((m_hash(person->getKey()) % m_oldCap) + (i * i) % m_oldCap);

        if (m_oldTable[index].getKey() == person->getKey() && m_oldTable[index].getID() == person->getID()) {
            return *person;
        }
    }
    return *person;
}

void Cache::rehash() {
    m_oldCap = m_currentSize - m_currNumDeleted;
    m_oldNumDeleted = m_currNumDeleted;
    m_oldSize = m_currentSize - m_currNumDeleted;

    m_oldTable = new Person[m_oldCap];
    int counter = 0;

    for (unsigned int i = 0; i < m_currentCap; i++) {
        
            m_oldTable[counter] = m_currentTable[i];
            counter++;
        
    }

    delete[] m_currentTable;
    m_currentCap = (m_currentSize - m_currNumDeleted) * 4;
    m_currentTable = new Person[m_currentCap];
    m_currentSize = 0;
    m_currNumDeleted = 0;
    int i = 0;

    float oneFourth = m_oldCap / 4.0;

    for (; i < oneFourth; i++) {
        insert(m_oldTable[i]);
        m_oldTable[i] = DELETED;
    }
    for (; i < oneFourth *2; i++) {
        insert(m_oldTable[i]);
        m_oldTable[i] = DELETED;
    }
    for (; i < oneFourth *3; i++) {
        insert(m_oldTable[i]);
        m_oldTable[i] = DELETED;
    }
    for (; i < oneFourth *4; i++) {
        insert(m_oldTable[i]);
        m_oldTable[i] = DELETED;
    }

    delete[] m_oldTable;
    m_oldTable = nullptr;
}

float Cache::lambda() const {
    return (float(m_currentSize) / float(m_currentCap));
}

float Cache::deletedRatio() const {
    return (float(m_currNumDeleted) / float(m_currentCap));
}

void Cache::dump() const {
    cout << "Dump for the current table: " << endl;
    if (m_currentTable != nullptr)
        for (int i = 0; i < m_currentCap; i++) {
            cout << "[" << i << "] : " << m_currentTable[i] << endl;
        }
    cout << "Dump for the old table: " << endl;
    if (m_oldTable != nullptr)
        for (int i = 0; i < m_oldCap; i++) {
            cout << "[" << i << "] : " << m_oldTable[i] << endl;
        }
}

bool Cache::isPrime(int number) {
    bool result = true;
    for (int i = 2; i <= number / 2; ++i) {
        if (number % i == 0) {
            result = false;
            break;
        }
    }
    return result;
}

int Cache::findNextPrime(int current) {
    //we always stay within the range [MINPRIME-MAXPRIME]
    //the smallest prime starts at MINPRIME
    if (current < MINPRIME) current = MINPRIME - 1;
    for (int i = current; i < MAXPRIME; i++) {
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0)
                break;
            else if (j + 1 > sqrt(i) && i != current) {
                return i;
            }
        }
    }
    //if a user tries to go over MAXPRIME
    return MAXPRIME;
}

ostream& operator<<(ostream& sout, const Person& person) {
    if (!person.m_key.empty())
        sout << person.m_key << " (ID " << person.m_id << ")";
    else
        sout << "";
    return sout;
}

bool operator==(const Person& lhs, const Person& rhs) {
    return ((lhs.m_key == rhs.m_key) && (lhs.m_id == rhs.m_id));
}