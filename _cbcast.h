/** CBCAST defines

    Author: Matheus da Rosa

    Date: 24.04.2102
    Modified: Deadline

**/

/* Functions */
int createGroup(char *IP, int port);
int joinGroup(int group, char *IP, int port);
int leaveGroup(int group);
int sendGroup(int group, char *msg);
int receiveGroup(int group, char *msg);