#include <stdio.h>

void strassenMultiplication(int A[2][2], int B[2][2], int C[2][2]) {
    int P1, P2, P3, P4, P5, P6, P7;
    P1 = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
    P2 = (A[1][0] + A[1][1]) * B[0][0];
    P3 = A[0][0] * (B[0][1] - B[1][1]);
    P4 = A[1][1] * (B[1][0] - B[0][0]);
    P5 = (A[0][0] + A[0][1]) * B[1][1];
    P6 = (A[1][0] - A[0][0]) * (B[0][0] + B[0][1]);
    P7 = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]);
    C[0][0] = P1 + P4 - P5 + P7;
    C[0][1] = P3 + P5;
    C[1][0] = P2 + P4;
    C[1][1] = P1 + P3 - P2 + P6;
}
void printMatrix(int matrix[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int A[2][2], B[2][2], C[2][2];
    printf("Enter elements of 2x2 matrix A:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    printf("Enter elements of 2x2 matrix B:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    strassenMultiplication(A, B, C);
    printf("Resultant Matrix C:\n");
    printMatrix(C);

    return 0;
}
