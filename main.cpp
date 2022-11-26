#include <iostream>
#include "IntArray.h"

using namespace std;

int main()
{
    try {
        //IntArray* array = new IntArray(-10); //ERROR: Bad Length!
        IntArray *array = new IntArray(10);
        array->resize(8);
        array->insertBefore(20, 3);
        //array->insertBefore(20, -5); //ERROR: Bad Range!
        //array->insertBefore(20, 15); //ERROR: Bad Range!
        array->remove(8);
        //array->remove(-3); //ERROR: Bad Range!
        //array->remove(13); //ERROR: Bad Range!
        array->insertAtEnd(30);
        array->insertAtBeginning(40);
        array->getValues();

        IntArray* array2 = new IntArray;
        array->copyArray(*array2);

        IntArray* array3 = new IntArray(30);
        array->copyToArray(*array3); //copy with zero filling
        array3->getValues();
        array3->resize(6);
        //array->copyToArray(*array3); //ERROR: Bad Range!
        array3->getValues();
        array3->resize(16);
        array3->getValues();
    
        IntArray* array4 = new IntArray(20);
        array->copyToArray(*array4, false); //copy without zero filling
        array4->getValues();
        cout << array4->getLength() << endl;
        cout << array4->getValue(5) << endl;
        //cout << array2->getValue(-5) << endl; //ERROR: Bad Range!
        //cout << array2->getValue(15) << endl; //ERROR: Bad Range!
        array->insertAtBeginning(40);
        array->search(40);

        IntArray array5(13);
        cout << array5[4] << endl;
        array->copyToArray(array5);
        //cout << array5[-4] << endl; //ERROR: Bad Range!
        //cout << array5[13] << endl; //ERROR: Bad Range!
        //cout << array5[44] << endl; //ERROR: Bad Range!

        delete array;
        delete array2;
        delete array3;
        delete array4;

        return 0;
    }

    catch (exception& e)
    {
        cout << e.what();
    }
    
}