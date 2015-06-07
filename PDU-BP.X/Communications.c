/*
 PDU Communications


    Authored by Zac Kilburn 6/2/2015



 */

#include <stdbool.h>
#include <xc.h>
#include "Communications.h"
#include "ADDRESSING.h"
#include "Functions.h"

void respondECU();
//extern void Send_put(unsigned char _data);

void updateComms() {
    if (receiveData()) {
        //if (receiveArray[RESPONSE_ADDRESS] == ECU_ADDRESS) {
            respondECU();
        //}
    }
}

void respondECU() {
    LATCbits.LATC5 = 1;
    ToSend(RESPONSE_ADDRESS, PDU_ADDRESS);
    ToSend(POWER_STATE, PDU_ADDRESS);
    Delay(5);

    sendData(ECU_ADDRESS);
    Delay(3);
    LATCbits.LATC5 = 0;
}