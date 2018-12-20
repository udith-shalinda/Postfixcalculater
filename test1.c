#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 20

struct stack{
    int top;
    int stk[max];
};

typedef struct stack st;
st s;

void create_stack(st *s){
    s->top = -1;
}

int push(st *s,int ch){
    if(s->top == max-1){
        printf("stack is full\n");
    }else{
        s->top++;
        s->stk[s->top] = ch;
        return  s->stk[s->top];
    }
}

int pop(st *s){
    if(s->top == -1){
        printf("stack is empty\n");
        return NULL;
    }else{
        return s->stk[s->top--];
    }

}
void display(st *s){
  for(int i = 0; i<= s->top ; i++){
      printf(" %c", s->stk[i]);
  }
  printf("\n");
}

void passString(char array[]){
    for(int i =0; i< strlen(array);i++){
            push(&s,array[i]);
    }
}


void main(){
    char stop[4],input[12];
    strcpy(stop, "stop");
    int answer;
   while(1){
        printf("Enter the String : ");

       do{
        scanf("%s",input);
        int inputvalue = atoi(input);
        if(inputvalue== 0){
            if(strcmp(input,"+") ==0){
                    answer = push(&s,(pop(&s) + pop(&s)));
            }else if(strcmp(input,"-") ==0){
                int popele1 = pop(&s);
                answer = push(&s,( pop(&s)-popele1));
            }else if(strcmp(input,"*") ==0){
                answer = push(&s,(pop(&s) * pop(&s)));
            }else if(strcmp(input,"/") ==0){
                int popele1 = pop(&s);
                answer = push(&s,(pop(&s)/popele1));
            }else if(strcmp(input,"=") ==0){
                answer = pop(&s);
            }else if(strcmp(stop,input) ==0){
                return;
            }
        }else{
            push(&s, inputvalue);
            }

       }while(strcmp(input,"=")!= 0 || );
        printf("The answer is %d\n", answer);
    }

}
