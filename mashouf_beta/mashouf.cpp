#include "mashouf.h"


BBMashouf MASHIO::mashOut(MASHOUF tmash) {
    BBMashouf bmash = packBBMash();
    uint8_t payload_shift17;
    uint8_t payload_shift0;
    
    bmash.seq_num = tmash.seqNum;
    bmash.dest = tmash.isDest;

    payload_shift17 = tmash.payload << 1;
    payload_shift0 = tmash.payload & 0x01;

    bmash.ctrl_sig = tmash.ctrl;
    bmash.P0 = payload_shift0;

    bmash.payload_17 = payload_shift17;

    bmash.crc_check = tmash.crc;

    return bmash;
}

MASHOUF MASHIO::mashIn(BBMashouf imash) {
    MASHOUF tmash;
    uint8_t top_pload, bot_pload, pload;

    tmash.seqNum = imash.seq_num;
    tmash.isDest = imash.dest;
    
    bot_pload = imash.P0;
    top_pload = imash.payload_17 >> 1;
    pload = bot_pload | top_pload;

    tmash.payload = pload;

    tmash.ctrl = static_cast<CTRL_CODE>(imash.ctrl_sig);
    tmash.address = imash.addr;

    tmash.crc = imash.crc_check;
}


BBMashouf MASHIO::packBBMash() {
    BBMashouf bm;
    bm.b1Flag = 1;
    bm.b2Flag = 0;
    bm.b3Flag = 0;
    bm.b4Flag = 1;

    bm.SoP = 0x3;
    bm.EoP = 0x6;

    return bm;
}