#ifndef USERSTRUCT_H
#define USERSTRUCT_H
typedef struct User{
    int blade_cnt;
    int assist_blade_cnt;
    int ratchet_cnt;
    int lock_chip_cnt;
    int bit_cnt;
    int simple_ratchet_cnt;
    char blade[1000][50];
    char assist_blade[100][50];
    char ratchet[100][50];
    char bit[100][50];
    char lock_chip[100][50];
    char simple_ratchet[100][50];
}User;
#endif USERSTRUCT_H