#pragma once

#include <stdint.h>

enum CTRL_CODE { CMD, DATA, ACK, NACK };

struct BBMashouf {
 public:
  bool b1Flag : 1;
  int SoP : 3;
  int SEQ_Num : 3;
  bool DEST : 1;

  bool b2Flag : 1;
  int CTRL_Sig : 2;
  int P0 : 1;
  int Address : 4;

  bool b3Flag : 1;
  int Payload_17 : 7;

  bool b4Flag : 1;
  int EoP : 3;
  int CRC : 4;
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
    
}

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
