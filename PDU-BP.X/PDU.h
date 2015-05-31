/* 
 * File:   PDU.h
 * Author: Richard Johnson
 *
 * Created on May 27, 2015, 7:46 PM
 */

#ifndef PDU_H
#define	PDU_H

#define NUMOFBYTES 12  //8-1

int Currentcomp[6] = 0;
char data[NUMOFBYTES] = 0;
int CurrentADC[6] = 0;
int Current[6] = 0;

typedef enum
{
    SAS = 1,
    DDS = 2,
    MCS = 3,
    BMM = 4,
    TSS = 5,
    AUX = 6,
    ON = 1,
    OFF = 0
}device;

extern void PDUStartup(void);
void EnableSlavePower(device slave, int onof);
void ComputeStorageData(void);
void ReadCurrent(char gather);
void Update(void);

#endif	/* PDU_H */
