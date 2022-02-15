//
// Created by muril on 10/02/2022.
//

#include "UID.h"

int UID::nextID = 0;

UID::UID() {
    id = ++nextID;
}

UID::UID(const UID& reference) {
    this->id = reference.id;
}