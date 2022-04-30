// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
  struct ITEM {
    T value;
    ITEM* next;
  };

 public:
  TPQueue() :head(nullptr), tail(nullptr) {}
  ~TPQueue();
  void push(const T&);
  T pop();

 private:
  TPQueue::ITEM* create(const T&);
  ITEM* head;
  ITEM* tail;
};

template<typename T>
typename TPQueue<T>::ITEM* TPQueue<T>::create(const T& value) {
  ITEM* item = new ITEM;
  item->value = value;
  item->next = nullptr;
  return item;
}

template<typename T>
TPQueue<T>::~TPQueue() {
  while (head)
    pop();
}

template<typename T>
void TPQueue<T>::push(const T& value) {
  if (tail && head) {
    ITEM* tmp = head;
    ITEM* newItem = create(value);
    if ((head->value).prior < value.prior) {
      newItem->next = head;
      head = newItem;
    } else {
      while (tmp->next != nullptr && (tmp->next->value.prior < value.prior)) {
        tmp = tmp->next;
      }
      newItem->next = tmp->next;
      tmp->next = newItem;
    }
  } else {
    head = create(value);
    head->next = tail;
    tail = head;
  }
}

template<typename T>
T TPQueue<T>::pop() {
  if (head) {
    ITEM* temp = head->next;
    T value = head->value;
    delete head;
    head = temp;
    return value;
 }

struct SYM {
  char ch;
  int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
