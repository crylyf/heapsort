#include <stdio.h>
#include <stdlib.h>

struct minheap {
  int len;
  int maxlen;
  int *data;
};

struct minheap *minheap_create(void) {
  struct minheap *h = malloc (sizeof(struct minheap)); 
  h->len = 0 ; 
  h->maxlen = 1; 
  h->data= malloc(h->maxlen * sizeof(int));
  return h; 
}


bool minheap_is_empty(const struct minheap *h) {
  if (h->len > 0){
    return false;
  }else{ 
    return true; 
}
}


void minheap_insert(int i, struct minheap *h) {
  int temp = i;
  int index = h->len;
  h->len++; 
  if (h->len == h->maxlen) { 
    h->maxlen = (h->maxlen * 2) + 1;
    h->data= realloc(h->data, h->maxlen *(sizeof (int)));
  }
  h->data[h->len - 1] = temp;
  while (temp < h->data[(index - 1) /2]){ 
    h->data[index] = h->data[(index-1)/2];
    h->data[(index-1)/2] = temp;
    index = (index - 1)/2;
  }
}
      
  
  
    



int minheap_top(const struct minheap *h) {
  return h->data[0];
}



int minheap_remove(struct minheap *h) {
  int index = 0 ; 
  int root = h->data[0]; 
  h->len-- ;
  int temp = h->data[h->len];
  h->data[0] = temp; 
  h->data[h->len] = h->data[h->len+1]; 

  while ((temp > h->data[index*2 + 1]) || (temp > h->data[index*2 + 2])) { 
    if ((index *2 +1 >= h->len) && (index * 2 + 2 >= h->len)) { 
      break;
    }else if ((h->data[index * 2 + 1] < temp) && (index *2 + 2) >= h->len){ 
      h->data[index] = h->data [index * 2 + 1]; 
      h->data[index*2 + 1] = temp;
      index = index * 2 + 1; 
    }else if ((h->data[index * 2 + 1] >= temp) && (index *2 + 2) >= h->len){ 
      break; 
    
    }else if (h->data [index *2 +2] >= h->data[index *2 +1]){ 
      h->data[index] = h->data [index * 2 + 1];
      h->data[index * 2 + 1] = temp; 
      index = index * 2 + 1;
    } else if (h->data[index *2 + 1] > h->data[index * 2 + 2]){
      h->data [index] = h->data [index * 2 + 2 ]; 
      h->data [index * 2 + 2] = temp; 
      index = index * 2 + 2; 
    }else { 
      break;
    }
  }
  return root;
}


void minheap_destroy(struct minheap *h) {
  free(h->data);
  free(h);
  
}

void heapsort(int a[], int len) {
  struct minheap *c = minheap_create();
  for (int i = 0 ; i < len; i++){ 
    minheap_insert(a[i], c);
  }
  for (int i = 0; i<len; i++){ 
    a[i]=minheap_remove(c); 
  }
  minheap_destroy(c);
}

/*int main(){ 
  struct minheap *h = minheap_create();
  minheap_insert(1,h);
  minheap_insert(5,h);
  minheap_insert(10,h);
  minheap_remove(h);
  minheap_destroy(h);
}*/
   

