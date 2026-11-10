#include <stdio.h>
#include <stdint.h>

#define BAD_SET_BIT(x,pos) (((pos) < 8) ? ((x) | (1U << (pos))) : (x))

#define BAD_TEST_BIT(x,pos) (x) & (1U << (pos))

int main(){
    
    uint8_t reg = 0x00U;
    uint8_t p = 2U;
    uint8_t res1 = BAD_SET_BIT(reg,p++);

    //printf("");

    printf("[Bay 1] res1 = 0x%02X (ky vong 0x04), p = %u (ky vong 3)\n", res1, p);

    /* --- Thực nghiệm Bẫy 2: Thứ tự ưu tiên giữa & và == --- */
    uint8_t status = 0x04U;   /* Nhị phân: 0000 0100 (Bit 2 đang bằng 1) */
    /* Kỳ vọng: Bit 2 khác 0, nên so sánh với 0 phải nhảy vào nhánh ELSE */
    if (BAD_TEST_BIT(status, 2) == 0U) {
        printf("[Bay 2] SAI LOGIC: Bit 2 dang bat nhung lai bao bang 0!\n");
    } else {
        printf("[Bay 2] DUNG: Bit 2 dang bat.\n");
    }

    /* --- Thực nghiệm Bẫy 3: Toán tử đảo bit ~ trên uint8_t --- */
    uint8_t mask = 0x01U;     /* Nhị phân: 0000 0001, đảo bit kỳ vọng là 0xFE */
    if (~mask == 0xFEU) {
        printf("[Bay 3] ~mask bang 0xFE\n");
    } else {
        printf("[Bay 3] SAI KIEU: ~mask = 0x%08X (khong bang 0xFE)!\n", ~mask);
    }

    return 0;
}

