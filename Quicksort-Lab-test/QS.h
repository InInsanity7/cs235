#ifndef QS_H_
#define QS_H_

#include <iostream>
#include <string>
#include "QSInterface.h"

class QS: public QSInterface {

public:
	QS() {}
	~QS();

	void sortAll();

    int medianOfThree(int left, int right);

    int partition(int left, int right, int pivotIndex);

    std::string getArray() const;

    int getSize() const;

    bool addToArray(int value);

	bool createArray(int capacity);

	void clear();

private:
    int *ptr; 
    int addIndex = 0;
    int capacity = 0;

    void quickSort(int first, int last);
};


#endif /* QS_H_ */
	

