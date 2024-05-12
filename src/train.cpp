// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
  countOp = 0;
  first = nullptr;
}

void Train::addCage(bool light) {
  Cage *newCage = new Cage();
  newCage->light = light;

  if (first == nullptr) {
    first = newCage;
    newCage->prev = newCage;
    newCage->next = newCage;
  } else {
    newCage->prev = first->prev;
    newCage->next = first;

    first->prev = newCage;
    first->prev->next = newCage;
  }
}
int Train::getLength() {
  first->light = true;

  int counter;
  Cage *cur;

  while (first->light) {
    counter = 1;
    cur = first->next;

    while (!(cur->light)) {
      cur = cur->next;
      counter++;
    }

    countOp += 2 * counter;
    cur->light = false;
  }
  return counter;
}
int Train::getOpCount() {
  return countOp;
}
