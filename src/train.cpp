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

  int counter = 1;
  int disabled = 0;

  Cage *cur = first->next;
  while (cur != first) {
    if (!(cur->light)) {
      disabled++;
    } else {
      counter += disabled + 1;
      countOp += 2 * disabled;
      disabled = 0;
    }
    cur = cur->next;
  }
  return counter;
}
int Train::getOpCount() {
  return countOp;
}
