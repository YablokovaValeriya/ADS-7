// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
  struct ITEM {
    T value;
    ITEM* next;
  };

 private:
  ITEM *head;
  ITEM *tail;
  ITEM *create(T value) {
    ITEM *t = new ITEM;
    t->value = value;
    t->next = nullptr;
    return t;
  }
  
   public:
  TPQueue() :head(nullptr), tail(nullptr) {}
  ~TPQueue() {
    while (head)
      pop();
  }
  
  void push(const T &value) {
    if (tail && head) {
      ITEM *temp = head;
      if (temp->value.prior < value.prior) {
        temp = create(value);
        temp->next = head;
        head = temp;
      } else {
        while (temp->next) {
          if (temp->next->value.prior < value.prior) {
            ITEM *t = create(value);
            t->next = temp->next;
            temp->next = t;
            break;
          } else {
            temp = temp->next;
          }
        }
      }
      if (!temp->next) {
        tail->next = create(value);
        tail = tail->next;
      }
    } else {
      head = create(value);
      tail = head;
    }
  }
  T pop() {
    ITEM *temp = head->next;
    T value = head->value;
    delete head;
    head = temp;
    return value;
  }
};

struct SYM {
  char ch;
  int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
