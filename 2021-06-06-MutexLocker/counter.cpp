#include "counter.h"

Counter::Counter(QObject *parent) : QObject(parent)
{
}

void Counter::increase()
{
    value++;
}

void Counter::decrease()
{
    value--;
}

int Counter::count()
{
    return value;
}
