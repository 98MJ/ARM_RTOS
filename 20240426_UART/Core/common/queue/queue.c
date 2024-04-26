#include "queue.h"

void que_init(que_t *que)
{
//   que->queBuff = buff;
   que->head = 0;
   que->tail = 0;
   que->queCounter = 0;
}

int queFull(que_t *que)
{
//if (head == ((tail + 1) % 4))
   if (que->queCounter == BUF_SIZE)
      return 1;
   else
      return 0;
}

int queEmpty(que_t *que)
{
//if (head == tail)
   if (que->queCounter == 0)
      return 1;
   else
      return 0;
}

//circular queue
void enQue(que_t *que, uint8_t data)
{
   if (queFull(que)) return;
   que->queBuff[que->tail] = data;
   que->tail = (que->tail + 1) % BUF_SIZE;      //tail = 0, 1, 2, 3 배열안에서 반복
   que->queCounter++;
}

int deQue(que_t *que)
{
   if (queEmpty(que)) return -1;
   int temp = que->queBuff[que->head];
   que->head = (que->head + 1) % BUF_SIZE;      //head = 0, 1, 2, 3 배열안에서 반복
   que->queCounter--;
   return temp;
}
