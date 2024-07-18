#ifndef LOCKER_H
#define LOCKER_H

#include <exception>
#include <pthread.h>
#include <semaphore.h>

class sem
{
public:
    sem(){
        if (sem_init(&m_sem, 0, 0) != 0){
            throw std::exception();
        }
    }


}