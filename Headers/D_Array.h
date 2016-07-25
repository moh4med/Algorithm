#ifndef D_ARRAY_H_
#define D_ARRAY_H_
#pragma once
class DArr
{
private:
    int *arr;
    int size;
    int capacity;
public:
    DArr();
    DArr(int i);
    int get(int i);
    void set(int i,int val);
    void pushback(int val);
    void remove(int i);
    int size_();
    int capacity_();
};
#endif /* D_ARRAY_H_ */
