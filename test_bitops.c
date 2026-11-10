#include <stdio.h>
#include <assert.h>
#include "bitops.h"

int main(void) {
    /* =====================================================================
     * PHẦN A: 4 ASSERT KIỂM THỬ MACRO (Tập trung vào biên MSB và độ ưu tiên)
     * ===================================================================== */

    /* Assert 1: Bật bit 7 (MSB) từ 0000 0000 (0x00) -> 1000 0000 (0x80)
     * Bắt lỗi nếu quên dùng 1U hoặc tràn bit dấu */
    assert(SET_BIT(0x00U, 7) == 0x80U);

    /* Assert 2: Xóa bit 0 từ 1111 1111 (0xFF) -> 1111 1110 (0xFE)
     * Bắt lỗi nếu quên ép kiểu (uint8_t) sau toán tử đảo bit ~ */
    assert(CLEAR_BIT(0xFFU, 0) == 0xFEU);

    /* Assert 3: Đảo bit 3 từ 0000 1010 (0x0A) -> 0000 0010 (0x02)
     * Kiểm tra toán tử XOR ^ trên bit đang bật */
    assert(TOGGLE_BIT(0x0AU, 3) == 0x02U);

    /* Assert 4: Kiểm tra bit 2 của 0000 0101 (0x05) đặt cạnh toán tử ==
     * Bắt lỗi thứ tự ưu tiên giữa & và == nếu thiếu ngoặc bao ngoài */
    assert(TEST_BIT(0x05U, 2) == true);

    /* =====================================================================
     * PHẦN B: 4 ASSERT KIỂM THỬ STATIC INLINE (Tập trung vào side-effect++)
     * ===================================================================== */

    /* Assert 5: Truyền x++ và p++ vào set_bit
     * x = 0000 0001 (0x01), bật bit 2 -> 0000 0101 (0x05).
     * Sau lệnh gọi, x phải bằng 0x02 và p1 phải bằng 3 (tăng đúng 1 lần) */
    uint8_t x1 = 0x01U, p1 = 2U;
    assert(set_bit(x1++, p1++) == 0x05U && x1 == 0x02U && p1 == 3U);

    /* Assert 6: Truyền p2++ vào clear_bit
     * 1000 0001 (0x81), xóa bit 7 -> 0000 0001 (0x01), p2 tăng từ 7 lên 8 */
    uint8_t p2 = 7U;
    assert(clear_bit(0x81U, p2++) == 0x01U && p2 == 8U);

    /* Assert 7: Truyền p3++ vào toggle_bit
     * 0101 0101 (0x55), đảo bit 0 -> 0101 0100 (0x54), p3 tăng từ 0 lên 1 */
    uint8_t p3 = 0U;
    assert(toggle_bit(0x55U, p3++) == 0x54U && p3 == 1U);

    /* Assert 8: Truyền p4++ vào test_bit ở vị trí bit đang bằng 0
     * 1111 1011 (0xFB) có bit 2 bằng 0 -> trả về false, p4 tăng từ 2 lên 3 */
    uint8_t p4 = 2U;
    assert(test_bit(0xFBU, p4++) == false && p4 == 3U);

    printf("PASSED\n");
    return 0;
}