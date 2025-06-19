#pragma once

#include <stdint.h>

enum CTRL_CODE { CMD, DATA, ACK, NACK };

struct BBMashouf {
 public:
  bool b1Flag : 1;
  int SoP : 3;
  int seq_num : 3;
  bool dest : 1;

  bool b2Flag : 1;
  int ctrl_sig : 2;
  int P0 : 1;
  int addr : 4;

  bool b3Flag : 1;
  int payload_17 : 7;

  bool b4Flag : 1;
  int EoP : 3;
  int crc_check : 4;
};

/*
class BBMash {
  public:
  BBMash();
  BBMashouf pkt;
};
*/

struct MASHOUF {
  int address;
  int seqNum;
  bool isDest;
  CTRL_CODE ctrl;
  unsigned char payload;
  int crc;
};

class MASHIO {
    public:
    static BBMashouf mashOut(MASHOUF tmash);
    static BBMashouf packBBMash();
    static MASHOUF mashIn(BBMashouf imash);
};

class PACKET_FIFO {
 public:
  int top;
  int bot;
  void mash_put();
  uint32_t mash_pop();
  uint8_t byte_buff[8][4];
};

class SWOMP_LIB {
 public:
  PACKET_FIFO pkt_fifo;
  int top;
  int bot;
  MASHOUF mash_buff[8];
  MASHOUF get_mash();
  void put_mash();
};

MASHOUF SWOMP_LIB::get_mash() {}
