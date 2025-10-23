#include <stdio.h>

#define MAX 100  // max size for stack

int stack[MAX];
int top = -1;

//below are your stack helpin fnss
int is_empty() {
    return top == -1;//return value either 1or0 after condition check
}

void push(int value) {
    if (top < MAX - 1)
        stack[++top] = value;//remember u always push a elemnt,here its indices
}

int pop() {
    if (top >= 0)
        return stack[top--];//here u pop a ele,its indices
    return -1;
}

int peek() {
    if (top >= 0)
        return stack[top];//whatever u r top points at
    return -1;
}

// The core idea 
void daily_temperatures(const int temperatures[], int n, int answer[]) {
    top = -1;  // reset stack;might contain previous call values

    for (int i = 0; i < n; i++) {
        //while block -> first iter stack is always gonna be empty
        // u just compare current i value with prevvious value in input array
        while (!is_empty() && temperatures[peek()] < temperatures[i]) {
            int j = pop();//poping top elemnt index and storing in j
            answer[j] = i - j;
            //storing that index in a result array, with subtracted value
        }

        push(i);//pushing the index of the temperatures[] array
        //u push every days index, basically says this day is waiting fora //warmer day
    }

    while (!is_empty()) {
        answer[pop()] = 0;//when there are no warmer days in the input assign 0
                            //pop the index of the stack; so eg: answer[2]=0
                            //in temp[]=73,74,75
    }
}


int main() {
    int n;

    // Ask user for number of days
    printf("Enter number of days: ");
    scanf("%d", &n);

    int temperatures[n];
    int answer[n];

    // Input temperatures
    printf("Enter temperatures: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &temperatures[i]);
    }

    daily_temperatures(temperatures, n, answer);

    printf("Result: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", answer[i]);
    }
    printf("\n");

    return 0;
    
}
