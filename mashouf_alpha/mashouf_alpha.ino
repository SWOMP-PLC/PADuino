enum CTRL_CODE {CMD, DATA, ACK, NACK}; 

struct BBMashouf {
  bool b1Flag:1;
  int SoP:3;
  int SEQ_Num:3;
  bool DEST:1;

  bool b2Flag:1;
  int CTRL_Sig:2;
  int P0:1;
  int Address:4;

  bool b3Flag:1;
  int Payload_17:7;

  bool b4Flag:1;
  int EoP:3;
  int CRC:4;
};

struct MASHOUF {
  int address;
  int seqNum;
  bool isDest;
  CTRL_CODE ctrl;
  unsigned char payload;
  int crc;
};

class SWOMP {
  public:
  static MASHOUF get_mash();


};

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}

