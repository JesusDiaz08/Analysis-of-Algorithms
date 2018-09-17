/* Se usa una lista enlazada para la pila */

#define bool int

struct sNode
{
  struct tNode *t;
  struct sNode *next;
};

void push (struct sNode ** top_ref, struct tNode * t);
struct tNode * pop (struct sNode ** top_ref);
bool isEmpty (struct sNode * top);
