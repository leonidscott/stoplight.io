int load1Level = 30;
int load2Level = 50;
int load3Level = 100;
int counter = 0;
int counter2 = 0;
int t = 0;
unsigned char LOAD1=load1Level,LOAD2=load2Level,LOAD3=load3Level;

void setup() {
  Serial.begin(9600);
}

void loop() {
  counter++;
  counter2++;
  t=counter%400;
  if(t<181){
    setLoad('A', 100);
    setLoad('B', 0);
    setLoad('C', 0);
    }
  if(t >180 && t <220){
    setLoad('A', 0);
    setLoad('B', 100);
    setLoad('C', 0);
    }
  if(t>219){
    setLoad('A', 0);
    setLoad('B', 0);
    setLoad('C', 100);
    }
  if(counter == 400) {
    counter=0;
  }
  delay(33);
}

void setLoad(char channel, unsigned char LOAD) {
  Serial.write(channel);
  CONVERT_DISPLAY(LOAD);
}

void CONVERT_DISPLAY(unsigned int d) {
  unsigned char dig1,dig2,dig3,dig[3];
  unsigned char x;
  unsigned char temp;
  temp=d/10;
  dig1=d%10;
  dig2=temp%10;
  dig3=temp/10;
  dig[0]=dig3;
  dig[1]=dig2;
  dig[2]=dig1;
  for(x=0;x<3;x++) {
    temp=dig[x]|0x30;
    Serial.write(temp);
  }
}
