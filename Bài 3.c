#include <stdio.h>
#define MAX 100

int main() {
    int so_thu_tu[MAX];
    int tuoi[MAX];
    int bhyt[MAX];

    int n;
    int K;
    int i; 

    int tong_doanh_thu;
    int so_uu_tien;

    do {
        printf("Nhap so luong benh nhan (0-%d): ", MAX);
        scanf("%d", &n);

        if (n < 0 || n > MAX) {
            printf("So luong khong hop le!\n");
        }
    } while (n < 0 || n > MAX);

    for (i = 0; i < n; i++) {
        so_thu_tu[i] = 1001 + i;

        do {
            printf("\nBenh nhan %d - Nhap tuoi: ", i + 1);
            scanf("%d", &tuoi[i]);

            if (tuoi[i] < 1 || tuoi[i] > 120) {
                printf("Tuoi khong hop le! Nhap lai.\n");
            }
        } while (tuoi[i] < 1 || tuoi[i] > 120);

        do {
            printf("Benh nhan %d - Nhap BHYT (0-Khong, 1-Co): ", i + 1);
            scanf("%d", &bhyt[i]);

            if (bhyt[i] != 0 && bhyt[i] != 1) {
                printf("Trang thai BHYT khong hop le! Nhap lai.\n");
            }
        } while (bhyt[i] != 0 && bhyt[i] != 1);
    }

    tong_doanh_thu = 0;
    so_uu_tien = 0;

    for (i = 0; i < n; i++) {
        if (bhyt[i] == 1) {
            tong_doanh_thu = tong_doanh_thu + 30000;
        }
        else {
            tong_doanh_thu = tong_doanh_thu + 150000;
        }

        if (tuoi[i] >= 70) {
            so_uu_tien = so_uu_tien + 1;
        }
    }

    printf("\n----------------------------------------\n");
    printf("DANH SACH HANG CHO BAN DAU\n");
    printf("-----------------------------------------\n");

    for (i = 0; i < n; i++) {
        printf("Index %d - So thu tu: %d - Tuoi: %d - BHYT: %d", i, so_thu_tu[i], tuoi[i], bhyt[i]);

        if (tuoi[i] >= 70) {
            printf(" - UU TIEN");
        }
        else {
            printf(" - THUONG");
        }

        printf("\n");
    }

    printf("Tong so benh nhan: %d\n", n);
    printf("Tong doanh thu du kien: %d VND\n", tong_doanh_thu);
    printf("So benh nhan uu tien: %d\n", so_uu_tien);

    if (n == 0) {
        printf("\nHang cho dang rong, khong the huy!\n");
    }
    else {
        printf("\nNhap vi tri K can huy: ");
        scanf("%d", &K);

        if (K < 0 || K >= n) {
            printf("Vi tri K khong hop le! Khong thuc hien huy.\n");
        }
        else {
            printf("Da huy benh nhan co so thu tu: %d\n", so_thu_tu[K]);

            for (i = K; i < n - 1; i++) {
                so_thu_tu[i] = so_thu_tu[i + 1];
                tuoi[i] = tuoi[i + 1];
                bhyt[i] = bhyt[i + 1];
            }

            n = n - 1;

            tong_doanh_thu = 0;
            so_uu_tien = 0;

            for (i = 0; i < n; i++) {
                if (bhyt[i] == 1) {
                    tong_doanh_thu = tong_doanh_thu + 30000;
                }
                else {
                    tong_doanh_thu = tong_doanh_thu + 150000;
                }

                if (tuoi[i] >= 70) {
                    so_uu_tien = so_uu_tien + 1;
                }
            }

            printf("\n========================================\n");
            printf("DANH SACH HANG CHO SAU KHI HUY\n");
            printf("========================================\n");

            for (i = 0; i < n; i++) {
                printf("Index %d - So thu tu: %d - Tuoi: %d - BHYT: %d",
                       i, so_thu_tu[i], tuoi[i], bhyt[i]);

                if (tuoi[i] >= 70) {
                    printf(" - UU TIEN");
                }
                else {
                    printf(" - THUONG");
                }

                printf("\n");
            }

            printf("Tong so benh nhan con lai: %d\n", n);
            printf("Tong doanh thu sau khi huy: %d VND\n",
                   tong_doanh_thu);
            printf("So benh nhan uu tien: %d\n", so_uu_tien);
        }
    }

    return 0;
}
