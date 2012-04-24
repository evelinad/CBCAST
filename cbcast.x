/** 
    Author: Avelino F. Zorzo
    avelino.zorzo@pucrs.br

    Date: 10.03.2001
    Modified: 10.03.2012

   This code will be translated into the needed stubs and headers
   Use: rpcgen cbcast.x

**/

struct cbcast_params {
    int groupID;
    char *IP;
    char *message;
};

program CBCASTPROG {                /* value to register the program */
    version CBCASTVERS {            /* version must be assigned a value */           
        int CREATEGROUP(cbcast_params)  = 1;
        int JOINGROUP(cbcast_params)    = 2;
        int LEAVEGROUP(cbcast_params)   = 3;
        int SENDGROUP(cbcast_params)    = 4;
        int RECEIVEGROUP(cbcast_params) = 5;
    } = 1;                          /* version value */
} = 0x20000003;                    /* program value */   
