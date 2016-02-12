#include <stdio.h>
struct hash{
    char c;
    int count;
};
typedef struct hash chars; 
chars letters[26];
int getHash(char c){
    int l = 0, r = 25, m;
    while(l <= r){
        m = (l + r) / 2;
        if(letters[m].c == c){
            return m;
        }else if(letters[m].c > c){
            r = m - 1;
        }else {
            l = m + 1;
        }
    } 
    return -1;
}
void hashIt(){
  for(int j = 0; j < 26; j++){
        letters[j].c = (char) j + 97;
        letters[j].count = 0;
    }
}
void reset(){
    for(int j = 0; j < 26; j++){
        letters[j].count = 0;
    }
}
int main(){
    char *input = "abcabc"; 
    int count = 0, i = 0, max = 0, j;
    hashIt();
    while(input[i] != '\0'){
       int index = getHash(input[i]);
       if (letters[index].count != 0){      
           count = 0;
           reset();
           printf("%c %d\n", input[i], i);
       }
       count++;
       max = count > max ? count : max;
       letters[index].count++; 
       i++;
    }
    printf("%d", max);
     return 0;
 }
