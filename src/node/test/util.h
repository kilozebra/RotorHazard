#include "../median-filter.h"

#define milliTick(nano) (nano->micros += 1000)
#define readPeak() (history.peakSend.rssi = 0)
#define readNadir() (history.nadirSend.rssi = MAX_RSSI)

const static int N_2 = _filter.getSampleCapacity()/2+1;
const static int N_TS = _filter.getTimestampCapacity();

void sendSignal(GodmodeState* nano, int rssi) {
  for(int t=0; t<N_2; t++) {
    rssiProcess(rssi, millis());
    milliTick(nano);
  }
}

mtime_t timestamp(int sendCount) {
  return sendCount*N_2 - N_TS;
}

mtime_t time(int sendCount) {
  return sendCount*N_2;
}
