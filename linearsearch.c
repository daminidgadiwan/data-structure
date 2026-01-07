
#include <stdio.h>
int main() {
    int n, key;
    int pos = 0; 
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &key);
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            pos = i;
            break; 
        }
    }
    if (pos != 0) {
        printf("found at position %d\n", pos);
    } else {
        printf("%d not found\n", key);
    }

    return 0;
}
