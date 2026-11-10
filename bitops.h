// #ifndef BITOPS_H
// #define BITOPS_H

// #include <stdint.h>
// #include <stdbool.h>

// /* Phiên bản Macro: Bọc ngoặc mọi đối số, dùng 1U và ép kiểu (uint8_t) */
// #define SET_BIT(x, pos)     ((uint8_t)((uint8_t)(x) | (uint8_t)(1U << (pos))))
// #define CLEAR_BIT(x, pos)   ((uint8_t)((uint8_t)(x) & (uint8_t)~(1U << (pos))))
// #define TOGGLE_BIT(x, pos)  ((uint8_t)((uint8_t)(x) ^ (uint8_t)(1U << (pos))))
// #define TEST_BIT(x, pos)    (((uint8_t)(x) & (uint8_t)(1U << (pos))) != 0U)

// /* Phiên bản static inline: Kiểm tra kiểu chặt chẽ, tính đối số đúng 1 lần */
// static inline uint8_t set_bit(uint8_t x, uint8_t pos) {
//     return (uint8_t)(x | (uint8_t)(1U << pos));
// }

// static inline uint8_t clear_bit(uint8_t x, uint8_t pos) {
//     return (uint8_t)(x & (uint8_t)~(1U << pos));
// }

// static inline uint8_t toggle_bit(uint8_t x, uint8_t pos) {
//     return (uint8_t)(x ^ (uint8_t)(1U << pos));
// }

// static inline bool test_bit(uint8_t x, uint8_t pos) {
//     return (x & (uint8_t)(1U << pos)) != 0U;
// }

// #endif /* BITOPS_H */