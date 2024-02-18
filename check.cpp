// // #include <stdio.h>

// // int main() {
// //     // int num = 537; // 5 + 3 + 7 = 15
// //     // num = num % 10;

// //     int num = 0;

// //     scanf("%d", &num);

// //     // printf("%d\n", num % 10);
// //     // printf("%d\n", num / 10);
// //     // num = num / 10;
// //     // printf("%d\n", num % 10);
// //     // num = num / 10;
// //     // printf("%d\n", num % 10);

// //     int sum = 0;
// //     while (num != 0) {
// //         int rem = num % 10; // last digit 7, 3, 5
// //         sum = sum + rem;    // 0 + 7 + 3 + 5

// //         num = num / 10;     // 53, 3, 0
// //     }

// //     printf("%d", sum);

// //     return 0;
// // }

// #include <stdio.h>

// int factorialFun (int num) {
//     if (num == 0 || num == 1) {
//         return 1;
//     } else {
//         return (num * factorialFun(num - 1));
//     }
// }

// int main() {
//     int num = 5;    // 5 x 4 x 3 x 2 x 1 = 120

//     // 0! = 1
//     // 1! = 1

//     printf("%d", factorialFun(num));

//     // int factorial = 1;

//     // if (num == 0) {
//     //     printf("1");
//     //     return 0;
//     // }

//     // non-recursive
//     // for (int i = 1; i <= num; i++) {
//     //     factorial = factorial * i;
//     // //  1 = 1 * 1 = 1
//     // //  1 = 1 * 2 = 2
//     // //  2 = 2 * 3 = 6
//     // //  6 = 6 * 4 = 24
//     // // 24 = 24 * 4 = 120
//     // }

//     // non-recursive
//     // while (num != 0) {
//     //     factorial = factorial * num;

//     //     num--;
//     // }

//     // printf("%d", factorial);
// }

// #include <stdio.h>
// #include <string.h>

// int main() {
//     char str1[50], str2[50];
//     int i, j, n, m, l;
//     printf("Enter the string\n");
//     gets(str1); // scanf ("%s",str1);
//     printf("Enter the position of the required character:\n ");
//     scanf("%d", &n);
//     printf("Enter the required number of characters to be extracted:\n ");
//     scanf("%d", &m);
//     l = strlen(str1);
//     if (m + n - 1 < l) {
//         for (i = n - 1, j = 0; i < m + n - 1; i++, j++) {
//             str2[j] = str1[i];
//         }
//         str2[j] = '\0';
//         printf("The extracted string is: %s", str2);
//     } else {
//         printf("string extraction is not possible");
//     }
//     return 0;
// }

// addition of two matrices
// #include <stdio.h>

// int main() {
//     int m1[3][3] = {
//         {1, 2, 3},
//         {4, 5, 6},
//         {7, 8, 9}
//     };

//     /*
//     m1[0][0] = 1
//     m1[1][2] = 6
//     */
//     int m2[3][3] = {
//         {2, 4, 6},
//         {8, 10, 12},
//         {14, 16, 18}
//     };

//     int sum[3][3];

//     for (int i = 0; i < 3; i++) {
//         for (int j = 0; j < 3; j++) {
//             sum[i][j] = m1[i][j] + m2[i][j];
//         }
//     }

//     for (int i = 0; i < 3; i++) {
//         for (int j = 0; j < 3; j++) {
//             printf("%d ", sum[i][j]);
//         }
//         printf("\n");
//     }

//     return 0;
// }

#include <stdio.h>

int main()
{
    int a[3][3], b[3][3], result[3][3], r1 = 3, c1 = 3, r2 = 3, c2 = 3, i, j, k;

    // Taking input for first matrix
    printf("Enter elements of 1st matrix\n");
    for (i = 0; i < r1; ++i)
        for (j = 0; j < c1; ++j)
        {
            printf("Enter element a%d%d: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }

    // Taking input for second matrix
    printf("\nEnter elements of 2nd matrix\n");
    for (i = 0; i < r2; ++i)
        for (j = 0; j < c2; ++j)
        {
            printf("Enter element b%d%d: ", i + 1, j + 1);
            scanf("%d", &b[i][j]);
        }

    // Initializing elements of matrix mult to 0.
    for (i = 0; i < r1; ++i)
        for (j = 0; j < c2; ++j)
        {
            result[i][j] = 0;
        }

    // Multiplying matrices a and b and storing in array mult.
    for (i = 0; i < r1; ++i)
        for (j = 0; j < c2; ++j)
            for (k = 0; k < c1; ++k)
            {
                result[i][j] += a[i][k] * b[k][j];
            }

    // Displaying the multiplication of two matrix.
    printf("\nOutput Matrix:\n");
    for (i = 0; i < r1; ++i)
        for (j = 0; j < c2; ++j)
        {
            printf("%d  ", result[i][j]);
            if (j == c2 - 1)
                printf("\n\n");
        }

    return 0;
}