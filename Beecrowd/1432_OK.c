#include<stdio.h>
#define MAX_SIZE 131071

struct {
	int number, size;
	int next;
}NO[3000];

int real_size, HASH_TABLE[MAX_SIZE+1];

void clearAll() {
    int i;
    for(i = 0, real_size = 1; i <= MAX_SIZE; i++)
        HASH_TABLE[i] = 0;
}

void insereNaHash(int number, int size) {
    static int index, previous, current;
    index = number & MAX_SIZE;
    previous = 0, current = HASH_TABLE[index];
    while(current) {
        if(NO[current].number == number && NO[current].size == size)
            return;
        else if(NO[current].number < number || (NO[current].number == number && NO[current].size < size))
            previous = current, current = NO[current].next;
        else    break;
    }
    NO[real_size].number = number, NO[real_size].size = size;
    NO[real_size].next = current;
    if(previous)    
        NO[previous].next = real_size;
    else    
        HASH_TABLE[index] = real_size;
    real_size++;
}

int buscaNaHash(int number, int size) {
	static int indice, previous, current;
    indice = number & MAX_SIZE;
    previous = 0, current = HASH_TABLE[indice];
    while(current) {
        if(NO[current].number == number && NO[current].size == size)
            return 1;
        else if(NO[current].number < number || (NO[current].number == number && NO[current].size < size))
            previous = current, current = NO[current].next;
        else    break;
    }
    return 0;
}

void build() {
	clearAll();
	int i, j, k, temporario;
	for(i = 1; i <= 10; i++) {
		k = (1<<i)-1;
		for(j = 0; j <= k; j++) {
			temporario = j | (j << i) | (j << (2*i)); 
			insereNaHash(temporario, i*3);
		}
	}
}

int n, answer, Caso = 0;
char padrao[35];

void DFS(int number, char *padrao, int indice) {
	int i;
	for(i = 3; i <= indice; i+=3) {
		if(buscaNaHash(number & ((1<<i)-1), i))
			return;
	}
	if(*padrao == '\0') {
		answer++; return;
	}
	if((*padrao) == '1' || (*padrao) == '0') {
		DFS((number<<1) | ((*padrao)-'0'), padrao+1, indice+1);
	} else {
		DFS((number<<1) | 0, padrao+1, indice+1);
		DFS((number<<1) | 1, padrao+1, indice+1);
	}
}

int main() {
	build();
	while(scanf("%d", &n) == 1 && n) {
		answer = 0;
		scanf("%s", padrao);
		DFS(0, padrao, 0);
		printf("Case %d: %d\n", ++Caso, answer);
	}
	return 0;
}